#define	DEBUG_LEVEL_FULL

#include "core/foundation.h"
#include "core/object.h"
#include "core/cons.h"
#include "core/symbolTable.h"
#include "core/designators.h"
#include "core/str.h"
#include "core/evaluator.h"
#include "core/lispStream.h"
#include "core/primitives.h"
#include "core/write_object.h"
#include "core/arguments.h"
#include "core/wrappers.h"

namespace core
{

    int brcl_print_base(void)
    {
	T_sp object = cl::_sym_STARprint_baseSTAR->symbolValue();
	int base;
	if ( !af_fixnumP(object) || (base = object.as<Fixnum_O>()->get()) < 2 || base > 36 )
	{
	    SIMPLE_ERROR(BF("The value of *PRINT-BASE*\n %s\n"
			    "is not of the expected type (INTEGER 2 36)") % _rep_(object) );
	}
	return base;
    }



    int brcl_print_level(void)
    {
	T_sp object = cl::_sym_STARprint_levelSTAR->symbolValue();
	int level;
	if ( object.nilp() )
	{
	    level = MOST_POSITIVE_FIXNUM;
	} else if ( af_fixnumP(object) )
	{
	    level = object.as<Fixnum_O>()->get();
	    if ( level < 0 )
	    {
	    ERROR:
		cl::_sym_STARprint_levelSTAR->setf_symbolValue(_Nil<T_O>());
		SIMPLE_ERROR(BF("The value of *PRINT-LEVEL*\n %s\n"
				"is not of the expected type (or NULL (INTEGER 0 *))")
			     % _rep_(object) );
	    }
	} else if ( af_bignumP(object) )
	{
	    goto ERROR;
	} else
	{
	    level = MOST_POSITIVE_FIXNUM;
	}
	return level;
    }

    int brcl_print_length(void)
    {
	T_sp object = cl::_sym_STARprint_lengthSTAR->symbolValue();
	int length;
	if ( object.nilp() )
	{
	    length = MOST_POSITIVE_FIXNUM;
	} else if ( af_fixnumP(object) )
	{
	    length = object.as<Fixnum_O>()->get();
	    if ( length < 0 )
	    {
	    ERROR:
		cl::_sym_STARprint_lengthSTAR->setf_symbolValue(_Nil<T_O>());
		SIMPLE_ERROR(BF("The value of *PRINT-LENGTH*\n %s\n"
				"is not of the expected type (or NULL (INTEGER 0 *))")
			     % _rep_(object) );
	    }
	} else if ( af_bignumP(object) )
	{
	    goto ERROR;
	} else
	{
	    length = MOST_POSITIVE_FIXNUM;
	}
	return length;
    }

    bool brcl_print_radix(void)
    {
	return cl::_sym_STARprint_radixSTAR->symbolValue().isTrue();
    }

    Symbol_sp brcl_print_case(void)
    {
	T_sp output = cl::_sym_STARprint_caseSTAR->symbolValue();
	if ( Symbol_sp soutput = output.asOrNull<Symbol_O>() )
	{
	    if ( soutput == kw::_sym_upcase ||
		 soutput == kw::_sym_downcase ||
		 soutput == kw::_sym_capitalize )
	    {
		return soutput;
	    }
	}
	SIMPLE_ERROR(BF("The value of *PRINT-CASE*\n %S\n"
			"is not of the expected type"
			"(MEMBER :UPCASE :DOWNCASE :CAPITALIZE)")
		     % _rep_(output) );
    }

    bool brcl_print_gensym(void)
    {
	return cl::_sym_STARprint_gensymSTAR->symbolValue().isTrue();
    }

    bool brcl_print_array(void)
    {
	return cl::_sym_STARprint_arraySTAR->symbolValue().isTrue();
    }

    bool brcl_print_readably(void)
    {
	return cl::_sym_STARprint_readablySTAR->symbolValue().isTrue();
    }

    bool brcl_print_escape(void)
    {
	return cl::_sym_STARprint_escapeSTAR->symbolValue().isTrue();
    }

    bool brcl_print_circle(void)
    {
	return cl::_sym_STARprint_circleSTAR->symbolValue().isTrue();
    }






#define ARGS_af_write "(x &key ((:stream strm) nil) (array *print-array*) (base *print-base*) ((:case cas) *print-case*) (escape *print-escape*) (gensym *print-gensym*) (length *print-length*) (level *print-level*) (lines *print-lines*) (miser_width *print-miser-width*) (pprint_dispatch *print-pprint-dispatch*) (pretty *print-pretty*) (radix *print-radix*) (readably *print-readably*) (right_margin *print-right-margin*))"
#define DECL_af_write ""
#define DOCS_af_write "write"
    T_sp af_write(T_sp x, T_sp strm, T_sp array, T_sp base,
		  T_sp cas, T_sp escape, T_sp gensym, T_sp length,
		  T_sp level, T_sp lines, T_sp miser_width, T_sp pprint_dispatch,
		  T_sp pretty, T_sp radix, T_sp readability, T_sp right_margin )
    {_G();
        DynamicScopeManager scope(cl::_sym_STARprint_arraySTAR,array);
        scope.pushSpecialVariableAndSet(cl::_sym_STARprint_baseSTAR,base);
        scope.pushSpecialVariableAndSet(cl::_sym_STARprint_caseSTAR,cas);
        scope.pushSpecialVariableAndSet(cl::_sym_STARprint_escapeSTAR,escape);
        scope.pushSpecialVariableAndSet(cl::_sym_STARprint_gensymSTAR,gensym);
        scope.pushSpecialVariableAndSet(cl::_sym_STARprint_lengthSTAR,length);
        scope.pushSpecialVariableAndSet(cl::_sym_STARprint_levelSTAR,level);
        scope.pushSpecialVariableAndSet(cl::_sym_STARprint_linesSTAR,lines);
        scope.pushSpecialVariableAndSet(cl::_sym_STARprint_miser_widthSTAR,miser_width);
        scope.pushSpecialVariableAndSet(cl::_sym_STARprint_pprint_dispatchSTAR,pprint_dispatch);
        scope.pushSpecialVariableAndSet(cl::_sym_STARprint_prettySTAR,pretty);
        scope.pushSpecialVariableAndSet(cl::_sym_STARprint_radixSTAR,radix);
        scope.pushSpecialVariableAndSet(cl::_sym_STARprint_readablySTAR,readability);
        scope.pushSpecialVariableAndSet(cl::_sym_STARprint_right_marginSTAR,right_margin);
        T_sp ostrm = coerce::outputStreamDesignator(strm);
        write_object(x,ostrm);
        clasp_forceOutput(ostrm);
        return Values(x);
    };




    
#if 0    
#define ARGS_af_writeAddr "(arg stream)"
#define DECL_af_writeAddr ""
#define DOCS_af_writeAddr "writeAddr"
    void af_writeAddr(T_sp arg, Stream_sp stream)
    {_G();
	cl_intptr_t i = arg.intptr();
	for ( int j=sizeof(i)*8-4; j>= 0; j-=4 ) {
	    int k = (i>>j) &0xf;
	    if ( k < 10 ) stream->writeChar('0'+k);
	    else stream->writeChar('a'+k-10);
	}
    }
#endif
    
    
#define ARGS_af_printUnreadableObjectFunction "(o stream type id function)"
#define DECL_af_printUnreadableObjectFunction ""
#define DOCS_af_printUnreadableObjectFunction "printUnreadableObjectFunction - see ecl::print_unreadable.d"
    void af_printUnreadableObjectFunction(T_sp o, T_sp ostream, T_sp type, T_sp id, T_sp function)
    {_G();
	T_sp stream = coerce::outputStreamDesignator(ostream);
	if ( brcl_print_readably() ) {
	    PRINT_NOT_READABLE_ERROR(o);
	} else {
            stringstream ss;
            ss << "#<";
            if (type.notnilp()) {
                type = af_type_of(o);
                if ( !type.isA<Symbol_O>() )
                {
                    type = cl::_sym_StandardObject_O;
                }
                Symbol_sp typesym = type.as<Symbol_O>();
                ss << typesym->symbolNameAsString();
                ss << " ";
            }
            if ( function.notnilp() )
            {
                eval::funcall(function);
            }
            ss << o.px_ref();
            ss << ">";
            Str_sp str = Str_O::create(ss.str());
            clasp_writeString(str,stream);
        }
    };






    void initialize_print()
    {
        Defun(write);
//        SYMBOL_EXPORT_SC_(CorePkg,writeAddr);
//        Defun(writeAddr);
        SYMBOL_EXPORT_SC_(CorePkg,printUnreadableObjectFunction);
        Defun(printUnreadableObjectFunction);
    }


};
