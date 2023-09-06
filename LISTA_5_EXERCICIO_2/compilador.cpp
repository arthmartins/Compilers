#include <iostream>
#include "compilador.hpp"
#include "automato.hpp"

void Compilador:: analyserLexic(std::string entrada){
    int last_final = 0;
    int current_state = 1;
    int start = 0;
    int token = 0;
    int count = 0;
    int flag =0;

    while(true){
    
    if(entrada.length() == count)
    {
        flag =1;
    }

    if(current_state==0)
    {
        for(int i = start; i < token;i++){
                std::cout << entrada[i];
        }
        
        std::cout << getToken(last_final);
    
        printf("\n");

        last_final = 0;
        current_state = 1;
            
        start = token;
        count = start;
    }

    current_state = transitions[current_state][entrada[count]];
    count++;

    if(final_states[current_state]){ last_final = current_state; token = count; }

        if (flag==1)
            break;
    }
}

std::string Compilador:: getToken(int finalState){
    return(tokens[finalState]);
}