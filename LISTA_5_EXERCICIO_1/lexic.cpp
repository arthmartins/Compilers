#include <iostream>
#include "lexic.hpp"

void Compilador:: analyserLexic(std::string entrada){
    int last_final = 0;
    int current_state = 1;
    int start = 0;
    int ponto_de_token = 0;
    int count = 0;
    

    while(true){
    
    if(current_state==0)
    {
        printTokens(entrada,start,ponto_de_token);
        
        current_state = 1;
        last_final=0;
    
        start = ponto_de_token;
        
        count = start;
    }


    current_state = transitions[current_state][entrada[count]];

    if(last_final == 0 && current_state == 0)
    {
        if(entrada[count] == 10){
            count++;
        }
        else{
            printf("ERRO\n");
        }
        start++;
        current_state = 1;
    }
    

    if (entrada[count]=='\0'){
        break;
    }

    count++;
    

    if(final_states[current_state]){ 
        last_final = current_state; 
        ponto_de_token  = count; 
    }

    }
}


void Compilador:: printTokens(std::string entrada, int start, int ptoken)
{
    for(int i = start; i < ptoken;i++){
            if(entrada[i]!=32 && entrada[i]!= 10)
                std::cout << entrada[i];
        
    } 
    printf("\n");
}

    

