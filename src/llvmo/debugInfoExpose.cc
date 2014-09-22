#define DEBUG_LEVEL_FULL

//#include <llvm/Support/system_error.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include "llvm/Support/raw_ostream.h"
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/InlineAsm.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/MathExtras.h>
#include <llvm/Pass.h>
#include <llvm/PassManager.h>
#include <llvm/ADT/SmallVector.h>
#include <llvm/IR/Verifier.h>
#include "llvm/IR/AssemblyAnnotationWriter.h" // Should be llvm/IR was
//#include <llvm/IR/PrintModulePass.h> // will be llvm/IR

#include "core/common.h"
#include "core/cons.h"
#include "core/evaluator.h"
#include "core/symbolTable.h"
#include "core/package.h"
#include "core/stringList.h"
#include "core/environment.h"
#include "core/builtInClass.h"
#include "core/lambdaListHandler.h"
#include "core/multipleValues.h"
#include "core/environment.h"
#include "core/loadTimeValues.h"
#include "core/bignum.h"
#include "core/pointer.h"
#include "core/str.h"
#include "core/translators.h"
#include "core/vectorObjectsWithFillPtr.h"
#include "debugInfoExpose.h"
#include "insertPoint.h"
#include "debugLoc.h"
#include "llvmo/llvmoExpose.h"
#include "core/external_wrappers.h"
#include "core/wrappers.h"



namespace llvmo
{
    EXPOSE_CLASS(llvmo,DebugInfo_O);

    void DebugInfo_O::exposeCando(core::Lisp_sp lisp)
    {_G();
	core::class_<DebugInfo_O>()
	    ;
    };

    void DebugInfo_O::exposePython(core::Lisp_sp lisp)
    {_G();
	IMPLEMENT_ME();
    };
}; // llvmo


namespace llvmo
{
    EXPOSE_CLASS(llvmo,DIDescriptor_O);

    void DIDescriptor_O::exposeCando(core::Lisp_sp lisp)
    {_G();
	core::class_<DIDescriptor_O>()
	    ;
    };

    void DIDescriptor_O::exposePython(core::Lisp_sp lisp)
    {_G();
	IMPLEMENT_ME();
    };
}; // llvmo


namespace llvmo
{
    EXPOSE_CLASS(llvmo,DIScope_O);

    void DIScope_O::exposeCando(core::Lisp_sp lisp)
    {_G();
	core::class_<DIScope_O>()
	    ;
    };

    void DIScope_O::exposePython(core::Lisp_sp lisp)
    {_G();
	IMPLEMENT_ME();
    };
}; // llvmo





namespace llvmo
{
    EXPOSE_CLASS(llvmo,DIFile_O);

    void DIFile_O::exposeCando(core::Lisp_sp lisp)
    {_G();
	core::class_<DIFile_O>()
	    ;
    };

    void DIFile_O::exposePython(core::Lisp_sp lisp)
    {_G();
	IMPLEMENT_ME();
    };
}; // llvmo









namespace llvmo
{
    EXPOSE_CLASS(llvmo,DISubprogram_O);

    void DISubprogram_O::exposeCando(core::Lisp_sp lisp)
    {_G();
	core::class_<DISubprogram_O>()
	    ;
    };

    void DISubprogram_O::exposePython(core::Lisp_sp lisp)
    {_G();
	IMPLEMENT_ME();
    };
}; // llvmo







namespace llvmo
{
    EXPOSE_CLASS(llvmo,DIType_O);

    void DIType_O::exposeCando(core::Lisp_sp lisp)
    {_G();
	core::class_<DIType_O>()
	    ;
    };

    void DIType_O::exposePython(core::Lisp_sp lisp)
    {_G();
	IMPLEMENT_ME();
    };
}; // llvmo




namespace llvmo
{
    EXPOSE_CLASS(llvmo,DIBasicType_O);

    void DIBasicType_O::exposeCando(core::Lisp_sp lisp)
    {_G();
	core::class_<DIBasicType_O>()
	    ;
    };

    void DIBasicType_O::exposePython(core::Lisp_sp lisp)
    {_G();
	IMPLEMENT_ME();
    };
}; // llvmo




namespace llvmo
{
    EXPOSE_CLASS(llvmo,DIDerivedType_O);

    void DIDerivedType_O::exposeCando(core::Lisp_sp lisp)
    {_G();
	core::class_<DIDerivedType_O>()
	    ;
    };

    void DIDerivedType_O::exposePython(core::Lisp_sp lisp)
    {_G();
	IMPLEMENT_ME();
    };
}; // llvmo



namespace llvmo
{
    EXPOSE_CLASS(llvmo,DICompositeType_O);

    void DICompositeType_O::exposeCando(core::Lisp_sp lisp)
    {_G();
	core::class_<DICompositeType_O>()
	    ;
    };

    void DICompositeType_O::exposePython(core::Lisp_sp lisp)
    {_G();
	IMPLEMENT_ME();
    };
}; // llvmo



namespace llvmo
{
    EXPOSE_CLASS(llvmo,DISubroutineType_O);

    void DISubroutineType_O::exposeCando(core::Lisp_sp lisp)
    {_G();
	core::class_<DISubroutineType_O>()
	    ;
    };

    void DISubroutineType_O::exposePython(core::Lisp_sp lisp)
    {_G();
	IMPLEMENT_ME();
    };
}; // llvmo




namespace llvmo
{
    EXPOSE_CLASS(llvmo,DIArray_O);

    void DIArray_O::exposeCando(core::Lisp_sp lisp)
    {_G();
	core::class_<DIArray_O>()
	    ;
    };

    void DIArray_O::exposePython(core::Lisp_sp lisp)
    {_G();
	IMPLEMENT_ME();
    };
}; // llvmo



namespace llvmo
{
    EXPOSE_CLASS(llvmo,DITypeArray_O);

    void DITypeArray_O::exposeCando(core::Lisp_sp lisp)
    {_G();
	core::class_<DITypeArray_O>()
	    ;
    };

    void DITypeArray_O::exposePython(core::Lisp_sp lisp)
    {_G();
	IMPLEMENT_ME();
    };
}; // llvmo





namespace llvmo
{
    EXPOSE_CLASS(llvmo,DILexicalBlock_O);

    void DILexicalBlock_O::exposeCando(core::Lisp_sp lisp)
    {_G();
	core::class_<DILexicalBlock_O>()
	    ;
    };

    void DILexicalBlock_O::exposePython(core::Lisp_sp lisp)
    {_G();
	IMPLEMENT_ME();
    };
}; // llvmo






namespace llvmo
{
    EXPOSE_CLASS(llvmo,DICompileUnit_O);

    void DICompileUnit_O::exposeCando(core::Lisp_sp lisp)
    {_G();
	core::class_<DICompileUnit_O>()
	    ;
    };

    void DICompileUnit_O::exposePython(core::Lisp_sp lisp)
    {_G();
	IMPLEMENT_ME();
    };
}; // llvmo







































namespace llvmo
{



#define ARGS_DIBuilder_O_make "(module)"
#define DECL_DIBuilder_O_make ""
#define DOCS_DIBuilder_O_make "make DIBuilder args: module"
    DIBuilder_sp DIBuilder_O::make(Module_sp module)
    {_G();
	GC_ALLOCATE(DIBuilder_O,me );
	me->set_wrapped(new llvm::DIBuilder(*(module->wrappedPtr())));
	return me;
    };

    EXPOSE_CLASS(llvmo,DIBuilder_O);

    void DIBuilder_O::exposeCando(core::Lisp_sp lisp)
    {_G();
	using namespace llvm;
	DISubprogram (DIBuilder::*createFunction_ptr)(DIDescriptor, // Scope
                                                      StringRef , // Name
                                                      StringRef , // LinkageName
                                                      DIFile ,      // File
                                                      unsigned ,    // lineno
                                                      DICompositeType,  // Ty
                                                      bool,
                                                      bool,
                                                      unsigned,
                                                      unsigned,
                                                      bool,
                                                      Function*,
                                                      MDNode*,
                                                      MDNode*) = &llvm::DIBuilder::createFunction;
	core::externalClass_<DIBuilder_O>()
	    .def("createCompileUnit",&llvm::DIBuilder::createCompileUnit)
	    .def("createFile",&llvm::DIBuilder::createFile)
	    .def("createFunction",createFunction_ptr)
	    .def("createLexicalBlock",&llvm::DIBuilder::createLexicalBlock)
	    .def("createBasicType",&llvm::DIBuilder::createBasicType)
	    .def("createNullPtrType",&llvm::DIBuilder::createNullPtrType)
	    .def("getOrCreateArray",&DIBuilder_O::getOrCreateArray)
	    .def("getOrCreateTypeArray",&DIBuilder_O::getOrCreateTypeArray)
	    .def("createUnspecifiedParameter",&llvm::DIBuilder::createUnspecifiedParameter)
	    .def("createSubroutineType",&llvm::DIBuilder::createSubroutineType)
	    .def("finalize",&llvm::DIBuilder::finalize)
	    ;
	core::af_def(LlvmoPkg,"make-dibuilder",&DIBuilder_O::make,ARGS_DIBuilder_O_make,DECL_DIBuilder_O_make,DOCS_DIBuilder_O_make);	
    };

    void DIBuilder_O::exposePython(core::Lisp_sp lisp)
    {_G();
	IMPLEMENT_ME();
    };



    DIArray_sp DIBuilder_O::getOrCreateArray(core::Cons_sp elements)
    {_G();
//		printf("%s:%d About to convert Cons into ArrayRef<llvm::Value*>\n", __FILE__, __LINE__);
//		printf("     cons --> %s\n", cur->__repr__().c_str() );
	vector<llvm::Value*> vector_values;
	for ( core::Cons_sp cur = elements; cur.notnilp(); cur=cCdr(cur) )
	{
	    if ( Value_sp val = oCar(cur).asOrNull<Value_O>() )
	    {
//			printf("      push_back val->wrappedPtr() --> %p\n", val->wrappedPtr());
		vector_values.push_back(val->wrappedPtr());
	    } else if ( DebugInfo_sp di = oCar(cur).asOrNull<DebugInfo_O>() )
	    {
//			printf("      getting DIDescriptor*\n");
		llvm::DIDescriptor* didescriptor = di->operator llvm::DIDescriptor*();
//			printf("      convert DIDescrptor* to MDNode* --> %p\n", didescriptor );
		llvm::MDNode* mdnode_didescriptor = *didescriptor;
//			printf("      push_back mdnode_didescriptor --> %p\n", mdnode_didescriptor );
		vector_values.push_back(mdnode_didescriptor);
	    } else
	    {
		SIMPLE_ERROR(BF("Handle conversion of %s to llvm::Value*") % _rep_(oCar(cur)) );
	    }
	}
	llvm::ArrayRef<llvm::Value*> array(vector_values);
	llvm::DIArray diarray = this->wrappedPtr()->getOrCreateArray(array);
        GC_ALLOCATE_VARIADIC(llvmo::DIArray_O,obj,diarray);
	return obj;
    }



    DITypeArray_sp DIBuilder_O::getOrCreateTypeArray(core::Cons_sp elements)
    {_G();
//		printf("%s:%d About to convert Cons into ArrayRef<llvm::Value*>\n", __FILE__, __LINE__);
//		printf("     cons --> %s\n", cur->__repr__().c_str() );
	vector<llvm::Value*> vector_values;
	for ( core::Cons_sp cur = elements; cur.notnilp(); cur=cCdr(cur) )
	{
	    if ( Value_sp val = oCar(cur).asOrNull<Value_O>() )
	    {
//			printf("      push_back val->wrappedPtr() --> %p\n", val->wrappedPtr());
		vector_values.push_back(val->wrappedPtr());
	    } else if ( DebugInfo_sp di = oCar(cur).asOrNull<DebugInfo_O>() )
	    {
//			printf("      getting DIDescriptor*\n");
		llvm::DIDescriptor* didescriptor = di->operator llvm::DIDescriptor*();
//			printf("      convert DIDescrptor* to MDNode* --> %p\n", didescriptor );
		llvm::MDNode* mdnode_didescriptor = *didescriptor;
//			printf("      push_back mdnode_didescriptor --> %p\n", mdnode_didescriptor );
		vector_values.push_back(mdnode_didescriptor);
	    } else
	    {
		SIMPLE_ERROR(BF("Handle conversion of %s to llvm::Value*") % _rep_(oCar(cur)) );
	    }
	}
	llvm::ArrayRef<llvm::Value*> array(vector_values);
	llvm::DITypeArray diarray = this->wrappedPtr()->getOrCreateTypeArray(array);
        GC_ALLOCATE_VARIADIC(llvmo::DITypeArray_O,obj,diarray);
	return obj;
    }

    
}; // llvmo

