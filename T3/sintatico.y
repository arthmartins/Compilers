%{
#include "graph.hpp"
#include <vector>


    extern int yylex(void);
    extern char* yytext;
    extern int yychar;
    extern void yyerror(char *s);
    extern void yylex_destroy(void);

    std::vector<Register*> registers;
    int k = 0;

%}

%union {
    int integer_value;
    char* string_id;
}


%token K
%token ARROW
%token<integer_value> NUM_INTEGER
%token EOL
%token <string_id> IDENTIFIER
%token EQUAL


%type <integer_value> Available_Registers

%start Programa

%%

Programa: Available_Registers Registers {}

Available_Registers: K EQUAL NUM_INTEGER { k = $3;}

Registers: IDENTIFIER ARROW NUM_INTEGER NUM_INTEGER EOL Registers {
            Register* r = new Register;
            r->name =  strdup($1);
            r->start = $3;
            r->end = $4;
            r->intervalor = r->end - r->start;
            r->reg_alocado = -1;
            registers.push_back(r);
}
        | {}






%%

void yyerror(char *s){

 }

int main(int argc, char **argv) {

    yyparse();
    
    yylex_destroy();

}