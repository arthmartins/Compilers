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

%token VOID
%token INT
%token CHAR
%token RETURN
%token BREAK
%token SWITCH
%token CASE
%token DEFAULT
%token DO
%token WHILE
%token FOR
%token IF
%token ELSE
%token TYPEDEF
%token STRUCT
%token PLUS
%token MINUS
%token MULTIPLY
%token DIV
%token REMAINDER
%token INC
%token DEC
%token BITWISE_AND
%token BITWISE_OR
%token BITWISE_NOT
%token BITWISE_XOR
%token NOT
%token LOGICAL_AND
%token LOGICAL_OR
%token EQUAL
%token NOT_EQUAL
%token LESS_THAN
%token GREATER_THAN
%token LESS_EQUAL
%token GREATER_EQUAL
%token R_SHIFT
%token L_SHIFT
%token ASSIGN
%token ADD_ASSIGN
%token MINUS_ASSIGN
%token SEMICOLON
%token COMMA
%token COLON
%token L_PAREN
%token R_PAREN
%token L_CURLY_BRACKET
%token R_CURLY_BRACKET
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token TERNARY_CONDITIONAL
%token NUMBER_SIGN
%token POINTER
%token PRINTF
%token SCANF
%token DEFINE
%token EXIT
%token NUM_OCTAL
%token NUM_INTEGER
%token NUM_HEXA
%token STRING
%token CHARACTER
%token IDENTIFIER


%start Programa

%%

Programa: Declaracoes Programa_2 {}
	        | Funcao Programa_2 {}

Programa_2: Programa{}
	        | {}

Declaracoes: NUMBER_SIGN DEFINE IDENTIFIER Expressao {}
            | Declara_variavel {}
            | Declara_prototipos {}

Funcao: Tipo Asterisco_aux IDENTIFIER Parametros L_CURLY_BRACKET Funcao_aux Comandos R_CURLY_BRACKET {}

Funcao_aux: Declara_variavel Funcao_aux {}
                    | {}

Asterisco_aux: MULTIPLY Asterisco_aux {}
            | {}

Declara_variavel: Tipo Declara_variavel_aux SEMICOLON {}

Declara_variavel_aux: Asterisco_aux IDENTIFIER Exp_Bet_Paren Declara_variavel_ExpAtrib Declara_variavel_loop {}

Declara_variavel_loop: COMMA Declara_variavel_aux {}
                    |   {}

Exp_Bet_Paren: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET {}
                    | {}

Declara_variavel_ExpAtrib: ASSIGN Expressao_atribuicao {}
                        |   {}

Declara_prototipos:  Tipo Asterisco_aux IDENTIFIER Parametros SEMICOLON {}

Parametros: L_PAREN Parametros_Going R_PAREN {}

Parametros_Going: Parametros_Type {}
                | {} 

Parametros_Type: Tipo Asterisco_aux IDENTIFIER Exp_Bet_Paren Parametros_Type_aux {}

Parametros_Type_aux: COMMA Parametros_Type
                    | {}

Tipo: INT {}
    | CHAR {}
    | VOID {}

Bloco: L_CURLY_BRACKET Comandos R_CURLY_BRACKET {} 

Comandos: Lista_comandos Comandos_loop {}

Comandos_loop: Comandos {}
            |   {}

Lista_comandos: DO Bloco WHILE L_PAREN Expressao R_PAREN SEMICOLON {}
            |   IF L_PAREN Expressao R_PAREN Bloco If_aux {}
            |   WHILE L_PAREN Expressao R_PAREN Bloco {}
            |   FOR L_PAREN For_aux SEMICOLON For_aux SEMICOLON For_aux R_PAREN Bloco {}
            |   PRINTF L_PAREN STRING Print_aux R_PAREN SEMICOLON {}
            |   SCANF L_PAREN STRING COMMA BITWISE_AND IDENTIFIER R_PAREN SEMICOLON {}
            |   EXIT L_PAREN Expressao R_PAREN SEMICOLON {}
            |   RETURN For_aux SEMICOLON {}
            |   Expressao SEMICOLON {}
            |   SEMICOLON {}
            |   Bloco {}

Print_aux:  COMMA Expressao {}
            | {}

For_aux: Expressao {}
        | {}

If_aux: ELSE Bloco {}
    | {}

Expressao:   Expressao_atribuicao {}
        |   Expressao COMMA Expressao_atribuicao {}

Expressao_atribuicao: Expressao_condicional {}
                    | Expressao_unaria Select_Unary Expressao_atribuicao {}

Select_Unary: ASSIGN {}
            | ADD_ASSIGN {}
            | MINUS_ASSIGN {}

Expressao_condicional: Expressao_OR_Logico {}
                    | Expressao_OR_Logico TERNARY_CONDITIONAL Expressao COLON Expressao_condicional {} 

Expressao_OR_Logico: Expressao_AND_Logico {}
                    | Expressao_OR_Logico LOGICAL_OR Expressao_AND_Logico {}

Expressao_AND_Logico: Expressao_OR {}
                    | Expressao_AND_Logico LOGICAL_AND Expressao_OR {}

Expressao_OR: Expressao_XOR {}
            | Expressao_OR BITWISE_OR Expressao_XOR {}

Expressao_XOR: Expressao_AND {}
            | Expressao_XOR BITWISE_XOR Expressao_AND {}

Expressao_AND: Expressao_igualdade {}
            | Expressao_AND BITWISE_AND Expressao_igualdade {}

Expressao_igualdade: Expressao_relacional {}
                    |Expressao_igualdade Expressao_igualdade_aux Expressao_relacional {}

Expressao_igualdade_aux: EQUAL {}
                        | NOT_EQUAL {}

Expressao_relacional: Expressao_shift {}
                    | Expressao_relacional Expressao_relacional_aux Expressao_shift {}

Expressao_relacional_aux: LESS_THAN {}
                        | GREATER_THAN {}
                        | LESS_EQUAL {}
                        | GREATER_EQUAL {}

Expressao_shift: Expressao_aditiva {}
                | Expressao_shift Expressao_shift_aux Expressao_aditiva {}

Expressao_shift_aux: R_SHIFT {}
                    | L_SHIFT {}

Expressao_aditiva: Expressao_multiplicativa {}
                | Expressao_aditiva Expressao_aditiva_aux Expressao_multiplicativa {}

Expressao_aditiva_aux: PLUS {}
                    |   MINUS {}

Expressao_multiplicativa: Expressao_cast {}
                | Expressao_multiplicativa Expressao_multiplicativa_aux Expressao_cast {}

Expressao_multiplicativa_aux: MULTIPLY {}
                            | DIV {}
                            | REMAINDER {}

Expressao_cast: Expressao_unaria {}
            |   L_PAREN Tipo Asterisco_aux R_PAREN Expressao_cast {}

Expressao_unaria: Expressao_pos_fixa {}
                | INC Expressao_unaria {}
                | DEC Expressao_unaria {}
                | Operadores Expressao_cast {}

Operadores: PLUS {}
        |   MINUS {}
        |   MULTIPLY {}
        |   BITWISE_AND {}
        |   BITWISE_NOT {}
        |   NOT {}

Expressao_pos_fixa: Expressao_primaria  {}
                |   Expressao_pos_fixa Pos_fixo_operators {}

Pos_fixo_operators: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET {}
                |   INC {}
                |   DEC {}
                |   L_PAREN Exp_atribuicao_aux R_PAREN {}

Exp_atribuicao_aux: Expressao_pos_fixa_aux {}
                    | {}

Expressao_pos_fixa_aux: Expressao_atribuicao Comma_aux {}

Comma_aux: COMMA Exp_atribuicao_aux {}
        | {}

Expressao_primaria: IDENTIFIER {}
                |   Numero {}
                |   CHARACTER {}
                |   STRING  {}
                |   L_PAREN Expressao R_PAREN {}

Numero: NUM_INTEGER {}
    |   NUM_HEXA {}
    |   NUM_OCTAL {}

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