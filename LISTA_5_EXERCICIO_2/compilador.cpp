#include <iostream>
#include "compilador.hpp"
#include "automato.hpp"

void Compilador:: analyserLexic(std::string entrada){
    int last_final = 0;
    int current_state = 1;
    int start = 0;
    int ponto_de_token = 0;
    int count = 0;
    int flag =0;

    while(true){
    
    if(current_state==0)
    {
        printTokens(entrada,start,ponto_de_token ,last_final);
        last_final = 0;
        current_state = 1;
            
        start = ponto_de_token ;
        count = start;
    }

    current_state = transitions[current_state][entrada[count]];
    if (entrada[count]== '\0'){
            break;
    }
    count++;

    if(final_states[current_state]){ 
        last_final = current_state; 
        ponto_de_token  = count; }

    }
}


void Compilador:: printTokens(std::string entrada, int start, int ptoken, int last_final)
{
    for(int i = start; i < ptoken;i++){
            if(entrada[i]!=32 && entrada[i]!= 10)
                std::cout << entrada[i];
        }
        
        if(last_final != 12)
            std::cout << " ";
        std::cout << getToken(last_final);
    
        printf("\n");
}

std::string Compilador:: getToken(int finalState){
    return(tokens[finalState]);
}