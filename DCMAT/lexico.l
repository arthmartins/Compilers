%option noyywrap

%{
#include "ast.hh"
#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sintatico.yy.hh>


extern YYSTYPE yylval;
extern std::string str;

%}



%%

<INITIAL>{

"about"          { return ABOUT; }
"float"          { return FLOAT; }
"pi"|"pI"|"Pi"|"PI"           { return PI; }
"settings"       { return SETTINGS; }

"abs"            { return ABS; }
"h_view"         { return H_VIEW; }
"plot"           { return PLOT; }
"show"           { return SHOW; }

"axis"           { return AXIS; }
"integral_steps" { return INTEGRAL_STEPS; }
"precision"      { return PRECISION; }
"solve"          { return SOLVE; }

"connect_dots"   { return CONNECT_DOTS; }
"integrate"      { return INTEGRATE; }
"quit"           { return QUIT; }
"sum"            { return SUM; }

"cos"            { return COS; }
"linear_system"  { return LINEAR_SYSTEM; }
"reset"          { return RESET; }
"symbols"        { return SYMBOLS; }

"determinant"    { return DETERMINANT; }
"matrix"         { return MATRIX; }
"rpn"            { return RPN; }
"tan"            { return TAN; }

"e"|"E"              { return E; }
"off"            { return OFF; }
"sen"            { return SEN; }
"v_view"         { return V_VIEW; }

"erase"          { return ERASE; }
"on"             { return ON; }
"set"            { return SET; }
"x"              {  return X; }

"+"          {  return PLUS;}
"-"          {  return MINUS;}
"*"          {  return MULTIPLY;}
"/"          {   return DIV;}
"%"          {  return REMAINDER;}
"^"          {  return POW;}


";"          { return SEMICOLON;}
","          {  return COMMA;}
":"          {  return COLON;}
"("          {  return L_PAREN;}
")"          {  return R_PAREN;}
"["          {  return L_SQUARE_BRACKET;}
"]"          {  return R_SQUARE_BRACKET;}
"="          {  return EQUAL;}
":="          {  return ATRIBUTE;}

[0-9]+       {  yylval.inteiro = atoi(yytext); return NUM_INTEGER;}
[0-9]+"."[0-9]+    { yylval.real = atof(yytext); return NUM_REAL;}

[ \r\t\a] {}
\f {} 
\v {}
\b {}
\\ {}
\0 {}

\n { return EOL; }

[_a-zA-Z][_a-zA-Z0-9]* {yylval.string_id = strdup(yytext); str = strdup(yytext); return IDENTIFIER; }

. { printf("\nInvalid Symbol: %s\n\n", yytext); return 1;} 

}

%%


