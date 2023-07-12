#ifndef lambda_h
#define lambda_h

/**
 * \file lambda.h
 * \brief This file defines macros that can be used to write code
 *        that can be compiled both as gcc local functions or as
 *        clang blocks.
 *
 * In the context of this file, we'll use the term "lambda" to
 * designate * either gcc local functions or clang blocks.
 *
 * The macros are:
 *
 * VAR: used to declare a variable that will be used in a lambda.
 *
 * FUN: used in the declaration of a lambda type.
 *
 * FLET: used to declare and name the lambda.
 *
 * FWRAP: wraps a function pointer into a clang block.
 *
 * PWRAP: wraps a procedure (function returning void) into a clang block.
 *
 * FWRAP and PWRAP are needed in clang to convert function pointers to blocks.
 *
 * Example (lambda_example.c):
 * \code{.c}
 *     #include <stdio.h>
 *     #include <assert.h>
 *     #include <common/code/lambda.h>
 *
 *     void caller(void(FUN hook)(int x))
 *     {
 *         int i;
 *         for(i=0;i<3;i++)
 *             hook(i);
 *     }
 *
 *     void my_callback(int x)
 *     {
 *         printf("my_callback %d\n",x);
 *     }
 *
 *     void foo(void)
 *     {
 *         VAR int result=0;
 *         FLET(void,my_function,(int x)){
 *             result = x;
 *             printf("my_function %d\n",x);
 *         };
 *
 *         caller(my_function);
 *         caller(PWRAP(my_callback,(int x),(x)));
 *         assert(result==2);
 *     }
 *
 *     int main(void)
 *     {
 *         foo();
 *         return 0;
 *     }
 * \endcode
 *
 * Output:
 * \verbatim
 *    $ gcc -Wall -std=c99 -I. -o example-lambda-gcc lambda-example.c && \
 *      echo '// ====== example-lambda-gcc' && ./example-lambda-gcc && \
 *      clang -Wall -std=c99 -I. -fblocks -lBlocksRuntime -o example-lambda-clang lambda-example.c && \
 *      echo '// ====== example-lambda-clang' &&  ./example-lambda-clang
 *    // ====== example-lambda-gcc
 *    my_function 0
 *    my_function 1
 *    my_function 2
 *    my_callback 0
 *    my_callback 1
 *    my_callback 2
 *    // ====== example-lambda-clang
 *    my_function 0
 *    my_function 1
 *    my_function 2
 *    my_callback 0
 *    my_callback 1
 *    my_callback 2
 *    $
 * \endverbatim
 *
 */


#if defined(__clang__)

/**
 * \def VAR
 *
 * \brief Introduces a variable that can be used in a "lambda".
 *
 * Adding this macro as a qualifier to a local variable declaration allows
 * it to be mutated by the lambda body. This is necessary because clang
 * blocks are closures, and therefore can mutate variables in the
 * enclosing scope.
 *
 * \code{.c}
 *     VAR int result = 0;
 * \endcode
 */
#define VAR __block

/**
 * \def FUN
 *
 * \brief Introduces a "lambda" type.
 *
 * Use this macro when defining a type that can take a lambda,
 * ie. either a gcc local function pointer, or a clang block
 * reference.
 *
 * \code{.c}
 *     typedef int (FUN my_callback_f)(int value);
 * \endcode
 */
#define FUN ^

/**
 * \def FLET(rettype, fname, parameters)
 *
 * \brief This is a macro for creating a function with a specified
 *        return type, name, and parameters.
 *
 * Use this macro to declare a named lambda, ie. either a gcc local
 * function, or a clang block.  The macro call must be followed by the
 * function body, and a semi-colon.
 *
 * \param rettype The return type of the function.
 * \param fname The name of the function.
 * \param parameters The parameters of the function, as a comma-separated list.
 */
#define FLET(rettype,fname,parameters) rettype (^ fname) parameters = ^ parameters
#define FDCL(rettype,fname,parameters) rettype (^ fname) parameters

#define FWRAP(rettype,fname,parameters,arguments) ^ parameters { return (rettype) fname arguments; }
#define PWRAP(fname,parameters,arguments) ^ parameters { fname arguments; }

#elif defined(__GNUC__) || defined(__gcc__)

/**
 * \def VAR
 *
 * \brief Introduces a variable that can be used in a "lambda".
 *
 * Adding this macro as a qualifier to a local variable declaration allows
 * it to be mutated by the lambda body. This is necessary because clang
 * blocks are closures, and therefore can mutate variables in the
 * enclosing scope.
 *
 * \code{.c}
 *     VAR int result = 0;
 * \endcode
 */
#define VAR

/**
 * \def FUN
 *
 * \brief Introduces a "lambda" type.
 *
 * Use this macro when defining a type that can take a lambda,
 * ie. either a gcc local function pointer, or a clang block
 * reference.
 *
 * \code{.c}
 *     typedef int (FUN my_callback_f)(int value);
 * \endcode
 */
#define FUN *

/**
 * \def FLET(rettype, fname, parameters)
 *
 * \brief This is a macro for creating a function with a specified
 *        return type, name, and parameters.
 *
 * Use this macro to declare a named lambda, ie. either a gcc local
 * function, or a clang block.  The macro call must be followed by the
 * function body, and a semi-colon.
 *
 * \param rettype The return type of the function.
 * \param fname The name of the function.
 * \param parameters The parameters of the function, as a comma-separated list.
 */
#define FLET(rettype, fname, parameters) rettype fname parameters
#define FDCL(rettype, fname, parameters) rettype fname parameters

#define FWRAP(rettype,fname,parameters,arguments) fname
#define PWRAP(fname,parameters,arguments) fname

#else
#error "No known way to define lambda, blocks or local functions with this compiler."
#endif

#endif
