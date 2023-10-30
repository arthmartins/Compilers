#include <iostream>
#include "lexico.hpp"
#include "automato.hpp"

    static int start;
    static int ponto_de_token;
    static int count;
    static int linha;
    static std::string token;

void Lexico::setVariaveis()
    {
        start = 0;
        ponto_de_token = 0;
        count = 0;
        setLinha_token();
        setColuna_token();
    }

int Lexico:: analyserLexic(std::string entrada){
    int last_final = 0;
    int current_state = 1;
     
    int tokenNumero = -1;

    while(true){
    
    if(current_state==0)
    {
        if(last_final!=0){
        //token = getToken(last_final);
        //if(token!= "WHITESPACE") 
        //{
            //std::cout << token << "\n";
        setToken(entrada,start, ponto_de_token);
        tokenNumero = tokensEnum[last_final];            
        //}

        }else if(entrada[start]!=10 && entrada[start]!=32){
            printf("ERRO LEXICO. Linha: %d Coluna: %d -> '%c'",this->linha_token,this->coluna_token,entrada[count-1]);
            exit(1);
        }
        
        last_final = 0;
        current_state = 1;
            
        start = ponto_de_token ;
        coluna_token -= count - start;
        count = start;

        if (tokenNumero != -1)
            return tokenNumero;
    }

    coluna_token++;

    if(entrada[count]==10){
        coluna_token = 0;
        this->linha_token++;
        ponto_de_token++;
    }
    current_state = transitions[current_state][entrada[count]];
    
    if (entrada[count] == '\0'){
        break;
    }

    ++count;
    
    if(final_states[current_state]){ 
        last_final = current_state; 
        ponto_de_token  = count; }
    }
    return -1;
}

std::string Lexico:: getToken(int finalState){
    return(tokens[tokensEnum[finalState]]);
}

void Lexico::setColuna_token()
{
    coluna_token = 0;
}

int Lexico::getColuna_token()
{
    return coluna_token;
}

void Lexico::setLinha_token()
{
    this->linha_token = 1;
}

int Lexico::getLinha_token()
{
    return linha_token;
}

void Lexico::setToken(std:: string entrada, int inicio_token, int fim_token)
{
    token = "";
    for(int i = inicio_token; i < fim_token;i++){
            if(entrada[i]!=32 && entrada[i]!= 10)
            token = token + entrada[i];  
        
    }
}