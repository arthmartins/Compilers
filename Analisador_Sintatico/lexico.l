%option noyywrap

%{
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sintatico.tab.h>
extern YYSTYPE yylval;
int entradas = 0;
int linha = 1;
int coluna = 1;
int block_counter = 0;
int block_coluna_counter=0;
int save_coluna = 1;
char erro_linha[2048];
void pick_erro_linha(int linha);


%}


%x BLOCK_COMMENT


%%

<INITIAL>{

"void"       {  coluna += strlen(yytext); return VOID;}
"int"        {  coluna += strlen(yytext); return INT;}
"char"       {  coluna += strlen(yytext); return CHAR;}
"return"     {  coluna += strlen(yytext); return RETURN;}
"break"      {  coluna += strlen(yytext); return BREAK;}
"switch"     {  coluna += strlen(yytext); return SWITCH;}
"case"       {  coluna += strlen(yytext); return CASE;}
"default"    {  coluna += strlen(yytext);return DEFAULT;}
"do"         {  coluna += strlen(yytext);return DO;}
"while"      {  coluna += strlen(yytext); return WHILE;}
"for"        {  coluna += strlen(yytext); return FOR;}
"if"         {  coluna += strlen(yytext); return IF;}
"else"       {  coluna += strlen(yytext); return ELSE;}
"typedef"    {  coluna += strlen(yytext); return TYPEDEF;}
"struct"     {  coluna += strlen(yytext); return STRUCT;}
"+"          {  coluna += strlen(yytext); return PLUS;}
"-"          {  coluna += strlen(yytext); return MINUS;}
"*"          {  coluna += strlen(yytext); return MULTIPLY;}
"/"          {  coluna += strlen(yytext); return DIV;}
"%"          {  coluna += strlen(yytext); return REMAINDER;}
"++"         {  coluna += strlen(yytext); return INC;}
"--"         {  coluna += strlen(yytext); return DEC;}
"&"          {  coluna += strlen(yytext); return BITWISE_AND;}
"|"          {  coluna += strlen(yytext); return BITWISE_OR;}
"~"          {  coluna += strlen(yytext); return BITWISE_NOT;}
"^"          {  coluna += strlen(yytext); return BITWISE_XOR;}
"!"          {  coluna += strlen(yytext); return NOT;}
"&&"         {  coluna += strlen(yytext); return LOGICAL_AND;}
"||"         {  coluna += strlen(yytext); return LOGICAL_OR;}
"=="         {  coluna += strlen(yytext); return EQUAL;}
"!="         {  coluna += strlen(yytext); return NOT_EQUAL;}
"<"          {  coluna += strlen(yytext); return LESS_THAN;}
">"          {  coluna += strlen(yytext); return GREATER_THAN;}
"<="         {  coluna += strlen(yytext); return LESS_EQUAL;}
">="         {  coluna += strlen(yytext); return GREATER_EQUAL;}
">>"         {  coluna += strlen(yytext); return R_SHIFT;}
"<<"         {  coluna += strlen(yytext); return L_SHIFT;}
"="          {  coluna += strlen(yytext); return ASSIGN;}
"+="         {  coluna += strlen(yytext); return ADD_ASSIGN;}
"-="         {  coluna += strlen(yytext); return MINUS_ASSIGN;}
";"          {  coluna += strlen(yytext); return SEMICOLON;}
","          {  coluna += strlen(yytext); return COMMA;}
":"          {  coluna += strlen(yytext); return COLON;}
"("          {  coluna += strlen(yytext); return L_PAREN;}
")"          {  coluna += strlen(yytext); return R_PAREN;}
"{"          {  coluna += strlen(yytext); return L_CURLY_BRACKET;}
"}"          {  coluna += strlen(yytext); return R_CURLY_BRACKET;}
"["          {  coluna += strlen(yytext); return L_SQUARE_BRACKET;}
"]"          {  coluna += strlen(yytext); return R_SQUARE_BRACKET;}
"?"          {  coluna += strlen(yytext); return TERNARY_CONDITIONAL;}
"#"          {  coluna += strlen(yytext); return NUMBER_SIGN;}
"->"         {  coluna += strlen(yytext); return POINTER;}
"printf"     {  coluna += strlen(yytext); return PRINTF;}
"scanf"      {  coluna += strlen(yytext); return SCANF;}
"define"     {  coluna += strlen(yytext); return DEFINE;}
"exit"       {  coluna += strlen(yytext); return EXIT;}
"0"[1-7][0-7]* {  coluna += strlen(yytext); return NUM_OCTAL;}
[0-9]+       {  coluna += strlen(yytext); return NUM_INTEGER;}
"0"[xX][0-9a-fA-F]+     {   coluna += strlen(yytext); return NUM_HEXA;}
\"(\\.|[^\"])*\"        { coluna += strlen(yytext); return STRING;}
\'[^'\n]*\'*            { coluna += strlen(yytext); return CHARACTER;}

[ \r\t\a] {coluna+= strlen(yytext);}
\f {} 
\v {}
\b {}
\\ {}
\0 {}

"//".*\n { linha++;}
"/*" { save_coluna = coluna; coluna += strlen(yytext); BEGIN(BLOCK_COMMENT);}
\n {linha++;  coluna = 1; }

[_a-zA-Z][_a-zA-Z0-9]* {
    if (strlen(yytext) > 255) {
        printf("error:lexical:%d:%d: identifier too long", linha, coluna);
        
    }else{
    coluna += strlen(yytext); return IDENTIFIER;
    }
}

. { printf("error:lexical:%d:%d: %s", linha, coluna, yytext);} 

}

<BLOCK_COMMENT>{

"/"*"*/" {linha+=block_counter;block_counter = 0; coluna += block_coluna_counter;
       block_coluna_counter=0; coluna+=strlen(yytext); BEGIN(INITIAL); }
"/*" {print_newline(entradas); entradas++; printf("warning:%d:%d: '/*' within block comment",linha+block_counter,save_coluna+block_coluna_counter); block_coluna_counter+= strlen(yytext);}

\n {block_counter++; block_coluna_counter =0;}
<<EOF>> {print_newline(entradas); printf("error:lexical:%d:%d: unterminated comment", linha, save_coluna); BEGIN(INITIAL);}
. {block_coluna_counter+= strlen(yytext);}

}

%%

void pick_erro_linha(int linha)
{
    fseek(stdin, 0, SEEK_SET);
    for(int i = 0; i < linha; i++) {
        fgets(erro_linha, 1000, stdin);
    }
}

void print_newline(int entradas){
    if(entradas > 0)
    {
        printf("\n");
    }
}