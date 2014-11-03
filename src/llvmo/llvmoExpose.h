/*
    File: llvmoExpose.h
*/

/*
Copyright (c) 2014, Christian E. Schafmeister

CLASP is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

See directory 'clasp/licenses' for full details.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
/* -^- */
#ifndef	llvmoExpose_H //[
#define llvmoExpose_H

#include "core/common.h"
#include "core/symbolToEnumConverter.h"
#include "core/hashTableEqual.h"
#include "core/str.h"
#include "core/ql.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Linker/Linker.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Target/TargetSubtargetInfo.h"
//#include "llvm/ExecutionEngine/JIT.h"
#include "llvm/ExecutionEngine/MCJIT.h"
//#include "llvm/ExecutionEngine/JITMemoryManager.h"
#include "llvm/ExecutionEngine/SectionMemoryManager.h"
#include "llvm/ExecutionEngine/Interpreter.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Analysis/Passes.h"
#include "llvm/PassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include <llvm/ADT/Triple.h>
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetLibraryInfo.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include <llvm/IR/Constants.h>
//#include "llvm/Support/IRBuilder.h"

#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include "core/foundation.h"
#include "core/object.h"
#include "core/metaClass.fwd.h"
#include "core/externalObject.h"
#include "core/lispVector.h"
#include "llvmoExpose.fwd.h"
#include "llvmo/symbolTable.h"
#include "core/loadTimeValues.fwd.h"
#include "core/vectorObjectsWithFillPtr.fwd.h"
#include "translators.h"
#include "insertPoint.fwd.h"
#include "debugLoc.fwd.h"
#include "llvmo/llvmoPackage.h"




namespace llvmo
{
    FORWARD(LLVMContext);
    class LLVMContext_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::LLVMContext,LLVMContext_O,"llvm-context",core::ExternalObject_O);
	typedef llvm::LLVMContext ExternalType;
	typedef llvm::LLVMContext* PointerToExternalType;

    protected:
	PointerToExternalType _ptr;
    public:
	virtual void* externalObject() const
	{
	    return this->_ptr;
	};
	PointerToExternalType wrappedPtr() const
	{
	    return this->_ptr;
	}

    public:
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	static LLVMContext_sp get_global_context();
	;
	LLVMContext_O() : Base(), _ptr(NULL)  {};
	~LLVMContext_O() {if (_ptr != NULL ) {/* delete _ptr;*/ _ptr = NULL;};}

    }; // LLVMContext_O
}; // llvmo
TRANSLATE(llvmo::LLVMContext_O);

namespace translate
{
    template <>
    struct from_object<llvm::LLVMContext&,std::true_type>
    {
        typedef llvm::LLVMContext& DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v(*(object.as<llvmo::LLVMContext_O>()->wrappedPtr())) {};
    };
};
;
/* to_object translators */




namespace llvmo
{
    FORWARD(Linker);
    class Linker_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::Linker,Linker_O,"Linker",core::ExternalObject_O);
	typedef llvm::Linker ExternalType;
	typedef llvm::Linker* PointerToExternalType;

    protected:
	PointerToExternalType _ptr;
    public:
        static Linker_sp make(Module_sp module);
    public:
	virtual void* externalObject() const
	{
	    return this->_ptr;
	};
	PointerToExternalType wrappedPtr() const
	{
	    return this->_ptr;
	}

    public:
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	Linker_O() : Base(), _ptr(NULL)  {};
	~Linker_O() {if (_ptr != NULL ) {/* delete _ptr;*/ _ptr = NULL;};}

    }; // Linker_O
}; // llvmo
TRANSLATE(llvmo::Linker_O);

namespace translate
{
    template <>
    struct from_object<llvm::Linker&,std::true_type>
    {
        typedef llvm::Linker& DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v(*(object.as<llvmo::Linker_O>()->wrappedPtr())) {};
    };
};
;
/* to_object translators */


namespace llvmo
{
    FORWARD(Pass);
    class Pass_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::Pass,Pass_O,"Pass",core::ExternalObject_O);
	typedef llvm::Pass ExternalType;
	typedef llvm::Pass* PointerToExternalType;

    protected:
	PointerToExternalType _ptr;
    public:
	virtual void* externalObject() const
	{
	    return this->_ptr;
	};
	PointerToExternalType wrappedPtr() const
	{
	    return this->_ptr;
	}

    public:
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	Pass_O() : Base(), _ptr(NULL)  {};
	~Pass_O() {if (_ptr != NULL ) {/* delete _ptr;*/ _ptr = NULL;};}

    }; // Pass_O
}; // llvmo
TRANSLATE(llvmo::Pass_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::Pass*,std::true_type>
    {
        typedef llvm::Pass* DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::Pass_O>()->wrappedPtr()) {};
    };
};

/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::Pass*>
    {
        static core::T_sp convert(llvm::Pass* ptr)
        {_G(); return((core::RP_Create_wrapped<llvmo::Pass_O,llvm::Pass*>(ptr)));}
    };
};
;





namespace llvmo
{
    FORWARD(Triple);
    class Triple_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::Triple,Triple_O,"Triple",core::ExternalObject_O);
	typedef llvm::Triple ExternalType;
	typedef llvm::Triple* PointerToExternalType;

    protected:
	PointerToExternalType _ptr;
    public:
	static Triple_sp make(const string& triple);
    public:
	virtual void* externalObject() const
	{
	    return this->_ptr;
	};
	PointerToExternalType wrappedPtr() const
	{
	    return this->_ptr;
	}

    public:
	void set_wrapped(PointerToExternalType ptr)
	{
	  if (this->_ptr != NULL ) delete this->_ptr;
	  this->_ptr = ptr;
	}
	Triple_O() : Base(), _ptr(NULL)  {};
	~Triple_O() {if (_ptr != NULL ) { delete _ptr; _ptr = NULL;};}

    }; // Triple_O
}; // llvmo
TRANSLATE(llvmo::Triple_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::Triple*,std::true_type>
    {
        typedef llvm::Triple* DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v( object.nilp() ? NULL : object.as<llvmo::Triple_O>()->wrappedPtr()) {};
    };

    template <>
    struct from_object<llvm::Triple&,std::true_type>
    {
        typedef llvm::Triple& DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v( *object.as<llvmo::Triple_O>()->wrappedPtr()) {};
    };
};

/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::Triple*>
    {
        static core::T_sp convert(llvm::Triple* ptr)
        {_G(); return((core::RP_Create_wrapped<llvmo::Triple_O,llvm::Triple*>(ptr)));}
    };
};
;




namespace llvmo
{
    FORWARD(TargetOptions);
    class TargetOptions_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::TargetOptions,TargetOptions_O,"TargetOptions",core::ExternalObject_O);
	typedef llvm::TargetOptions ExternalType;
	typedef llvm::TargetOptions* PointerToExternalType;

    protected:
	PointerToExternalType _ptr;
    public:
	static TargetOptions_sp make();
    public:
	virtual void* externalObject() const
	{
	    return this->_ptr;
	};
	PointerToExternalType wrappedPtr() const
	{
	    return this->_ptr;
	}

    public:
	void set_wrapped(PointerToExternalType ptr)
	{
	    if (this->_ptr != NULL ) delete this->_ptr;
	    this->_ptr = ptr;
	}
    public:
	bool JITEmitDebugInfo();
	void setfJITEmitDebugInfo(bool val);
	bool JITEmitDebugInfoToDisk();
	void setfJITEmitDebugInfoToDisk(bool val);
    public:
	TargetOptions_O() : Base(), _ptr(NULL)  {};
	~TargetOptions_O() {if (_ptr != NULL ) { delete _ptr; _ptr = NULL;};}

    }; // TargetOptions_O
}; // llvmo
TRANSLATE(llvmo::TargetOptions_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::TargetOptions*,std::true_type>
    {
        typedef llvm::TargetOptions* DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v( object.nilp() ? NULL : object.as<llvmo::TargetOptions_O>()->wrappedPtr()) {};
    };
    template <>
    struct from_object<const llvm::TargetOptions&,std::true_type>
    {
        typedef const llvm::TargetOptions& DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v(*object.as<llvmo::TargetOptions_O>()->wrappedPtr()) {};
    };
};

/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::TargetOptions*>
    {
        static core::T_sp convert(llvm::TargetOptions* ptr)
        {_G(); return((core::RP_Create_wrapped<llvmo::TargetOptions_O,llvm::TargetOptions*>(ptr)));}
    };
};
;


namespace llvmo
{
    FORWARD(Target);
    class Target_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::Target,Target_O,"Target",core::ExternalObject_O);
	typedef llvm::Target ExternalType;
	typedef llvm::Target* PointerToExternalType;

    protected:
	PointerToExternalType _ptr;
    public:
	virtual void* externalObject() const
	{
	    return this->_ptr;
	};
	PointerToExternalType wrappedPtr() const
	{
	    return this->_ptr;
	}

    public:
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	Target_O() : Base(), _ptr(NULL)  {};
	~Target_O() {if (_ptr != NULL ) {/* delete _ptr;*/ _ptr = NULL;};}

    }; // Target_O
}; // llvmo
TRANSLATE(llvmo::Target_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::Target*,std::true_type>
    {
        typedef llvm::Target* DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v( object.nilp() ? NULL : object.as<llvmo::Target_O>()->wrappedPtr()) {};
    };
};
/* to_object translators */
namespace translate
{
    template <>
    struct to_object<llvm::Target*,translate::dont_adopt_pointer>
    {
      static core::T_sp convert(llvm::Target* ptr)
        {_G(); return((core::RP_Create_wrapped<llvmo::Target_O,llvm::Target*>(ptr)));}
    };

    template <>
    struct to_object<const llvm::Target*>
    {
      static core::T_sp convert(const llvm::Target* ptr)
      {_G(); return((core::RP_Create_wrapped<llvmo::Target_O,llvm::Target*>(const_cast<llvm::Target*>(ptr))));}
    };
};
;








namespace llvmo
{
    FORWARD(MCSubtargetInfo);
    class MCSubtargetInfo_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::MCSubtargetInfo,MCSubtargetInfo_O,"MCSubtargetInfo",core::ExternalObject_O);
	typedef llvm::MCSubtargetInfo ExternalType;
	typedef llvm::MCSubtargetInfo* PointerToExternalType;

    protected:
	PointerToExternalType _ptr;
    public:
	virtual void* externalObject() const
	{
	    return this->_ptr;
	};
	PointerToExternalType wrappedPtr() const
	{
	    return this->_ptr;
	}

    public:
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	MCSubtargetInfo_O() : Base(), _ptr(NULL)  {};
	~MCSubtargetInfo_O() {if (_ptr != NULL ) {/* delete _ptr;*/ _ptr = NULL;};}

    }; // MCSubtargetInfo_O
}; // llvmo
TRANSLATE(llvmo::MCSubtargetInfo_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::MCSubtargetInfo*,std::true_type>
    {
        typedef llvm::MCSubtargetInfo* DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v( object.nilp() ? NULL : object.as<llvmo::MCSubtargetInfo_O>()->wrappedPtr()) {};
    };
};
/* to_object translators */
namespace translate
{
    template <>
    struct to_object<llvm::MCSubtargetInfo*,translate::dont_adopt_pointer>
    {
      static core::T_sp convert(llvm::MCSubtargetInfo* ptr)
        {_G(); return((core::RP_Create_wrapped<llvmo::MCSubtargetInfo_O,llvm::MCSubtargetInfo*>(ptr)));}
    };

    template <>
    struct to_object<const llvm::MCSubtargetInfo*>
    {
      static core::T_sp convert(const llvm::MCSubtargetInfo* ptr)
      {_G(); return((core::RP_Create_wrapped<llvmo::MCSubtargetInfo_O,llvm::MCSubtargetInfo*>(const_cast<llvm::MCSubtargetInfo*>(ptr))));}
    };
};
;





namespace llvmo
{
    class TargetSubtargetInfo_O : public MCSubtargetInfo_O
    {
        LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::TargetSubtargetInfo,TargetSubtargetInfo_O,"TargetSubtargetInfo",MCSubtargetInfo_O);
        typedef llvm::TargetSubtargetInfo ExternalType;
        typedef llvm::TargetSubtargetInfo* PointerToExternalType;

    public:    PointerToExternalType wrappedPtr() const { return static_cast<PointerToExternalType>(this->_ptr);};
        void set_wrapped(PointerToExternalType ptr)
        {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
            this->_ptr = ptr;
        }

        TargetSubtargetInfo_O() : Base() {};
        ~TargetSubtargetInfo_O() {}

    }; // TargetSubtargetInfo_O
}; // llvmo
TRANSLATE(llvmo::TargetSubtargetInfo_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::TargetSubtargetInfo*,std::true_type>
    {
        typedef llvm::TargetSubtargetInfo* DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::TargetSubtargetInfo_O>()->wrappedPtr()) {};
    };
    template <>
    struct to_object<const llvm::TargetSubtargetInfo*>
    {
        static core::T_sp convert(const llvm::TargetSubtargetInfo* ptr)
        {_G(); return((core::RP_Create_wrapped<llvmo::TargetSubtargetInfo_O,llvm::TargetSubtargetInfo*>(const_cast<llvm::TargetSubtargetInfo*>(ptr))));}
    };
};










namespace llvmo
{
    FORWARD(TargetMachine);
    class TargetMachine_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::TargetMachine,TargetMachine_O,"TargetMachine",core::ExternalObject_O);
	typedef llvm::TargetMachine ExternalType;
	typedef llvm::TargetMachine* PointerToExternalType;
    protected:
	PointerToExternalType _ptr;
    public:
	virtual void* externalObject() const
	{
	    return this->_ptr;
	};
	PointerToExternalType wrappedPtr() const
	{
	    return this->_ptr;
	}
    public:
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	TargetMachine_O() : Base(), _ptr(NULL)  {};
	~TargetMachine_O() {if (_ptr != NULL ) {/* delete _ptr;*/ _ptr = NULL;};}
    }; // TargetMachine_O
}; // llvmo
TRANSLATE(llvmo::TargetMachine_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::TargetMachine*,std::true_type>
    {
        typedef llvm::TargetMachine* DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v( object.nilp() ? NULL : object.as<llvmo::TargetMachine_O>()->wrappedPtr()) {};
    };
};

/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::TargetMachine*>
    {
        static core::T_sp convert(llvm::TargetMachine* ptr)
        {_G(); return((core::RP_Create_wrapped<llvmo::TargetMachine_O,llvm::TargetMachine*>(ptr)));}
    };
};
;















namespace llvmo
{
    FORWARD(PassManagerBase);
    FORWARD(LLVMTargetMachine);
    class LLVMTargetMachine_O : public TargetMachine_O
    {
        LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::LLVMTargetMachine,LLVMTargetMachine_O,"LLVMTargetMachine",TargetMachine_O);
        typedef llvm::LLVMTargetMachine ExternalType;
        typedef llvm::LLVMTargetMachine* PointerToExternalType;

    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
        void set_wrapped(PointerToExternalType ptr)
        {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
            this->_ptr = ptr;
        }

//        static LLVMTargetMachine_sp makeLLVMTargetMachine(
        bool LLVMTargetMachine_addPassesToEmitFile( PassManagerBase_sp pm,
                                                    core::T_sp stream,
                                                    core::Symbol_sp fileType);
        LLVMTargetMachine_O() : Base() {};
        ~LLVMTargetMachine_O() {}

    }; // LLVMTargetMachine_O
}; // llvmo
TRANSLATE(llvmo::LLVMTargetMachine_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::LLVMTargetMachine*,std::true_type>
    {
        typedef llvm::LLVMTargetMachine* DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::LLVMTargetMachine_O>()->wrappedPtr()) {};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::LLVMTargetMachine*>
    {
        static core::T_sp convert(llvm::LLVMTargetMachine* ptr)
        {_G(); return((core::RP_Create_wrapped<llvmo::LLVMTargetMachine_O,llvm::LLVMTargetMachine*>(ptr)));}
    };
};
;














namespace llvmo
{
FORWARD(FunctionPass);
class FunctionPass_O : public Pass_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::FunctionPass,FunctionPass_O,"FunctionPass",Pass_O);
    typedef llvm::FunctionPass ExternalType;
    typedef llvm::FunctionPass* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
FunctionPass_O() : Base() {};
~FunctionPass_O() {}

 }; // FunctionPass_O
 }; // llvmo
TRANSLATE(llvmo::FunctionPass_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::FunctionPass*,std::true_type>
    {
        typedef llvm::FunctionPass* DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::FunctionPass_O>()->wrappedPtr()) {};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::FunctionPass*>
    {
        static core::T_sp convert(llvm::FunctionPass* ptr)
        {_G(); return((core::RP_Create_wrapped<llvmo::FunctionPass_O,llvm::FunctionPass*>(ptr)));}
    };
};
;


namespace llvmo
{
FORWARD(ModulePass);
class ModulePass_O : public Pass_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::ModulePass,ModulePass_O,"ModulePass",Pass_O);
    typedef llvm::ModulePass ExternalType;
    typedef llvm::ModulePass* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
ModulePass_O() : Base() {};
~ModulePass_O() {}

 }; // ModulePass_O
 }; // llvmo
TRANSLATE(llvmo::ModulePass_O);

namespace translate
{
    template <>
    struct from_object<llvm::ModulePass*,std::true_type>
    {
        typedef llvm::ModulePass* DeclareType;
	DeclareType _v;
        from_object(T_P object) : _v(object.as<llvmo::ModulePass_O>()->wrappedPtr()) {};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::ModulePass*>
    {
        static core::T_sp convert(llvm::ModulePass* ptr)
        {_G(); return((core::RP_Create_wrapped<llvmo::ModulePass_O,llvm::ModulePass*>(ptr)));}
    };
};
;


namespace llvmo
{
FORWARD(ImmutablePass);
/*! ImmutablePass_O doesn't own its pointer because ownership is given to the PassManager */
class ImmutablePass_O : public ModulePass_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::ImmutablePass,ImmutablePass_O,"ImmutablePass",ModulePass_O);
    typedef llvm::ImmutablePass ExternalType;
    typedef llvm::ImmutablePass* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
ImmutablePass_O() : Base() {};
~ImmutablePass_O() {}

 }; // ImmutablePass_O
 }; // llvmo
TRANSLATE(llvmo::ImmutablePass_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::ImmutablePass*,std::true_type>
    {
        typedef llvm::ImmutablePass* DeclareType;
	DeclareType _v;
        from_object(T_P object) : _v(object.as<llvmo::ImmutablePass_O>()->wrappedPtr()) {};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::ImmutablePass*>
    {
        static core::T_sp convert(llvm::ImmutablePass* ptr)
        {_G(); return((core::RP_Create_wrapped<llvmo::ImmutablePass_O,llvm::ImmutablePass*>(ptr)));}
    };
};
;


namespace llvmo
{
FORWARD(PassManagerBase);
class PassManagerBase_O : public core::ExternalObject_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::PassManagerBase,PassManagerBase_O,"PassManagerBase",core::ExternalObject_O);
    typedef llvm::PassManagerBase ExternalType;
    typedef llvm::PassManagerBase* PointerToExternalType;

protected:
    PointerToExternalType _ptr;
public:
    virtual void* externalObject() const
    {
        return this->_ptr;
    };
    PointerToExternalType wrappedPtr() const
    {
        return this->_ptr;
    }

public:
    void set_wrapped(PointerToExternalType ptr)
    {
        if (this->_ptr != NULL ) delete this->_ptr;
        this->_ptr = ptr;
    }
PassManagerBase_O() : Base(), _ptr(NULL)  {};
~PassManagerBase_O() {if (_ptr != NULL ) { delete _ptr; _ptr = NULL;};}

 }; // PassManagerBase_O
 }; // llvmo
TRANSLATE(llvmo::PassManagerBase_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::PassManagerBase*,std::true_type>
    {
        typedef llvm::PassManagerBase* DeclareType;
        DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::PassManagerBase_O>()->wrappedPtr()) {};
    };
    template <>
    struct from_object<llvm::PassManagerBase&,std::true_type>
    {
        typedef llvm::PassManagerBase& DeclareType;
        DeclareType _v;
	from_object(T_P object) : _v(*object.as<llvmo::PassManagerBase_O>()->wrappedPtr()) {};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::PassManagerBase*>
    {
        static core::T_sp convert(llvm::PassManagerBase* ptr)
        {_G(); return((core::RP_Create_wrapped<llvmo::PassManagerBase_O,llvm::PassManagerBase*>(ptr)));}
    };
};
;


namespace llvmo
{
    FORWARD(Value);
    class Value_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::Value,Value_O,"value",core::ExternalObject_O);
	typedef llvm::Value ExternalType;
	typedef llvm::Value* PointerToExternalType;

    protected:
	PointerToExternalType _ptr;
    public:
	virtual void* externalObject() const
	{
	    return this->_ptr;
	};
	PointerToExternalType wrappedPtr() const
	{
	    return this->_ptr;
	}

    public:
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	static Value_sp create(llvm::Value* ptr);
	;
	Value_O() : Base(), _ptr(NULL)  {};
	~Value_O() {if (_ptr != NULL ) {/* delete _ptr;*/ _ptr = NULL;};}
	bool llvm_sys_value_p() const { return true; };
	string __repr__() const;
	bool valid() const;
    }; // Value_O
}; // llvmo
TRANSLATE(llvmo::Value_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::Value*,std::true_type>
    {
        typedef llvm::Value* DeclareType;
        DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::Value_O>()->wrappedPtr()) {};
    };
    template <>
    struct from_object<llvm::ArrayRef<llvm::Value*> > {
        typedef std::vector<llvm::Value*> DeclareType;
        DeclareType _v;
        from_object(core::T_sp o) {
            if ( o.nilp() ) {
                _v.clear();
                return;
            } else if ( core::Cons_sp cvals = o.asOrNull<core::Cons_O>() ) {
                for ( ; cvals.notnilp(); cvals=cCdr(cvals) ) {
                    llvm::Value* vP = core::oCar(cvals).as<llvmo::Value_O>()->wrappedPtr();
                    _v.push_back(vP);
                }
                return;
            } else if ( core::Vector_sp vvals = o.asOrNull<core::Vector_O>() ) {
                _v.resize(vvals->length());
                for (int i(0),iEnd(vvals->length()); i<iEnd; ++i ) {
                    _v[i] = vvals->elt(i).as<llvmo::Value_O>()->wrappedPtr();
                }
                return;
            }
            SIMPLE_ERROR(BF("Could not convert %s to llvm::ArrayRef<llvm::Value*>") % core::_rep_(o));
        }
    };


};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::Value*>
    {
        static core::T_sp convert(llvm::Value* ptr)
        {_G(); return((llvmo::Value_O::create(ptr)));}
    };
};
;


namespace llvmo
{
FORWARD(User);
class User_O : public Value_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::User,User_O,"user",Value_O);
    typedef llvm::User ExternalType;
    typedef llvm::User* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
User_O() : Base() {};
~User_O() {}

 }; // User_O
 }; // llvmo
TRANSLATE(llvmo::User_O);
/* from_object translators */
/* to_object translators */









namespace llvmo
{
    class Attribute_O : public core::T_O
    {
	LISP_BASE1(core::T_O);
	LISP_CLASS(llvmo,LlvmoPkg,Attribute_O,"Attribute");
	DECLARE_INIT();
//    DECLARE_ARCHIVE();
    public: // Simple default ctor/dtor
	DEFAULT_CTOR_DTOR(Attribute_O);
    public: // ctor/dtor for classes with shared virtual base
//    explicit Attribute_O() : T_O(), T(mc) {};
//    virtual ~Attribute_O() {};
    public:

    private: // instance variables here
	llvm::Attribute		_Attribute;

    public: // Functions here
	static Attribute_sp get(LLVMContext_sp context,core::Cons_sp attribute_symbols);

	llvm::Attribute attributes() { return this->_Attribute;};
	void setAttribute(llvm::Attribute attr) { this->_Attribute = attr;};
    }; // Attribute class

}; // llvmo namespace
TRANSLATE(llvmo::Attribute_O);
namespace translate
{
    template <>
    struct from_object<llvm::Attribute,std::true_type>
    {
        typedef llvm::Attribute DeclareType;
        DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::Attribute_O>()->attributes()) {};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::Attribute>
    {
        static core::T_sp convert(llvm::Attribute attr)
        {_G();
	    GC_ALLOCATE(llvmo::Attribute_O,oattr );
	    oattr->setAttribute(attr);
	    return(( oattr));
	}
    };

};
;






namespace llvmo
{
    FORWARD(DataLayout);
    class DataLayout_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::DataLayout,DataLayout_O,"DataLayout",core::ExternalObject_O);
	typedef llvm::DataLayout ExternalType;
	typedef llvm::DataLayout* PointerToExternalType;

    protected:
        PointerToExternalType _ptr;
    public:
	PointerToExternalType wrappedPtr() { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	DataLayout_O() : Base() {};
	~DataLayout_O() {}


	DataLayout_sp copy() const;

    }; // DataLayout_O
}; // llvmo
TRANSLATE(llvmo::DataLayout_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::DataLayout*,std::true_type>
    {
        typedef llvm::DataLayout* DeclareType;
        DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::DataLayout_O>()->wrappedPtr()) {};
    };

    template <>
    struct from_object<const llvm::DataLayout*,std::true_type>
    {
        typedef llvm::DataLayout* DeclareType;
        DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::DataLayout_O>()->wrappedPtr()) {};
    };

    template <>
    struct from_object<llvm::DataLayout const&,std::true_type>
    {
        typedef llvm::DataLayout const& DeclareType;
        DeclareType _v;
	from_object(T_P object) : _v(*(object.as<llvmo::DataLayout_O>()->wrappedPtr())) {};
    };

    template <>
    struct to_object<const llvm::DataLayout*>
    {
        static core::T_sp convert(const llvm::DataLayout* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::DataLayout_O,llvm::DataLayout*>(const_cast<llvm::DataLayout*>(ptr))));}
    };

    template <>
    struct to_object<llvm::DataLayout*>
    {
        static core::T_sp convert(llvm::DataLayout* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::DataLayout_O,llvm::DataLayout*>(ptr)));}
    };
};
;










namespace llvmo
{
    class CompiledClosure : public core::FunctionClosure {
        friend void dump_funcs(core::CompiledFunction_sp compiledFunction);
    public:
        typedef void (*fptr_type) (LISP_CALLING_CONVENTION_RETURN, LISP_CALLING_CONVENTION_CLOSED_ENVIRONMENT, LISP_CALLING_CONVENTION_ARGS );
    public:
        Function_sp             llvmFunction;
	fptr_type		fptr;
        core::Cons_sp           associatedFunctions;
// constructor
    public:
        virtual size_t templatedSizeof() const { return sizeof(*this);};
    public:
	CompiledClosure( core::T_sp functionName, core::SourcePosInfo_sp spi, core::Symbol_sp type,
                         fptr_type ptr, Function_sp llvmFunc, core::T_sp renv, core::T_sp assocFuncs)
            : FunctionClosure(functionName,spi,type,renv)
            , fptr(ptr)
            , associatedFunctions(assocFuncs)
        {};
        void setAssociatedFunctions(core::Cons_sp assocFuncs) { this->associatedFunctions = assocFuncs; };
        bool compiledP() const { return true; };
        core::LambdaListHandler_sp lambdaListHandler() const { return _Nil<core::LambdaListHandler_O>(); };
        DISABLE_NEW();
	void LISP_CALLING_CONVENTION()
	{_G();
            core::InvocationHistoryFrame _frame(this,this->closedEnvironment);
            (*(this->fptr))(lcc_resultP,&(this->closedEnvironment),lcc_nargs,lcc_fixed_arg0,lcc_fixed_arg1,lcc_fixed_arg2,lcc_arglist);
	};

    };
};






namespace llvmo
{
    FORWARD(Constant);
    class Constant_O : public User_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::Constant,Constant_O,"constant",User_O);
	typedef llvm::Constant ExternalType;
	typedef llvm::Constant* PointerToExternalType;

    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	static Constant_sp create(llvm::Constant* ptr);
	;
	Constant_O() : Base() {};
	~Constant_O() {}

    }; // Constant_O
}; // llvmo
TRANSLATE(llvmo::Constant_O);
/* from_object translators */
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::Constant*>
    {
        static core::T_sp convert(llvm::Constant* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::Constant_O,llvm::Constant*>(ptr)));};
    };
    template <>
    struct from_object<llvm::Constant*,std::true_type>
    {
        typedef llvm::Constant* DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::Constant_O>()->wrappedPtr()) {};
    };


    template <>
    struct from_object<llvm::ArrayRef<llvm::Constant*> > {
        typedef std::vector<llvm::Constant*> DeclareType;
        DeclareType _v;
        from_object(core::T_sp o) {
            if ( o.nilp() ) {
                _v.clear();
                return;
            } else if ( core::Cons_sp cvals = o.asOrNull<core::Cons_O>() ) {
                for ( ; cvals.notnilp(); cvals=cCdr(cvals) ) {
                    llvm::Constant* vP = core::oCar(cvals).as<llvmo::Constant_O>()->wrappedPtr();
                    _v.push_back(vP);
                }
                return;
            } else if ( core::Vector_sp vvals = o.asOrNull<core::Vector_O>() ) {
                _v.resize(vvals->length());
                for (int i(0),iEnd(vvals->length()); i<iEnd; ++i ) {
                    _v[i] = vvals->elt(i).as<llvmo::Constant_O>()->wrappedPtr();
                }
                return;
            }
            SIMPLE_ERROR(BF("Could not convert %s to llvm::ArrayRef<llvm::Constant*>") % core::_rep_(o));
        }
    };

};
;



namespace llvmo
{
    FORWARD(ConstantArray);
    class ConstantArray_O : public Constant_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::ConstantArray,ConstantArray_O,"constant-array",Constant_O);
	typedef llvm::ConstantArray ExternalType;
	typedef llvm::ConstantArray* PointerToExternalType;
    private:
    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
#if 0
	    if (this->_ptr != NULL && this->_PtrIsOwned ) delete this->_ptr;
#endif
	    this->_ptr = ptr;
	}
	ConstantArray_O() : Base() {};
	virtual ~ConstantArray_O() {};
    public:
	static Constant_sp get(ArrayType_sp type, core::Cons_sp values);
    }; // ConstantArray_O
}; // llvmo
TRANSLATE(llvmo::ConstantArray_O);
/* from_object translators */
/* to_object translators */







namespace llvmo
{
    FORWARD(BlockAddress);
    class BlockAddress_O : public Constant_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::BlockAddress,BlockAddress_O,"BlockAddress",Constant_O);
	typedef llvm::BlockAddress ExternalType;
	typedef llvm::BlockAddress* PointerToExternalType;
    private:
    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
#if 0
	    if (this->_ptr != NULL && this->_PtrIsOwned ) delete this->_ptr;
#endif
	    this->_ptr = ptr;
	}
	BlockAddress_O() : Base() {};
	virtual ~BlockAddress_O() {};
    public:
	static BlockAddress_sp get(Function_sp func, BasicBlock_sp bb);
    }; // BlockAddress_O
}; // llvmo
TRANSLATE(llvmo::BlockAddress_O);
/* from_object translators */
/* to_object translators */






namespace llvmo
{
    FORWARD(ConstantDataSequential);
    class ConstantDataSequential_O : public Constant_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::ConstantDataSequential,ConstantDataSequential_O,"ConstantDataSequential",Constant_O);
	typedef llvm::ConstantDataSequential ExternalType;
	typedef llvm::ConstantDataSequential* PointerToExternalType;
    private:
    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
#if 0
	    if (this->_ptr != NULL && this->_PtrIsOwned ) delete this->_ptr;
#endif
	    this->_ptr = ptr;
	}
	ConstantDataSequential_O() : Base() {};
	virtual ~ConstantDataSequential_O() {};
    public:
    }; // ConstantDataSequential_O
}; // llvmo
TRANSLATE(llvmo::ConstantDataSequential_O);
/* from_object translators */
/* to_object translators */




namespace llvmo
{
    FORWARD(ConstantDataArray);
    class ConstantDataArray_O : public ConstantDataSequential_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::ConstantDataArray,ConstantDataArray_O,"constant-data-array",ConstantDataSequential_O);
	typedef llvm::ConstantDataArray ExternalType;
	typedef llvm::ConstantDataArray* PointerToExternalType;
    private:
    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
#if 0
	    if (this->_ptr != NULL && this->_PtrIsOwned ) delete this->_ptr;
#endif
	    this->_ptr = ptr;
	}
	ConstantDataArray_O() : Base() {};
	virtual ~ConstantDataArray_O() {};
    public:
	static Constant_sp getUInt32(LLVMContext_sp context, core::T_sp values);
    }; // ConstantDataArray_O
}; // llvmo
TRANSLATE(llvmo::ConstantDataArray_O);
/* from_object translators */
/* to_object translators */






namespace llvmo
{
    FORWARD(ConstantExpr);
    class ConstantExpr_O : public Constant_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::ConstantExpr,ConstantExpr_O,"ConstantExpr",Constant_O);
	typedef llvm::ConstantExpr ExternalType;
	typedef llvm::ConstantExpr* PointerToExternalType;
    private:
    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
#if 0
	    if (this->_ptr != NULL && this->_PtrIsOwned ) delete this->_ptr;
#endif
	    this->_ptr = ptr;
	}
	ConstantExpr_O() : Base() {};
	virtual ~ConstantExpr_O() {};
    public:

	static Constant_sp getInBoundsGetElementPtr(Constant_sp constant, core::Cons_sp idxList );


    }; // ConstantExpr_O
}; // llvmo
TRANSLATE(llvmo::ConstantExpr_O);
/* from_object translators */
/* to_object translators */











namespace llvmo
{
    FORWARD(GlobalValue);
    class GlobalValue_O : public Constant_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::GlobalValue,GlobalValue_O,"global-value",Constant_O);
	typedef llvm::GlobalValue ExternalType;
	typedef llvm::GlobalValue* PointerToExternalType;
    private:
	bool	_PtrIsOwned;
    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
	    if (this->_ptr != NULL && this->_PtrIsOwned ) delete this->_ptr;
	    this->_ptr = ptr;
	}
	void set_ptrIsOwned(bool b) { this->_PtrIsOwned = b;};
	GlobalValue_O() : Base(), _PtrIsOwned(false) {};
	virtual ~GlobalValue_O() {if ( this->_ptr!=NULL && this->_PtrIsOwned) delete this->_ptr;}

    }; // GlobalValue_O
}; // llvmo
TRANSLATE(llvmo::GlobalValue_O);
/* from_object translators */
/* to_object translators */


namespace llvmo
{
    FORWARD(GlobalVariable);
    class GlobalVariable_O : public GlobalValue_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::GlobalVariable,GlobalVariable_O,"GlobalVariable",GlobalValue_O);
	typedef llvm::GlobalVariable ExternalType;
	typedef llvm::GlobalVariable* PointerToExternalType;

    public:
	static GlobalVariable_sp make(Module_sp module, Type_sp type, bool isConstant, core::Symbol_sp linkage, Constant_sp initializer, core::Str_sp name );

    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	GlobalVariable_O() : Base() {};
	virtual ~GlobalVariable_O() {}

    }; // GlobalVariable_O
}; // llvmo
TRANSLATE(llvmo::GlobalVariable_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::GlobalVariable*,std::true_type>
    {
        typedef llvm::GlobalVariable* DeclareType;
        DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::GlobalVariable_O>()->wrappedPtr()) {};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::GlobalVariable*>
    {
        static core::T_sp convert(llvm::GlobalVariable* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::GlobalVariable_O,llvm::GlobalVariable*>(ptr)));}
    };
};
;





namespace llvmo
{
    FORWARD(ExecutionEngine);
    class ExecutionEngine_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::ExecutionEngine,ExecutionEngine_O,"EXECUTION-ENGINE",core::ExternalObject_O);
	friend class EngineBuilder_O;
	typedef llvm::ExecutionEngine ExternalType;
	typedef llvm::ExecutionEngine* PointerToExternalType;

        void initialize();

    GCPROTECTED:
	PointerToExternalType _ptr;
        core::HashTableEqual_sp _DependentModules;
    public:
	virtual void* externalObject() const
	{
	    return this->_ptr;
	};
	PointerToExternalType wrappedPtr() const
	{
	    return this->_ptr;
	}

    public:
	PointerToExternalType wrappedPtr() { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	string __repr__() const;

	ExecutionEngine_O() : Base(), _ptr(NULL)  {};
	~ExecutionEngine_O() {if (_ptr != NULL ) {/* delete _ptr;*/ _ptr = NULL;};}

        void addModule(Module_sp module);

	core::Function_sp getCompiledFunction(core::Symbol_sp sym, Function_sp fn, core::ActivationFrame_sp env, core::Symbol_sp functionKind);

	void addNamedModule(const string& name, Module_sp module);
	bool hasNamedModule(const string& name);
	void removeNamedModule(const string& name);
	core::Cons_sp dependentModuleNames() const;

	void addGlobalMapping(GlobalValue_sp value, core::Pointer_sp ptr);
	/*! Add a global mapping for an object, give it a new name and return the GlobalVariable_sp */
	void addGlobalMappingForLoadTimeValueVector(GlobalValue_sp value, const string& name);


	void runFunction( Function_sp func, core::Str_sp fileName ); //, core::Cons_sp args );
    }; // ExecutionEngine_O
}; // llvmo




namespace llvmo
{
#if 0
    struct GlobalVariableStringHolder
    {
	string			_String;
	GlobalVariable_sp 	_LlvmValue;
        DECLARE_onHeapScanGCRoots();
    };
#endif
};



namespace llvmo {


    FORWARD(Module);
    class Module_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::Module,Module_O,"module",core::ExternalObject_O);
	typedef llvm::Module ExternalType;
	typedef llvm::Module* PointerToExternalType;
        void initialize();
    GCPROTECTED:
	PointerToExternalType _ptr;
        core::HashTableEqual_sp _UniqueGlobalVariableStrings;
    public:
	virtual void* externalObject() const
	{
	    return this->_ptr;
	};
	PointerToExternalType wrappedPtr() const
	{
	    return this->_ptr;
	}

    public:
	PointerToExternalType wrappedPtr() { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	Module_O() : Base(), _ptr(NULL)  {};
	~Module_O() {if (_ptr != NULL ) {/* delete _ptr;*/ _ptr = NULL;};}
	static Module_sp make(llvm::StringRef module_name, LLVMContext_sp context);
	/*! Return true if the wrapped Module is defined */
	bool valid() const;
	/*! Return a Cons of all the globals for this module */
	core::Cons_sp getGlobalList() const;
    public:
	/*! Return a list of all functions as a cons */
	core::Cons_sp getFunctionList() const;

	/*! Wrap the Module::getFunction function */
	llvm::Function* getFunction(core::Str_sp dispatchName);

	/*! Get or create a string GlobalVariable with the given name.
	  Make sure that the string passed is the same as the string
	  in the GlobalVariable.
	I created this method to avoid lots of duplicate strings being
	created as global variables within the Module. */
	GlobalVariable_sp getOrCreateUniquedStringGlobalVariable( const string& value, const string& name );

	/*! Delete the module */
	void moduleDelete();

	/*! Get a Cons of all named MetaData */
	void dump_namedMDList() const;

    }; // Module_O
}; // llvmo
TRANSLATE(llvmo::Module_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::Module*,std::true_type>
    {
        typedef llvm::Module* DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::Module_O>()->wrappedPtr()) {};
    };
    template <>
    struct from_object<llvm::Module&,std::true_type>
    {
        typedef llvm::Module& DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v(*object.as<llvmo::Module_O>()->wrappedPtr()) {};
    };
};
;
/* to_object translators */
namespace translate
{
    template <>
    struct to_object<llvm::Module*>
    {
        static core::T_sp convert(llvm::Module* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::Module_O,llvm::Module*>(ptr)));}
    };
};
;














TRANSLATE(llvmo::ExecutionEngine_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::ExecutionEngine*,std::true_type>
    {
        typedef llvm::ExecutionEngine* DeclareType;
        DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::ExecutionEngine_O>()->wrappedPtr()) {};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::ExecutionEngine*>
    {
        static core::T_sp convert(llvm::ExecutionEngine* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::ExecutionEngine_O,llvm::ExecutionEngine*>(ptr)));}
    };
};
;






namespace llvmo
{
    FORWARD(DataLayoutPass);
    class DataLayoutPass_O : public ImmutablePass_O
    {
        LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::DataLayoutPass,DataLayoutPass_O,"DataLayoutPass",ImmutablePass_O);
        typedef llvm::DataLayoutPass ExternalType;
        typedef llvm::DataLayoutPass* PointerToExternalType;
    public:
        static DataLayoutPass_sp make();
    public:
        PointerToExternalType wrappedPtr() { return static_cast<PointerToExternalType>(this->_ptr);};
        void set_wrapped(PointerToExternalType ptr)
        {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
            this->_ptr = ptr;
        }
        DataLayoutPass_O() : Base() {};
        ~DataLayoutPass_O() {}
    }; // DataLayoutPass_O
}; // llvmo
TRANSLATE(llvmo::DataLayoutPass_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::DataLayoutPass*,std::true_type>
    {
        typedef llvm::DataLayoutPass* DeclareType;
        DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::DataLayoutPass_O>()->wrappedPtr()) {};
    };
    template <>
    struct from_object<llvm::DataLayoutPass const&,std::true_type>
    {
        typedef llvm::DataLayoutPass const& DeclareType;
        DeclareType _v;
	from_object(T_P object) : _v(*(object.as<llvmo::DataLayoutPass_O>()->wrappedPtr())) {};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::DataLayoutPass*>
    {
        static core::T_sp convert(llvm::DataLayoutPass* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::DataLayoutPass_O,llvm::DataLayoutPass*>(ptr)));}
    };
};
;

namespace translate
{
    template <>
    struct to_object<const llvm::DataLayoutPass*>
    {
        static core::T_sp convert(const llvm::DataLayoutPass* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::DataLayoutPass_O,llvm::DataLayoutPass*>(const_cast<llvm::DataLayoutPass*>(ptr))));}
    };
};
;




namespace llvmo
{
    FORWARD(TargetLibraryInfo);
    class TargetLibraryInfo_O : public ImmutablePass_O
    {
        LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::TargetLibraryInfo,TargetLibraryInfo_O,"TargetLibraryInfo",ImmutablePass_O);
        typedef llvm::TargetLibraryInfo ExternalType;
        typedef llvm::TargetLibraryInfo* PointerToExternalType;
    public:
        static TargetLibraryInfo_sp make();
    public:
        PointerToExternalType wrappedPtr() { return static_cast<PointerToExternalType>(this->_ptr);};
        void set_wrapped(PointerToExternalType ptr)
        {
	    //	    if (this->_ptr != NULL ) delete this->_ptr;
            this->_ptr = ptr;
        }
        TargetLibraryInfo_O() : Base() {};
        ~TargetLibraryInfo_O() {/*if (this->_ptr) delete this->_ptr;*/}
    }; // TargetLibraryInfo_O
}; // llvmo
TRANSLATE(llvmo::TargetLibraryInfo_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::TargetLibraryInfo*,std::true_type>
    {
        typedef llvm::TargetLibraryInfo* DeclareType;
        DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::TargetLibraryInfo_O>()->wrappedPtr()) {};
    };
    template <>
    struct from_object<llvm::TargetLibraryInfo const&,std::true_type>
    {
        typedef llvm::TargetLibraryInfo const& DeclareType;
        DeclareType _v;
	from_object(T_P object) : _v(*(object.as<llvmo::TargetLibraryInfo_O>()->wrappedPtr())) {};
    };
    template <>
    struct to_object<llvm::TargetLibraryInfo*>
    {
        static core::T_sp convert(llvm::TargetLibraryInfo* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::TargetLibraryInfo_O,llvm::TargetLibraryInfo*>(ptr)));}
    };
    template <>
    struct to_object<const llvm::TargetLibraryInfo*>
    {
        static core::T_sp convert(const llvm::TargetLibraryInfo* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::TargetLibraryInfo_O,llvm::TargetLibraryInfo*>(const_cast<llvm::TargetLibraryInfo*>(ptr))));}
    };
};
;








#if 0
namespace llvmo
{
  FORWARD(TargetData);
  c l a s s TargetData_O : public ImmutablePass_O
  {
    L I S P_EXTERNAL_CLASS(LlvmoPkg,llvm::TargetData,TargetData_O,"TARGET-DATA",ImmutablePass_O);
    typedef llvm::TargetData ExternalType;
    typedef llvm::TargetData* PointerToExternalType;
  public:
    static TargetData_sp copy(llvm::TargetData const& orig);
  public:
    PointerToExternalType wrappedPtr() { return static_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
      /*        if (this->_ptr != NULL ) delete this->_ptr; */
      this->_ptr = ptr;
    }
    TargetData_O() : Base() {};
    ~TargetData_O() {}
  }; // TargetData_O
}; // llvmo
TRANSLATE(llvmo::TargetData_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::TargetData*,std::true_type>
    {
        typedef llvm::TargetData* DeclareType;
        DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::TargetData_O>()->wrappedPtr()) {};
    };
    template <>
    struct from_object<llvm::TargetData const&,std::true_type>
    {
        typedef llvm::TargetData const& DeclareType;
        DeclareType _v;
	from_object(T_P object) : _v(*(object.as<llvmo::TargetData_O>()->wrappedPtr())) {};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::TargetData*>
    {
        static core::T_sp convert(llvm::TargetData* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::TargetData_O,llvm::TargetData*>(ptr)));}
    };
};
;

namespace translate
{
    template <>
    struct to_object<const llvm::TargetData*>
    {
        static core::T_sp convert(const llvm::TargetData* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::TargetData_O,llvm::TargetData*>(const_cast<llvm::TargetData*>(ptr))));}
    };
};
;

#endif




namespace llvmo
{
    FORWARD(FunctionPassManager);
    class FunctionPassManager_O : public PassManagerBase_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::FunctionPassManager,FunctionPassManager_O,"FUNCTION-PASS-MANAGER",PassManagerBase_O);
	typedef llvm::FunctionPassManager ExternalType;
	typedef llvm::FunctionPassManager* PointerToExternalType;

    public:
	static FunctionPassManager_sp make(llvm::Module* module);
    public:
	PointerToExternalType wrappedPtr() { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
	    if (this->_ptr != NULL ) delete this->_ptr;
	    this->_ptr = ptr;
	}
	FunctionPassManager_O() : Base() {};
	~FunctionPassManager_O()
	{
	    //	    if ( this->_ptr!=NULL ) delete this->_ptr;
	}
    public:

    }; // FunctionPassManager_O
}; // llvmo
TRANSLATE(llvmo::FunctionPassManager_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::FunctionPassManager*,std::true_type>
    {
        typedef llvm::FunctionPassManager* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::FunctionPassManager_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::FunctionPassManager*>
    {
        static core::T_sp convert(llvm::FunctionPassManager* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::FunctionPassManager_O,llvm::FunctionPassManager*>(ptr)));}
    };
};
;





namespace llvmo
{
    FORWARD(PassManager);
    class PassManager_O : public PassManagerBase_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::PassManager,PassManager_O,"PASS-MANAGER",PassManagerBase_O);
	typedef llvm::PassManager ExternalType;
	typedef llvm::PassManager* PointerToExternalType;

    public:
	static PassManager_sp make();
    public:
	PointerToExternalType wrappedPtr() { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
	    if (this->_ptr != NULL ) delete this->_ptr;
	    this->_ptr = ptr;
	}
	PassManager_O() : Base() {};
	~PassManager_O()
	{
	    //	    if ( this->_ptr!=NULL ) { delete this->_ptr; this->_ptr = NULL; };
	}
    public:

    }; // PassManager_O
}; // llvmo
TRANSLATE(llvmo::PassManager_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::PassManager*,std::true_type>
    {
        typedef llvm::PassManager* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::PassManager_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::PassManager*>
    {
        static core::T_sp convert(llvm::PassManager* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::PassManager_O,llvm::PassManager*>(ptr)));}
    };
};
;


namespace llvmo
{
    FORWARD(EngineBuilder);
    class EngineBuilder_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::EngineBuilder,EngineBuilder_O,"ENGINEBUILDER",core::ExternalObject_O);
	typedef llvm::EngineBuilder ExternalType;
	typedef llvm::EngineBuilder* PointerToExternalType;

    protected:
	PointerToExternalType 		_ptr;
	string				_ErrorStr;	// store creation errors here
    public:
	virtual void* externalObject() const
	{
	    return this->_ptr;
	};
	PointerToExternalType wrappedPtr() const
	{
	    return this->_ptr;
	}

    public:
	PointerToExternalType wrappedPtr() { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	string error_string() const { return this->_ErrorStr;};

	EngineBuilder_O() : Base(), _ptr(NULL)  {};
	~EngineBuilder_O() {if (_ptr != NULL ) {/* delete _ptr;*/ _ptr = NULL;};}
	static EngineBuilder_sp make(Module_sp module);

	/*! Create the ExecutionEngine */
	ExecutionEngine_sp createExecutionEngine();

	/*! kind can be INTERPRETER or JIT */
	void setEngineKind(core::Symbol_sp kind);

	/*! Set the target options (see llvm:EngineBuilder::setTargetOptions).
	  Options are passed as a p-list with keyword/value pairs like :jitemit-debug-info t.
	*/
	void setTargetOptions(TargetOptions_sp targetOptions);

	/*! Set to use MCJIT */
//	void setUseMCJIT(bool mcjit);

    }; // EngineBuilder_O
}; // llvmo
TRANSLATE(llvmo::EngineBuilder_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::EngineBuilder*,std::true_type>
    {
        typedef llvm::EngineBuilder* DeclareType;
        DeclareType _v;
	from_object(T_P object) {_G(); this->_v = (object.as<llvmo::EngineBuilder_O>()->wrappedPtr());};
    };
};
;
/* to_object translators */





namespace llvmo
{
    FORWARD(PassManagerBuilder);
    class PassManagerBuilder_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::PassManagerBuilder,PassManagerBuilder_O,"PASS-MANAGER-BUILDER",core::ExternalObject_O);
	typedef llvm::PassManagerBuilder ExternalType;
	typedef llvm::PassManagerBuilder* PointerToExternalType;

    protected:
	PointerToExternalType 		_ptr;
	string				_ErrorStr;	// store creation errors here
    public:
	virtual void* externalObject() const
	{
	    return this->_ptr;
	};
	PointerToExternalType wrappedPtr() const
	{
	    return this->_ptr;
	}

    public:
	PointerToExternalType wrappedPtr() { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	string error_string() const { return this->_ErrorStr;};

	PassManagerBuilder_O() : Base(), _ptr(NULL)  {};
	~PassManagerBuilder_O() {if (_ptr != NULL ) {/* delete _ptr;*/ _ptr = NULL;};}
	static PassManagerBuilder_sp make();

	/*! Create the ExecutionEngine */
	ExecutionEngine_sp createExecutionEngine();

	/*! kind can be INTERPRETER or JIT */
	void setEngineKind(core::Symbol_sp kind);

	/*! Set the target options (see llvm:PassManagerBuilder::setTargetOptions).
	  Options are passed as a p-list with keyword/value pairs like :jitemit-debug-info t.
	*/
	//	void setTargetOptions(TargetOptions_sp targetOptions);

	/*! Set to use MCJIT */
	void setUseMCJIT(bool mcjit);

    }; // PassManagerBuilder_O
}; // llvmo
TRANSLATE(llvmo::PassManagerBuilder_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::PassManagerBuilder*,std::true_type>
    {
        typedef llvm::PassManagerBuilder* DeclareType;
        DeclareType _v;
	from_object(T_P object) {_G(); this->_v = (object.as<llvmo::PassManagerBuilder_O>()->wrappedPtr());};
    };
};
;
/* to_object translators */




namespace llvmo
{
    FORWARD(APFloat);
    class APFloat_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::APFloat,APFloat_O,"APFLOAT",core::ExternalObject_O);
    public:
	typedef llvm::APFloat ExternalType;
	llvm::APFloat	_value;
    public:
	static APFloat_sp makeAPFloatFloat(core::SingleFloat_sp value);
	static APFloat_sp makeAPFloatDouble(core::DoubleFloat_sp value);
    public:
	APFloat_O() : Base(), _value(0.0) {};
	~APFloat_O() {};
    }; // APFloat_O
}; // llvmo
TRANSLATE(llvmo::APFloat_O);
namespace translate
{
    template <>
    struct from_object<const llvm::APFloat&,std::true_type>
    {
        typedef const llvm::APFloat& DeclareType;
        DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::APFloat_O>()->_value) {};
    };
};
/* to_object translators */


namespace llvmo
{
    FORWARD(APInt);
    class APInt_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::APInt,APInt_O,"APINT",core::ExternalObject_O);
    public:
	typedef llvm::APInt 	ExternalType;
	llvm::APInt		_value;
    public:
        static APInt_sp create(llvm::APInt i);
	/*! Return an APInt that has the value of (val) */
	static APInt_sp makeAPInt(core::Integer_sp val);
	static APInt_sp makeAPIntWidth(core::Integer_sp val, uint bitwidth, bool sign);
	static APInt_sp makeAPInt1(core::T_sp val);
	static APInt_sp makeAPInt32(core::Integer_sp val);
	static APInt_sp makeAPInt64(core::Integer_sp val);
    public:
        string toString(int radix, bool isigned) const;
	APInt_O() : Base() {};
	~APInt_O() {};

    public:
	string __repr__() const;
    }; // APInt_O
}; // llvmo
TRANSLATE(llvmo::APInt_O);
/* from_object translators */
namespace translate
{
    template <>
    struct from_object<const llvm::APInt&,std::true_type>
    {
        typedef const llvm::APInt& DeclareType;
        DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::APInt_O>()->_value) {};
    };
/* to_object translators */

    template <>
    struct to_object<llvm::APInt>
    {
	static core::T_sp convert(llvm::APInt sr)
	{return llvmo::APInt_O::create(sr);};
    };

};




namespace llvmo
{
    FORWARD(IRBuilderBase);
    class IRBuilderBase_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::IRBuilderBase,IRBuilderBase_O,"IRBuilderBase",core::ExternalObject_O);
	typedef llvm::IRBuilderBase ExternalType;
	typedef llvm::IRBuilderBase* PointerToExternalType;

    protected:
	PointerToExternalType _ptr;
    public:
	virtual void* externalObject() const
	{
	    return this->_ptr;
	};
	PointerToExternalType wrappedPtr() const
	{
	    return this->_ptr;
	}

    public:
	PointerToExternalType wrappedPtr() { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	static IRBuilderBase_sp create(llvm::IRBuilderBase* ptr);
	;
	IRBuilderBase_O() : Base(), _ptr(NULL)  {};
	~IRBuilderBase_O() {if (_ptr != NULL ) {/* delete _ptr;*/ _ptr = NULL;};}

    public:
	void restoreIP(InsertPoint_sp insertPoint);
	InsertPoint_sp saveIP();

	/*! Set the current debug location for generated code */
	void SetCurrentDebugLocation(DebugLoc_sp loc);

    }; // IRBuilderBase_O
}; // llvmo
TRANSLATE(llvmo::IRBuilderBase_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::IRBuilderBase*,std::true_type>
    {
        typedef llvm::IRBuilderBase* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::IRBuilderBase_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::IRBuilderBase*>
    {
        static core::T_sp convert(llvm::IRBuilderBase* ptr)
        {_G(); return(( llvmo::IRBuilderBase_O::create(ptr)));}
    };
};
;








namespace llvmo
{
    FORWARD(IRBuilder);
    class IRBuilder_O : public IRBuilderBase_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::IRBuilder<>,IRBuilder_O,"IRBUILDER",IRBuilderBase_O);
	typedef llvm::IRBuilder<> ExternalType;
	typedef llvm::IRBuilder<>* PointerToExternalType;

    public:
	PointerToExternalType wrappedPtr() { return static_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	IRBuilder_O() : Base() {};
	~IRBuilder_O() {}
	static IRBuilder_sp make(LLVMContext_sp context);
    public:
	llvm::InvokeInst* CreateInvoke(llvm::Value *Callee, llvm::BasicBlock *NormalDest, llvm::BasicBlock *UnwindDest, core::Cons_sp Args, const llvm::Twine &Name="");
	llvm::Value* CreateInBoundsGEP(llvm::Value* Ptr, core::Cons_sp IdxList, const llvm::Twine&Name="");

	llvm::Value* CreateExtractValue(llvm::Value* Ptr, core::Cons_sp IdxList, const llvm::Twine& Name="");

	llvm::Value* CreateInsertValue(llvm::Value* Agg, llvm::Value* Val, core::Cons_sp IdxList, const llvm::Twine& Name="");

	string __repr__() const;
    }; // IRBuilder_O
}; // llvmo
TRANSLATE(llvmo::IRBuilder_O);
/* from_object translators */
/* to_object translators */







namespace llvmo
{
    FORWARD(Instruction);
    class Instruction_O : public User_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::Instruction,Instruction_O,"Instruction",User_O);
	typedef llvm::Instruction ExternalType;
	typedef llvm::Instruction* PointerToExternalType;

    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	Instruction_O() : Base() {};
	~Instruction_O() {}

    public:
	void setMetadata(core::Str_sp kind, MDNode_sp mdnode);

	bool terminatorInstP() const;
    }; // Instruction_O
}; // llvmo
TRANSLATE(llvmo::Instruction_O);
namespace translate
{
    template <>
    struct from_object<llvm::Instruction*,std::true_type>
    {
        typedef llvm::Instruction* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::Instruction_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::Instruction*>
    {
        static core::T_sp convert(llvm::Instruction* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::Instruction_O,llvm::Instruction*>(ptr)));}
    };
};
;




/* from_object translators */
/* to_object translators */





namespace llvmo
{
    FORWARD(StoreInst);
    class StoreInst_O : public Instruction_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::StoreInst,StoreInst_O,"StoreInst",Instruction_O);
	typedef llvm::StoreInst ExternalType;
	typedef llvm::StoreInst* PointerToExternalType;

    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	StoreInst_O() : Base() {};
	~StoreInst_O() {}

    }; // StoreInst_O
}; // llvmo
TRANSLATE(llvmo::StoreInst_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::StoreInst*,std::true_type>
    {
        typedef llvm::StoreInst* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::StoreInst_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::StoreInst*>
    {
        static core::T_sp convert(llvm::StoreInst* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::StoreInst_O,llvm::StoreInst*>(ptr)));}
    };
};
;


namespace llvmo
{
FORWARD(FenceInst);
class FenceInst_O : public Instruction_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::FenceInst,FenceInst_O,"FenceInst",Instruction_O);
    typedef llvm::FenceInst ExternalType;
    typedef llvm::FenceInst* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
FenceInst_O() : Base() {};
~FenceInst_O() {}

 }; // FenceInst_O
 }; // llvmo
TRANSLATE(llvmo::FenceInst_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::FenceInst*,std::true_type>
    {
        typedef llvm::FenceInst* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::FenceInst_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::FenceInst*>
    {
        static core::T_sp convert(llvm::FenceInst* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::FenceInst_O,llvm::FenceInst*>(ptr)));}
    };
};
;


namespace llvmo
{
FORWARD(AtomicCmpXchgInst);
class AtomicCmpXchgInst_O : public Instruction_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::AtomicCmpXchgInst,AtomicCmpXchgInst_O,"AtomicCmpXchgInst",Instruction_O);
    typedef llvm::AtomicCmpXchgInst ExternalType;
    typedef llvm::AtomicCmpXchgInst* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
AtomicCmpXchgInst_O() : Base() {};
~AtomicCmpXchgInst_O() {}

 }; // AtomicCmpXchgInst_O
 }; // llvmo
TRANSLATE(llvmo::AtomicCmpXchgInst_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::AtomicCmpXchgInst*,std::true_type>
    {
        typedef llvm::AtomicCmpXchgInst* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::AtomicCmpXchgInst_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::AtomicCmpXchgInst*>
    {
        static core::T_sp convert(llvm::AtomicCmpXchgInst* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::AtomicCmpXchgInst_O,llvm::AtomicCmpXchgInst*>(ptr)));}
    };
};
;


namespace llvmo
{
FORWARD(AtomicRMWInst);
class AtomicRMWInst_O : public Instruction_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::AtomicRMWInst,AtomicRMWInst_O,"AtomicRMWInst",Instruction_O);
    typedef llvm::AtomicRMWInst ExternalType;
    typedef llvm::AtomicRMWInst* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
AtomicRMWInst_O() : Base() {};
~AtomicRMWInst_O() {}

 }; // AtomicRMWInst_O
 }; // llvmo
TRANSLATE(llvmo::AtomicRMWInst_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::AtomicRMWInst*,std::true_type>
    {
        typedef llvm::AtomicRMWInst* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::AtomicRMWInst_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::AtomicRMWInst*>
    {
        static core::T_sp convert(llvm::AtomicRMWInst* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::AtomicRMWInst_O,llvm::AtomicRMWInst*>(ptr)));}
    };
};
;


namespace llvmo
{
FORWARD(PHINode);
class PHINode_O : public Instruction_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::PHINode,PHINode_O,"PHINode",Instruction_O);
    typedef llvm::PHINode ExternalType;
    typedef llvm::PHINode* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
PHINode_O() : Base() {};
~PHINode_O() {}

 }; // PHINode_O
 }; // llvmo
TRANSLATE(llvmo::PHINode_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::PHINode*,std::true_type>
    {
        typedef llvm::PHINode* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::PHINode_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::PHINode*>
    {
        static core::T_sp convert(llvm::PHINode* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::PHINode_O,llvm::PHINode*>(ptr)));}
    };
};
;


namespace llvmo
{
FORWARD(CallInst);
class CallInst_O : public Instruction_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::CallInst,CallInst_O,"CallInst",Instruction_O);
    typedef llvm::CallInst ExternalType;
    typedef llvm::CallInst* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
CallInst_O() : Base() {};
~CallInst_O() {}

 }; // CallInst_O
 }; // llvmo
TRANSLATE(llvmo::CallInst_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::CallInst*,std::true_type>
    {
        typedef llvm::CallInst* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::CallInst_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::CallInst*>
    {
        static core::T_sp convert(llvm::CallInst* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::CallInst_O,llvm::CallInst*>(ptr)));}
    };
};
;


namespace llvmo
{
    FORWARD(LandingPadInst);
    class LandingPadInst_O : public Instruction_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::LandingPadInst,LandingPadInst_O,"LandingPadInst",Instruction_O);
	typedef llvm::LandingPadInst ExternalType;
	typedef llvm::LandingPadInst* PointerToExternalType;

    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	LandingPadInst_O() : Base() {};
	~LandingPadInst_O() {}


    }; // LandingPadInst_O
}; // llvmo
TRANSLATE(llvmo::LandingPadInst_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::LandingPadInst*,std::true_type>
    {
        typedef llvm::LandingPadInst* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::LandingPadInst_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::LandingPadInst*>
    {
        static core::T_sp convert(llvm::LandingPadInst* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::LandingPadInst_O,llvm::LandingPadInst*>(ptr)));}
    };
};
;


namespace llvmo
{
FORWARD(UnaryInstruction);
class UnaryInstruction_O : public Instruction_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::UnaryInstruction,UnaryInstruction_O,"UnaryInstruction",Instruction_O);
    typedef llvm::UnaryInstruction ExternalType;
    typedef llvm::UnaryInstruction* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
UnaryInstruction_O() : Base() {};
~UnaryInstruction_O() {}

 }; // UnaryInstruction_O
 }; // llvmo
TRANSLATE(llvmo::UnaryInstruction_O);
/* from_object translators */
/* to_object translators */


namespace llvmo
{
    FORWARD(AllocaInst);
    class AllocaInst_O : public UnaryInstruction_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::AllocaInst,AllocaInst_O,"AllocaInst",UnaryInstruction_O);
	typedef llvm::AllocaInst ExternalType;
	typedef llvm::AllocaInst* PointerToExternalType;

    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	AllocaInst_O() : Base() {};
	~AllocaInst_O() {}
    }; // AllocaInst_O
}; // llvmo
TRANSLATE(llvmo::AllocaInst_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::AllocaInst*,std::true_type>
    {
        typedef llvm::AllocaInst* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::AllocaInst_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::AllocaInst*>
    {
        static core::T_sp convert(llvm::AllocaInst* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::AllocaInst_O,llvm::AllocaInst*>(ptr)));}
    };
};
;


namespace llvmo
{
FORWARD(VAArgInst);
class VAArgInst_O : public UnaryInstruction_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::VAArgInst,VAArgInst_O,"VAArgInst",UnaryInstruction_O);
    typedef llvm::VAArgInst ExternalType;
    typedef llvm::VAArgInst* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
VAArgInst_O() : Base() {};
~VAArgInst_O() {}

 }; // VAArgInst_O
 }; // llvmo
TRANSLATE(llvmo::VAArgInst_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::VAArgInst*,std::true_type>
    {
        typedef llvm::VAArgInst* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::VAArgInst_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::VAArgInst*>
    {
        static core::T_sp convert(llvm::VAArgInst* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::VAArgInst_O,llvm::VAArgInst*>(ptr)));}
    };
};
;


namespace llvmo
{
FORWARD(LoadInst);
class LoadInst_O : public UnaryInstruction_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::LoadInst,LoadInst_O,"LoadInst",UnaryInstruction_O);
    typedef llvm::LoadInst ExternalType;
    typedef llvm::LoadInst* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
LoadInst_O() : Base() {};
~LoadInst_O() {}

 }; // LoadInst_O
 }; // llvmo
TRANSLATE(llvmo::LoadInst_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::LoadInst*,std::true_type>
    {
        typedef llvm::LoadInst* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::LoadInst_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::LoadInst*>
    {
        static core::T_sp convert(llvm::LoadInst* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::LoadInst_O,llvm::LoadInst*>(ptr)));}
    };
};
;


namespace llvmo
{
    FORWARD(TerminatorInst);
    class TerminatorInst_O : public Instruction_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::TerminatorInst,TerminatorInst_O,"TerminatorInst",Instruction_O);
	typedef llvm::TerminatorInst ExternalType;
	typedef llvm::TerminatorInst* PointerToExternalType;

    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	TerminatorInst_O() : Base() {};
	~TerminatorInst_O() {}

    }; // TerminatorInst_O
}; // llvmo
TRANSLATE(llvmo::TerminatorInst_O);
/* from_object translators */
/* to_object translators */


namespace llvmo
{
FORWARD(BranchInst);
class BranchInst_O : public TerminatorInst_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::BranchInst,BranchInst_O,"BranchInst",TerminatorInst_O);
    typedef llvm::BranchInst ExternalType;
    typedef llvm::BranchInst* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
BranchInst_O() : Base() {};
~BranchInst_O() {}

 }; // BranchInst_O
 }; // llvmo
TRANSLATE(llvmo::BranchInst_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::BranchInst*,std::true_type>
    {
        typedef llvm::BranchInst* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::BranchInst_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::BranchInst*>
    {
        static core::T_sp convert(llvm::BranchInst* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::BranchInst_O,llvm::BranchInst*>(ptr)));}
    };
};
;


namespace llvmo
{
    FORWARD(SwitchInst);
    class SwitchInst_O : public TerminatorInst_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::SwitchInst,SwitchInst_O,"SwitchInst",TerminatorInst_O);
	typedef llvm::SwitchInst ExternalType;
	typedef llvm::SwitchInst* PointerToExternalType;

    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	SwitchInst_O() : Base() {};
	~SwitchInst_O() {}

	void addCase(ConstantInt_sp onVal, BasicBlock_sp dest);

    }; // SwitchInst_O
}; // llvmo
TRANSLATE(llvmo::SwitchInst_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::SwitchInst*,std::true_type>
    {
        typedef llvm::SwitchInst* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::SwitchInst_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::SwitchInst*>
    {
        static core::T_sp convert(llvm::SwitchInst* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::SwitchInst_O,llvm::SwitchInst*>(ptr)));}
    };
};
;


namespace llvmo
{
FORWARD(IndirectBrInst);
class IndirectBrInst_O : public TerminatorInst_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::IndirectBrInst,IndirectBrInst_O,"IndirectBrInst",TerminatorInst_O);
    typedef llvm::IndirectBrInst ExternalType;
    typedef llvm::IndirectBrInst* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
IndirectBrInst_O() : Base() {};
~IndirectBrInst_O() {}

 }; // IndirectBrInst_O
 }; // llvmo
TRANSLATE(llvmo::IndirectBrInst_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::IndirectBrInst*,std::true_type>
    {
        typedef llvm::IndirectBrInst* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::IndirectBrInst_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::IndirectBrInst*>
    {
        static core::T_sp convert(llvm::IndirectBrInst* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::IndirectBrInst_O,llvm::IndirectBrInst*>(ptr)));}
    };
};
;


namespace llvmo
{
FORWARD(InvokeInst);
class InvokeInst_O : public TerminatorInst_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::InvokeInst,InvokeInst_O,"InvokeInst",TerminatorInst_O);
    typedef llvm::InvokeInst ExternalType;
    typedef llvm::InvokeInst* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
InvokeInst_O() : Base() {};
~InvokeInst_O() {}

 }; // InvokeInst_O
 }; // llvmo
TRANSLATE(llvmo::InvokeInst_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::InvokeInst*,std::true_type>
    {
        typedef llvm::InvokeInst* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::InvokeInst_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::InvokeInst*>
    {
        static core::T_sp convert(llvm::InvokeInst* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::InvokeInst_O,llvm::InvokeInst*>(ptr)));}
    };
};
;


namespace llvmo
{
FORWARD(ResumeInst);
class ResumeInst_O : public TerminatorInst_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::ResumeInst,ResumeInst_O,"ResumeInst",TerminatorInst_O);
    typedef llvm::ResumeInst ExternalType;
    typedef llvm::ResumeInst* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
ResumeInst_O() : Base() {};
~ResumeInst_O() {}

 }; // ResumeInst_O
 }; // llvmo
TRANSLATE(llvmo::ResumeInst_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::ResumeInst*,std::true_type>
    {
        typedef llvm::ResumeInst* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::ResumeInst_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::ResumeInst*>
    {
        static core::T_sp convert(llvm::ResumeInst* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::ResumeInst_O,llvm::ResumeInst*>(ptr)));}
    };
};
;


namespace llvmo
{
FORWARD(UnreachableInst);
class UnreachableInst_O : public TerminatorInst_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::UnreachableInst,UnreachableInst_O,"UnreachableInst",TerminatorInst_O);
    typedef llvm::UnreachableInst ExternalType;
    typedef llvm::UnreachableInst* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
UnreachableInst_O() : Base() {};
~UnreachableInst_O() {}

 }; // UnreachableInst_O
 }; // llvmo
TRANSLATE(llvmo::UnreachableInst_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::UnreachableInst*,std::true_type>
    {
        typedef llvm::UnreachableInst* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::UnreachableInst_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::UnreachableInst*>
    {
        static core::T_sp convert(llvm::UnreachableInst* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::UnreachableInst_O,llvm::UnreachableInst*>(ptr)));}
    };
};
;


namespace llvmo
{
FORWARD(ReturnInst);
class ReturnInst_O : public TerminatorInst_O
{
    LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::ReturnInst,ReturnInst_O,"ReturnInst",TerminatorInst_O);
    typedef llvm::ReturnInst ExternalType;
    typedef llvm::ReturnInst* PointerToExternalType;

public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
    void set_wrapped(PointerToExternalType ptr)
    {
/*        if (this->_ptr != NULL ) delete this->_ptr; */
        this->_ptr = ptr;
    }
ReturnInst_O() : Base() {};
~ReturnInst_O() {}

 }; // ReturnInst_O
 }; // llvmo
TRANSLATE(llvmo::ReturnInst_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::ReturnInst*,std::true_type>
    {
        typedef llvm::ReturnInst* DeclareType;
        DeclareType _v;
	from_object(T_P object) {this->_v = object.as<llvmo::ReturnInst_O>()->wrappedPtr();};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::ReturnInst*>
    {
        static core::T_sp convert(llvm::ReturnInst* ptr)
	{_G(); return((core::RP_Create_wrapped<llvmo::ReturnInst_O,llvm::ReturnInst*>(ptr)));}
    };
};
;






namespace llvmo
{
    FORWARD(ConstantFP);
    class ConstantFP_O : public Constant_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::ConstantFP,ConstantFP_O,"ConstantFP",Constant_O);
	typedef llvm::ConstantFP ExternalType;
	typedef llvm::ConstantFP* PointerToExternalType;

    public:
	PointerToExternalType wrappedPtr() { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	static ConstantFP_sp create(llvm::ConstantFP* ptr);
	;
	ConstantFP_O() : Base() {};
	~ConstantFP_O() {}

    public:
	string __repr__() const;

    }; // ConstantFP_O
}; // llvmo
TRANSLATE(llvmo::ConstantFP_O);
/* from_object translators */
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::ConstantFP*>
    {
        static core::T_sp convert(llvm::ConstantFP* ptr)
        {_G(); return(( llvmo::ConstantFP_O::create(ptr)));}
    };
};
;








namespace llvmo
{
    FORWARD(ConstantInt);
    class ConstantInt_O : public Constant_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::ConstantInt,ConstantInt_O,"ConstantInt",Constant_O);
	typedef llvm::ConstantInt ExternalType;
	typedef llvm::ConstantInt* PointerToExternalType;

    public:
	PointerToExternalType wrappedPtr() { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	static ConstantInt_sp create(llvm::ConstantInt* ptr);
	;
	ConstantInt_O() : Base() {};
	~ConstantInt_O() {}
    public:
	string __repr__() const;
    }; // ConstantInt_O
}; // llvmo
TRANSLATE(llvmo::ConstantInt_O);
/* from_object translators */
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::ConstantInt*>
    {
        static core::T_sp convert(llvm::ConstantInt* ptr)
        {_G(); return(( llvmo::ConstantInt_O::create(ptr)));}
    };
};
;




namespace llvmo
{
    FORWARD(ConstantStruct);
    class ConstantStruct_O : public Constant_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::ConstantStruct,ConstantStruct_O,"ConstantStruct",Constant_O);
	typedef llvm::ConstantStruct ExternalType;
	typedef llvm::ConstantStruct* PointerToExternalType;

    public:
	PointerToExternalType wrappedPtr() { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	static ConstantStruct_sp create(llvm::ConstantStruct* ptr);
	;
	ConstantStruct_O() : Base() {};
	~ConstantStruct_O() {}
    public:
    }; // ConstantStruct_O
}; // llvmo
TRANSLATE(llvmo::ConstantStruct_O);
/* from_object translators */
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::ConstantStruct*>
    {
        static core::T_sp convert(llvm::ConstantStruct* ptr)
        {_G(); return(( llvmo::ConstantStruct_O::create(ptr)));}
    };

};
;









namespace llvmo
{
    FORWARD(UndefValue);
    class UndefValue_O : public Constant_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::UndefValue,UndefValue_O,"UndefValue",Constant_O);
	typedef llvm::UndefValue ExternalType;
	typedef llvm::UndefValue* PointerToExternalType;

    public:
	PointerToExternalType wrappedPtr() { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	static UndefValue_sp create(llvm::UndefValue* ptr);
	;
	UndefValue_O() : Base() {};
	~UndefValue_O() {}
    public:
	string __repr__() const;
    }; // UndefValue_O
}; // llvmo
TRANSLATE(llvmo::UndefValue_O);
/* from_object translators */
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::UndefValue*>
    {
        static core::T_sp convert(llvm::UndefValue* ptr)
        {_G(); return(( llvmo::UndefValue_O::create(ptr)));}
    };
};
;







namespace llvmo
{
    FORWARD(ConstantPointerNull);
    class ConstantPointerNull_O : public Constant_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::ConstantPointerNull,ConstantPointerNull_O,"ConstantPointerNull",Constant_O);
	typedef llvm::ConstantPointerNull ExternalType;
	typedef llvm::ConstantPointerNull* PointerToExternalType;

    public:
	PointerToExternalType wrappedPtr() { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	static ConstantPointerNull_sp create(llvm::ConstantPointerNull* ptr);
	;
	ConstantPointerNull_O() : Base() {};
	~ConstantPointerNull_O() {}
    public:
	string __repr__() const;
    }; // ConstantPointerNull_O
}; // llvmo
TRANSLATE(llvmo::ConstantPointerNull_O);
/* from_object translators */
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::ConstantPointerNull*>
    {
        static core::T_sp convert(llvm::ConstantPointerNull* ptr)
        {_G(); return(( llvmo::ConstantPointerNull_O::create(ptr)));}
    };

    template <>
    struct from_object<llvm::ConstantPointerNull*,std::true_type>
    {
        typedef llvm::ConstantPointerNull* DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v(object.as<llvmo::ConstantPointerNull_O>()->wrappedPtr()) {};
    };

};
;












namespace llvmo
{
    FORWARD(MDNode);
    class MDNode_O : public Value_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::MDNode,MDNode_O,"MDNode",Value_O);
	typedef llvm::MDNode ExternalType;
	typedef llvm::MDNode* PointerToExternalType;

    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	MDNode_O() : Base() {};
	~MDNode_O() {}

    public:
	static MDNode_sp get(LLVMContext_sp context, core::Cons_sp values);

    }; // MDNode_O
}; // llvmo
TRANSLATE(llvmo::MDNode_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::MDNode*,std::true_type>
    {
        typedef llvm::MDNode* DeclareType;
	DeclareType _v;
        from_object(T_P o) : _v(o.nilp() ? NULL : o.as<llvmo::MDNode_O>()->wrappedPtr()) {};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::MDNode*>
    {
        static llvmo::MDNode_mv convert(llvm::MDNode* ptr)
        {_G(); return(Values(core::RP_Create_wrapped<llvmo::MDNode_O,llvm::MDNode*>(ptr)));}
    };
};
;






namespace llvmo
{
    FORWARD(MDString);
    class MDString_O : public Value_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::MDString,MDString_O,"MDString",Value_O);
	typedef llvm::MDString ExternalType;
	typedef llvm::MDString* PointerToExternalType;

    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	MDString_O() : Base() {};
	~MDString_O() {}

    public:
	static MDString_sp get(LLVMContext_sp context, core::Str_sp str);

    }; // MDString_O
}; // llvmo
TRANSLATE(llvmo::MDString_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::MDString*,std::true_type>
    {
        typedef llvm::MDString* DeclareType;
	DeclareType _v;
	from_object(T_P object) {
	    this->_v = object.as<llvmo::MDString_O>()->wrappedPtr();
	};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::MDString*>
    {
        static core::T_sp convert(llvm::MDString* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::MDString_O,llvm::MDString*>(ptr)));}
    };
};
;



namespace llvmo
{
    FORWARD(NamedMDNode);
    class NamedMDNode_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::NamedMDNode,NamedMDNode_O,"NamedMDNode",core::ExternalObject_O);
	typedef llvm::NamedMDNode ExternalType;
	typedef llvm::NamedMDNode* PointerToExternalType;
    protected:
	PointerToExternalType _ptr;

    public:    PointerToExternalType wrappedPtr() const { return dynamic_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	NamedMDNode_O() : Base() {};
	~NamedMDNode_O() {}

    public:
	llvm::MDNode* getOperand(uint i) { return this->_ptr->getOperand(i);};
	uint getNumOperands() {return this->_ptr->getNumOperands();};
	void addOperand(llvm::MDNode* m) { this->_ptr->addOperand(m);};
	string getName() { return this->_ptr->getName();};

    }; // NamedMDNode_O
}; // llvmo
TRANSLATE(llvmo::NamedMDNode_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::NamedMDNode*,std::true_type>
    {
        typedef llvm::NamedMDNode* DeclareType;
	DeclareType _v;
	from_object(T_P object)
        {
	    this->_v = object.nilp() ? NULL : object.as<llvmo::NamedMDNode_O>()->wrappedPtr();
	};
    };
};
;
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::NamedMDNode*>
    {
        static llvmo::NamedMDNode_mv convert(llvm::NamedMDNode* ptr)
        {_G(); return(Values(core::RP_Create_wrapped<llvmo::NamedMDNode_O,llvm::NamedMDNode*>(ptr)));}
    };
};
;









namespace llvmo
{
    FORWARD(Function);
    class Function_O : public GlobalValue_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::Function,Function_O,"FUNCTION",GlobalValue_O);
	typedef llvm::Function ExternalType;
	typedef llvm::Function* PointerToExternalType;

    GCPRIVATE:
	core::LoadTimeValues_sp 	_RunTimeValues;
    public:
	/*! If a Function is compiled with COMPILE then quoted values and literals need to be stored
	  somewhere.  We store them in a LoadTimeValue array and associate it with the Function
	  so that if the Function is destructed then the LoadTimeValues get destructed as well */
	void setLiterals( core::LoadTimeValues_sp ltv);
	core::LoadTimeValues_sp literals() const;
    public:
	PointerToExternalType wrappedPtr() { return static_cast<PointerToExternalType>(this->_ptr);};
	PointerToExternalType wrappedPtr() const { return static_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	Function_O() : Base() {};
	~Function_O() {}

	core::Cons_sp getArgumentList();
	void appendBasicBlock(BasicBlock_sp basicBlock);

    }; // Function_O
}; // llvmo
TRANSLATE(llvmo::Function_O);
/* from_object translators */
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::Function*>
    {
        static core::T_sp convert(llvm::Function* ptr)
        {_G();
	    if ( ptr==NULL ) return((_Nil<core::T_O>()));
	    return((core::RP_Create_wrapped<llvmo::Function_O,llvm::Function*>(ptr)));
	};
    };

    template <>
    struct to_object<const llvm::Function&>
    {
        static core::T_sp convert(const llvm::Function& val)
        {_G();
	    return((core::RP_Create_wrapped<llvmo::Function_O,llvm::Function*>(const_cast<llvm::Function*>(&val))));};
    };


    template <>
    struct from_object<llvm::Function*,std::true_type>
    {
	typedef llvm::Function* DeclareType;
	DeclareType _v;
	from_object(T_P object)
	{
	    if ( object.nilp() ) {
		this->_v = NULL;
	    } else
	    {
		this->_v = static_cast<llvm::Function*>(object.as<llvmo::Function_O>()->wrappedPtr());
	    }
	}
    };
    template <>
    struct from_object<const llvm::Function&,std::true_type>
    {
	typedef llvm::Function const & DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v(*(static_cast<llvm::Function*>(object.as<llvmo::Function_O>()->wrappedPtr()))) {};
    };
    template <>
    struct from_object<llvm::Function&,std::true_type>
    {
	typedef llvm::Function& DeclareType;
	DeclareType _v;
	from_object(T_P object) : _v(*(static_cast<llvm::Function*>(object.as<llvmo::Function_O>()->wrappedPtr()))) {};
    };
};










namespace llvmo
{
    FORWARD(BasicBlock);
    class BasicBlock_O : public Value_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::BasicBlock,BasicBlock_O,"BasicBlock",Value_O);
	typedef llvm::BasicBlock ExternalType;
	typedef llvm::BasicBlock* PointerToExternalType;

    public:
	PointerToExternalType wrappedPtr() { return static_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	BasicBlock_O() : Base() {};
	~BasicBlock_O() {}

	bool empty();
	Instruction_sp back();

    }; // BasicBlock_O
}; // llvmo
TRANSLATE(llvmo::BasicBlock_O);
/* from_object translators */
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::BasicBlock*>
    {
        static core::T_sp convert(llvm::BasicBlock* ptr)
        {_G();
	    if ( ptr!=NULL )
	    {
		return((core::RP_Create_wrapped<llvmo::BasicBlock_O,llvm::BasicBlock*>(ptr)));
	    }
	    return((_Nil<core::T_O>()));
	};
    };
    template <>
    struct from_object<llvm::BasicBlock*,std::true_type>
    {
	typedef llvm::BasicBlock* DeclareType;
	DeclareType _v;
	from_object(T_P object) {
	    this->_v = object.nilp() ? NULL : static_cast<llvm::BasicBlock*>(object.as<llvmo::BasicBlock_O>()->wrappedPtr());
	}
    };
};


















namespace llvmo
{
    FORWARD(Argument);
    class Argument_O : public Value_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::Argument,Argument_O,"Argument",Value_O);
	typedef llvm::Argument ExternalType;
	typedef llvm::Argument* PointerToExternalType;

    public:
	PointerToExternalType wrappedPtr() { return static_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	Argument_O() : Base() {};
	~Argument_O() {}


	void addAttr(llvm::Attribute a);

    public:

    }; // Argument_O
}; // llvmo
TRANSLATE(llvmo::Argument_O);
/* from_object translators */
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::Argument*>
    {
        static core::T_sp convert( llvm::Argument* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::Argument_O,llvm::Argument*>(ptr)));};
    };
    template <>
    struct to_object<llvm::Argument>
    {
        static core::T_sp convert( llvm::Argument& arg)
        {_G(); return(( core::RP_Create_wrapped<llvmo::Argument_O,llvm::Argument*>(&arg)));};
    };
};

namespace translate
{
    template <>
    struct to_object<llvm::Function::ArgumentListType&>
    {
	static core::Cons_sp convert(llvm::Function::ArgumentListType& al)
	{_G();
	    ql::list l(_lisp);
	    for ( llvm::Function::ArgumentListType::iterator it=al.begin(); it!=al.end(); it++ )
	    {
		l<< to_object<llvm::Argument>::convert(*it);
	    }
	    return(Values(l.cons()));
	}
    };
};









namespace llvmo
{
    FORWARD(Type);
    class Type_O : public core::ExternalObject_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::Type,Type_O,"TYPE",core::ExternalObject_O);
	typedef llvm::Type ExternalType;
	typedef llvm::Type* PointerToExternalType;

    protected:
	PointerToExternalType _ptr;
    public:
	virtual void* externalObject() const
	{
	    return this->_ptr;
	};
	PointerToExternalType wrappedPtr() const
	{
	    return this->_ptr;
	}

    public:
	PointerToExternalType wrappedPtr() { return static_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	static Type_sp create(llvm::Type* ptr);
	;
	Type_O() : Base(), _ptr(NULL)  {};
	~Type_O() {if (_ptr != NULL ) {/* delete _ptr;*/ _ptr = NULL;};}

        core::Integer_sp getArrayNumElements() const;

	PointerType_sp getPointerTo(int addressSpace=0);

	bool equal(core::T_sp obj) const;

	string __repr__() const;

    }; // Type_O
}; // llvmo
TRANSLATE(llvmo::Type_O);
/* from_object translators */

namespace translate
{
    template <>
    struct from_object<llvm::Type*,std::true_type>
    {
        typedef llvm::Type* DeclareType;
	DeclareType _v;
	from_object(T_P object) {_G(); this->_v = (object.as<llvmo::Type_O>()->wrappedPtr());};
    };

/* to_object translators */
    template <>
    struct to_object<llvm::Type*>
    {
        static core::T_sp convert(llvm::Type* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::Type_O,llvm::Type*>(ptr)));};
    };
};
;












namespace llvmo
{
    FORWARD(FunctionType);
    class FunctionType_O : public Type_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::FunctionType,FunctionType_O,"FUNCTION-TYPE",Type_O);
	typedef llvm::FunctionType ExternalType;
	typedef llvm::FunctionType* PointerToExternalType;

    public:
	PointerToExternalType wrapped() { return static_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	FunctionType_O() : Base() {};
	~FunctionType_O() {}
    public: // static methods
	static core::T_sp get(core::T_sp result_type, core::T_sp params, core::T_sp is_var_arg);
    }; // FunctionType_O
}; // llvmo
TRANSLATE(llvmo::FunctionType_O);
/* from_object translators */
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::FunctionType*>
    {
        static core::T_sp convert(llvm::FunctionType* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::FunctionType_O,llvm::FunctionType*>(ptr)));};
    };
    template <>
    struct from_object<llvm::FunctionType*,std::true_type>
    {
	typedef llvm::FunctionType* DeclareType;
	DeclareType _v;
	from_object(T_P object) {
	    this->_v = static_cast<llvm::FunctionType*>(object.as<llvmo::FunctionType_O>()->wrappedPtr());
	}
    };

};
;








namespace llvmo
{
    FORWARD(IntegerType);
    class IntegerType_O : public Type_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::IntegerType,IntegerType_O,"INTEGER-TYPE",Type_O);
	typedef llvm::IntegerType ExternalType;
	typedef llvm::IntegerType* PointerToExternalType;

    public:
	PointerToExternalType wrapped() { return static_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	IntegerType_O() : Base() {};
	~IntegerType_O() {}
    public: // static methods
	static core::T_sp get(core::T_sp result_type, core::T_sp params, core::T_sp is_var_arg);
    }; // IntegerType_O
}; // llvmo
TRANSLATE(llvmo::IntegerType_O);
/* from_object translators */
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::IntegerType*>
    {
        static core::T_sp convert(llvm::IntegerType* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::IntegerType_O,llvm::IntegerType*>(ptr)));};
    };
    template <>
    struct from_object<llvm::IntegerType*,std::true_type>
    {
	typedef llvm::IntegerType* DeclareType;
	DeclareType _v;
	from_object(T_P object) {
	    this->_v = static_cast<llvm::IntegerType*>(object.as<llvmo::IntegerType_O>()->wrappedPtr());
	}
    };

};
;




namespace llvmo
{
    FORWARD(CompositeType);
    class CompositeType_O : public Type_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::CompositeType,CompositeType_O,"CompositeType",Type_O);
	typedef llvm::CompositeType ExternalType;
	typedef llvm::CompositeType* PointerToExternalType;

    public:
	PointerToExternalType wrapped() { return static_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	CompositeType_O() : Base() {};
	~CompositeType_O() {}
    public: // static methods
	static core::T_sp get(core::T_sp result_type, core::T_sp params, core::T_sp is_var_arg);
    }; // CompositeType_O
}; // llvmo
TRANSLATE(llvmo::CompositeType_O);
/* from_object translators */
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::CompositeType*>
    {
        static core::T_sp convert(llvm::CompositeType* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::CompositeType_O,llvm::CompositeType*>(ptr)));};
    };
    template <>
    struct from_object<llvm::CompositeType*,std::true_type>
    {
	typedef llvm::CompositeType* DeclareType;
	DeclareType _v;
	from_object(T_P object) {
	    this->_v = static_cast<llvm::CompositeType*>(object.as<llvmo::CompositeType_O>()->wrappedPtr());
	}
    };

};
;









namespace llvmo
{
    FORWARD(StructType);
    class StructType_O : public CompositeType_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::StructType,StructType_O,"StructType",CompositeType_O);
	typedef llvm::StructType ExternalType;
	typedef llvm::StructType* PointerToExternalType;

    public:
	PointerToExternalType wrapped() { return static_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	StructType_O() : Base() {};
	~StructType_O() {}
    public: // static methods
	/*! Get a structure using llvm:StructType::create(LLVMContext& context, ArrayRef<Type*>Elements,StringRef name,bool isPacked) */
	static StructType_sp make(LLVMContext_sp context, core::T_sp elements, core::Str_sp name, core::T_sp isPacked);

	static StructType_sp get(LLVMContext_sp context, core::T_sp elements, bool isPacked=false);
    public:
	void setBody(core::T_sp elements, core::T_sp isPacked);
    }; // StructType_O
}; // llvmo
TRANSLATE(llvmo::StructType_O);
/* from_object translators */
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::StructType*>
    {
        static llvmo::StructType_mv convert(llvm::StructType* ptr)
        {_G(); return(Values(core::RP_Create_wrapped<llvmo::StructType_O,llvm::StructType*>(ptr)));};
    };
    template <>
    struct from_object<llvm::StructType*,std::true_type>
    {
	typedef llvm::StructType* DeclareType;
	DeclareType _v;
	from_object(T_P object) {
	    this->_v = static_cast<llvm::StructType*>(object.as<llvmo::StructType_O>()->wrappedPtr());
	}
    };

};
;





namespace llvmo
{
    FORWARD(SequentialType);
    class SequentialType_O : public CompositeType_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::SequentialType,SequentialType_O,"SequentialType",CompositeType_O);
	typedef llvm::SequentialType ExternalType;
	typedef llvm::SequentialType* PointerToExternalType;

    public:
	PointerToExternalType wrapped() { return static_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	SequentialType_O() : Base() {};
	~SequentialType_O() {}
    public: // static methods
	static core::T_sp get(core::T_sp result_type, core::T_sp params, core::T_sp is_var_arg);
    }; // SequentialType_O
}; // llvmo
TRANSLATE(llvmo::SequentialType_O);
/* from_object translators */
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::SequentialType*>
    {
        static core::T_sp convert(llvm::SequentialType* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::SequentialType_O,llvm::SequentialType*>(ptr)));};
    };
    template <>
    struct from_object<llvm::SequentialType*,std::true_type>
    {
	typedef llvm::SequentialType* DeclareType;
	DeclareType _v;
	from_object(T_P object) {
	    this->_v = static_cast<llvm::SequentialType*>(object.as<llvmo::SequentialType_O>()->wrappedPtr());
	}
    };

};
;









namespace llvmo
{
    FORWARD(PointerType);
    class PointerType_O : public SequentialType_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::PointerType,PointerType_O,"PointerType",SequentialType_O);
	typedef llvm::PointerType ExternalType;
	typedef llvm::PointerType* PointerToExternalType;

    public:
	PointerToExternalType wrapped() { return static_cast<PointerToExternalType>(this->_ptr);};
	void set_wrapped(PointerToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	PointerType_O() : Base() {};
	~PointerType_O() {}
    public: // static methods
//	static core::T_sp get(core::T_sp result_type, core::T_sp params, core::T_sp is_var_arg);
    public: // static methods
	static PointerType_sp get(Type_sp elementType, uint addressSpace);

    }; // PointerType_O
}; // llvmo
TRANSLATE(llvmo::PointerType_O);
/* from_object translators */
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::PointerType*>
    {
        static llvmo::PointerType_mv convert(llvm::PointerType* ptr)
        {_G(); return(Values(core::RP_Create_wrapped<llvmo::PointerType_O,llvm::PointerType*>(ptr)));};
    };
    template <>
    struct from_object<llvm::PointerType*,std::true_type>
    {
	typedef llvm::PointerType* DeclareType;
	DeclareType _v;
	from_object(T_P object) {
	    this->_v = static_cast<llvm::PointerType*>(object.as<llvmo::PointerType_O>()->wrappedPtr());
	}
    };

};
;







namespace llvmo
{
    FORWARD(ArrayType);
    class ArrayType_O : public SequentialType_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::ArrayType,ArrayType_O,"ArrayType",SequentialType_O);
	typedef llvm::ArrayType ExternalType;
	typedef llvm::ArrayType* ArrayToExternalType;

    public:
	ArrayToExternalType wrapped() { return static_cast<ArrayToExternalType>(this->_ptr);};
	void set_wrapped(ArrayToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	ArrayType_O() : Base() {};
	~ArrayType_O() {}
    public: // static methods
	static ArrayType_sp get(Type_sp elementType, uint64_t numElements);
    }; // ArrayType_O
}; // llvmo
TRANSLATE(llvmo::ArrayType_O);
/* from_object translators */
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::ArrayType*>
    {
        static core::T_sp convert(llvm::ArrayType* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::ArrayType_O,llvm::ArrayType*>(ptr)));};
    };
    template <>
    struct from_object<llvm::ArrayType*,std::true_type>
    {
	typedef llvm::ArrayType* DeclareType;
	DeclareType _v;
	from_object(T_P object) {
	    this->_v = static_cast<llvm::ArrayType*>(object.as<llvmo::ArrayType_O>()->wrappedPtr());
	}
    };

};
;




namespace llvmo
{
    FORWARD(VectorType);
    class VectorType_O : public SequentialType_O
    {
	LISP_EXTERNAL_CLASS(llvmo,LlvmoPkg,llvm::VectorType,VectorType_O,"VectorType",SequentialType_O);
	typedef llvm::VectorType ExternalType;
	typedef llvm::VectorType* VectorToExternalType;

    public:
	VectorToExternalType wrapped() { return static_cast<VectorToExternalType>(this->_ptr);};
	void set_wrapped(VectorToExternalType ptr)
	{
/*        if (this->_ptr != NULL ) delete this->_ptr; */
	    this->_ptr = ptr;
	}
	VectorType_O() : Base() {};
	~VectorType_O() {}
    public: // static methods
	static core::T_sp get(core::T_sp result_type, core::T_sp params, core::T_sp is_var_arg);
    }; // VectorType_O
}; // llvmo
TRANSLATE(llvmo::VectorType_O);
/* from_object translators */
/* to_object translators */

namespace translate
{
    template <>
    struct to_object<llvm::VectorType*>
    {
        static core::T_sp convert(llvm::VectorType* ptr)
        {_G(); return(( core::RP_Create_wrapped<llvmo::VectorType_O,llvm::VectorType*>(ptr)));};
    };
    template <>
    struct from_object<llvm::VectorType*,std::true_type>
    {
	typedef llvm::VectorType* DeclareType;
	DeclareType _v;
	from_object(T_P object) {
	    this->_v = static_cast<llvm::VectorType*>(object.as<llvmo::VectorType_O>()->wrappedPtr());
	}
    };

};




















namespace translate
{


    template <>
    struct from_object<const llvm::StringRef,std::true_type>
    {
	typedef llvm::StringRef DeclareType;
	DeclareType _v;
	string _Storage;
	from_object(T_P object)
	{
	    this->_Storage = object.as<core::Str_O>()->get();
	    this->_v = llvm::StringRef(this->_Storage);
	}
    };




    template <>
    struct from_object<llvm::GlobalValue::LinkageTypes,std::true_type>
    {
	typedef llvm::GlobalValue::LinkageTypes	DeclareType;
	DeclareType _v;
	from_object(T_P object)
	{_G();
	    if ( core::Symbol_sp sym = object.asOrNull<core::Symbol_O>() )
	    {
		core::SymbolToEnumConverter_sp converter = llvmo::_sym_STARglobal_value_linkage_typesSTAR->symbolValue().as<core::SymbolToEnumConverter_O>();
		this->_v = converter->enumForSymbol<llvm::GlobalValue::LinkageTypes>(sym);
		return;
	    }
	    SIMPLE_ERROR(BF("Cannot convert object %s to llvm::GlobalValue::LinkageType") % _rep_(object) );
	}
    };


#if 0
    template <>
    struct from_object<llvm::VerifierFailureAction,std::true_type>
    {
	typedef llvm::VerifierFailureAction	DeclareType;
	DeclareType _v;
	from_object(T_P object)
	{_G();
	    if ( core::Symbol_sp sym = object.asOrNull<core::Symbol_O>() )
	    {
		core::SymbolToEnumConverter_sp converter = llvmo::_sym_STARverifier_failure_actionsSTAR->symbolValue().as<core::SymbolToEnumConverter_O>();
		this->_v = converter->enumForSymbol<llvm::VerifierFailureAction>(sym);
		return;
	    }
	    SIMPLE_ERROR(BF("Cannot convert object %s to llvm::VerifierFailureAction") % _rep_(object) );
	}
    };
#endif


    template <>
    struct from_object<llvm::AtomicOrdering,std::true_type>
    {
	typedef llvm::AtomicOrdering	DeclareType;
	DeclareType _v;
	from_object(T_P object)
	{_G();
	    if ( core::Symbol_sp sym = object.asOrNull<core::Symbol_O>() )
	    {
		core::SymbolToEnumConverter_sp converter = llvmo::_sym_STARatomic_orderingSTAR->symbolValue().as<core::SymbolToEnumConverter_O>();
		this->_v = converter->enumForSymbol<llvm::AtomicOrdering>(sym);
		return;
	    }
	    SIMPLE_ERROR(BF("Cannot convert object %s to llvm::AtomicOrdering") % _rep_(object) );
	}
    };



    template <>
    struct from_object<llvm::SynchronizationScope,std::true_type>
    {
	typedef llvm::SynchronizationScope	DeclareType;
	DeclareType _v;
	from_object(T_P object)
	{_G();
	    if ( core::Symbol_sp sym = object.asOrNull<core::Symbol_O>() )
	    {
		core::SymbolToEnumConverter_sp converter = llvmo::_sym_STARsynchronization_scopeSTAR->symbolValue().as<core::SymbolToEnumConverter_O>();
		this->_v = converter->enumForSymbol<llvm::SynchronizationScope>(sym);
		return;
	    }
	    SIMPLE_ERROR(BF("Cannot convert object %s to llvm::SynchronizationScope") % _rep_(object) );
	}
    };



    template <>
    struct from_object<llvm::AtomicRMWInst::BinOp,std::true_type>
    {
	typedef llvm::AtomicRMWInst::BinOp	DeclareType;
	DeclareType _v;
	from_object(T_P object)
	{_G();
	    if ( core::Symbol_sp sym = object.asOrNull<core::Symbol_O>() )
	    {
		core::SymbolToEnumConverter_sp converter = llvmo::_sym_STARAtomicRMWInstBinOpSTAR->symbolValue().as<core::SymbolToEnumConverter_O>();
		this->_v = converter->enumForSymbol<llvm::AtomicRMWInst::BinOp>(sym);
		return;
	    }
	    SIMPLE_ERROR(BF("Cannot convert object %s to llvm::AtomicRMWInst::BinOp") % _rep_(object) );
	}
    };



    template <>
    struct from_object<llvm::Instruction::CastOps,std::true_type>
    {
	typedef llvm::Instruction::CastOps	DeclareType;
	DeclareType _v;
	from_object(T_P object)
	{_G();
	    if ( core::Symbol_sp sym = object.asOrNull<core::Symbol_O>() )
	    {
		core::SymbolToEnumConverter_sp converter = llvmo::_sym_STARInstructionCastOpsSTAR->symbolValue().as<core::SymbolToEnumConverter_O>();
		this->_v = converter->enumForSymbol<llvm::Instruction::CastOps>(sym);
		return;
	    }
	    SIMPLE_ERROR(BF("Cannot convert object %s to llvm::Instruction::CastOps") % _rep_(object) );
	}
    };

    template <>
    struct from_object<llvm::Instruction::BinaryOps,std::true_type>
    {
	typedef llvm::Instruction::BinaryOps	DeclareType;
	DeclareType _v;
	from_object(T_P object)
	{_G();
	    if ( core::Symbol_sp sym = object.asOrNull<core::Symbol_O>() )
	    {
		core::SymbolToEnumConverter_sp converter = llvmo::_sym_STARBinaryOpsSTAR->symbolValue().as<core::SymbolToEnumConverter_O>();
		this->_v = converter->enumForSymbol<llvm::Instruction::BinaryOps>(sym);
		return;
	    }
	    SIMPLE_ERROR(BF("Cannot convert object %s to llvm::Instruction::BinaryOps") % _rep_(object) );
	}
    };



    template <>
    struct from_object<llvm::CmpInst::Predicate,std::true_type>
    {
	typedef llvm::CmpInst::Predicate	DeclareType;
	DeclareType _v;
	from_object(T_P object)
	{_G();
	    if ( core::Symbol_sp sym = object.asOrNull<core::Symbol_O>() )
	    {
		core::SymbolToEnumConverter_sp converter = llvmo::_sym_STARCmpInstPredicateSTAR->symbolValue().as<core::SymbolToEnumConverter_O>();
		this->_v = converter->enumForSymbol<llvm::CmpInst::Predicate>(sym);
		return;
	    }
	    SIMPLE_ERROR(BF("Cannot convert object %s to llvm::CmpInst::Predicate") % _rep_(object) );
	}
    };

};




namespace llvmo
{

    void initialize_llvmo_expose();
}


#endif //]
