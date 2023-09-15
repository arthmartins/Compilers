%option noyywrap

%{
#include <stdio.h>
int entradas = 0;
void print_newline(int entradas);
%}

%%
"void"       { print_newline(entradas); printf("VOID"); entradas++;}
"int"        { print_newline(entradas); printf("INT"); entradas++;}
"char"       { print_newline(entradas); printf("CHAR"); entradas++;}
"return"     { print_newline(entradas); printf("RETURN"); entradas++;}
"break"      { print_newline(entradas); printf("BREAK"); entradas++;}
"switch"     { print_newline(entradas); printf("SWITCH"); entradas++;}
"case"       { print_newline(entradas); printf("CASE"); entradas++;}
"default"    { print_newline(entradas); printf("DEFAULT"); entradas++;}
"do"         { print_newline(entradas); printf("DO"); entradas++;}
"while"      { print_newline(entradas); printf("WHILE"); entradas++;}
"for"        { print_newline(entradas); printf("FOR"); entradas++;}
"if"         { print_newline(entradas); printf("IF"); entradas++;}
"else"       { print_newline(entradas); printf("ELSE"); entradas++;}
"typedef"    { print_newline(entradas); printf("TYPEDEF"); entradas++;}
"struct"     { print_newline(entradas); printf("STRUCT"); entradas++;}
"+"          { print_newline(entradas); printf("PLUS"); entradas++;}
"-"          { print_newline(entradas); printf("MINUS"); entradas++;}
"*"          { print_newline(entradas); printf("MULTIPLY"); entradas++;}
"/"          { print_newline(entradas); printf("DIV"); entradas++;}
"%"          { print_newline(entradas); printf("REMAINDER"); entradas++;}
"++"         { print_newline(entradas); printf("INC"); entradas++;}
"--"         { print_newline(entradas); printf("DEC"); entradas++;}
"&"          { print_newline(entradas); printf("BITWISE_AND"); entradas++;}
"|"          { print_newline(entradas); printf("BITWISE_OR"); entradas++;}
"~"          { print_newline(entradas); printf("BITWISE_NOT"); entradas++;}
"^"          { print_newline(entradas); printf("BITWISE_XOR"); entradas++;}
"!"          { print_newline(entradas); printf("NOT"); entradas++;}
"&&"         { print_newline(entradas); printf("LOGICAL_AND"); entradas++;}
"||"         { print_newline(entradas); printf("LOGICAL_OR"); entradas++;}
"=="         { print_newline(entradas); printf("EQUAL"); entradas++;}
"!="         { print_newline(entradas); printf("NOT_EQUAL"); entradas++;}
"<"          { print_newline(entradas); printf("LESS_THAN"); entradas++;}
">"          { print_newline(entradas); printf("GREATER_THAN"); entradas++;}
"<="         { print_newline(entradas); printf("LESS_EQUAL"); entradas++;}
">="         { print_newline(entradas); printf("GREATER_EQUAL"); entradas++;}
">>"         { print_newline(entradas); printf("R_SHIFT"); entradas++;}
"<<"         { print_newline(entradas); printf("L_SHIFT"); entradas++;}
"="          { print_newline(entradas); printf("ASSIGN"); entradas++;}
"+="         { print_newline(entradas); printf("ADD_ASSIGN"); entradas++;}
"-="         { print_newline(entradas); printf("MINUS_ASSIGN"); entradas++;}
";"          { print_newline(entradas); printf("SEMICOLON"); entradas++;}
","          { print_newline(entradas); printf("COMMA"); entradas++;}
":"          { print_newline(entradas); printf("COLON"); entradas++;}
"("          { print_newline(entradas); printf("L_PAREN"); entradas++;}
")"          { print_newline(entradas); printf("R_PAREN"); entradas++;}
"{"          { print_newline(entradas); printf("L_CURLY_BRACKET"); entradas++;}
"}"          { print_newline(entradas); printf("R_CURLY_BRACKET"); entradas++;}
"["          { print_newline(entradas); printf("L_SQUARE_BRACKET"); entradas++;}
"]"          { print_newline(entradas); printf("R_SQUARE_BRACKET"); entradas++;}
"?"          { print_newline(entradas); printf("TERNARY_CONDITIONAL"); entradas++;}
"#"          { print_newline(entradas); printf("NUMBER_SIGN"); entradas++;}
"->"         { print_newline(entradas); printf("POINTER"); entradas++;}
"printf"     { print_newline(entradas); printf("PRINTF"); entradas++;}
"scanf"      { print_newline(entradas); printf("SCANF"); entradas++;}
"define"     { print_newline(entradas); printf("DEFINE"); entradas++;}
"exit"       { print_newline(entradas); printf("EXIT"); entradas++;}

0[0-7]+               { print_newline(entradas); printf("NUM_OCTAL(%s)", yytext); entradas++;}
[0-9]+                  { print_newline(entradas); printf("NUM_INTEGER(%s)", yytext); entradas++;}
0[xX][0-9a-fA-F]+     { print_newline(entradas); printf("NUM_HEXA(%s)", yytext); entradas++;}
\"[^\"\n]*\"            { print_newline(entradas); printf("STRING(%s)", yytext); entradas++;}
'[^'\n]*'               { print_newline(entradas); printf("CHARACTER(%s)", yytext); entradas++;}

[ \t\n]     ; // Ignorar espaços em branco, tabulações e novas linhas

[_a-zA-Z][_a-zA-Z0-9]+ {
    if (strlen(yytext) > 255) {
        print_newline(entradas); printf("Erro: Identificador excede o tamanho máximo de 255 caracteres");
        entradas++;
    }else{
    print_newline(entradas); printf("IDENTIFIER(%s)", yytext);
    entradas++;
    }
}

%%

void print_newline(int entradas){
    if(entradas > 0)
    {
        printf("\n");
    }
}


int main(int argc, char* argv[]){

    yylex();
    return 0;
}