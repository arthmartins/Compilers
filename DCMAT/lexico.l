%option noyywrap

%{
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sintatico.yy.hh>
extern YYSTYPE yylval;
int entradas = 0;
int linha = 1;
int coluna = 1;
int linha_anterior = 1;
int coluna_anterior =1;
int block_counter = 0;
int block_coluna_counter=0;
int save_coluna = 1;
char erro_linha[2048];
void pick_erro_linha(int linha);


%}


%x BLOCK_COMMENT


%%

<INITIAL>{

"about"          { coluna += strlen(yytext); return ABOUT; }
"float"          { coluna += strlen(yytext); return FLOAT; }
"pi"|"pI"|"Pi"|"PI"           { coluna += strlen(yytext); return PI; }
"settings"       { coluna += strlen(yytext); return SETTINGS; }

"abs"            { coluna += strlen(yytext); return ABS; }
"h_view"         { coluna += strlen(yytext); return H_VIEW; }
"plot"           { coluna += strlen(yytext); return PLOT; }
"show"           { coluna += strlen(yytext); return SHOW; }

"axis"           { coluna += strlen(yytext); return AXIS; }
"integral_steps" { coluna += strlen(yytext); return INTEGRAL_STEPS; }
"precision"      { coluna += strlen(yytext); return PRECISION; }
"solve"          { coluna += strlen(yytext); return SOLVE; }

"connect_dots"   { coluna += strlen(yytext); return CONNECT_DOTS; }
"integrate"      { coluna += strlen(yytext); return INTEGRATE; }
"quit"           { coluna += strlen(yytext); return QUIT; }
"sum"            { coluna += strlen(yytext); return SUM; }

"cos"            { coluna += strlen(yytext); return COS; }
"linear_system"  { coluna += strlen(yytext); return LINEAR_SYSTEM; }
"reset"          { coluna += strlen(yytext); return RESET; }
"symbols"        { coluna += strlen(yytext); return SYMBOLS; }

"determinant"    { coluna += strlen(yytext); return DETERMINANT; }
"matrix"         { coluna += strlen(yytext); return MATRIX; }
"rpn"            { coluna += strlen(yytext); return RPN; }
"tan"            { coluna += strlen(yytext); return TAN; }

"e"|"E"              { coluna += strlen(yytext); return E; }
"off"            { coluna += strlen(yytext); return OFF; }
"sen"            { coluna += strlen(yytext); return SEN; }
"v_view"         { coluna += strlen(yytext); return V_VIEW; }

"erase"          { coluna += strlen(yytext); return ERASE; }
"on"             { coluna += strlen(yytext); return ON; }
"set"            { coluna += strlen(yytext); return SET; }
"x"              { coluna += strlen(yytext); return X; }

"+"          {  coluna += strlen(yytext); return PLUS;}
"-"          {  coluna += strlen(yytext); return MINUS;}
"*"          {  coluna += strlen(yytext); return MULTIPLY;}
"/"          {  coluna += strlen(yytext); return DIV;}
"%"          {  coluna += strlen(yytext); return REMAINDER;}
"^"          {  coluna += strlen(yytext); return POW;}


";"          {  coluna += strlen(yytext); return SEMICOLON;}
","          {  coluna += strlen(yytext); return COMMA;}
":"          {  coluna += strlen(yytext); return COLON;}
"("          {  coluna += strlen(yytext); return L_PAREN;}
")"          {  coluna += strlen(yytext); return R_PAREN;}
"["          {  coluna += strlen(yytext); return L_SQUARE_BRACKET;}
"]"          {  coluna += strlen(yytext); return R_SQUARE_BRACKET;}
"="          {  coluna += strlen(yytext); return EQUAL;}
":="          {  coluna += strlen(yytext); return ATRIBUTE;}

[0-9]+       {  coluna += strlen(yytext); return NUM_INTEGER;}
[0-9]+"."[0-9]+    {   coluna += strlen(yytext); return NUM_REAL;}

[ \r\t\a] {coluna+= strlen(yytext);}
\f {} 
\v {}
\b {}
\\ {}
\0 {}

"//".*\n { linha_anterior= linha; coluna_anterior= coluna; linha++;}
"/*" { save_coluna = coluna; coluna += strlen(yytext); BEGIN(BLOCK_COMMENT);}
\n {linha_anterior= linha; coluna_anterior= coluna-1;linha++;  coluna = 1; }

[_a-zA-Z][_a-zA-Z0-9]* {
    if (strlen(yytext) > 255) {
        printf("error:lexical:%d:%d: identifier too long", linha, coluna);
        exit(0);
    }else{
    coluna += strlen(yytext); return IDENTIFIER;
    }
}

. { printf("error:lexical:%d:%d: %s", linha, coluna, yytext); exit(0);} 

}

%%

void pick_erro_linha(int linha)
{
    fseek(stdin, 0, SEEK_SET);
    for(int i = 0; i < linha; i++) {
        fgets(erro_linha, 1000, stdin);
    }
}

