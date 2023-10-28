#include <iostream>
#include "lexico.hpp"
#include "automato.hpp"

void Lexico:: analyserLexic(std::string entrada){
    int last_final = 0;
    int current_state = 1;
    int start = 0;
    int ponto_de_token = 0;
    int count = 0;
    int linha = 1;
    int coluna = 1;
    std::string token; 

    while(true){
    
    if(current_state==0)
    {
        if(last_final!=0){
        token = getToken(last_final);
        if(token!= "WHITESPACE") 
        {
        std::cout << getToken(last_final);
        if(entrada[ponto_de_token+1]!='\0')
            printf("\n");
        }

        }else if(entrada[start]!=10 && entrada[start]!=32){
            printf("ERRO LEXICO. Linha: %d Coluna: %d -> '%c'",linha,coluna-1,entrada[count-1]);
            ponto_de_token++;
            if(entrada[ponto_de_token+1]!='\0')
            printf("\n");
        }
        
        last_final = 0;
        current_state = 1;
            
        start = ponto_de_token ;
        coluna -= count - start;
        count = start;
        
    }

    ++coluna;
    
    if(entrada[count]==10){
        coluna = 1;
        linha++;
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
    
}

std::string Lexico:: getToken(int finalState){
   
    return(tokens[tokensEnum[finalState]]);
}