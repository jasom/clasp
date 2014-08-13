#define	DEBUG_LEVEL_FULL

#include "foundation.h"
#include "serialize.h"
#include "sexpSaveArchive.h"
#include "hashTable.h"
#include "arguments.h"
#include "symbolTable.h"
#include "write_ugly.h"
#include "designators.h"
#include "str.h"
#include "lispStream.h"
#include "numbers.h"
#include "symbol.h"
#include "wrappers.h"


namespace core 
{


/*
  __BEGIN_DOC( candoScript.general.saveArchive, subsection, saveArchive)
  \scriptCmd{save}{Object::object Text::fileName}

  Save the \sa{object} to the \sa{fileName} in Cando-Archive format.
  __END_DOC
*/
    const char* keywords_saveArchive[] = {":debug",""};





    EXPOSE_CLASS(core,SexpSaveArchive_O);

    void SexpSaveArchive_O::exposeCando(Lisp_sp lisp)
    {_G();
	class_<SexpSaveArchive_O>("make-sexp-save-archive")
	    .def("sexpSaveArchiveWrite",&SexpSaveArchive_O::sexpSaveArchiveWrite)
	    ;	
    }
    void SexpSaveArchive_O::exposePython(Lisp_sp lisp)
    {_G();
    }


    void SexpSaveArchive_O::write(SNode_sp snode, HashTable_sp snodeToRef, T_sp stream )
    {_G();
	if ( snode->refCount() > 1 ) {
	    Fixnum_sp ref = snodeToRef->gethash(snode,_Nil<T_O>()).as<Fixnum_O>();
	    if ( ref.notnilp() ) {
                clasp_write_char('#',stream);
		ref->__write__(stream);
                clasp_write_char('#',stream);
		return;
	    } else {
		ref = Fixnum_O::create(snodeToRef->hashTableCount()+1);
		snodeToRef->hash_table_setf_gethash(snode,ref);
		clasp_write_char('#',stream);
		ref->__write__(stream);
		clasp_write_char('=',stream);
	    }
	}
	if ( snode->leafSNodeP() ) {
	    T_sp obj = snode->object();
	    write_ugly_object(obj,stream);
	    clasp_write_char(' ',stream);
	} else {
	    BranchSNode_sp bsnode = snode.as<BranchSNode_O>();
	    clasp_write_char('\n',stream);
	    clasp_write_char('(',stream);
	    write_ugly_object(bsnode->_Kind,stream);
	    clasp_write_string(" (",stream);
	    for ( Cons_sp cur=bsnode->_SNodePList; cur.notnilp(); cur=cCddr(cur) )
	    {
		write_ugly_object(oCar(cur),stream);
		clasp_write_char(' ',stream);
		SNode_sp property = oCadr(cur).as<SNode_O>();
		this->write(property,snodeToRef,stream);
		clasp_write_char(' ',stream);
	    }
	    clasp_write_string(") ",stream);
	    if ( bsnode->_VectorSNodes.notnilp() && bsnode->_VectorSNodes->length()>0) {
		clasp_write_string(" #",stream);
		write_ugly_object(Fixnum_O::create(bsnode->_VectorSNodes->length()),stream);
		clasp_write_string("( ",stream);
		for ( int i(0), iEnd(bsnode->_VectorSNodes->length()); i<iEnd; ++i ) {
		    SNode_sp snode = bsnode->_VectorSNodes->elt(i).as<SNode_O>();
		    this->write(snode,snodeToRef,stream);
		    clasp_write_char(' ',stream);
		}
		clasp_write_char(')',stream);
	    }
        clasp_write_char(')',stream);
	}
    }

    void SexpSaveArchive_O::sexpSaveArchiveWrite(T_sp streamDesignator )
    {
	DynamicScopeManager scope(_sym_STARserializerArchiveSTAR,this->asSmartPtr());
	Stream_sp stream = coerce::outputStreamDesignator(streamDesignator);
	HashTable_sp sNodeToRef = HashTable_O::create(cl::_sym_eq);
	scope.pushSpecialVariableAndSet(cl::_sym_STARprint_readablySTAR,_lisp->_true());
	scope.pushSpecialVariableAndSet(cl::_sym_STARprint_escapeSTAR,_lisp->_true());
	this->write(this->_TopNode,sNodeToRef,stream);
    };





    
    

};
