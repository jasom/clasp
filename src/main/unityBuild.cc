/*
    File: unityBuild.cc
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
#include "/Users/meister/Development/cando/brcl/src/core/evaluator.cc"
#include "/Users/meister/Development/cando/brcl/src/core/lispList.cc"
#include "/Users/meister/Development/cando/brcl/src/core/executables.cc"
#include "/Users/meister/Development/cando/brcl/src/core/object.cc"
#include "/Users/meister/Development/cando/brcl/src/core/documentation.cc"
#include "/Users/meister/Development/cando/brcl/src/core/compPackage.cc"
#include "/Users/meister/Development/cando/brcl/src/core/closPackage.cc"
#include "/Users/meister/Development/cando/brcl/src/core/vectorObjects.cc"
#include "/Users/meister/Development/cando/brcl/src/core/loadTimeValues.cc"
#include "/Users/meister/Development/cando/brcl/src/core/funcallableStandardClass.cc"
#include "/Users/meister/Development/cando/brcl/src/core/sexpLoadArchive.cc"
#include "/Users/meister/Development/cando/brcl/src/core/genericFunction.cc"
#include "/Users/meister/Development/cando/brcl/src/core/debugger.cc"
#include "/Users/meister/Development/cando/brcl/src/clbind/link_compatibility.cc"
#include "/Users/meister/Development/cando/brcl/src/core/print.cc"
#include "/Users/meister/Development/cando/brcl/src/core/profile.cc"
#include "/Users/meister/Development/cando/brcl/src/asttooling/Diagnostics.cc"
#include "/Users/meister/Development/cando/brcl/src/core/corePackage.cc"
#include "/Users/meister/Development/cando/brcl/src/core/singleDispatchGenericFunction.cc"
#include "/Users/meister/Development/cando/brcl/src/llvmo/llvmoPackage.cc"
#include "/Users/meister/Development/cando/brcl/src/clbind/open.cc"
#include "/Users/meister/Development/cando/brcl/src/asttooling/clangTooling.cc"
#include "/Users/meister/Development/cando/brcl/src/core/activationFrame.cc"
#include "/Users/meister/Development/cando/brcl/src/core/pointer.cc"
#include "/Users/meister/Development/cando/brcl/src/core/globals.cc"
#include "/Users/meister/Development/cando/brcl/src/core/symbolVector.cc"
#include "/Users/meister/Development/cando/brcl/src/asttooling/asttoolingPackage.cc"
#include "/Users/meister/Development/cando/brcl/src/core/primitives.cc"
#include "/Users/meister/Development/cando/brcl/src/clbind/inheritance.cc"
#include "/Users/meister/Development/cando/brcl/src/core/lispString.cc"
#include "/Users/meister/Development/cando/brcl/src/clbind/class_registry.cc"
#include "/Users/meister/Development/cando/brcl/src/core/strWithFillPtr.cc"
#include "/Users/meister/Development/cando/brcl/src/core/stringList.cc"
#include "/Users/meister/Development/cando/brcl/src/core/hashTableEqualp.cc"
#include "/Users/meister/Development/cando/brcl/src/core/python_wrappers.cc"
#include "/Users/meister/Development/cando/brcl/src/core/vectorObjectsWithFillPtr.cc"
#include "/Users/meister/Development/cando/brcl/src/core/lisp.cc"
#include "/Users/meister/Development/cando/brcl/src/core/lambdaListHandler.cc"
#include "/Users/meister/Development/cando/brcl/src/core/null.cc"
#include "/Users/meister/Development/cando/brcl/src/sockets/socketsPackage.cc"
#include "/Users/meister/Development/cando/brcl/src/clbind/class_rep.cc"
#include "/Users/meister/Development/cando/brcl/src/main/main.cc"
#include "/Users/meister/Development/cando/brcl/src/core/num_co.cc"
#include "/Users/meister/Development/cando/brcl/src/core/objectSet.cc"
#include "/Users/meister/Development/cando/brcl/src/core/stdClass.cc"
#include "/Users/meister/Development/cando/brcl/src/clbind/clbindPackage.cc"
#include "/Users/meister/Development/cando/brcl/src/core/symbolToEnumConverter.cc"
#include "/Users/meister/Development/cando/brcl/src/llvmo/intrinsics.cc"
#include "/Users/meister/Development/cando/brcl/src/core/arrayObjects.cc"
#include "/Users/meister/Development/cando/brcl/src/core/iterator.cc"
#include "/Users/meister/Development/cando/brcl/src/core/lispVector.cc"
#include "/Users/meister/Development/cando/brcl/src/core/commonLispUserPackage.cc"
#include "/Users/meister/Development/cando/brcl/src/core/hashTable.cc"
#include "/Users/meister/Development/cando/brcl/src/core/symbolList.cc"
#include "/Users/meister/Development/cando/brcl/src/core/commandLineOptions.cc"
#include "/Users/meister/Development/cando/brcl/src/core/cache.cc"
#include "/Users/meister/Development/cando/brcl/src/core/bitVector.cc"
#include "/Users/meister/Development/cando/brcl/src/core/arguments.cc"
#include "/Users/meister/Development/cando/brcl/src/core/candoOpenMp.cc"
#include "/Users/meister/Development/cando/brcl/src/core/profiler.cc"
#include "/Users/meister/Development/cando/brcl/src/asttooling/astVisitor.cc"
#include "/Users/meister/Development/cando/brcl/src/core/externalObject.cc"
#include "/Users/meister/Development/cando/brcl/src/core/compiler.cc"
#include "/Users/meister/Development/cando/brcl/src/core/sourceFileInfo.cc"
#include "/Users/meister/Development/cando/brcl/src/core/testing.cc"
#include "/Users/meister/Development/cando/brcl/src/core/stringSet.cc"
#include "/Users/meister/Development/cando/brcl/src/core/load.cc"
#include "/Users/meister/Development/cando/brcl/src/core/write_object.cc"
#include "/Users/meister/Development/cando/brcl/src/cffi/cffiPackage.cc"
#include "/Users/meister/Development/cando/brcl/src/core/lispDefinitions.cc"
#include "/Users/meister/Development/cando/brcl/src/core/lispStream.cc"
#include "/Users/meister/Development/cando/brcl/src/core/hashTableEqual.cc"
#include "/Users/meister/Development/cando/brcl/src/asttooling/testAST.cc"
#include "/Users/meister/Development/cando/brcl/src/core/structureObject.cc"
#include "/Users/meister/Development/cando/brcl/src/core/unixfsys.cc"
#include "/Users/meister/Development/cando/brcl/src/core/stacks.cc"
#include "/Users/meister/Development/cando/brcl/src/sockets/sockets.cc"
#include "/Users/meister/Development/cando/brcl/src/clbind/clbind.cc"
#include "/Users/meister/Development/cando/brcl/src/core/keywordPackage.cc"
#include "/Users/meister/Development/cando/brcl/src/core/model.cc"
#include "/Users/meister/Development/cando/brcl/src/core/reader.cc"
#include "/Users/meister/Development/cando/brcl/src/core/wrappedPointer.cc"
#include "/Users/meister/Development/cando/brcl/src/asttooling/astExpose.cc"
#include "/Users/meister/Development/cando/brcl/src/core/userData.cc"
#include "/Users/meister/Development/cando/brcl/src/core/smart_pointers.cc"
#include "/Users/meister/Development/cando/brcl/src/core/specializer.cc"
#include "/Users/meister/Development/cando/brcl/src/core/str.cc"
#include "/Users/meister/Development/cando/brcl/src/llvmo/llvmoExpose.cc"
#include "/Users/meister/Development/cando/brcl/src/llvmo/insertPoint.cc"
#include "/Users/meister/Development/cando/brcl/src/core/exceptions.cc"
#include "/Users/meister/Development/cando/brcl/src/core/symbolSet.cc"
#include "/Users/meister/Development/cando/brcl/src/serveEvent/serveEvent.cc"
#include "/Users/meister/Development/cando/brcl/src/core/numerics.cc"
#include "/Users/meister/Development/cando/brcl/src/core/structureClass.cc"
#include "/Users/meister/Development/cando/brcl/src/core/serialize.cc"
#include "/Users/meister/Development/cando/brcl/src/core/standardObject.cc"
#include "/Users/meister/Development/cando/brcl/src/core/myReadLine.cc"
#include "/Users/meister/Development/cando/brcl/src/core/write_ugly.cc"
#include "/Users/meister/Development/cando/brcl/src/core/character.cc"
#include "/Users/meister/Development/cando/brcl/src/llvmo/debugInfoExpose.cc"
#include "/Users/meister/Development/cando/brcl/src/core/sexpSaveArchive.cc"
#include "/Users/meister/Development/cando/brcl/src/serveEvent/serveEventPackage.cc"
#include "/Users/meister/Development/cando/brcl/src/asttooling/Registry.cc"
#include "/Users/meister/Development/cando/brcl/src/core/instance.cc"
#include "/Users/meister/Development/cando/brcl/src/core/symbol.cc"
#include "/Users/meister/Development/cando/brcl/src/core/microHeap.cc"
#include "/Users/meister/Development/cando/brcl/src/clbind/class.cc"
#include "/Users/meister/Development/cando/brcl/src/core/multipleValues.cc"
#include "/Users/meister/Development/cando/brcl/src/core/multiStringBuffer.cc"
#include "/Users/meister/Development/cando/brcl/src/core/metaobject.cc"
#include "/Users/meister/Development/cando/brcl/src/llvmo/llvmoDwarf.cc"
#include "/Users/meister/Development/cando/brcl/src/core/hashTableEq.cc"
#include "/Users/meister/Development/cando/brcl/src/core/numberToString.cc"
#include "/Users/meister/Development/cando/brcl/src/core/lispMath.cc"
#include "/Users/meister/Development/cando/brcl/src/core/write_list.cc"
#include "/Users/meister/Development/cando/brcl/src/core/num_arith.cc"
#include "/Users/meister/Development/cando/brcl/src/core/standardClass.cc"
#include "/Users/meister/Development/cando/brcl/src/gctools/memoryManagement.cc"
#include "/Users/meister/Development/cando/brcl/src/core/intArray.cc"
#include "/Users/meister/Development/cando/brcl/src/core/lispReader.cc"
#include "/Users/meister/Development/cando/brcl/src/core/package.cc"
#include "/Users/meister/Development/cando/brcl/src/core/commonLispPackage.cc"
#include "/Users/meister/Development/cando/brcl/src/core/hashTableEql.cc"
#include "/Users/meister/Development/cando/brcl/src/llvmo/irtests.cc"
#include "/Users/meister/Development/cando/brcl/src/core/posixTime.cc"
#include "/Users/meister/Development/cando/brcl/src/core/binder.cc"
#include "/Users/meister/Development/cando/brcl/src/core/environment.cc"
#include "/Users/meister/Development/cando/brcl/src/core/foundation.cc"
#include "/Users/meister/Development/cando/brcl/src/core/objRef.cc"
#include "/Users/meister/Development/cando/brcl/src/gctools/gctoolsPackage.cc"
#include "/Users/meister/Development/cando/brcl/src/core/conditions.cc"
#include "/Users/meister/Development/cando/brcl/src/core/regex.cc"
#include "/Users/meister/Development/cando/brcl/src/core/lightProfiler.cc"
#include "/Users/meister/Development/cando/brcl/src/core/forwardReferencedClass.cc"
#include "/Users/meister/Development/cando/brcl/src/core/grayPackage.cc"
#include "/Users/meister/Development/cando/brcl/src/core/backquote.cc"
#include "/Users/meister/Development/cando/brcl/src/core/designators.cc"
#include "/Users/meister/Development/cando/brcl/src/core/predicates.cc"
#include "/Users/meister/Development/cando/brcl/src/core/fileSystem.cc"
#include "/Users/meister/Development/cando/brcl/src/llvmo/debugLoc.cc"
#include "/Users/meister/Development/cando/brcl/src/clbind/adapter.cc"
#include "/Users/meister/Development/cando/brcl/src/cffi/cffi.cc"
#include "/Users/meister/Development/cando/brcl/src/asttooling/tools.cc"
#include "/Users/meister/Development/cando/brcl/src/core/builtInClass.cc"
#include "/Users/meister/Development/cando/brcl/src/core/pathname.cc"
#include "/Users/meister/Development/cando/brcl/src/core/cons.cc"
#include "/Users/meister/Development/cando/brcl/src/core/singleDispatchMethod.cc"
#include "/Users/meister/Development/cando/brcl/src/core/specialForm.cc"
#include "/Users/meister/Development/cando/brcl/src/core/weakReference.cc"
#include "/Users/meister/Development/cando/brcl/src/core/sequence.cc"
#include "/Users/meister/Development/cando/brcl/src/core/bundle.cc"
#include "/Users/meister/Development/cando/brcl/src/core/bootStrapCoreSymbolMap.cc"
#include "/Users/meister/Development/cando/brcl/src/core/float_to_digits.cc"
#include "/Users/meister/Development/cando/brcl/src/core/numbers.cc"
#include "/Users/meister/Development/cando/brcl/src/core/metaClass.cc"
#include "/Users/meister/Development/cando/brcl/src/core/array.cc"
#include "/Users/meister/Development/cando/brcl/src/core/sysprop.cc"
#include "/Users/meister/Development/cando/brcl/src/core/bignum.cc"
#include "/Users/meister/Development/cando/brcl/src/clbind/scope.cc"
#include "/Users/meister/Development/cando/brcl/src/core/readtable.cc"
#include "/Users/meister/Development/cando/brcl/src/asttooling/example.cc"
#include "/Users/meister/Development/cando/brcl/src/core/extensionPackage.cc"
#include "/Users/meister/Development/cando/brcl/src/core/singleDispatchEffectiveMethodFunction.cc"
#include "/Users/meister/Development/cando/brcl/src/core/bformat.cc"
