#ifndef	_core_Null_H
#define _core_Null_H

#include "core/foundation.h"
#include "symbol.h"
#include "lispList.h"


namespace core
{

    FORWARD(Null);
    class Null_O : public Symbol_O
    {
	LISP_BASE1(Symbol_O); // ,List_O);
	LISP_CLASS(core,ClPkg,Null_O,"null");
	DECLARE_INIT();
#if defined(XML_ARCHIVE)
	DECLARE_ARCHIVE();
#endif // defined(XML_ARCHIVE)
    public: // ctor/dtor for classes with shared virtual base
	explicit Null_O() : Symbol_O() {}; // List_O
	virtual ~Null_O() {};
    public:
	void initialize();

    public: // Functions here
	string __repr__() const;
    };

}; /* core */

TRANSLATE(core::Null_O);


#endif /* _core_Null_H */


