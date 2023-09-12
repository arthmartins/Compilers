#include <iostream>
#include "compilador.hpp"
#include "automato.hpp"

void Compilador:: analyserLexic(std::string entrada){
    int last_final = 0;
    int current_state = 1;
    int start = 0;
    int ponto_de_token = 0;
    int count = 0;

    while(true){
    
    if(current_state==0)
    {
        if(last_final!=0){
        printTokens(entrada,start,ponto_de_token ,last_final);


        }else if(entrada[start]!=10 && entrada[start]!=32){
            
            printf("ERRO\n");
            ponto_de_token++;
        }
        if(entrada[start]==32 || entrada[start]==10 ){ponto_de_token++;}
        last_final = 0;
        current_state = 1;
            
        start = ponto_de_token ; 
        count = start;

    }

    if(entrada[count]==10 || entrada[count] ==32){
        if(current_state == last_final){
            current_state= 0;
            ponto_de_token++;
        }else
            current_state= 0;
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

    printTokens(entrada,start,ponto_de_token ,last_final);
}


void Compilador:: printTokens(std::string entrada, int start, int ptoken, int last_final)
{
    
    std::cout << getToken(last_final);

    if(getToken(last_final) == "REAL" || getToken(last_final) == "INTEIRO")
    {
        printf(" ");
        for(int i = start; i < ptoken;i++){
            if(entrada[i]!= 32)
                std::cout << entrada[i];
        }
    }
    if(entrada[ptoken+1]!='\0')
        printf("\n");

}

std::string Compilador:: getToken(int finalState){
    return(tokens[finalState]);
}