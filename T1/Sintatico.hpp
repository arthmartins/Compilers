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

void Declaracoes_prime();

void DeclaraTipo();

void DeclaraVariaveis();

void DeclaraIdentificador();

void DeclaraIdentificador_prime();

void VetorMatriz();

void Dimensao();

void Dimensao_prime();

void TipoBasico();

void BlocoComandos();

void ListaComandos();

void ListaComandos_prime();

void Comandos();

void Comandos_id();

void Comandos_se();

void Comandos_para();

void Expressao();

void Expressao_prime();

void ExpressaoSimples();

void ExpressaoSimples_prime();

void Termo();

void Termo_prime();

void Fator();

void Fator_prime();

void Variavel();

void Variavel_prime();

void ExprIter();

void ExprIter_prime();


};

#endif