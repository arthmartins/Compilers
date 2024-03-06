#include "ast.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "comandos.hpp"


extern bool not_existId;
extern std::string idName;
int contador = 0;
extern bool break_matriz;
extern int sinal_x;

std::vector<std::vector<float>>* matriz_ast;

void setContador(){
    contador = 0;
}

double RPN_Walk_calculatinge(TreeNode* aux, float x, HashTable hash){
    TreeNode* root = aux;
    double valor = 0;
    if(aux != NULL){
        RPN_Walk_calculatinge(aux->left,x,hash);
        RPN_Walk_calculatinge(aux->right,x,hash);
        switch(aux->node_type){
            case IDENTIFIER_NODE:
                if(contador == 0){
                valor += aux->value;
                }
                contador++;
                break;
            case NUMBER:
                if(contador == 0){
                valor += aux->value;
                }
                break;
            case ADD:
                aux->value = aux->left->value + aux->right->value;
                valor += aux->value;
                contador++;
                break;
            case SUB:
                aux->value = aux->left->value - aux->right->value;
                valor += aux->value;
                contador++;
                break;
            case MUL:
                aux->value = aux->left->value * aux->right->value;
                valor += aux->value;
                contador++;
                break;
            case DI:
                aux->value = aux->left->value / aux->right->value;
                valor += aux->value;
                contador++;
                break;
            case POW_NODE:
                aux->value = pow(aux->left->value, aux->right->value);
                valor += aux->value;
                contador++;
                break;

            case REM:
                aux->value = fmod(aux->left->value, aux->right->value);
                valor += aux->value;
                contador++;
                break;

            case ABS_NODE:
                aux->value = abs((int)aux->left->value);
                valor += aux->value;
                contador++;
                break;
            case SEN_NODE:
    
                aux->value = sin(aux->left->value);
                valor += aux->value;
                contador++;
                break;
            case COS_NODE:
                aux->value = cos(aux->left->value);
                valor += aux->value;
                contador++;
                break;
            case TAN_NODE:  
                aux->value = tan(aux->left->value);
                valor += aux->value;
                contador++;
                break;
            case X_NODE:
                aux->value = aux->sinal*x;
        
                if(contador == 0){
                valor += aux->value;
                }
                contador++;
                break;
        }
    }
    //pega a root e imprime o valor

    return valor;
}

void calculate(TreeNode* aux, HashTable hash){
    float valor = RPN_Walk_calculatinge(aux,0.0,hash);
    printf("%f\n", valor);
    
}

void RPN_Walk(TreeNode* aux, int float_precision )
{
    if(aux != NULL)
    {
        RPN_Walk(aux->left, float_precision);
        RPN_Walk(aux->right, float_precision);
        switch(aux->node_type)
        {
            case IDENTIFIER_NODE:
                std::cout << *aux->name << " ";
                break;
            case NUMBER:
                printf("%.*f ", float_precision,aux->value);
                break;
            case ADD:
                printf("+ ");
                break;
            case SUB:
                printf("- ");
                break;
            case MUL:
                printf("* ");
                break;
            case DI:
                printf("/ ");
                break;
            case POW_NODE:
                printf("^ ");
                break;
            case REM:
                printf("%% ");
                break;

            case ABS_NODE:
                printf("ABS ");
                break;
            case SEN_NODE:

                printf("SEN ");
                break;
            case COS_NODE:
                printf("COS ");
                break;
            case TAN_NODE:
                printf("TAN ");
                break;
            case X_NODE:
                printf("x ");
                break;
          
        }
    }
}

float RPN_Walk_somatorio(TreeNode* aux, std::string name, int i, HashTable hash){
    TreeNode* root = aux;
    float valor = 0;
    if(aux != NULL){
        RPN_Walk_somatorio(aux->left,name,i,hash);
        RPN_Walk_somatorio(aux->right,name,i,hash);
        switch(aux->node_type){
            case IDENTIFIER_NODE:
                if(*aux->name == name){
                    aux->value = i;
                }
                if(contador == 0){
                valor += aux->value;
                }
                break;
            case NUMBER:
                if(contador == 0){
                valor += aux->value;
                }
                break;
            case ADD:
                aux->value = aux->left->value + aux->right->value;
                valor += aux->value;
                contador++;
                break;
            case SUB:
                aux->value = aux->left->value - aux->right->value;
                valor += aux->value;
                contador++;
                break;
            case MUL:
                aux->value = aux->left->value * aux->right->value;
                valor += aux->value;
                contador++;
                break;
            case DI:
                aux->value = aux->left->value / aux->right->value;
                valor += aux->value;
                contador++;
                break;
            case POW_NODE:
                aux->value = pow(aux->left->value, aux->right->value);
                valor += aux->value;
                contador++;
                break;
            case REM:
                aux->value = fmod(aux->left->value, aux->right->value);
                valor += aux->value;
                contador++;
            break;

            case ABS_NODE:
                aux->value = abs((int)aux->left->value);
                valor += aux->value;
                contador++;
                break;
            case SEN_NODE:
    
                aux->value = sin(aux->left->value);
                valor += aux->value;
                contador++;
                break;
            case COS_NODE:
                aux->value = cos(aux->left->value);
                valor += aux->value;
                contador++;
                break;
            case TAN_NODE:  
                aux->value = tan(aux->left->value);
                valor += aux->value;
                contador++;
                break;
            case X_NODE:
                break;
        }
    }
    //pega a root e imprime o valor

    return valor;
}

void RPN_Walk_Errors(TreeNode* aux, HashTable hash){

    if(aux != NULL){
        RPN_Walk_Errors(aux->left,hash);
        RPN_Walk_Errors(aux->right,hash);
        switch(aux->node_type){
            case IDENTIFIER_NODE:
                
                if(hash.getType((*aux->name).c_str()) == -1){
                    printf("\nUndefined symbol [");
                    std::cout << *aux->name << "]";
                    not_existId = true;
                }
                break;
            case X_NODE:
                printf("\nThe x variable cannot be present on expressions.");
                not_existId = true;

                break;
            default:
                
                break;
        }
    }

}

void RPN_Walk_Errors_2(TreeNode* aux, HashTable hash){

    if(aux != NULL){
        RPN_Walk_Errors_2(aux->left,hash);
        RPN_Walk_Errors_2(aux->right,hash);
        switch(aux->node_type){
            case IDENTIFIER_NODE:
                
                if(hash.getType(*aux->name) == -1){
                    printf("\nUndefined symbol [");
                    std::cout << *aux->name << "]";
                    not_existId = true;
                }
                break;
        
            default:
                
                break;
        }
    }

}

void RPN_Walk_Errors_sum(TreeNode* aux,std::string name, HashTable hash){

    if(aux != NULL){
        RPN_Walk_Errors_sum(aux->left,name,hash);
        RPN_Walk_Errors_sum(aux->right,name,hash);
        switch(aux->node_type){
            case IDENTIFIER_NODE:
                if(*aux->name != name){
                    
                
                if(hash.getType(*aux->name) == -1){
                    printf("\nUndefined symbol [");
                    std::cout << *aux->name << "]";
                    not_existId = true;
                }
                }
                break;
        
            default:
                
                break;
        }
    }

}

std::vector<std::vector<float>>* RPN_Walk_matriz(TreeNode* aux, HashTable hash){
    TreeNode* root = aux;
    if(aux != NULL){
        RPN_Walk_matriz(aux->left,hash);
        RPN_Walk_matriz(aux->right,hash);
        switch(aux->node_type){
            case IDENTIFIER_NODE:
                if(contador == 0){
                    if(hash.getType(*aux->name) == 1){
                        matriz_ast = (aux->matriz_a);
                    }
                }
                break;
            case NUMBER:
                contador++;
                break;
            case ADD:
                if(!break_matriz){
                if(aux->left->node_type == NUMBER && aux->right->node_type == IDENTIFIER_NODE){
                    printf("\nIncorrect type for operator '+' - have FLOAT and MATRIX\n\n");
                    break_matriz = true;
                    matriz_ast = NULL;
                }else if (aux->left->node_type == IDENTIFIER_NODE && aux->right->node_type == NUMBER){
                    printf("\nIncorrect type for operator '+' - have MATRIX and FLOAT\n\n");
                    break_matriz = true;
                    matriz_ast = NULL;
                }else
                if(hash.getType(*aux->left->name) == 1 && hash.getType(*aux->right->name) == 1){

                    matriz_ast = addMatrices(*aux->left->matriz_a, *aux->right->matriz_a);

                    aux->matriz_a = matriz_ast;
                    aux->name = aux->left->name;
                    

                }else if(hash.getType(*aux->left->name) == 1) {    
                        printf("\nIncorrect type for operator '+' - have MATRIX and FLOAT\n\n");
                        break_matriz = true;
                    }else if(hash.getType(*aux->right->name) == 1){
                        printf("\nIncorrect type for operator '+' - have FLOAT and MATRIX\n\n");
                        break_matriz = true;
                    }
                }
                contador++;
                break;
            case SUB:
                if(!break_matriz){
                
                if(aux->left->node_type == NUMBER && aux->right->node_type == IDENTIFIER_NODE){
                    printf("\nIncorrect type for operator '-' - have FLOAT and MATRIX\n\n");
                    break_matriz = true;
                    matriz_ast = NULL;
                }else if (aux->left->node_type == IDENTIFIER_NODE && aux->right->node_type == NUMBER){
                    printf("\nIncorrect type for operator '-' - have MATRIX and FLOAT\n\n");
                    break_matriz = true;
                    matriz_ast = NULL;
                }else
                if(hash.getType(*aux->left->name) == 1 && hash.getType(*aux->right->name) == 1){
                    matriz_ast = subtractMatrices(*aux->left->matriz_a, *aux->right->matriz_a);
                    aux->matriz_a = matriz_ast;
                    aux->name = aux->left->name;
                }
                
                else if(hash.getType(*aux->left->name) == 1) {    
                        printf("\nIncorrect type for operator '-' - have MATRIX and FLOAT\n\n");
                        break_matriz = true;
                        matriz_ast = NULL;
                    }else if(hash.getType(*aux->right->name) == 1){
                        printf("\nIncorrect type for operator '-' - have FLOAT and MATRIX\n\n");  
                        break_matriz = true;
                        matriz_ast = NULL;
                    }
                }
                contador++;
                break;
            case MUL:
                if(!break_matriz){
                    if(aux->left->node_type == NUMBER && aux->right->node_type == IDENTIFIER_NODE){

                        matriz_ast = multiplyByNumber(*aux->right->matriz_a, aux->left->value);
                        aux->matriz_a = matriz_ast;
                        aux->name = aux->right->name;

                    }else if (aux->left->node_type == IDENTIFIER_NODE && aux->right->node_type == NUMBER){
                        matriz_ast = multiplyByNumber(*aux->left->matriz_a, aux->right->value);
                        aux->matriz_a = matriz_ast;
                        aux->name = aux->left->name;
                    }
                    else if(hash.getType(*aux->left->name) == 1 && hash.getType(*aux->right->name) == 1){
                        matriz_ast = multiplyMatrices(*aux->left->matriz_a, *aux->right->matriz_a);
                        aux->matriz_a = matriz_ast;
                        aux->name = aux->left->name;

                    }else if(hash.getType(*aux->left->name) == 1) {    
                        matriz_ast = multiplyByNumber(*aux->left->matriz_a,aux->right->value);
                        aux->matriz_a = matriz_ast;
                        aux->name = aux->left->name;

                    }else if(hash.getType(*aux->right->name) == 1){
                        matriz_ast = multiplyByNumber(*aux->right->matriz_a, aux->left->value);
                        aux->matriz_a = matriz_ast;
                        aux->name = aux->right->name;
                    }
                }
             contador++;
                break; 
            case SEN_NODE:
                printf("\nIncorrect type for operator 'SEN' - have MATRIX\n\n");
                break_matriz = true;
                contador++;
                break;
            case COS_NODE:
                printf("\nIncorrect type for operator 'COS' - have MATRIX\n\n");
                break_matriz = true;
                contador++;
                break;
            case TAN_NODE:
                printf("\nIncorrect type for operator 'TAN' - have MATRIX\n\n");
                break_matriz = true;
                contador++;
                break;

            case POW_NODE:
                printf("\nIncorrect type for operator 'POW' - have MATRIX\n\n");
                break_matriz = true;
                contador++;
                break;
            case REM:
                printf("\nIncorrect type for operator 'REM' - have MATRIX\n\n");
                break_matriz = true;
                contador++;
                break;
            case ABS_NODE:
                printf("\nIncorrect type for operator 'ABS' - have MATRIX\n\n");
                break_matriz = true;
                contador++;
                break;
            case X_NODE:
                printf("\nIncorrect type for operator 'x' - have MATRIX\n\n");
                break_matriz = true;
                contador++;
                break;
                
        }
    }
    

    return matriz_ast;
}


void Delete_Tree(TreeNode* ast)
{

    switch(ast->node_type) {

        /* two subtrees */
        case ADD: 
        case SUB: 
        case MUL: 
        case DI:
        case POW_NODE:
        case REM:
            Delete_Tree(ast->right);
        /* one subtree */
        case ABS_NODE:
        case SEN_NODE:
        case COS_NODE:
        case TAN_NODE:
      
            Delete_Tree(ast->left);
        /* no subtree */
        case NUMBER:
        case IDENTIFIER_NODE:
        case X_NODE:
            free(ast);
            break;
        default: 
            break;
    }

}
