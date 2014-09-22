#ifndef _llvmo_translators_H
#define _llvmo_translators_H


#include <llvm/ADT/StringRef.h>
#include <llvm/ADT/Twine.h>
#include <llvm/ADT/ArrayRef.h>
#include <llvm/IR/DebugInfo.h>
#include <llvm/IR/DIBuilder.h>
#include "core/symbolTable.h"
#include <core/str.h>
#include "llvmo/llvmoExpose.fwd.h"


namespace translate {

    template<>
    struct from_object<llvm::StringRef,std::true_type>
    {
        typedef llvm::StringRef DeclareType;
	string _Storage; // Store the string here so it won't get wiped out before its used by the callee
        DeclareType _v;;
	from_object(T_P o) : _Storage(o.as<core::Str_O>()->get()), _v(llvm::StringRef(this->_Storage)) {};
    };


    template<>
    struct from_object<const llvm::Twine&>
    {
        typedef llvm::Twine DeclareType;
	string _Storage; // Store the string here so it won't get wiped out before its used by the callee
        DeclareType _v;;
	from_object(T_P o) : _Storage(o.as<core::Str_O>()->get()), _v(llvm::Twine(this->_Storage)) {};
    };


    template <>
    struct to_object<const llvm::StringRef&>
    {
	static core::T_sp convert(llvm::StringRef const& sr)
	{_G(); return(Values( core::Str_O::create(sr.data()))); }
    };


    template <>
    struct to_object<llvm::StringRef&>
    {
	static core::T_sp convert(llvm::StringRef & sr)
	{return core::Str_O::create(sr.data()); }
    };

    template <>
    struct to_object<llvm::StringRef>
    {
	static core::T_sp convert(const llvm::StringRef & sr)
	{return core::Str_O::create(sr.data(),sr.size()); }
    };




    template <>
    struct from_object<llvm::DIBuilder::DebugEmissionKind>
    {
        typedef llvm::DIBuilder::DebugEmissionKind DeclareType;
        DeclareType _v;
        from_object(core::T_sp o) {
            if ( o.nilp() ) {
                goto INVALID;
            }
            if ( o.isA<core::Symbol_O>() ) {
                core::Symbol_sp sym = o.as<core::Symbol_O>();
                if ( sym == kw::_sym_FullDebug ) {
                    this->_v = llvm::DIBuilder::FullDebug;
                    return;
                } else if ( sym == kw::_sym_LineTablesOnly ) {
                    this->_v = llvm::DIBuilder::LineTablesOnly;
                    return;
                }
            }
        INVALID:
            SIMPLE_ERROR(BF("You must pass :full-debug or :line-tables-only, only those are valid DebugEmissionKind"));
        }
    };



    template <>
    struct from_object<llvm::ArrayRef<std::string> > {
        typedef std::vector<std::string> DeclareType;
        DeclareType _v;
        from_object(core::T_sp o) {
            if ( o.nilp() ) {
                _v.clear();
                return;
            } else if ( core::Cons_sp cstrs = o.asOrNull<core::Cons_O>() ) {
                for ( ; cstrs.notnilp(); cstrs=cCdr(cstrs) ) {
                    core::Str_sp s = core::oCar(cstrs).as<core::Str_O>();
                    _v.push_back(std::string(s->get()));
                }
                return;
            } else if ( core::Vector_sp vstrs = o.asOrNull<core::Vector_O>() ) {
                _v.resize(vstrs->length());
                for (int i(0),iEnd(vstrs->length()); i<iEnd; ++i ) {
                    _v[i] = vstrs->elt(i).as<core::Str_O>()->get();
                }
                return;
            }
            SIMPLE_ERROR(BF("Could not convert %s to llvm::ArrayRef<std::string>") % core::_rep_(o));
        }
    };







};
#endif
