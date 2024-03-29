/*
    File: memoryManagement.cc
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
//

#include <llvm/Support/ErrorHandling.h>
#include "core/foundation.h"
#include "core/object.h"
#include "core/numbers.h"
#include "memoryManagement.h"
//#include "main/allHeaders.cc"

#ifdef _TARGET_OS_LINUX
# include <signal.h>
#endif


namespace gctools {

    void* _global_stack_marker;


#if 0
    HeapRoot* 	rooted_HeapRoots = NULL;
    StackRoot* 	rooted_StackRoots = NULL;
#endif


};

#ifdef USE_REFCOUNT
#include "intrusiveRefCountGarbageCollection.cc"
#endif

#ifdef USE_BOEHM
#include "boehmGarbageCollection.cc"
#endif

#if defined(USE_MPS)
#include "mpsGarbageCollection.cc"
#endif




namespace gctools {


void handle_signals(int signo) {
    //
    // Indicate that a signal was caught and handle it at a safe-point
//
    SET_SIGNAL(signo);
}


void fatal_error_handler(void* user_data, const std::string& reason, bool gen_crash_diag)
{
    printf("Hit a fatal error in llvm/clang: %s\n", reason.c_str());
    printf("Terminating via exit(0)\n");
    exit(0);
}



#ifdef USE_BOEHM
void clasp_warn_proc(char *msg, GC_word arg)
{
    printf("%s:%d clasp trapped Boehm-gc warning...\n", __FILE__, __LINE__ );
    printf( msg, arg );
}
#endif




    void setupSignals()
    {
        if (signal(SIGINT, handle_signals) == SIG_ERR) {
            printf("failed to register SIGINT signal-handler with kernel\n");
        }
        if (signal(SIGCHLD, handle_signals) == SIG_ERR) {
            printf("failed to register SIGCHLD signal-handler with kernel\n");
        }
        if (signal(SIGABRT, handle_signals) == SIG_ERR) {
            printf("failed to register SIGABRT signal-handler with kernel\n");
        }
        llvm::install_fatal_error_handler(fatal_error_handler,NULL);
    }




    int handleFatalCondition()
    {
        int exitCode = 0;
        try {
            throw;
        } catch ( core::ExitProgram& ee )
        {
// Do nothing
//            printf("Caught ExitProgram in %s:%d\n", __FILE__, __LINE__);
            exitCode = ee.getExitResult();
        } catch ( core::TerminateProgramIfBatch& ee )
        {
// Do nothing
            printf("Caught TerminateProgramIfBatch in %s:%d\n", __FILE__, __LINE__);
        } catch (core::Condition& ee)
        {
            IMPLEMENT_MEF(BF("Figure out what to do if we catch a Condition"));
//        printf("Caught Condition at %s:%d - %s\n", __FILE__, __LINE__, ee.message().c_str() );
//        printf("Stack trace:\n%s", ee.conditionObject()->getStackTraceDump().c_str() );
        }
        catch (core::CatchThrow& ee)
        {
            _lisp->print(BF("%s:%d Uncaught THROW frame[%s] - this should NEVER happen - the stack should never be unwound unless there is a CATCH clause that matches the THROW") % __FILE__ % __LINE__ % ee.getFrame() );
        }
        catch (core::HardError& ee)
        {
            _lisp->print(BF("At %s:%d - HardError caught: %s") % __FILE__ % __LINE__ % ee.message() );
        }
#if 0
        catch ( ... )
        {
            _lisp->print(BF("Unknown exception in main - everything should be caught lower down %s:%d") % __FILE__ % __LINE__);
        }
#endif
        return exitCode;
    }




        int startupGarbageCollectorAndSystem( MainFunctionType startupFn
                                              , int argc
                                              , char* argv[]
                                              , bool mpiEnabled
                                              , int mpiRank
                                              , int mpiSize ) {
            void* stackMarker = NULL;
            gctools::_global_stack_marker = &stackMarker;

            setupSignals();

#if defined(USE_MPS)
            int exitCode = gctools::initializeMemoryPoolSystem(startupFn, argc, argv, mpiEnabled, mpiRank, mpiSize );
#endif

#if defined(USE_BOEHM)
//    GC_set_all_interior_pointers(1);
            GC_set_warn_proc(clasp_warn_proc);
            GC_init();
            int exitCode = startupFn(argc, argv, mpiEnabled, mpiRank, mpiSize );
#endif
            return exitCode;
        }
        


    };
