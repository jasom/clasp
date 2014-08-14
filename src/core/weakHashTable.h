#ifndef	_core_WeakHashTable_H
#define _core_WeakHashTable_H

#include "core/foundation.h"
#include "core/object.h"
#include "gctools/gcweak.h"
#include "hashTable.h"
#include "symbolTable.h"
#include "corePackage.fwd.h"

namespace core
{

    FORWARD(WeakHashTable);
    class WeakHashTable_O : public T_O
    {
	LISP_BASE1(T_O);
	LISP_CLASS(core,CorePkg,WeakHashTable_O,"WeakHashTable");
#if defined(XML_ARCHIVE)
	DECLARE_ARCHIVE();
#endif // defined(XML_ARCHIVE)
	DEFAULT_CTOR_DTOR(WeakHashTable_O);
    private: // instance variables here

    public: // Functions here


    };

}; /* core */
template<> struct gctools::GCInfo<core::WeakHashTable_O> {
    static bool constexpr NeedsInitialization = false;
    static bool constexpr NeedsFinalization = false;
    static bool constexpr Moveable = true;
    static bool constexpr Atomic = false;
};

TRANSLATE(core::WeakHashTable_O);



namespace core
{

    FORWARD(WeakKeyHashTable);
    class WeakKeyHashTable_O : public WeakHashTable_O
    {
	LISP_BASE1(WeakHashTable_O);
	LISP_CLASS(core,CorePkg,WeakKeyHashTable_O,"WeakKeyHashTable");
#if defined(XML_ARCHIVE)
	DECLARE_ARCHIVE();
#endif // defined(XML_ARCHIVE)
    public: // instance variables here
#if 1
        typedef typename gctools::WeakHashTable::value_type value_type;
        typedef typename gctools::WeakHashTable::KeyBucketsType KeyBucketsType;
        typedef typename gctools::WeakHashTable::ValueBucketsType ValueBucketsType;
        typedef typename gctools::WeakHashTable::KeyBucketsAllocatorType KeyBucketsAllocatorType;
        typedef typename gctools::WeakHashTable::ValueBucketsAllocatorType ValueBucketsAllocatorType;
        typedef gctools::WeakHashTable  HashTableType;
#else
        typedef gctools::tagged_backcastable_base_ptr<T_O> value_type;
        typedef gctools::Buckets<value_type,value_type,gctools::WeakLinks> KeyBucketsType;
        typedef gctools::Buckets<value_type,value_type,gctools::StrongLinks> ValueBucketsType;
        typedef gctools::GCBucketAllocator<KeyBucketsType> KeyBucketsAllocatorType;
        typedef gctools::GCBucketAllocator<ValueBucketsType> ValueBucketsAllocatorType;
        typedef gctools::WeakHashTable<KeyBucketsType,ValueBucketsType> HashTableType;
#endif
        HashTableType  _HashTable;
        
    public:
        WeakKeyHashTable_O() : _HashTable(16) {};
        WeakKeyHashTable_O(uint sz) : _HashTable(sz) {};
    public:
//	static WeakKeyHashTable_sp make(uint sz ); // ,  Number_sp rehashSize, double rehashThreshold);
        static WeakKeyHashTable_sp create_default();
    public:
        virtual int tableSize() const;

        void set( T_sp key, T_sp value );

        bool fullp();


        void describe(); 
	virtual T_sp hashTableTest() const { return cl::_sym_eq;};
	bool keyTest(T_sp entryKey, T_sp searchKey) const;

	int sxhashKey(T_sp key,int bound, bool willAddKey) const;

        T_mv gethash(T_sp key, T_sp defaultValue=_Nil<T_O>());
	void remhash(T_sp key);
	void clrhash();


    };
}; /* core */
template<> struct gctools::GCInfo<core::WeakKeyHashTable_O> {
    static bool constexpr NeedsInitialization = false;
    static bool constexpr NeedsFinalization = false;
    static bool constexpr Moveable = true;
    static bool constexpr Atomic = false;
};

TRANSLATE(core::WeakKeyHashTable_O);





#endif /* _core_WeakHashTable_H */


