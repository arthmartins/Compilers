#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <string>
#include "hash.hpp"


#define IDENTIFIER_NODE 1
#define NUMBER 2
#define ADD 3
#define SUB 4
#define MUL 5
#define DI 6
#define ABS_NODE 7
#define SEN_NODE 8
#define COS_NODE 9
#define TAN_NODE 10
#define X_NODE 11
#define POW_NODE 12
#define REM 13


typedef struct node TreeNode;
struct node
{
int node_type;
float value;
std::string* name;
int sinal;
vector<vector<float>>* matriz_a;

TreeNode* left;
TreeNode* right;
};

void RPN_Walk(TreeNode* aux, int float_precision);
void Delete_Tree(TreeNode* aux);



void calculate(TreeNode* aux, HashTable hash);

double RPN_Walk_calculatinge(TreeNode* aux, float x, HashTable hash);

float RPN_Walk_somatorio(TreeNode* aux, std::string name, int i, HashTable hash);

void RPN_Walk_Errors(TreeNode* aux, HashTable hash);

void setContador();

std::vector<std::vector<float>>* RPN_Walk_matriz(TreeNode* aux, HashTable hash);

void RPN_Walk_Errors_2(TreeNode* aux, HashTable hash);

void RPN_Walk_Errors_sum(TreeNode* aux,std::string name, HashTable hash);

#endif