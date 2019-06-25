#include <ensemble.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>

ENSEMBLE* E;

int yyparse(void);
ENSEMBLE* parsed_set;

int main(){
    yyparse();
    E=parsed_set;
    ensemble_print(E);
    return EX_OK;}
