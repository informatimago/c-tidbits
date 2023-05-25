#include <stdio.h>
#include "lambda.h"

#if defined(__clang__)
#define VAR __block
#define FUN ^
#define FLET(retype,name,lambda_list) retype (^ name) lambda_list = ^ lambda_list 
#elif defined(__GNUC__) || defined(__GNUG__)
#define VAR
#define FUN *
#define FLET(retype,name,lambda_list) retype name lambda_list 
#else
#error "No known way to define lambda, blocks or local functions."
#endif

typedef void (FUN localfun_callback)(int counter);

static void try_local_function(localfun_callback callback)
{
  int i;
  for (i = 0; i < 10; i++) {
    callback(i);
  }
}

void test_lambda(void)
{
  VAR int local_counter = 0;
  FLET(void,local_function,(int counter)){
      printf("lambda counter = %d\n", counter);
      local_counter = counter;
  };

  try_local_function(local_function);
  printf("lambda local counter = %d\n", local_counter);
}
