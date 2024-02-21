%{

#include <stdio.h>
#include "comandos.hh"
#include <list>
#include "hash.hh"
#include <iostream>
#include <vector>
#include <cmath>

#define QUIT_VALUE 329179
#define CONTINUE_VALUE 0

extern int yylex();
extern char* yytext;
extern int yychar;
extern void yylex_destroy(void);

std::vector<std::vector<float>> matriz_global;

HashTable hashTable;

std::list<float> listMatriz;
std::list<int> elemtsPlinha;

int elementosLinha = 0;
int maisElementosLinha = 0;

int sinal = 1;


extern void yyerror(char*); 

%}

%union{
int inteiro;
char* string_id;
float real; 
}


%token IDENTIFIER
%token ABOUT
%token FLOAT
%token PI
%token SETTINGS
%token ABS
%token H_VIEW
%token PLOT
%token SHOW
%token AXIS
%token INTEGRAL_STEPS
%token PRECISION
%token SOLVE
%token CONNECT_DOTS
%token INTEGRATE
%token QUIT
%token SUM
%token COS
%token LINEAR_SYSTEM
%token RESET
%token SYMBOLS
%token DETERMINANT
%token MATRIX
%token RPN
%token TAN
%token E
%token OFF
%token SEN
%token V_VIEW
%token ERASE
%token ON
%token SET
%token X
%token PLUS
%token MINUS
%token MULTIPLY
%token DIV
%token REMAINDER
%token POW
%token SEMICOLON
%token COMMA
%token COLON
%token L_PAREN
%token R_PAREN
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token EQUAL
%token ATRIBUTE
%token NUM_INTEGER
%token NUM_REAL


%start Programa
 
%type <inteiro> Sinal NUM_INTEGER ONorOFF RepeatValuesMatrixOne  OperadoresBinarios
%type <string_id> IDENTIFIER
%type <real> NUM_REAL ValorIntOrFloat Expressao_aux Expressao Constantes

%%

Programa: Comandos {return CONTINUE_VALUE;}
        | ManipulacaoSimbolos {return CONTINUE_VALUE;}
        | AvaliacaoExpressao {return CONTINUE_VALUE;}


Comandos: OnlyComandos {}
        | ComandosPlus {}

OnlyComandos: SHOW SETTINGS SEMICOLON { showSettings(); return CONTINUE_VALUE;}
            | RESET SETTINGS SEMICOLON { setDefaultValues(); return CONTINUE_VALUE;}
            | QUIT { return QUIT_VALUE;}
            | SET FuncoesSet SEMICOLON {return CONTINUE_VALUE;}
            | ABOUT SEMICOLON { printAbout(); return CONTINUE_VALUE;}
            


FuncoesSet: H_VIEW Sinal ValorIntOrFloat COLON Sinal ValorIntOrFloat { setH_view($2*$3, $5*$6); }
            | V_VIEW Sinal ValorIntOrFloat COLON Sinal ValorIntOrFloat {setV_view($2*$3, $5*$6);}
            | AXIS ONorOFF {setAxis($2);}
            | ERASE PLOT ONorOFF {setErase($3);}
            | CONNECT_DOTS ONorOFF {setConnectDots($2);}
            | FLOAT PRECISION Sinal NUM_INTEGER {setFloatPrecision($3*$4);}
            | INTEGRAL_STEPS NUM_INTEGER {setIntegralSteps($2);}


ValorIntOrFloat: NUM_INTEGER {$$ = $1;}
        |   NUM_REAL {$$ = $1;}

Sinal: PLUS {$$ = 1;}
    | MINUS {$$ = -1;}
    | {$$ = 1;}



ONorOFF: ON {$$ = 1;}
        | OFF{$$ = 0;}

ComandosPlus: Grafico {}
            | FuncaoRpn {}
            | Integral {}
            | Sum {}
            | Matrix {}

// --------------------------------------------------------
Grafico: PLOT InfoPlot SEMICOLON {return CONTINUE_VALUE;}


InfoPlot: L_PAREN FuncaoPlot R_PAREN {return CONTINUE_VALUE;}
        | {}

FuncaoPlot: Funcoes L_PAREN InsideFuncoes R_PAREN {return CONTINUE_VALUE;}

InsideFuncoes: L_PAREN InsideFuncoes R_PAREN InsideFuncoes{}
            | X InsideFuncoes{}
            | OperadoresBinarios InsideFuncoes{}
            | Constantes InsideFuncoes{}
            | ValorIntOrFloat InsideFuncoes{}
            | {}

// --------------------------------------------------------

FuncaoRpn: RPN L_PAREN Expressao R_PAREN SEMICOLON {return CONTINUE_VALUE;}

// --------------------------------------------------------

Integral: INTEGRATE L_PAREN IntegralAux R_PAREN SEMICOLON {return CONTINUE_VALUE;}

IntegralAux: Sinal ValorIntOrFloat COLON Sinal ValorIntOrFloat COMMA Funcoes InsideFuncoes{} // isso pode dar certo



// --------------------------------------------------------

//REVER ISSO AQUI!!!!!!!!!!! NO LUGAR DO X DEVE SER UMA VARIAVEL
Sum: SUM L_PAREN IDENTIFIER COMMA NUM_INTEGER COLON NUM_INTEGER COMMA Expressao R_PAREN SEMICOLON {return CONTINUE_VALUE;}

// --------------------------------------------------------
Matrix: MATRIX EQUAL ChamaCreateMatrix {}
        | SHOW MATRIX SEMICOLON { showMatriz(); return CONTINUE_VALUE;}
      | SOLVE DETERMINANT SEMICOLON { determinanteMatriz(); return CONTINUE_VALUE;}
      | SOLVE LINEAR_SYSTEM SEMICOLON { solveLinearSystem();  return CONTINUE_VALUE;}

ChamaCreateMatrix: CreateMatrix { matriz_global = createMatriz(listMatriz,elemtsPlinha,maisElementosLinha); elementosLinha = 0; maisElementosLinha = 0;
 /* destruir listas aqui */ }
      

CreateMatrix: L_SQUARE_BRACKET CreateMatrixAux R_SQUARE_BRACKET SEMICOLON {}

CreateMatrixAux: L_SQUARE_BRACKET Sinal ValorIntOrFloat { elementosLinha++; listMatriz.push_back($2*$3); } RepeatValuesMatrixOne 
                                R_SQUARE_BRACKET { elemtsPlinha.push_back(elementosLinha); maisElementosLinha = (elementosLinha > maisElementosLinha) ? elementosLinha : maisElementosLinha;
                                         elementosLinha = 0; } RepeatValuesMatrixTwo{ }

RepeatValuesMatrixOne: COMMA Sinal ValorIntOrFloat {elementosLinha++; listMatriz.push_back($2*$3); } RepeatValuesMatrixOne {}
                    | {}

RepeatValuesMatrixTwo: COMMA L_SQUARE_BRACKET Sinal ValorIntOrFloat {elementosLinha++; listMatriz.push_back($3*$4);  } RepeatValuesMatrixOne 
                                R_SQUARE_BRACKET{ elemtsPlinha.push_back(elementosLinha); maisElementosLinha = (elementosLinha > maisElementosLinha) ? elementosLinha : maisElementosLinha;
                                         elementosLinha = 0; } RepeatValuesMatrixTwo {}
                     | {}           

// ----------------   2   ----------------------------------------

ManipulacaoSimbolos: AtribuicaoValores {return CONTINUE_VALUE;}
                    | AtribuicaoMatrizes {}
                    | IDENTIFIER SEMICOLON { printValorSimbolo($1, hashTable); } // mostrar valor de símbolos 
                    | SHOW SYMBOLS SEMICOLON { hashTable.printAll(); return CONTINUE_VALUE;}
                    

AtribuicaoValores: IDENTIFIER ATRIBUTE Expressao SEMICOLON { hashTable.insert($1,$3);}

AtribuicaoMatrizes: IDENTIFIER ATRIBUTE ChamaCreateMatrix {hashTable.insert($1,matriz_global);}

// -----------------------    3    --------------------------------

AvaliacaoExpressao: AvaExpressoesMatematicas {}

AvaExpressoesMatematicas: Expressao SemicolonOpcional {}

SemicolonOpcional: SEMICOLON {return CONTINUE_VALUE;}
                | {}



Expressao: Delimitadores Expressao_aux Delimitadores {$$ = $2;}

Expressao_aux: Funcoes L_PAREN Expressao_aux R_PAREN Expressao {}
         | X Expressao_aux {}
         | OperadoresBinarios {sinal = $1;} Expressao_aux {}
         | Constantes Expressao_aux {$$ = $1;}
         | ValorIntOrFloat Expressao_aux {$$ = $1*sinal; sinal = 1;}
         | IDENTIFIER Expressao_aux {}
         | {}

Delimitadores: L_PAREN {}
            | R_PAREN {}
            | {}

Funcoes: COS {}
        | SEN {}
        | TAN {}
        | ABS {}

OperadoresBinarios: PLUS {$$ = 1;}
                    | MINUS {$$ = -1;}
                    | MULTIPLY {}
                    | DIV {}
                    | POW {}
                    | REMAINDER {}
                    

Constantes: PI {$$ = M_PI;}
            | E {$$ = M_E;}





%%

void yyerror(char *s) {
	
        printf("\nSYNTAX ERROR: [%s]\n\n", yytext);
	
}

int main(int argc, char** argv)
{
    
    setDefaultValues();
    int input = 0;

    while(input != QUIT_VALUE){
    printf(">");
    input  = yyparse();
    } 
    
    printf("SUCCESSFUL COMPILATION.");
    return 0;
}