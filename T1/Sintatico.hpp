#ifndef SINTATICO_HPP
#define SINTATICO_HPP

#include <iostream>
#include "lexico.hpp"
using namespace std;


class Sintatico
{
public:

void setEntrada(string inString);

void ErroSintatico();

void advance();

void eat(int t);

void Programa();

void ProcedimentoFuncao();

void DeclaraProcedimento();

void DeclaraFuncao();

void Parametros();

void DeclaraParametros();

void BlocoVariaveis();

void Declaracoes();

void Declaracoes_aux();

void DeclaraTipo();

void DeclaraVariaveis();

void DeclaraIdentificador();

void DeclaraIdentificador_aux();

void VetorMatriz();

void Dimensao();

void Dimensao_aux();

void TipoBasico();

void BlocoComandos();

void ListaComandos();

void ListaComandos_aux();

void Comandos();

void Comandos_id();

void Comandos_se();

void Comandos_para();

void Expressao();

void Expressao_aux();

void ExpressaoSimples();

void ExpressaoSimples_aux();

void Termo();

void Termo_aux();

void Fator();

void Fator_aux();

void Variavel();

void Variavel_aux();

void ExprIter();

void ExprIter_aux();


};

#endif