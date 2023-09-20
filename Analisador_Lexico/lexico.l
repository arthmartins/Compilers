%option noyywrap

%{
#include <stdio.h>
int entradas = 0;
int linha = 1;
int coluna = 1;
int block_counter = 0;
int block_coluna_counter=0;
int save_coluna = 1;
void print_newline(int entradas);
char* repair_string(char* yytext);
%}

%x BLOCK_COMMENT

%%
<INITIAL>{

"void"       { print_newline(entradas); printf("VOID"); coluna += strlen(yytext); entradas++;}
"int"        { print_newline(entradas); printf("INT"); entradas++; coluna += strlen(yytext);}
"char"       { print_newline(entradas); printf("CHAR"); entradas++;coluna += strlen(yytext);}
"return"     { print_newline(entradas); printf("RETURN"); entradas++; coluna += strlen(yytext);}
"break"      { print_newline(entradas); printf("BREAK"); entradas++; coluna += strlen(yytext);}
"switch"     { print_newline(entradas); printf("SWITCH"); entradas++; coluna += strlen(yytext);}
"case"       { print_newline(entradas); printf("CASE"); entradas++; coluna += strlen(yytext);}
"default"    { print_newline(entradas); printf("DEFAULT"); entradas++; coluna += strlen(yytext);}
"do"         { print_newline(entradas); printf("DO"); entradas++; coluna += strlen(yytext);}
"while"      { print_newline(entradas); printf("WHILE"); entradas++; coluna += strlen(yytext);}
"for"        { print_newline(entradas); printf("FOR"); entradas++; coluna += strlen(yytext);}
"if"         { print_newline(entradas); printf("IF"); entradas++; coluna += strlen(yytext);}
"else"       { print_newline(entradas); printf("ELSE"); entradas++; coluna += strlen(yytext);}
"typedef"    { print_newline(entradas); printf("TYPEDEF"); entradas++; coluna += strlen(yytext);}
"struct"     { print_newline(entradas); printf("STRUCT"); entradas++; coluna += strlen(yytext);}
"+"          { print_newline(entradas); printf("PLUS"); entradas++; coluna += strlen(yytext);}
"-"          { print_newline(entradas); printf("MINUS"); entradas++; coluna += strlen(yytext);}
"*"          { print_newline(entradas); printf("MULTIPLY"); entradas++; coluna += strlen(yytext);}
"/"          { print_newline(entradas); printf("DIV"); entradas++; coluna += strlen(yytext);}
"%"          { print_newline(entradas); printf("REMAINDER"); entradas++; coluna += strlen(yytext);}
"++"         { print_newline(entradas); printf("INC"); entradas++; coluna += strlen(yytext);}
"--"         { print_newline(entradas); printf("DEC"); entradas++; coluna += strlen(yytext);}
"&"          { print_newline(entradas); printf("BITWISE_AND"); entradas++; coluna += strlen(yytext);}
"|"          { print_newline(entradas); printf("BITWISE_OR"); entradas++; coluna += strlen(yytext);}
"~"          { print_newline(entradas); printf("BITWISE_NOT"); entradas++; coluna += strlen(yytext);}
"^"          { print_newline(entradas); printf("BITWISE_XOR"); entradas++; coluna += strlen(yytext);}
"!"          { print_newline(entradas); printf("NOT"); entradas++; coluna += strlen(yytext);}
"&&"         { print_newline(entradas); printf("LOGICAL_AND"); entradas++; coluna += strlen(yytext);}
"||"         { print_newline(entradas); printf("LOGICAL_OR"); entradas++; coluna += strlen(yytext);}
"=="         { print_newline(entradas); printf("EQUAL"); entradas++; coluna += strlen(yytext);}
"!="         { print_newline(entradas); printf("NOT_EQUAL"); entradas++; coluna += strlen(yytext);}
"<"          { print_newline(entradas); printf("LESS_THAN"); entradas++; coluna += strlen(yytext);}
">"          { print_newline(entradas); printf("GREATER_THAN"); entradas++; coluna += strlen(yytext);}
"<="         { print_newline(entradas); printf("LESS_EQUAL"); entradas++; coluna += strlen(yytext);}
">="         { print_newline(entradas); printf("GREATER_EQUAL"); entradas++; coluna += strlen(yytext);}
">>"         { print_newline(entradas); printf("R_SHIFT"); entradas++; coluna += strlen(yytext);}
"<<"         { print_newline(entradas); printf("L_SHIFT"); entradas++; coluna += strlen(yytext);}
"="          { print_newline(entradas); printf("ASSIGN"); entradas++; coluna += strlen(yytext);}
"+="         { print_newline(entradas); printf("ADD_ASSIGN"); entradas++; coluna += strlen(yytext);}
"-="         { print_newline(entradas); printf("MINUS_ASSIGN"); entradas++; coluna += strlen(yytext);}
";"          { print_newline(entradas); printf("SEMICOLON"); entradas++; coluna += strlen(yytext);}
","          { print_newline(entradas); printf("COMMA"); entradas++; coluna += strlen(yytext);}
":"          { print_newline(entradas); printf("COLON"); entradas++; coluna += strlen(yytext);}
"("          { print_newline(entradas); printf("L_PAREN"); entradas++; coluna += strlen(yytext);}
")"          { print_newline(entradas); printf("R_PAREN"); entradas++; coluna += strlen(yytext);}
"{"          { print_newline(entradas); printf("L_CURLY_BRACKET"); entradas++; coluna += strlen(yytext);}
"}"          { print_newline(entradas); printf("R_CURLY_BRACKET"); entradas++; coluna += strlen(yytext);}
"["          { print_newline(entradas); printf("L_SQUARE_BRACKET"); entradas++; coluna += strlen(yytext);}
"]"          { print_newline(entradas); printf("R_SQUARE_BRACKET"); entradas++; coluna += strlen(yytext);}
"?"          { print_newline(entradas); printf("TERNARY_CONDITIONAL"); entradas++; coluna += strlen(yytext);}
"#"          { print_newline(entradas); printf("NUMBER_SIGN"); entradas++; coluna += strlen(yytext);}
"->"         { print_newline(entradas); printf("POINTER"); entradas++; coluna += strlen(yytext);}
"printf"     { print_newline(entradas); printf("PRINTF"); entradas++; coluna += strlen(yytext);}
"scanf"      { print_newline(entradas); printf("SCANF"); entradas++; coluna += strlen(yytext);}
"define"     { print_newline(entradas); printf("DEFINE"); entradas++; coluna += strlen(yytext);}
"exit"       { print_newline(entradas); printf("EXIT"); entradas++; coluna += strlen(yytext);}


0[1-7][0-7]*          { print_newline(entradas); printf("NUM_OCTAL(%s)", yytext); entradas++; coluna += strlen(yytext);}
[0-9]+       { print_newline(entradas); printf("NUM_INTEGER(%s)", yytext); entradas++; coluna += strlen(yytext);}
0[xX][0-9a-fA-F]+     { print_newline(entradas); printf("NUM_HEXA(%s)", yytext); entradas++; coluna += strlen(yytext);}
\"(\\.|[^\"])*\"          { print_newline(entradas); printf("STRING(%s)", repair_string(yytext)); entradas++; coluna += strlen(yytext);}
\'[^'\n]*\'*               { print_newline(entradas); printf("CHARACTER(%s)", repair_string(yytext)); entradas++; coluna += strlen(yytext);}

[ \r\t\a] {coluna+= strlen(yytext);}
\f {} 
\v {}
\b {}
\\ {}
\0 {}
"//".*\n { linha++;}
"/*" { save_coluna = coluna; coluna += strlen(yytext); BEGIN(BLOCK_COMMENT);}
\n {linha++;  coluna = 1;}

[_a-zA-Z][_a-zA-Z0-9]* {
    if (strlen(yytext) > 255) {
        print_newline(entradas);
        printf("error:lexical:%d:%d: identifier too long", linha, coluna);
        entradas++;
    }else{
    print_newline(entradas); printf("IDENTIFIER(%s)", yytext);  coluna += strlen(yytext);
    entradas++;
    }
}

. { print_newline(entradas); printf("error:lexical:%d:%d: %s", linha, coluna, yytext); entradas++;}
}

<BLOCK_COMMENT>{
"/"*"*/" {linha+=block_counter;block_counter = 0; coluna += block_coluna_counter;
       block_coluna_counter=0; coluna+=strlen(yytext); BEGIN(INITIAL); }
"/*" {print_newline(entradas); printf("warning:%d:%d: '/*' within block comment",linha+block_counter,save_coluna+block_coluna_counter); block_coluna_counter+= strlen(yytext);}

\n {block_counter++; block_coluna_counter =0;}
<<EOF>> {print_newline(entradas); printf("error:lexical:%d:%d: unterminated comment", linha, save_coluna); BEGIN(INITIAL);}
. {block_coluna_counter+= strlen(yytext);}

}

%%
char* repair_string(char* yytext)
{
    int i,j;
    char* new_string = (char*)malloc(strlen(yytext)-1);
    j=0;
    for(i = 1; i <= strlen(yytext);i++)
    {
        new_string[j] = yytext[i];
        j++;
    }
    new_string[strlen(new_string)-1] = '\0';
    return new_string;
}

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