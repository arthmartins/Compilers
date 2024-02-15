%{

#include <stdio.h>
#include "comandos.hh"
extern int yylex();
extern char* yytext;
extern int yychar;


extern void yyerror(char*); 

%}

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

%%

Programa: Comandos {printf(">");}
        | ManipulacaoSimbolos {printf(">");}
        | AvaliacaoExpressao {printf(">");}
        | ApresentacaoResultados {printf(">");}


Comandos: OnlyComandos {}
        | ComandosPlus {}

OnlyComandos: SHOW ComplementoSettings {}
            | RESET ComplementoSettings {}
            | QUIT { exit(0);}
            | SET FuncoesSet SEMICOLON {}
            | ABOUT SEMICOLON { printAbout();}
            | SET CONNECT_DOTS ONorOFF SEMICOLON {}

ComplementoSettings: SETTINGS SEMICOLON {}

FuncoesSet: H_VIEW ValoresEscala {}
            | V_VIEW ValoresEscala {}
            | AXIS ONorOFF {}

ValoresEscala: Sinal ValorIntOrFloat COLON Sinal ValorIntOrFloat {}

Sinal: PLUS {}
    | MINUS {}
    | {}

ONorOFF: ON {}
        | OFF{}

ComandosPlus: Grafico {}
            | FuncaoRpn {}
            | Integral {}
            | Sum {}
            | Matrix {}

// --------------------------------------------------------
Grafico: PLOT InfoPlot SEMICOLON {}
        | SET ERASE PLOT ONorOFF {}

InfoPlot: L_PAREN FuncaoPlot R_PAREN {}
        | {}

FuncaoPlot: Funcoes L_PAREN InsideFuncoes R_PAREN {}

InsideFuncoes: L_PAREN InsideFuncoes R_PAREN InsideFuncoes{}
            | X InsideFuncoes{}
            | OperadoresBinarios InsideFuncoes{}
            | Constantes InsideFuncoes{}
            | ValorIntOrFloat InsideFuncoes{}
            | {}

// --------------------------------------------------------

FuncaoRpn: RPN L_PAREN Expressao R_PAREN SEMICOLON {}

// --------------------------------------------------------

Integral: SET INTEGRAL_STEPS NUM_INTEGER SEMICOLON {}
        | INTEGRATE L_PAREN IntegralAux R_PAREN SEMICOLON {}

IntegralAux: Sinal ValorIntOrFloat COLON Sinal ValorIntOrFloat COMMA Funcoes InsideFuncoes{} // isso pode dar certo



// --------------------------------------------------------

//REVER ISSO AQUI!!!!!!!!!!! NO LUGAR DO X DEVE SER UMA VARIAVEL
Sum: SUM L_PAREN IDENTIFIER COMMA NUM_INTEGER COLON NUM_INTEGER COMMA Expressao R_PAREN SEMICOLON {}

// --------------------------------------------------------

Matrix: MATRIX EQUAL CreateMatrix {}
      | SHOW MATRIX SEMICOLON {}
      | SOLVE DETERMINANT SEMICOLON {}
      | SOLVE LINEAR_SYSTEM SEMICOLON {}

CreateMatrix: L_SQUARE_BRACKET CreateMatrixAux R_SQUARE_BRACKET SEMICOLON {}

CreateMatrixAux: L_SQUARE_BRACKET Sinal ValorIntOrFloat RepeatValuesMatrixOne R_SQUARE_BRACKET RepeatValuesMatrixTwo{}

RepeatValuesMatrixOne: COMMA Sinal ValorIntOrFloat RepeatValuesMatrixOne {}
                    | {}

RepeatValuesMatrixTwo: COMMA L_SQUARE_BRACKET Sinal ValorIntOrFloat RepeatValuesMatrixOne R_SQUARE_BRACKET RepeatValuesMatrixTwo {}
                     | {}           

// ----------------   2   ----------------------------------------

ManipulacaoSimbolos: AtribuicaoValores {}
                    | AtribuicaoMatrizes {}
                    | IDENTIFIER SEMICOLON {} // mostrar valor de símbolos 
                    | SHOW SYMBOLS SEMICOLON {}
                    

AtribuicaoValores: IDENTIFIER ATRIBUTE Expressao SEMICOLON {}

AtribuicaoMatrizes: IDENTIFIER ATRIBUTE CreateMatrix {}

// -----------------------    3    --------------------------------

AvaliacaoExpressao: AvaExpressoesMatematicas {}

AvaExpressoesMatematicas: Expressao SemicolonOpcional {}

SemicolonOpcional: SEMICOLON {}
                | {}

// --------------------------  4   -----------------------------

ApresentacaoResultados: SET FLOAT PRECISION NUM_INTEGER SEMICOLON {}



Expressao: Delimitadores Expressao_aux Delimitadores {}

Expressao_aux: Funcoes L_PAREN Expressao_aux R_PAREN Expressao {}
         | X Expressao_aux {}
         | OperadoresBinarios Expressao_aux {}
         | Constantes Expressao_aux {}
         | ValorIntOrFloat Expressao_aux {}
         | IDENTIFIER Expressao_aux {}
         | {}

Delimitadores: L_PAREN {}
            | R_PAREN {}
            | {}

Funcoes: COS {}
        | SEN {}
        | TAN {}
        | ABS {}

OperadoresBinarios: PLUS {}
                    | MINUS {}
                    | MULTIPLY {}
                    | DIV {}
                    | POW {}
                    | REMAINDER {}

Constantes: PI {}
            | E {}

ValorIntOrFloat: NUM_INTEGER {}
        |   NUM_REAL {}



%%

void yyerror(char *s) {
	
        printf("Deu erro");
	exit(0);
    
}

int main(int argc, char** argv)
{
    printf(">");
    yyparse();
    
    
    printf("SUCCESSFUL COMPILATION.");
    return 0;
}