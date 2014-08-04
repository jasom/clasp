;;;;  -*- Mode: Lisp; Syntax: Common-Lisp; Package: CLOS -*-
;;;;
;;;;  Copyright (c) 1992, Giuseppe Attardi.
;;;;  Copyright (c) 2001, Juan Jose Garcia Ripoll.
;;;;
;;;;    ECoLisp is free software; you can redistribute it and/or
;;;;    modify it under the terms of the GNU Library General Public
;;;;    License as published by the Free Software Foundation; either
;;;;    version 2 of the License, or (at your option) any later version.
;;;;
;;;;    See file '../Copyright' for full details.

(in-package "CLOS")

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; COMPILING EFFECTIVE METHODS
;;;
;;; The following functions take care of transforming the forms
;;; produced by the method combinations into effective methods. In ECL
;;; effective methods are nothing but directly callable functions.
;;; Ideally, this compilation should just produce new compiled
;;; functions. However, we do not want to cons a lot of functions, and
;;; therefore we use closures.
;;;
;;; Formerly we used to keep a list of precompiled effective methods
;;; and made a structural comparison between the current method and
;;; the precompiled ones, so as to save memory. This only causes
;;; improvements in declarative combinations. For standard combinations
;;; it should be enough with a couple of different closures and hence
;;; the structural comparison is a loss of time.
;;;
;;; This is the core routine. It produces effective methods (i.e.
;;; functions) out of the forms generated by the method combinators.
;;; We consider the following cases:
;;;  1) Ordinary methods. The function of the method is extracted.
;;;  2) Functions. They map to themselves. This only happens
;;;     when these functions have been generated by previous calls
;;;     to EFFECTIVE-METHOD-FUNCTION.
;;;  3) (CALL-METHOD method rest-methods) A closure is
;;;	generated that invokes the current method while informing
;;;	it about the remaining methods.
;;;  4) (MAKE-METHOD form) A function is created that takes the
;;;	list of arguments of the generic function and evaluates
;;;	the forms in a null environment. This is the only form
;;;	that may lead to consing of new bytecodes objects. Nested
;;;	CALL-METHOD are handled via the global macro CALL-METHOD.
;;;  5) Ordinary forms are turned into lambda forms, much like
;;;	what happens with the content of MAKE-METHOD.
;;;
#+compare(print "combin.lsp 50")
(defun effective-method-function (form &optional top-level &aux first)
  (cond ((functionp form)
	 form)
	((method-p form)
	 (method-function form))
	((atom form)
	 (error "Malformed effective method form:~%~A" form))
	((eq (setf first (first form)) 'MAKE-METHOD)
	 (coerce `(lambda (.combined-method-args. *next-methods*)
		    (declare (special .combined-method-args. *next-methods*))
		    ,(second form))
		 'function))
	((eq first 'CALL-METHOD)
	 (combine-method-functions
	  (effective-method-function (second form))
	  (mapcar #'effective-method-function (third form))))
	(top-level
	 (coerce `(lambda (.combined-method-args. no-next-methods)
		    (declare (ignorable no-next-methods))
		    ,form)
		 'function))
	(t
	 (error "Malformed effective method form:~%~A" form))))

;;;
;;; This function is a combinator of effective methods. It creates a
;;; closure that invokes the first method while passing the information
;;; of the remaining methods. The resulting closure (or effective method)
;;; is the equivalent of (CALL-METHOD method rest-methods)
;;;
#+compare(print "combin.lsp 81")
(defun combine-method-functions (method rest-methods)
  (declare (si::c-local))
  #'(lambda (.combined-method-args. no-next-methods)
      (declare (ignorable no-next-methods))
      (funcall method .combined-method-args. rest-methods)))

#+compare(print "combin.lsp 88")
(defmacro call-method (method &optional rest-methods)
  `(funcall ,(effective-method-function method)
	    .combined-method-args.
	    ',(and rest-methods (mapcar #'effective-method-function rest-methods))))

#+compare(print "combin.lsp 94")
(defun call-next-method (&rest args)
  (declare (special .combined-method-args. *next-methods*))
  (unless *next-methods*
    (error "No next method."))
  (funcall (car *next-methods*) (or args .combined-method-args.) (rest *next-methods*)))

#+compare(print "combin.lsp 104")
(defun next-method-p ()
  (declare (special *next-methods*))
  *next-methods*)

#+compare(print "combin.lsp 109")
(define-compiler-macro call-next-method (&rest args)
  `(if *next-methods*
       (funcall (car *next-methods*)
		,(if args `(list ,@args) '.combined-method-args.)
		(rest *next-methods*))
       (error "No next method.")))

#+compare(print "combin.lsp 117")
(define-compiler-macro next-method-p ()
  'clos::*next-methods*)

#+compare(print "combin.lsp 121")
(defun error-qualifier (m qualifier)
  (declare (si::c-local))
  (error "Standard method combination allows only one qualifier ~
          per method, either :BEFORE, :AFTER, or :AROUND; while ~
          a method with ~S was found."
	 m qualifier))

#+compare(print "combin.lsp 129")
(defun standard-main-effective-method (before primary after)
  (declare (si::c-local))
  #'(lambda (.combined-method-args. no-next-method)
      (declare (ignorable no-next-method))
      (dolist (i before)
	(funcall i .combined-method-args. nil))
      (if after
	  (multiple-value-prog1
	   (funcall (first primary) .combined-method-args. (rest primary))
	   (dolist (i after)
	     (funcall i .combined-method-args. nil)))
	(funcall (first primary) .combined-method-args. (rest primary)))))

#+compare(print "combin.lsp 143")
(defun standard-compute-effective-method (gf methods)
  (with-early-accessors (+standard-method-slots+)
    (let* ((before ())
	   (primary ())
	   (after ())
	   (around ()))
      (dolist (m methods)
	(let* ((qualifiers (method-qualifiers m))
	       (f (method-function m)))
	  (cond ((null qualifiers) (push f primary))
		((rest qualifiers) (error-qualifier m qualifiers))
		((eq (setq qualifiers (first qualifiers)) :BEFORE)
		 (push f before))
		((eq qualifiers :AFTER) (push f after))
		((eq qualifiers :AROUND) (push f around))
		(t (error-qualifier m qualifiers)))))
      ;; When there are no primary methods, an error is to be signaled,
      ;; and we need not care about :AROUND, :AFTER or :BEFORE methods.
      (when (null primary)
	(return-from standard-compute-effective-method
	  #'(lambda (&rest args)
	      (apply 'no-primary-method gf args))))
      ;; PRIMARY, BEFORE and AROUND are reversed because they have to
      ;; be on most-specific-first order (ANSI 7.6.6.2), while AFTER
      ;; may remain as it is because it is least-specific-order.
      (setf primary (nreverse primary)
	    before (nreverse before))
      (if around
	  (let ((main (if (or before after)
			  (list
			   (standard-main-effective-method before primary after))
			  primary)))
	    (setf around (nreverse around))
	    (combine-method-functions (first around)
				      (nconc (rest around) main)))
	  (if (or before after)
	      (standard-main-effective-method before primary after)
	      (combine-method-functions (first primary) (rest primary))))
      )))

;; ----------------------------------------------------------------------
;; DEFINE-METHOD-COMBINATION
;;
;; METHOD-COMBINATION objects are just a list
;;	(name arg*)
;; where NAME is the name of the method combination type defined with
;; DEFINE-METHOD-COMBINATION, and ARG* is zero or more arguments.
;;
;; For each method combination type there is an associated function,
;; and the list of all known method combination types is kept in
;; *METHOD-COMBINATIONS* in the form of property list:
;;	(mc-type-name1 function1 mc-type-name2 function2 ....)
;;
;; FUNCTIONn is the function associated to a method combination. It
;; is of type (FUNCTION (generic-function method-list) FUNCTION),
;; and it outputs an anonymous function which is the effective method.
;;

#+compare(print "combin.lsp 202")

#+threads
(defparameter *method-combinations-lock* (mp:make-lock :name 'find-method-combination))
(defparameter *method-combinations* (make-hash-table :size 32 :test 'eq))


#-brcl
(defun search-method-combination (name)
  (mp:with-lock (*method-combinations-lock*)
    (or (gethash name *method-combinations*)
	(error "~A does not name a method combination" name))))


#+compare(print "combin.lsp 216")

#+brcl
(defun search-method-combination (name)
    (or (gethash name *method-combinations*)
	(error "~A does not name a method combination" name)))

#-brcl
(defun install-method-combination (name function)
  (mp:with-lock (*method-combinations-lock*)
    (setf (gethash name *method-combinations*) function))
  name)

#+compare(print "combin.lsp 229")

#+brcl
(defun install-method-combination (name function)
  (setf (gethash name *method-combinations*) function)
  name)

#+compare(print "combin.lsp 236")
(defun make-method-combination (name compiler options)
  (with-early-make-instance +method-combination-slots+
    (o (find-class 'method-combination)
       :name name
       :compiler compiler
       :options options)
    o))

#+compare(print "combin.lsp 245")
(defun find-method-combination (gf method-combination-type-name method-combination-options)
  (make-method-combination method-combination-type-name
			   (search-method-combination method-combination-type-name)
			   method-combination-options
			   ))

#+compare(print "combin.lsp 252")
(defun define-simple-method-combination (name &key documentation
					 identity-with-one-argument
					 (operator name))
  `(define-method-combination
     ,name (&optional (order :MOST-SPECIFIC-FIRST))
     ((around (:AROUND))
      (principal (,name) :REQUIRED t))
     ,documentation
     (let ((main-effective-method
	    `(,',operator ,@(mapcar #'(lambda (x) `(CALL-METHOD ,x NIL))
				    (if (eql order :MOST-SPECIFIC-LAST)
					(reverse principal)
					principal)))))
       (cond (around
	      `(call-method ,(first around)
		(,@(rest around) (make-method ,main-effective-method))))
	     (,(if identity-with-one-argument
		   '(rest principal)
		   t)
	      main-effective-method)
	     (t (second main-effective-method))))))

#+compare(print "combin.lsp 275")
(defun define-complex-method-combination (form)
  (declare (si::c-local))
  (flet ((syntax-error ()
	   (error "~S is not a valid DEFINE-METHOD-COMBINATION form"
		  form)))
    (destructuring-bind (name lambda-list method-groups &rest body &aux
			 (group-names '())
			 (group-checks '())
			 (group-after '())
			 (generic-function '.generic-function.)
			 (method-arguments '()))
	form
      (unless (symbolp name) (syntax-error))
      (let ((x (first body)))
	(when (and (consp x) (eql (first x) :ARGUMENTS))
	  (error "Option :ARGUMENTS is not supported in DEFINE-METHOD-COMBINATION.")))
      (let ((x (first body)))
	(when (and (consp x) (eql (first x) :GENERIC-FUNCTION))
	  (setf body (rest body))
	  (unless (symbolp (setf generic-function (second x)))
	    (syntax-error))))
      (dolist (group method-groups)
	(destructuring-bind (group-name predicate &key description
				  (order :most-specific-first) (required nil))
	    group
	  (if (symbolp group-name)
	      (push group-name group-names)
	      (syntax-error))
	  (let ((condition
		(cond ((eql predicate '*) 'T)
		      ((and predicate (symbolp predicate))
                       `(,predicate .METHOD-QUALIFIERS.))
		      ((and (listp predicate)
			    (let* ((q (last predicate 0))
				   (p (copy-list (butlast predicate 0))))
			      (when (every #'symbolp p)
				(if (eql q '*)
				    `(every #'equal ',p .METHOD-QUALIFIERS.)
				    `(equal ',p .METHOD-QUALIFIERS.))))))
		      (t (syntax-error)))))
	    (push `(,condition (push .METHOD. ,group-name)) group-checks))
	  (when required
	    (push `(unless ,group-name
		    (error "Method combination: ~S. No methods ~
			    in required group ~S." ,name ,group-name))
		  group-after))
	  (case order
	    (:most-specific-first
	     (push `(setf ,group-name (nreverse ,group-name)) group-after))
	    (:most-specific-last)
	    (otherwise
             (let ((order-var (gensym)))
               (setf group-names (append group-names (list (list order-var order)))
                     group-after (list* `(when (eq ,order-var :most-specific-first)
                                           (setf ,group-name (nreverse ,group-name)))
                                        group-after)))))))
      `(install-method-combination ',name
	  (ext::lambda-block ,name (,generic-function .methods-list. ,@lambda-list)
	    (let (,@group-names)
	      (dolist (.method. .methods-list.)
		(let ((.method-qualifiers. (method-qualifiers .method.)))
		  (cond ,@(nreverse group-checks)
			(t (invalid-method-error .method.
			     "Method qualifiers ~S are not allowed in the method~
			      combination ~S." .method-qualifiers. ,name)))))
	      ,@group-after
	      (effective-method-function (progn ,@body) t))))
      )))

#+compare(print "combin.lsp 345")
(defmacro define-method-combination (name &body body)
  (if (and body (listp (first body)))
      (define-complex-method-combination (list* name body))
      (apply #'define-simple-method-combination name body)))

#+compare(print "combin.lsp 351")
(defun method-combination-error (format-control &rest args)
  ;; FIXME! We should emit a more detailed error!
  (error "Method-combination error:~%~S"
	 (apply #'format nil format-control args)))

#+compare(print "combin.lsp 357")
(defun invalid-method-error (method format-control &rest args)
  (error "Invalid method error for ~A~%~S"
	 method
	 (apply #'format nil format-control args)))

;;; ----------------------------------------------------------------------
;;; COMPUTE-EFFECTIVE-METHOD
;;;

#+compare(print "combin.lsp 367")
;; The following chokes in clasp because I don't have the method-combination class defined
;; during compilation of the full clasp source code.
;; I don't use compiler macros anyway so I'll feature this out
#-clasp
(eval-when (compile #+brcl-boot :load-toplevel)
  (let* ((class (find-class 'method-combination)))
    (define-compiler-macro method-combination-compiler (o)
      `(si::instance-ref ,o ,(slot-definition-location (gethash 'compiler (slot-table class)))))
    (define-compiler-macro method-combination-options (o)
      `(si::instance-ref ,o ,(slot-definition-location (gethash 'options (slot-table class)))))))

#+compare(print "combin.lsp 376")
(defun std-compute-effective-method (gf method-combination applicable-methods)
  (declare (type method-combination method-combination)
	   (type generic-function gf)
	   (optimize speed (safety 0)))
  (with-early-accessors (+method-combination-slots+)
    (let* ((compiler (method-combination-compiler method-combination))
	   (options (method-combination-options method-combination)))
      (if options
	  (apply compiler gf applicable-methods options)
	  (funcall compiler gf applicable-methods)))))

#+compare(print "combin.lsp 388")
(defun compute-effective-method-function (gf method-combination applicable-methods)
  ;; Cannot be inlined because it will be a method
  (declare (notinline compute-effective-method))
  (let ((form (compute-effective-method gf method-combination applicable-methods)))
    (let ((aux form) f)
      (if (and (listp aux)
		 (eq (pop aux) 'funcall)
		 (functionp (setf f (pop aux)))
		 (eq (pop aux) '.combined-method-args.)
		 (eq (pop aux) '*next-methods*))
	  f
	  (effective-method-function form t)))))

#+compare(print "combin.lsp 402")
(defun compute-effective-method (gf method-combination applicable-methods)
  `(funcall ,(std-compute-effective-method gf method-combination applicable-methods)
	    .combined-method-args. *next-methods*))

;;
;; These method combinations are bytecompiled, for simplicity.
;;
#+compare(print "MLOG About to install-method-combination")
(install-method-combination 'standard 'standard-compute-effective-method)
(eval '(progn
	(define-method-combination progn :identity-with-one-argument t)
	(define-method-combination and :identity-with-one-argument t)
	(define-method-combination max :identity-with-one-argument t)
	(define-method-combination + :identity-with-one-argument t)
	(define-method-combination nconc :identity-with-one-argument t)
	(define-method-combination append :identity-with-one-argument nil)
	(define-method-combination list :identity-with-one-argument nil)
	(define-method-combination min :identity-with-one-argument t)
	(define-method-combination or :identity-with-one-argument t)))

#+compare( print "MLOG ****** Done with combin.lsp ******")
