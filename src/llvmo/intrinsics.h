#ifndef	llvmo_primitives_H
#define llvmo_primitives_H

extern "C"
{

    typedef void (*fnTmvActivationFramesp)(core::T_mv*, core::ActivationFrame_sp*, int nargs, ArgArray args);
    typedef void (*fnVoidType)();


    class  JITClosure : public core::FunctionClosure
    {
    protected:
	fnTmvActivationFramesp	_FuncPtr;
    public:
	// By default the zeroth argument is dispatched on
	explicit JITClosure(core::T_sp name,fnTmvActivationFramesp fptr) : FunctionClosure(name), _FuncPtr(fptr) {};
        DISABLE_NEW();
        virtual size_t templatedSizeof() const { return sizeof(*this);};
	virtual string describe() const {return "JITClosure";};
	void LISP_CALLING_CONVENTION()
	{
            IMPLEMENT_MEF(BF("Handle LISP_CALLING_CONVENTION"));
#if 0
	    core::T_mv result;
	    core::ActivationFrame_sp tclosedEnv(closedEnv);
	    this->_FuncPtr(&result,&tclosedEnv,nargs, args);
	    return result;
#endif
	}
    };



};




namespace llvmo
{

    void redirect_llvm_interface_addSymbol();

    void initialize_intrinsics();
}

#endif
