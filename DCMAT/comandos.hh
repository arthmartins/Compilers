#include "ast.hh"

#ifndef COMANDOS_HH
#define COMANDOS_HH

#define H_VIEW_LO_DEFAULT -6.5
#define H_VIEW_HI_DEFAULT 6.5
#define V_VIEW_LO_DEFAULT -3.5
#define V_VIEW_HI_DEFAULT 3.5
#define FLOAT_PRECISION_DEFAULT 6
#define INTEGRAL_STEPS_DEFAULT 1000

#define DRAW_AXIX_DEFAULT true
#define ERASE_PLOT_DEFAULT true
#define CONNECT_DOTS_DEFAULT false

#include <vector>
#include <list>
#include <iostream>
#include "hash.hh"
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <string>



void setDefaultValues();

void showSettings();

void printAbout();

void setH_view(float h_lo, float h_hi);

void setV_view(float v_lo, float v_hi);

void setAxis(int valor);

void setErase(int valor);

void setConnectDots(int valor);

void setFloatPrecision(int valor);

void setIntegralSteps(int valor);

std::vector<std::vector<float>> createMatriz(std::list<float>& listaMatriz, std::list<int>& ElementsPLinha, int numerodeColunas);

void showMatriz();

void determinanteMatriz();

void solveLinearSystem() ;

void printValorSimbolo(std::string name, HashTable hash); 

void printMatriz(std::vector<std::vector<float>> matriz_aux);

void integrate(float a, float b, TreeNode* ast, HashTable hash);

void RpnFunc(TreeNode* ast);

void somatorio(std::string variavel,float a, float b, TreeNode* ast, HashTable hash);

float calculate_Exp(TreeNode* ast, HashTable hash);

void printValorCalculoExp(float valor);

void multiplyMatrixByScalar(std::vector<std::vector<float>>& matrix, int scalar);

std::vector<std::vector<float>> addMatrices(std::vector<std::vector<float>> matrix1, std::vector<std::vector<float>> matrix2);

std::vector<std::vector<float>> solve_Matriz_expressao(TreeNode* ast, HashTable hash);

std::vector<std::vector<float>> subtractMatrices(std::vector<std::vector<float>> matrix1, std::vector<std::vector<float>> matrix2);

std::vector<std::vector<float>> multiplyMatrices(const std::vector<std::vector<float>>& matrix1, const std::vector<std::vector<float>>& matrix2);

std::vector<std::vector<float>> multiplyByNumber(const std::vector<std::vector<float>>& matrix, float scalar);

void plotarGrafico(TreeNode *plot, HashTable hash);

#endif