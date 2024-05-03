%{
#include "scan.hpp"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <string.h>

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

Programa: Available_Registers EOL Registers_aux {}

Available_Registers: K EQUAL NUM_INTEGER  { k = $3;}

Registers_aux: Registers EOL Registers_aux {}
            | { }

Registers: IDENTIFIER ARROW NUM_INTEGER NUM_INTEGER  Registers {Register* r = new Register;
            r->name =  strdup($1);
            r->begin = $3;
            r->end = $4;
           
            
            r->intervalo = r->end - r->begin;
            r->reg_alocado = -1;
        
            
            r->spill = false;
            //registers.insert(registers.begin(), r);
            registers.push_back(r);
            }
        |{ }







%%

void yyerror(char *s){

 }

int main(int argc, char **argv) {

    yyparse();
    std::vector<historico*> num_spills;
    
    for(int j = k; j >1; j--){
    
        std::cout << "K = " << j << std::endl << std::endl;
        historico *hist = new historico;

        hist->k = j;
        LinearScan(j,registers,hist);

        for(int i = 0; i < registers.size(); i++){

            if(registers[i]->spill){
                std::cout << registers[i]->name << ": " << "SPILL" << std::endl;
            }else{
            std::cout << registers[i]->name << ": " << registers[i]->reg_alocado << std::endl;
            }
            
        }
        num_spills.push_back(hist);
        printf("----------------------------------------\n");
        resetAll(registers);
    }
    printf("----------------------------------------");
    

    for (int i = 0; i < num_spills.size(); i++) {
        historico* elemento = num_spills[i];
        int m = 0;
        std::cout << "\nK = " << elemento->k << ": ";
        if(elemento->iteracoes.size() == 0){
            std::cout << "Successful Allocation";
        }
        else{
            std::cout << "SPILL on interation(s): ";
            for(int j = 0 ; j < elemento->iteracoes.size() ; j++){
                std::cout << elemento->iteracoes[j] << "";
                if (j!=elemento->iteracoes.size()-1){
                    std::cout << ", ";
                }
            }
            }
        }

    
    yylex_destroy();


}