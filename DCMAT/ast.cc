#include "ast.hh"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "comandos.hh"


extern bool not_existId;
extern std::string idName;
int contador = 0;

std::vector<std::vector<float>> matriz_ast;

void setContador(){
    contador = 0;
}

float RPN_Walk_calculatinge(TreeNode* aux, float x, HashTable hash){
    TreeNode* root = aux;
    float valor = 0;
    if(aux != NULL){
        RPN_Walk_calculatinge(aux->left,x,hash);
        RPN_Walk_calculatinge(aux->right,x,hash);
        switch(aux->node_type){
            case IDENTIFIER_NODE:
                if(hash.getType(aux->name) == -1){
                    idName = aux->name;
                    not_existId = true;
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
                aux->value = x;
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
                printf("\n\n\n\n\n");
                std::cout << aux->name << " ";
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
                if(aux->name == name){
                    aux->value = i;
                }else if (hash.getType(aux->name) == -1){
                    idName = aux->name;
                    not_existId = true;
                }
                break;
            case NUMBER:
                
                break;
            case ADD:
                aux->value = aux->left->value + aux->right->value;
                valor += aux->value;
                break;
            case SUB:
                aux->value = aux->left->value - aux->right->value;
                valor += aux->value;
                break;
            case MUL:
                aux->value = aux->left->value * aux->right->value;
                valor += aux->value;
                break;
            case DI:
                aux->value = aux->left->value / aux->right->value;
                valor += aux->value;
                break;
            case ABS_NODE:
                aux->value = abs((int)aux->left->value);
                valor += aux->value;
                break;
            case SEN_NODE:
    
                aux->value = sin(aux->left->value);
                valor += aux->value;
                break;
            case COS_NODE:
                aux->value = cos(aux->left->value);
                valor += aux->value;
                break;
            case TAN_NODE:  
                aux->value = tan(aux->left->value);
                valor += aux->value;
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
                
                if(hash.getType(aux->name) == -1){
                    printf("\nUndefined symbol [");
                    std::cout << aux->name << "]";
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

std::vector<std::vector<float>> RPN_Walk_matriz(TreeNode* aux, HashTable hash){
    TreeNode* root = aux;
    if(aux != NULL){
        RPN_Walk_matriz(aux->left,hash);
        RPN_Walk_matriz(aux->right,hash);
        switch(aux->node_type){
            case IDENTIFIER_NODE:
                
                break;
            case NUMBER:
                
                break;
            case ADD:
                if(hash.getType(aux->left->name) == 1 && hash.getType(aux->right->name) == 1){
                    matriz_ast = addMatrices(*(static_cast<std::vector<std::vector<float>>*>(hash.search(aux->left->name))), *(static_cast<std::vector<std::vector<float>>*>(hash.search(aux->right->name))));
                }
                break;
            case SUB:
                if(hash.getType(aux->left->name) == 1 && hash.getType(aux->right->name) == 1){
                    matriz_ast = subtractMatrices(*(static_cast<std::vector<std::vector<float>>*>(hash.search(aux->left->name))), *(static_cast<std::vector<std::vector<float>>*>(hash.search(aux->right->name))));
                }
                
                break;
            case MUL:
                aux->value = aux->left->value * aux->right->value;
                
        }
    }
    //pega a root e imprime o valor

    return matriz_ast;
}


void Delete_Tree(TreeNode* aux)
{
    if(aux != NULL)
    {
        Delete_Tree(aux->left);
        Delete_Tree(aux->right);
        free(aux);
    }
}

