/* -*- mode:c -*- */
%{

#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <util.h>
#include <tokens.h>
    
int yyvalue;
int convert_int(const char*);

// #define DEBUG(e) do{e}while(0)
#define DEBUG(e) do{}while(0)

%}

%option noyywrap

%%

"," { DEBUG(printf("COMMA\n");); return COMMA; }
"{" { DEBUG(printf("OPEN\n"););  return OPEN;  }
"}" { DEBUG(printf("CLOSE\n");); return CLOSE; }


[\-+]{0,1}([1-9][0-9]*|0)   { yyvalue=convert_int(yytext); DEBUG(printf("INTEGER %d\n",yyvalue);); return INTEGER; }
 

[ \t\n]+    /* eat up whitespace */
.           error("Unrecognized character: %s\n",yytext);

%%

