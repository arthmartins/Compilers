%{
#include <stdio.h>
#include "comandos.hh"
#include <list>
#include "hash.hh"
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include "ast.hh"

#define QUIT_VALUE 329179
#define CONTINUE_VALUE 0


extern int yylex();
extern char* yytext;

extern int yychar;
extern void yylex_destroy(void);

extern bool not_existId;
bool matriz_exp = false;

std::string universal;
std::string str;
std::string str_aux;
std::string str_aux2;

std::vector<std::vector<float>> matriz_global;

HashTable hashTable;

std::list<float> listMatriz;
std::list<int> elemtsPlinha;

int elementosLinha = 0;
int maisElementosLinha = 0;
float valorExp = 0;
int sinal = 1;

TreeNode* AST = NULL;

extern void yyerror(char*); 

%}

%union{
        
TreeNode* ast;
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
%token EOL

%start Programa
 
%type <inteiro> Sinal NUM_INTEGER ONorOFF RepeatValuesMatrixOne  OperadoresBinarios
%type <string_id> IDENTIFIER X
%type <real> NUM_REAL ValorIntOrFloat Constantes  Expressao_matematica_Direta

%type <ast> Integral_Complemento Integral_DivMul Integral_aux Funcao_Integral continua_id Exp_aux Exp_Complemento Exp_DivMul Expressao_matematica

%%

Programa: Comandos EOL {return CONTINUE_VALUE;}
        | ManipulacaoSimbolos EOL {return CONTINUE_VALUE;}
        | Expressao_matematica_Direta EOL {return CONTINUE_VALUE;}
        | EOL {return CONTINUE_VALUE;}

Comandos: OnlyComandos {}
        | ComandosPlus {}

OnlyComandos: SHOW SETTINGS SEMICOLON { showSettings();}
            | RESET SETTINGS SEMICOLON { setDefaultValues(); }
            | QUIT { return QUIT_VALUE;}
            | SET FuncoesSet SEMICOLON {}
            | ABOUT SEMICOLON { printAbout(); }
            


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

FuncaoRpn: RPN L_PAREN Funcao_Integral R_PAREN SEMICOLON {    RpnFunc(AST); /*Delete_Tree(AST);*/ }

// --------------------------------------------------------

Integral: INTEGRATE L_PAREN IntegralAux R_PAREN SEMICOLON {}

IntegralAux: Sinal ValorIntOrFloat COLON Sinal ValorIntOrFloat COMMA Funcao_Integral { integrate($1*$2, $4*$5, AST,hashTable); /*Delete_Tree(AST);*/} // isso pode dar certo


Funcao_Integral: Integral_aux { AST = $1; valorExp = calculate_Exp(AST, hashTable); }


Integral_aux: Integral_DivMul { $$ = $1;}

    | Integral_aux PLUS  Integral_DivMul  {     TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = ADD;
                                                aux->value = 0;
                                                aux->name = "cos";
                                                aux->left = $1;
                                                aux->right = $3;
                                                $$ = aux;
                                        }

    | Integral_aux MINUS Integral_DivMul {      TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = SUB;
                                                aux->value = 0;
                                                aux->name = "cos";
                                                aux->left = $1;
                                                aux->right = $3;
                                                $$ = aux;
                                        }

Integral_DivMul: Integral_Complemento { $$ = $1;}
        | Integral_DivMul MULTIPLY Integral_Complemento {       TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                                aux->node_type = MUL;
                                                                aux->value = 0;
                                                                aux->name = "cos";
                                                                aux->left = $1;
                                                                aux->right = $3;
                                                                $$ = aux;
                                                        }
 
        | Integral_DivMul DIV  Integral_Complemento {   TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                        aux->node_type = DI;
                                                        aux->value = 0;
                                                        aux->name = "cos";
                                                        aux->left = $1;
                                                        aux->right = $3;
                                                        $$ = aux;
                                                        }


Integral_Complemento: Sinal  ValorIntOrFloat { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = NUMBER;
                                                aux->value = $1*$2;
                                                aux->name = "cos";
                                                aux->left = NULL;

                                                aux->right = NULL;
                                                $$ = (TreeNode*) aux;
                                                }

      | Sinal IDENTIFIER {str_aux  = strdup($2); } continua_id {   
                                        
                                        TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                        aux->node_type = IDENTIFIER_NODE;
                                        if(hashTable.search(str) == NULL){
                                                aux->value = 0;
                                                
                                        }else if(hashTable.getType(str)== 0){
                                        aux->value = $1*(*(static_cast<float*>(hashTable.search(str))));
                                        }else if(hashTable.getType(str)== 1){
                                                aux->value = 0;
                                                
                                                //multiplyMatrixByScalar(*(static_cast<std::vector<std::vector<float>>*>(hashTable.search(str))), $1);
                                                
                                                matriz_exp = true;
                                        }
                                        aux->name = str;
                                        aux->left = NULL;
                                        aux->right = NULL;
                                        $$ = (TreeNode*) aux; 
                        }

      | COS L_PAREN  Integral_Complemento  R_PAREN {    TreeNode* cosNode = (TreeNode*)malloc(sizeof(struct node));
                                                        
                                                        cosNode->node_type = COS_NODE;
                                                        cosNode->value = 0;
                                                        cosNode->name = "cos";
                                                        cosNode->left = $3; // AST do complemento
                                                        cosNode->right = NULL;
                                                        $$ = (TreeNode*) cosNode;
                                                }

      | SEN L_PAREN  Integral_Complemento  R_PAREN {    TreeNode* senNode = (TreeNode*)malloc(sizeof(struct node));
                                                        senNode->node_type = SEN_NODE;
                                                        senNode->value = 0;
                                                        senNode->name = "cos";
                                                        senNode->left = $3; // AST do complemento
                                                        senNode->right = NULL;
                                                        $$ = (TreeNode*) senNode;
                                                }
      | TAN L_PAREN  Integral_Complemento  R_PAREN {    TreeNode* tanNode = (TreeNode*)malloc(sizeof(struct node));
                                                        tanNode->node_type = TAN_NODE;
                                                        tanNode->value = 0;
                                                        tanNode->name = "cos";
                                                        tanNode->left = $3; // AST do complemento
                                                        tanNode->right = NULL;
                                                        $$ = (TreeNode*) tanNode;
                                                }

      | X {     TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                aux->node_type = X_NODE;
                                aux->value = 0;
                               
                                                        aux->name = "cos";
                                aux->left = NULL;
                                aux->right = NULL;
                                $$ = (TreeNode*) aux;
                        }

      | ABS L_PAREN Integral_Complemento R_PAREN {      TreeNode* absNode = (TreeNode*)malloc(sizeof(struct node));
                                                        absNode->node_type = ABS_NODE;
                                                        absNode->value = 0;
                                                        absNode->name = "cos";
                                                        absNode->left = $3; // AST do complemento
                                                        absNode->right = NULL;
                                                        $$ = (TreeNode*) absNode;
                                                }

      | L_PAREN  Integral_aux R_PAREN  {$$ = $2;}

      | PI { TreeNode* piNode = (TreeNode*)malloc(sizeof(struct node));
            piNode->node_type = NUMBER;
            piNode->value = M_PI;
            piNode->name = "cos";
            piNode->left = NULL;
            piNode->right = NULL;
            $$ = (TreeNode*) piNode;
            }

      | E { TreeNode* eNode = (TreeNode*)malloc(sizeof(struct node));
            eNode->node_type = NUMBER;
            eNode->value = M_E;
                eNode->name = "cos";
            eNode->left = NULL;
            eNode->right = NULL;
            $$ = (TreeNode*) eNode;
            }


// --------------------------------------------------------

Sum: SUM L_PAREN IDENTIFIER COMMA NUM_INTEGER COLON NUM_INTEGER COMMA Funcao_Integral R_PAREN SEMICOLON {somatorio($3, $5, $7, AST,hashTable); /*Delete_Tree(AST);*/}

// --------------------------------------------------------
Matrix: MATRIX EQUAL ChamaCreateMatrix {}
        | SHOW MATRIX SEMICOLON { showMatriz(); return CONTINUE_VALUE;}
      | SOLVE DETERMINANT SEMICOLON { determinanteMatriz(); return CONTINUE_VALUE;}
      | SOLVE LINEAR_SYSTEM SEMICOLON { solveLinearSystem();  return CONTINUE_VALUE;}

ChamaCreateMatrix: CreateMatrix {  
                                
                                 matriz_global = createMatriz(listMatriz,elemtsPlinha,maisElementosLinha); elementosLinha = 0; maisElementosLinha = 0;
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



ManipulacaoSimbolos: SHOW SYMBOLS SEMICOLON { hashTable.printAll();}
                   

continua_id: ATRIBUTE {str_aux2 = str_aux;} continua_atribute {}
        | SEMICOLON EOL {printValorSimbolo(str_aux, hashTable);  matriz_exp = false; return CONTINUE_VALUE;}
        | { }

continua_atribute: Expressao_matematica SEMICOLON EOL { sinal = 1; if(!not_existId){hashTable.insert(str_aux2,valorExp);} not_existId = false; /*Delete_Tree(AST);*/; return CONTINUE_VALUE;}
                | ChamaCreateMatrix EOL {sinal = 1; hashTable.insert(str,matriz_global);/*Delete_Tree(AST);*/ not_existId = false; matriz_exp = false; return CONTINUE_VALUE;}






Expressao_matematica_Direta: Funcao_Integral {if(!not_existId && !matriz_exp){printValorCalculoExp(valorExp);} matriz_exp =false; not_existId = false; /*Delete_Tree(AST);*/}
                            
                            


// Tirei uma produção vazia aqui caso de erro
Expressao_matematica: {}
                        |Expressao_matematica Exp_aux{ AST = $2; if(!not_existId) {valorExp = calculate_Exp(AST, hashTable); } not_existId = false; }

Exp_aux: Exp_DivMul {  $$ = $1;}
    | Exp_aux PLUS Exp_DivMul {     TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = ADD;
                                                aux->value = 0;
                                                aux->left = $1;
                                                aux->right = $3;
                                                $$ = aux;  
                                        }

    | Exp_aux MINUS Exp_DivMul {   TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = SUB;
                                                aux->value = 0;
                                                aux->left = $1;
                                                aux->right = $3;
                                                $$ = aux;}

Exp_DivMul: Exp_Complemento { $$ = $1; }
        | Exp_DivMul MULTIPLY Exp_Complemento {    TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                                aux->node_type = MUL;
                                                                aux->value = 0;
                                                                aux->left = $1;
                                                                aux->right = $3;
                                                                $$ = aux;}

        | Exp_DivMul DIV Exp_Complemento { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                        aux->node_type = DI;
                                                        aux->value = 0;
                                                        aux->left = $1;
                                                        aux->right = $3;
                                                        $$ = aux;}           
                                        

Exp_Complemento: Sinal ValorIntOrFloat { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                                aux->node_type = NUMBER;
                                                aux->value = $1*$2;
                                                aux->left = NULL;
                                                aux->right = NULL;
                                                $$ = (TreeNode*) aux; }

        | Sinal IDENTIFIER  {TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                        aux->node_type = IDENTIFIER_NODE;
                                        if(hashTable.search(str) == NULL){
                                                aux->value = 0;
                                        }else{

                                        aux->value = $1*(*(static_cast<float*>(hashTable.search(str))));
                                        }
                                       
                                        aux->name = str;
                                        aux->left = NULL;
                                        aux->right = NULL;
                                        $$ = (TreeNode*) aux; }

        | COS L_PAREN Exp_Complemento R_PAREN {  TreeNode* cosNode = (TreeNode*)malloc(sizeof(struct node));
                                                        cosNode->node_type = COS_NODE;
                                                        cosNode->left = $3; // AST do complemento
                                                        cosNode->right = NULL;
                                                        $$ = (TreeNode*) cosNode;}
        | SEN L_PAREN Exp_Complemento R_PAREN {  TreeNode* senNode = (TreeNode*)malloc(sizeof(struct node));
                                                        senNode->node_type = SEN_NODE;
                                                        senNode->left = $3; // AST do complemento
                                                        senNode->right = NULL;
                                                        $$ = (TreeNode*) senNode;}
        | TAN L_PAREN Exp_Complemento R_PAREN { TreeNode* tanNode = (TreeNode*)malloc(sizeof(struct node));
                                                        tanNode->node_type = TAN_NODE;
                                                        tanNode->left = $3; // AST do complemento
                                                        tanNode->right = NULL;
                                                        $$ = (TreeNode*) tanNode; }
        | X { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
                                aux->node_type = X_NODE;
                                aux->value = 0;
                                aux->left = NULL;
                                aux->right = NULL;
                                $$ = (TreeNode*) aux; }
        | PI { TreeNode* piNode = (TreeNode*)malloc(sizeof(struct node));
            piNode->node_type = NUMBER;
            piNode->value = M_PI;
            piNode->left = NULL;
            piNode->right = NULL;
            $$ = (TreeNode*) piNode;
            }

      | E { TreeNode* eNode = (TreeNode*)malloc(sizeof(struct node));
            eNode->node_type = NUMBER;
            eNode->value = M_E;
            eNode->left = NULL;
            eNode->right = NULL;
            $$ = (TreeNode*) eNode;
            }
        | ABS L_PAREN Exp_Complemento R_PAREN { TreeNode* absNode = (TreeNode*)malloc(sizeof(struct node));
                                                        absNode->node_type = ABS_NODE;
                                                        absNode->left = $3; // AST do complemento
                                                        absNode->right = NULL;
                                                        $$ = (TreeNode*) absNode; }
        | L_PAREN Exp_aux R_PAREN { $$ = $2; }
        



Funcoes: COS {}
        | SEN {}
        | TAN {}

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