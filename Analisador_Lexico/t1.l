%option noyywrap

%{
#include <stdio.h>
%}

%%
"void"       { printf("VOID"); }
"int"        { printf("INT"); }
"char"       { printf("CHAR"); }
"return"     { printf("RETURN"); }
"break"      { printf("BREAK"); }
"switch"     { printf("SWITCH"); }
"case"       { printf("CASE"); }
"default"    { printf("DEFAULT"); }
"do"         { printf("DO"); }
"while"      { printf("WHILE"); }
"for"        { printf("FOR"); }
"if"         { printf("IF"); }
"else"       { printf("ELSE"); }
"typedef"    { printf("TYPEDEF"); }
"struct"     { printf("STRUCT"); }
"+"          { printf("PLUS"); }
"-"          { printf("MINUS"); }
"*"          { printf("MULTIPLY"); }
"/"          { printf("DIV"); }
"%"          { printf("REMAINDER"); }
"++"         { printf("INC"); }
"--"         { printf("DEC"); }
"&"          { printf("BITWISE_AND"); }
"|"          { printf("BITWISE_OR"); }
"~"          { printf("BITWISE_NOT"); }
"^"          { printf("BITWISE_XOR"); }
"!"          { printf("NOT"); }
"&&"         { printf("LOGICAL_AND"); }
"||"         { printf("LOGICAL_OR"); }
"=="         { printf("EQUAL"); }
"!="         { printf("NOT_EQUAL"); }
"<"          { printf("LESS_THAN"); }
">"          { printf("GREATER_THAN\n"); }
"<="         { printf("LESS_EQUAL\n"); }
">="         { printf("GREATER_EQUAL\n"); }
">>"         { printf("R_SHIFT\n"); }
"<<"         { printf("L_SHIFT\n"); }
"="          { printf("ASSIGN\n"); }
"+="         { printf("ADD_ASSIGN\n"); }
"-="         { printf("MINUS_ASSIGN\n"); }
";"          { printf("SEMICOLON\n"); }
","          { printf("COMMA\n"); }
":"          { printf("COLON\n"); }
"("          { printf("L_PAREN\n"); }
")"          { printf("R_PAREN\n"); }
"{"          { printf("L_CURLY_BRACKET\n"); }
"}"          { printf("R_CURLY_BRACKET\n"); }
"["          { printf("L_SQUARE_BRACKET\n"); }
"]"          { printf("R_SQUARE_BRACKET\n"); }
"?"          { printf("TERNARY_CONDITIONAL\n"); }
"#"          { printf("NUMBER_SIGN\n"); }
"->"         { printf("POINTER\n"); }
"printf"     { printf("PRINTF\n"); }
"scanf"      { printf("SCANF\n"); }
"define"     { printf("DEFINE\n"); }
"exit"       { printf("EXIT\n"); }

[0-9]+              { printf("NUM_INTEGER(%s)", yytext); }
0[xX][0-9a-fA-F]+   { printf("NUM_HEXA(%s)\n", yytext); }
0[0-7]+             { printf("NUM_OCTAL(%s)\n", yytext); }
\"[^\"\n]*\"        { printf("STRING(%s)\n", fixed_string(yytext)); }
'[^'\n]*'           { printf("CHARACTER(%s)\n", fix_char(yytext)); }

[ \t\n]     ; // Ignorar espaços em branco, tabulações e novas linhas

[_a-zA-Z][_a-zA-Z0-9]{0,254} {
    if (strlen(yytext) > 255) {
        printf("Erro: Identificador excede o tamanho máximo de 255 caracteres\n");
    }
    printf(""IDENTIFIER(%s)\n", yytext");
}

%%

int main(int argc, char* argv[]){

    yylex();
    return 0;
}