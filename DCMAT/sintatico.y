%{

#include <stdio.h>
#include "comandos.hh"
#define QUIT_VALUE 329179
#define CONTINUE_VALUE 0

extern int yylex();
extern char* yytext;
extern int yychar;
extern void yylex_destroy(void);


extern void yyerror(char*); 

%}

%union{
int inteiro;
char *string;
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

%type <inteiro> Sinal NUM_INTEGER ONorOFF
//%type <string> IDENTIFIER
%type <real> NUM_REAL ValorIntOrFloat

%%

Programa: Comandos {}
        | ManipulacaoSimbolos {}
        | AvaliacaoExpressao {}


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
            | FLOAT PRECISION NUM_INTEGER {setFloatPrecision($3);}
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

Matrix: MATRIX EQUAL CreateMatrix {}
      | SHOW MATRIX SEMICOLON {return CONTINUE_VALUE;}
      | SOLVE DETERMINANT SEMICOLON {return CONTINUE_VALUE;}
      | SOLVE LINEAR_SYSTEM SEMICOLON {return CONTINUE_VALUE;}

CreateMatrix: L_SQUARE_BRACKET CreateMatrixAux R_SQUARE_BRACKET SEMICOLON {return CONTINUE_VALUE;}

CreateMatrixAux: L_SQUARE_BRACKET Sinal ValorIntOrFloat RepeatValuesMatrixOne R_SQUARE_BRACKET RepeatValuesMatrixTwo{}

RepeatValuesMatrixOne: COMMA Sinal ValorIntOrFloat RepeatValuesMatrixOne {}
                    | {}

RepeatValuesMatrixTwo: COMMA L_SQUARE_BRACKET Sinal ValorIntOrFloat RepeatValuesMatrixOne R_SQUARE_BRACKET RepeatValuesMatrixTwo {}
                     | {}           

// ----------------   2   ----------------------------------------

ManipulacaoSimbolos: AtribuicaoValores {}
                    | AtribuicaoMatrizes {}
                    | IDENTIFIER SEMICOLON {return CONTINUE_VALUE;} // mostrar valor de símbolos 
                    | SHOW SYMBOLS SEMICOLON {return CONTINUE_VALUE;}
                    

AtribuicaoValores: IDENTIFIER ATRIBUTE Expressao SEMICOLON {return CONTINUE_VALUE;}

AtribuicaoMatrizes: IDENTIFIER ATRIBUTE CreateMatrix {}

// -----------------------    3    --------------------------------

AvaliacaoExpressao: AvaExpressoesMatematicas {}

AvaExpressoesMatematicas: Expressao SemicolonOpcional {}

SemicolonOpcional: SEMICOLON {return CONTINUE_VALUE;}
                | {}



Expressao: Delimitadores Expressao_aux Delimitadores {}

Expressao_aux: Funcoes L_PAREN Expressao_aux R_PAREN Expressao {}
         | X Expressao_aux {}
         | OperadoresBinarios Expressao_aux {}
         | Constantes Expressao_aux {}
         | ValorIntOrFloat Expressao_aux {}
         | IDENTIFIER Expressao_aux {}
         | {}

Delimitadores: L_PAREN {return CONTINUE_VALUE;}
            | R_PAREN {return CONTINUE_VALUE;}
            | {}

Funcoes: COS {return CONTINUE_VALUE;}
        | SEN {return CONTINUE_VALUE;}
        | TAN {return CONTINUE_VALUE;}
        | ABS {return CONTINUE_VALUE;}

OperadoresBinarios: PLUS {return CONTINUE_VALUE;}
                    | MINUS {return CONTINUE_VALUE;}
                    | MULTIPLY {return CONTINUE_VALUE;}
                    | DIV {return CONTINUE_VALUE;}
                    | POW {return CONTINUE_VALUE;}
                    | REMAINDER {return CONTINUE_VALUE;}

Constantes: PI {return CONTINUE_VALUE;}
            | E {return CONTINUE_VALUE;}





%%

void yyerror(char *s) {
	
        printf("Deu erro %s", yytext);
	exit(0);
    
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