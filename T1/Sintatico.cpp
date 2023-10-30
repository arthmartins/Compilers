#include <iostream>
#include "Sintatico.hpp"
#include "automato.hpp"

using namespace std;

int token;

static string entrada;

Lexico lexico;

void Sintatico:: setEntrada(string inString){
    entrada = inString;
    lexico.setVariaveis();
    token = lexico.analyserLexic(entrada);
    while(token == COMENTARIO_LINHA || token == COMENTARIO_BLOCO){
        token = lexico.analyserLexic(entrada);
    }
}

void Sintatico:: ErroSintatico()
{
    printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> ''",lexico.getLinha_token(),lexico.getColuna_token());
    exit(1);
}

void Sintatico:: advance()
{
    token = lexico.analyserLexic(entrada);
    while(token == COMENTARIO_LINHA || token == COMENTARIO_BLOCO || token == WHITESPACE){
        token = lexico.analyserLexic(entrada);
    }
}

void Sintatico:: eat(int t){
    if(token == t)
    {
        advance();

    }else{
        ErroSintatico();
    }
}

void Sintatico:: Programa()
{
    eat(ALGORITMO); eat(ID); eat(PONTO_VIRGULA); BlocoVariaveis(); 
    ProcedimentoFuncao(); BlocoComandos(); eat(PONTO);
    cout << "PROGRAMA CORRETO.";
}

void Sintatico:: ProcedimentoFuncao()
{
    switch (token)
    {
        case(PROCEDIMENTO): DeclaraProcedimento(); ProcedimentoFuncao(); break;
        case(FUNCAO): DeclaraFuncao(); ProcedimentoFuncao(); break;
        case(INICIO): break;

        default: ErroSintatico(); break;
    }
}

void Sintatico:: DeclaraProcedimento()
{
    switch (token)
    {
        case(PROCEDIMENTO): 
            eat(PROCEDIMENTO); 
            eat(ID); 
            Parametros();
            eat(PONTO_VIRGULA); 
            DeclaraParametros(); 
            BlocoVariaveis(); 
            BlocoComandos(); 
            eat(PONTO_VIRGULA); 
        break;


        default: 
            ErroSintatico(); 
        break;
    }
}

void Sintatico:: DeclaraFuncao()
{
    switch (token)
    {
        case(FUNCAO): 
           eat(FUNCAO);
           eat(ID);
           Parametros();
           eat(DOIS_PONTOS);
           TipoBasico();
           eat(PONTO_VIRGULA);
           DeclaraParametros();
           BlocoVariaveis();
           BlocoComandos();
           eat(PONTO_VIRGULA);
        break;


        default: 
            ErroSintatico(); 
        break;
    }
}

void Sintatico:: Parametros()
{
    switch (token)
    {
        case(ABRE_PAREN):
            eat(ABRE_PAREN);
            DeclaraIdentificador();
            eat(FECHA_PAREN); 
        break;

        case(PONTO_VIRGULA):
        break;

        case(DOIS_PONTOS):
        break;

        default: 
            ErroSintatico(); 
        break;
    }
}

void Sintatico:: DeclaraParametros()
{
    switch (token)
    {
        case(TIPO): 
           Declaracoes();
            break;

        case(INTEIRO): 
           Declaracoes();
            break;

        case(REAL): 
           Declaracoes();
            break;

        case(CARACTERE): 
           Declaracoes();
            break;

        case(LOGICO): 
           Declaracoes();
            break;

        case(VARIAVEIS): 
           break;

        case(ID): 
           Declaracoes();
            break;

        case(INICIO): 
            break;
        


        default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: BlocoVariaveis()
{
    switch (token)
    {
        case(VARIAVEIS): 
            eat(VARIAVEIS);
            Declaracoes();
           break;

        case(INICIO): 
            break;
        case(PROCEDIMENTO): 
            break;
        case(FUNCAO):
            break;
        default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: Declaracoes()
{
     switch (token)
    {
        case(TIPO): 
            DeclaraTipo();
            Declaracoes_prime();
            break;

        case(INTEIRO): 
            DeclaraVariaveis();
            Declaracoes_prime();
            break;

        case(REAL): 
            DeclaraVariaveis();
            Declaracoes_prime();
            break;

        case(CARACTERE): 
            DeclaraVariaveis();
            Declaracoes_prime();
            break;

        case(LOGICO): 
            DeclaraVariaveis();
            Declaracoes_prime();
            break;

        case(ID): 
            DeclaraVariaveis();
            Declaracoes_prime();
            break;
    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: Declaracoes_prime()
{
     switch (token)
    {
        case(TIPO): 
            Declaracoes();
            break;

        case(INTEIRO): 
            Declaracoes();
            break;

        case(REAL): 
            Declaracoes();
            break;

        case(CARACTERE): 
            Declaracoes();
            break;

        case(LOGICO): 
            Declaracoes();
            break;

        case(ID): 
            Declaracoes();
            break;

        case(PROCEDIMENTO):
            break;
        case(FUNCAO):
            break;
        case(VARIAVEIS):
            break;
        case(INICIO):
            break;

    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: DeclaraTipo()
{
     switch (token)
    {
        case(TIPO): 
            eat(TIPO);
            eat(ID);
            eat(IGUAL);
            VetorMatriz();
            eat(ABRE_COLCH);
            Dimensao();
            eat(FECHA_COLCH);
            TipoBasico();
            eat(PONTO_VIRGULA);
            break;
            
    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: DeclaraVariaveis()
{
     switch (token)
    {
        case(INTEIRO): 
            TipoBasico();
            eat(DOIS_PONTOS);
            DeclaraIdentificador();
            eat(PONTO_VIRGULA);
            break;

        case(REAL): 
            TipoBasico();
            eat(DOIS_PONTOS);
            DeclaraIdentificador();
            eat(PONTO_VIRGULA);
            break;

        case(CARACTERE): 
            TipoBasico();
            eat(DOIS_PONTOS);
            DeclaraIdentificador();
            eat(PONTO_VIRGULA);
            break;

        case(LOGICO): 
            TipoBasico();
            eat(DOIS_PONTOS);
            DeclaraIdentificador();
            eat(PONTO_VIRGULA);
            break;

        case(ID): 
            TipoBasico();
            eat(DOIS_PONTOS);
            DeclaraIdentificador();
            eat(PONTO_VIRGULA);
            break;

    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: DeclaraIdentificador()
{
     switch (token)
    {
        case(ID): 
            eat(ID);
            DeclaraIdentificador_prime();
            break;
            
    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: DeclaraIdentificador_prime()
{
     switch (token)
    {
        case(VIRGULA): 
            eat(VIRGULA);
            DeclaraIdentificador(); // AQUI ESTAVA DECLARAIDENTIFICADOR_PRIME
            break;
        case(PONTO_VIRGULA):
            break;
        case(FECHA_PAREN):
            break;

    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: VetorMatriz()
{
     switch (token)
    {
        case(VETOR): 
            eat(VETOR);
            break;
        case(MATRIZ):
            eat(MATRIZ);
            break;
        

    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: Dimensao()
{
     switch (token)
    {
        case(NUM_INTEIRO): 
            eat(NUM_INTEIRO);
            eat(DOIS_PONTOS);
            eat(NUM_INTEIRO);
            Dimensao_prime();
            break;
        
        

    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: Dimensao_prime()
{
     switch (token)
    {
        case(VIRGULA): 
            eat(VIRGULA);
            Dimensao();
            break;
        
        case(FECHA_COLCH):
            break;
        

    default: 
            ErroSintatico(); 
            break;
    }
}


void Sintatico:: TipoBasico()
{
     switch (token)
    {
        case(INTEIRO): 
            eat(INTEIRO);
            break;

        case(REAL): 
            eat(REAL);
            break;

        case(CARACTERE): 
            eat(CARACTERE);
            break;

        case(LOGICO): 
            eat(LOGICO);
            break;

        case(ID): 
            eat(ID);
            break;

    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: BlocoComandos()
{
     switch (token)
    {
        case(INICIO): 
            eat(INICIO);
            ListaComandos();
            eat(FIM);
            break;

    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: ListaComandos()
{
     switch (token)
    {
        case(ID): 
            Comandos();
            eat(PONTO_VIRGULA);
            ListaComandos_prime();
            break;

        case(SE): 
            Comandos();
            eat(PONTO_VIRGULA);
            ListaComandos_prime();
            break;

        case(ENQUANTO): 
            Comandos();
            eat(PONTO_VIRGULA);
            ListaComandos_prime();
            break;

        case(PARA): 
            Comandos();
            eat(PONTO_VIRGULA);
            ListaComandos_prime();
            break;

        case(REPITA): 
            Comandos();
            eat(PONTO_VIRGULA);
            ListaComandos_prime();
            break;

        case(LEIA): 
            Comandos();
            eat(PONTO_VIRGULA);
            ListaComandos_prime();
            break;

        case(IMPRIMA): 
            Comandos();
            eat(PONTO_VIRGULA);
            ListaComandos_prime();
            break;

    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: ListaComandos_prime()
{
     switch (token)
    {
        case(ID): 
            ListaComandos();
            break;

        case(SE): 
            ListaComandos();
            break;

        case(ENQUANTO): 
            ListaComandos();
            break;

        case(PARA): 

            ListaComandos();
            break;

        case(REPITA): 
            ListaComandos();
            break;

        case(LEIA): 
            ListaComandos();
            break;
            
        case(IMPRIMA): 
            ListaComandos();
            break;
        
        case(FIM):
            break;
        
        case(SENAO):
            break;
        
        case(ATE):
            break;

    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: Comandos()
{
     switch (token)
    {
        case(ID): 
            eat(ID);
            Comandos_id();
            break;

        case(SE): 
            eat(SE);
            Expressao();
            eat(ENTAO);
            ListaComandos();
            Comandos_se();

            break;

        case(ENQUANTO): 
            eat(ENQUANTO);
            Expressao();
            eat(FACA);
            ListaComandos();
            eat(FIM);
            eat(ENQUANTO);
            break;

        case(PARA): 
            eat(PARA);
            eat(ID);
            eat(DE);
            Expressao();
            eat(ATE);
            Expressao();
            Comandos_para();
            break;

        case(REPITA): 
            eat(REPITA);
            ListaComandos();
            eat(ATE);
            Expressao();
            break;

        case(LEIA): 
            eat(LEIA);
            eat(ABRE_PAREN);
            Variavel();
            eat(FECHA_PAREN);
            break;

        case(IMPRIMA): 
            eat(IMPRIMA);
            eat(ABRE_PAREN);
            ExprIter();
            eat(FECHA_PAREN);
            break;

    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: Comandos_id()
{
     switch (token)
    {
        case(PONTO_VIRGULA):
            break;
        
        case(ATRIBUICAO):
            eat(ATRIBUICAO);
            Expressao();
            break;
        case(ABRE_PAREN):
            eat(ABRE_PAREN);
            ExprIter();
            eat(FECHA_PAREN);
            break;
        case(ABRE_COLCH):
            eat(ABRE_COLCH);
            ExprIter();
            eat(FECHA_COLCH);
            eat(ATRIBUICAO);
            Expressao();

            break;

    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: Comandos_se()
{
     switch (token)
    {
        case(FIM):
            eat(FIM);
            eat(SE);
            break;
        
        case(SENAO):
            eat(SENAO);
            ListaComandos();
            eat(FIM);
            eat(SE);
            break;

    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: Comandos_para()
{
     switch (token)
    {
        case(FACA):
            eat(FACA);
            ListaComandos();
            eat(FIM);
            eat(PARA);
            break;
        
        case(PASSO):
            eat(PASSO);
            Expressao();
            eat(FACA);
            ListaComandos();
            eat(FIM);
            eat(PARA);
            break;

    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: Expressao()
{
     switch (token)
    {
        case(ABRE_PAREN):
            ExpressaoSimples();
            Expressao_prime();

            break;
        case(NAO):
            ExpressaoSimples();
            Expressao_prime();
            break;
        
        case(NUM_INTEIRO):
            ExpressaoSimples();
            Expressao_prime();
            break;
        
        case(NUM_REAL):
            ExpressaoSimples();
            Expressao_prime();
            break;
        case(VERDADEIRO):
            ExpressaoSimples();
            Expressao_prime();
            break;
        case(FALSO):
            ExpressaoSimples();
            Expressao_prime();
            break;
        case(STRING):
            ExpressaoSimples();
            Expressao_prime();
            break;
        case(ID):
            ExpressaoSimples();
            Expressao_prime();
            break;
        case(MAIS):
            ExpressaoSimples();
            Expressao_prime();
            break;
        case(MENOS):
            ExpressaoSimples();
            Expressao_prime();
            break;
    
    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: Expressao_prime()
{
     switch (token)
    {
        case(IGUAL):
            eat(IGUAL);
            ExpressaoSimples();
            Expressao_prime();

            break;
        case(DIFERENTE):
            eat(DIFERENTE);
            ExpressaoSimples();
            Expressao_prime();
            break;
        
        case(MENOR):
            eat(MENOR);
            ExpressaoSimples();
            Expressao_prime();
            break;
        
        case(MENOR_IGUAL):
            eat(MENOR_IGUAL);
            ExpressaoSimples();
            Expressao_prime();

            break;

        case(MAIOR):
            eat(MAIOR);
            ExpressaoSimples();
            Expressao_prime();
            break;

        case(MAIOR_IGUAL):
            eat(MAIOR_IGUAL);
            ExpressaoSimples();
            Expressao_prime();

            break;

        case(PONTO_VIRGULA):
            break;
        case(FECHA_PAREN):
            break;
        case(FECHA_COLCH):
            break;
        case(VIRGULA):
            break;
        case(ENTAO):
            break;
        case(FACA):
            break;
        case(PASSO):
            break;
        case(ATE):
            break;
    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: ExpressaoSimples()
{
     switch (token)
    {
        case(ABRE_PAREN):
            Termo();
            ExpressaoSimples_prime();

            break;
        case(NAO):

            Termo();
            ExpressaoSimples_prime();

            break;
        
        case(NUM_INTEIRO):

            Termo();
            ExpressaoSimples_prime();
            
            break;
        
        case(NUM_REAL):
            Termo();
            ExpressaoSimples_prime();
            
            break;
        case(VERDADEIRO):
            Termo();
            ExpressaoSimples_prime();
            
            break;
        case(FALSO):
            Termo();
            ExpressaoSimples_prime();
            
            break;
        case(STRING):

            Termo();
            ExpressaoSimples_prime();
            
            break;
        case(ID):

            Termo();
            ExpressaoSimples_prime();
            
            break;
        case(MAIS):
            eat(MAIS);
            Termo();
            ExpressaoSimples_prime();
            
            break;
        case(MENOS):
            eat(MENOS);
            Termo();
            ExpressaoSimples_prime();
            break;
    
    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: ExpressaoSimples_prime()
{
     switch (token)
    {
        
        case(MAIS):
            eat(MAIS);
            Termo();
            ExpressaoSimples_prime();

            break;
        case(MENOS):
            eat(MENOS);
            Termo();
            ExpressaoSimples_prime();
            break;

        case(OU):
            eat(OU);
            Termo();
            ExpressaoSimples_prime();
            break;
        case(PONTO_VIRGULA):
            break;
        case(FECHA_PAREN):
            break;
        case(IGUAL):
            break;
        case(FECHA_COLCH):
            break;
        case(VIRGULA):
            break;
        case(ENTAO):
            break;
        case(FACA):
            break;
        case(PASSO):
            break;
        case(ATE):
            break;
        case(DIFERENTE):
            break;
        case(MENOR):
            break;
        case(MENOR_IGUAL):
            break;
        case(MAIOR):
            break;
        case(MAIOR_IGUAL):
            break;

    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: Termo()
{
     switch (token)
    {
        case(ABRE_PAREN):
            Fator();
            Termo_prime();
            break;
        case(NAO):
            Fator();
            Termo_prime();
            break;
        
        case(NUM_INTEIRO):
            Fator();
            Termo_prime();
            break;
        
        case(NUM_REAL):
            Fator();
            Termo_prime();
            break;
        case(VERDADEIRO):
            Fator();
            Termo_prime();
            break;
        case(FALSO):
            Fator();
            Termo_prime();
            break;
        case(STRING):
            Fator();
            Termo_prime();
            break;
        case(ID):
            Fator();
            Termo_prime();
            break;
    
    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: Termo_prime()
{
     switch (token)
    {
        case(VEZES):
            eat(VEZES);
            Fator();
            Termo_prime();
            break;
        case(DIVISAO):
            eat(DIVISAO);
            Fator();
            Termo_prime();
            break;
        case(DIV):
            eat(DIV);
            Fator();
            Termo_prime();
            break;
        case(E):
            eat(E);
            Fator();
            Termo_prime();
            break;

        case(MAIS):
            break;
        case(MENOS):
            break;
        case(OU):
            break;
        case(PONTO_VIRGULA):
            break;
        case(FECHA_PAREN):
            break;
        case(IGUAL):
            break;
        case(FECHA_COLCH):
            break;
        case(VIRGULA):
            break;
        case(ENTAO):
            break;
        case(FACA):
            break;
        case(PASSO):
            break;
        case(ATE):
            break;
        case(DIFERENTE):
            break;
        case(MENOR):
            break;
        case(MENOR_IGUAL):
            break;
        case(MAIOR):
            break;
        case(MAIOR_IGUAL):
            break;
        

    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: Fator()
{
     switch (token)
    {
        case(ABRE_PAREN):
            eat(ABRE_PAREN);
            Expressao();
            eat(FECHA_PAREN);
            break;

        case(NAO):
            eat(NAO);
            Fator();
            break;
        
        case(NUM_INTEIRO):
            eat(NUM_INTEIRO);
            break;
        
        case(NUM_REAL):
            eat(NUM_REAL);
            break;


        case(VERDADEIRO):
            eat(VERDADEIRO);
            break;
        case(FALSO):
            eat(FALSO);
            break;
        case(STRING):
            eat(STRING);
            break;
        case(ID):
            eat(ID);
            Fator_prime();
            break;
    
    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: Fator_prime()
{
     switch (token)
    {
        case(ABRE_COLCH):
            eat(ABRE_COLCH);
            ExprIter();
            eat(FECHA_COLCH);
            break;

        case(ABRE_PAREN):
            eat(ABRE_PAREN);
            ExprIter();
            eat(FECHA_PAREN);
            break;
        
        case(FACA):
            break;
        
        case(PASSO):
            break;

        case(ATE):
            break;
        case(PONTO_VIRGULA):
            break;
        case(ENTAO):
            break;
        case(FECHA_PAREN):
            break;
        case(DIFERENTE):
            break;
        case(IGUAL):
            break;
        case(MAIOR):
            break;
        case(MAIOR_IGUAL):
            break;
        case(MENOR):
            break;
        case(MENOR_IGUAL):
            break;
        case(MAIS):
            break;
        case(MENOS):
            break;
        case(OU):
            break;
        case(DIV):
            break;
        case(DIVISAO):
            break;
        case(E):
            break;
        case(VEZES):
            break;
        case(FECHA_COLCH):
            break;
        case(VIRGULA):
            break;
        
    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: Variavel()
{
     switch (token)
    {
        case(ID):
            eat(ID);
            Variavel_prime();
            break;
    
    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: Variavel_prime()
{
     switch (token)
    {
        case(ABRE_COLCH):
            eat(ABRE_COLCH);
            ExprIter();
            eat(FECHA_COLCH);
            break;
        case(FECHA_PAREN):
            break;
    
    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: ExprIter()
{
     switch (token)
    {
        case(ABRE_PAREN):
            Expressao();
            ExprIter_prime();

            break;
        case(NAO):
            Expressao();
            ExprIter_prime();
            break;
        
        case(NUM_INTEIRO):
            Expressao();
            ExprIter_prime();
            break;
        
        case(NUM_REAL):
            Expressao();
            ExprIter_prime();
            break;
        case(VERDADEIRO):
            Expressao();
            ExprIter_prime();
            break;
        case(FALSO):
            Expressao();
            ExprIter_prime();
            break;
        case(STRING):
            Expressao();
            ExprIter_prime();
            break;
        case(ID):
            Expressao();
            ExprIter_prime();
            break;
        case(MAIS):
            Expressao();
            ExprIter_prime();
            break;
        case(MENOS):
            Expressao();
            ExprIter_prime();
            break;
    
    default: 
            ErroSintatico(); 
            break;
    }
}

void Sintatico:: ExprIter_prime()
{
     switch (token)
    {
        case(VIRGULA):
            eat(VIRGULA);
            ExprIter();
            break;

        case(FECHA_PAREN):   
            break;
        
        case(FECHA_COLCH):
            break;
  
        default: 
            ErroSintatico(); 
            break;
    }
}