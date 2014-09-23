/*
    File: symbols_scraped_inc.h
*/

/*
Copyright (c) 2014, Christian E. Schafmeister
 
CLASP is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.
 
See file 'clasp/Copyright' for full details.
 
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
// Symbol table
#include "cffi_scrape_flag.h"
// SYMBOL_TABLE_ENTRY      CffiPkg    0 unsigned_long_long             UNSIGNED-LONG-LONG             private ; cName=_sym_unsigned_long_long lispName=UNSIGNED-LONG-LONG
// SYMBOL_TABLE_ENTRY      CffiPkg    1 unsigned_int                   UNSIGNED-INT                   private ; cName=_sym_unsigned_int lispName=UNSIGNED-INT
// SYMBOL_TABLE_ENTRY      CffiPkg    2 PERCENTmem_ref                 %MEM-REF                       private ; cName=_sym_PERCENTmem_ref lispName=%MEM-REF
// SYMBOL_TABLE_ENTRY      CffiPkg    3 uint64                         UINT64                         private ; cName=_sym_uint64 lispName=UINT64
// SYMBOL_TABLE_ENTRY      CffiPkg    4 double                         DOUBLE                         private ; cName=_sym_double lispName=DOUBLE
// SYMBOL_TABLE_ENTRY      CffiPkg    5 foreign_symbol_pointer         FOREIGN-SYMBOL-POINTER         export ; cName=_sym_foreign_symbol_pointer lispName=FOREIGN-SYMBOL-POINTER
// SYMBOL_TABLE_ENTRY      CffiPkg    6 int16                          INT16                          private ; cName=_sym_int16 lispName=INT16
// SYMBOL_TABLE_ENTRY      CffiPkg    7 long_long                      LONG-LONG                      private ; cName=_sym_long_long lispName=LONG-LONG
// SYMBOL_TABLE_ENTRY      CffiPkg    8 unsigned_long                  UNSIGNED-LONG                  private ; cName=_sym_unsigned_long lispName=UNSIGNED-LONG
// SYMBOL_TABLE_ENTRY      CffiPkg    9 int32                          INT32                          private ; cName=_sym_int32 lispName=INT32
// SYMBOL_TABLE_ENTRY      CffiPkg   10 PERCENTforeign_type_alignment  %FOREIGN-TYPE-ALIGNMENT        export ; cName=_sym_PERCENTforeign_type_alignment lispName=%FOREIGN-TYPE-ALIGNMENT
// SYMBOL_TABLE_ENTRY      CffiPkg   11 float                          FLOAT                          private ; cName=_sym_float lispName=FLOAT
// SYMBOL_TABLE_ENTRY      CffiPkg   12 PERCENTload_foreign_library    %LOAD-FOREIGN-LIBRARY          export ; cName=_sym_PERCENTload_foreign_library lispName=%LOAD-FOREIGN-LIBRARY
// SYMBOL_TABLE_ENTRY      CffiPkg   13 char                           CHAR                           private ; cName=_sym_char lispName=CHAR
// SYMBOL_TABLE_ENTRY      CffiPkg   14 pointer                        POINTER                        private ; cName=_sym_pointer lispName=POINTER
// SYMBOL_TABLE_ENTRY      CffiPkg   15 Pointer_O                      POINTER                        export ; cName=_sym_Pointer_O lispName=POINTER
// SYMBOL_TABLE_ENTRY      CffiPkg   16 time                           TIME                           private ; cName=_sym_time lispName=TIME
// SYMBOL_TABLE_ENTRY      CffiPkg   17 size                           SIZE                           private ; cName=_sym_size lispName=SIZE
// SYMBOL_TABLE_ENTRY      CffiPkg   18 foreign_alloc                  FOREIGN-ALLOC                  export ; cName=_sym_foreign_alloc lispName=FOREIGN-ALLOC
// SYMBOL_TABLE_ENTRY      CffiPkg   19 uint16                         UINT16                         private ; cName=_sym_uint16 lispName=UINT16
// SYMBOL_TABLE_ENTRY      CffiPkg   20 ssize                          SSIZE                          private ; cName=_sym_ssize lispName=SSIZE
// SYMBOL_TABLE_ENTRY      CffiPkg   21 ptrdiff                        PTRDIFF                        private ; cName=_sym_ptrdiff lispName=PTRDIFF
// SYMBOL_TABLE_ENTRY      CffiPkg   22 short                          SHORT                          private ; cName=_sym_short lispName=SHORT
// SYMBOL_TABLE_ENTRY      CffiPkg   23 int8                           INT8                           private ; cName=_sym_int8 lispName=INT8
// SYMBOL_TABLE_ENTRY      CffiPkg   24 void                           VOID                           private ; cName=_sym_void lispName=VOID
// SYMBOL_TABLE_ENTRY      CffiPkg   25 uint32                         UINT32                         private ; cName=_sym_uint32 lispName=UINT32
// SYMBOL_TABLE_ENTRY      CffiPkg   26 uint8                          UINT8                          private ; cName=_sym_uint8 lispName=UINT8
// SYMBOL_TABLE_ENTRY      CffiPkg   27 unsigned_short                 UNSIGNED-SHORT                 private ; cName=_sym_unsigned_short lispName=UNSIGNED-SHORT
// SYMBOL_TABLE_ENTRY      CffiPkg   28 int                            INT                            private ; cName=_sym_int lispName=INT
// SYMBOL_TABLE_ENTRY      CffiPkg   29 int64                          INT64                          private ; cName=_sym_int64 lispName=INT64
// SYMBOL_TABLE_ENTRY      CffiPkg   30 long                           LONG                           private ; cName=_sym_long lispName=LONG
// SYMBOL_TABLE_ENTRY      CffiPkg   31 PERCENTforeign_type_size       %FOREIGN-TYPE-SIZE             export ; cName=_sym_PERCENTforeign_type_size lispName=%FOREIGN-TYPE-SIZE
// SYMBOL_TABLE_ENTRY      CffiPkg   32 unsigned_char                  UNSIGNED-CHAR                  private ; cName=_sym_unsigned_char lispName=UNSIGNED-CHAR
// SYMBOL_TABLE_ENTRY      CffiPkg   33 PERCENTsetf_mem_ref            %SETF-MEM-REF                  private ; cName=_sym_PERCENTsetf_mem_ref lispName=%SETF-MEM-REF
#ifdef CffiPkg_SYMBOLS
DO_SYMBOL(_sym_unsigned_long_long,0,CffiPkg,"UNSIGNED-LONG-LONG",false);
DO_SYMBOL(_sym_unsigned_int,1,CffiPkg,"UNSIGNED-INT",false);
DO_SYMBOL(_sym_PERCENTmem_ref,2,CffiPkg,"%MEM-REF",false);
DO_SYMBOL(_sym_uint64,3,CffiPkg,"UINT64",false);
DO_SYMBOL(_sym_double,4,CffiPkg,"DOUBLE",false);
DO_SYMBOL(_sym_foreign_symbol_pointer,5,CffiPkg,"FOREIGN-SYMBOL-POINTER",true);
DO_SYMBOL(_sym_int16,6,CffiPkg,"INT16",false);
DO_SYMBOL(_sym_long_long,7,CffiPkg,"LONG-LONG",false);
DO_SYMBOL(_sym_unsigned_long,8,CffiPkg,"UNSIGNED-LONG",false);
DO_SYMBOL(_sym_int32,9,CffiPkg,"INT32",false);
DO_SYMBOL(_sym_PERCENTforeign_type_alignment,10,CffiPkg,"%FOREIGN-TYPE-ALIGNMENT",true);
DO_SYMBOL(_sym_float,11,CffiPkg,"FLOAT",false);
DO_SYMBOL(_sym_PERCENTload_foreign_library,12,CffiPkg,"%LOAD-FOREIGN-LIBRARY",true);
DO_SYMBOL(_sym_char,13,CffiPkg,"CHAR",false);
DO_SYMBOL(_sym_pointer,14,CffiPkg,"POINTER",false);
DO_SYMBOL(_sym_Pointer_O,15,CffiPkg,"POINTER",true);
DO_SYMBOL(_sym_time,16,CffiPkg,"TIME",false);
DO_SYMBOL(_sym_size,17,CffiPkg,"SIZE",false);
DO_SYMBOL(_sym_foreign_alloc,18,CffiPkg,"FOREIGN-ALLOC",true);
DO_SYMBOL(_sym_uint16,19,CffiPkg,"UINT16",false);
DO_SYMBOL(_sym_ssize,20,CffiPkg,"SSIZE",false);
DO_SYMBOL(_sym_ptrdiff,21,CffiPkg,"PTRDIFF",false);
DO_SYMBOL(_sym_short,22,CffiPkg,"SHORT",false);
DO_SYMBOL(_sym_int8,23,CffiPkg,"INT8",false);
DO_SYMBOL(_sym_void,24,CffiPkg,"VOID",false);
DO_SYMBOL(_sym_uint32,25,CffiPkg,"UINT32",false);
DO_SYMBOL(_sym_uint8,26,CffiPkg,"UINT8",false);
DO_SYMBOL(_sym_unsigned_short,27,CffiPkg,"UNSIGNED-SHORT",false);
DO_SYMBOL(_sym_int,28,CffiPkg,"INT",false);
DO_SYMBOL(_sym_int64,29,CffiPkg,"INT64",false);
DO_SYMBOL(_sym_long,30,CffiPkg,"LONG",false);
DO_SYMBOL(_sym_PERCENTforeign_type_size,31,CffiPkg,"%FOREIGN-TYPE-SIZE",true);
DO_SYMBOL(_sym_unsigned_char,32,CffiPkg,"UNSIGNED-CHAR",false);
DO_SYMBOL(_sym_PERCENTsetf_mem_ref,33,CffiPkg,"%SETF-MEM-REF",false);
#endif
