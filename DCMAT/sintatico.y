%{

#include <stdio.h>
extern int yylex();
extern char* yytext;
extern int entradas;
extern int linha;
extern int coluna;
extern int yychar;
extern int linha_anterior;
extern int coluna_anterior;
extern char erro_linha[2048];
extern void pick_erro_linha(int linha);

void yyerror(void *s); 

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

Programa: Comandos {}
        | ManipulacaoSimbolos {}
        | AvaliacaoExpressao {}
        | ApresentacaoResultados {}


Comandos: OnlyComandos {}
        | ComandosPlus {}

OnlyComandos: SHOW ComplementoSettings {}
            | RESET ComplementoSettings {}
            | QUIT {}
            | SET FuncoesSet SEMICOLON {}
            | ABOUT SEMICOLON {}

ComplementoSettings: SETTINGS SEMICOLON {}

FuncoesSet: H_VIEW ValoresEscala {}
            | V_VIEW ValoresEscala {}
            | AXIS ONorOFF {}

ValoresEscala: Sinal ValorIntOrFloat COLON Sinal ValorIntOrFloat {}

ValorIntOrFloat: NUM_INTEGER {}
        |   NUM_REAL {}

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

FuncaoPlot: Funcoes InsideFuncoes{}

InsideFuncoes: L_PAREN InsideFuncoes R_PAREN{}
            | Sinal X InsideFuncoes{}
            | OperadoresBinarios InsideFuncoes{}
            | Sinal Constantes InsideFuncoes{}
            | Sinal ValorIntOrFloat InsideFuncoes{}
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

Matrix: MATRIX CreateMatrix {}
      | SHOW MATRIX SEMICOLON {}
      | SOLVE DETERMINANT SEMICOLON {}
      | SOLVE LINEAR_SYSTEM SEMICOLON {}

CreateMatrix: EQUAL L_SQUARE_BRACKET CreateMatrixAux R_SQUARE_BRACKET SEMICOLON {}

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
                    

AtribuicaoValores: IDENTIFIER COLON EQUAL Expressao SEMICOLON {}

AtribuicaoMatrizes: IDENTIFIER COLON CreateMatrix {}

// -----------------------    3    --------------------------------

AvaliacaoExpressao: AvaExpressoesMatematicas {}

AvaExpressoesMatematicas: Expressao SemicolonOpcional {}

SemicolonOpcional: SEMICOLON {}
                |   {}

// --------------------------  4   -----------------------------

ApresentacaoResultados: SET FLOAT PRECISION NUM_INTEGER SEMICOLON {}



Expressao: Delimitadores Expressao Delimitadores {}
         | Funcoes L_PAREN Expressao R_PAREN Expressao {}
         | X Expressao {}
         | OperadoresBinarios Expressao {}
         | Constantes Expressao {}
         | ValorIntOrFloat Expressao {}
         | IDENTIFIER Expressao {}
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



%%

void yyerror(void *s) {
	
    //linha = linha_anterior;
    //coluna = coluna_anterior;
    //pick_erro_linha(linha);
    if(entradas > 0)
        printf("\n");
     if (yychar == 0) {

                pick_erro_linha(linha_anterior);
                printf("error:syntax:%d:%d: expected declaration or statement at end of input\n%s", linha_anterior, coluna_anterior, erro_linha);
                for(int i = 0; i < coluna_anterior -1; i++) {
                    printf(" ");
                }
                printf("^");
        } else {
            pick_erro_linha(linha);
	        coluna -= strlen(yytext);
                printf("error:syntax:%d:%d: %s\n%s", linha, coluna, yytext, erro_linha);
                for(int i = 0; i < coluna -1; i++) {
                    printf(" ");
                }
                printf("^");
        }
	exit(0);
    
}

int main(int argc, char** argv)
{
    yyparse();
    if(entradas > 0)
        printf("\n");
    
    printf("SUCCESSFUL COMPILATION.");
    return 0;
}