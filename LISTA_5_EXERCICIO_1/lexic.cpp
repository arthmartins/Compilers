#include <iostream>
#include "lexic.hpp"

void Compilador:: analyserLexic(std::string entrada){
    int last_final = 0;
    int current_state = 1;
    int start = 0;
    int token = 0;
    int count = 0;
    

    while(true){

        if(entrada[count]< 58 && entrada[count] > 47)
        {
            current_state = transitions[current_state][entrada[count]-20];
            if(final_states[current_state]){ last_final = current_state; token++; }
            count++;

        }else if(entrada[count]< 123  && entrada[count] > 96)
        {
            current_state = transitions[current_state][entrada[count]-95];
            if(final_states[current_state]){ last_final = current_state; token++; }
            count++;

        }else if(entrada[count]==43)
        {
            current_state = transitions[current_state][entrada[count]-43];
            if(final_states[current_state]){ last_final = current_state; token++; }
            count++;

        }else if(entrada[count]==45)
        {
            current_state = transitions[current_state][entrada[count]-44];
            if(final_states[current_state]){ last_final = current_state; token++; }
            count++;
            
        }else if(current_state==0 || (entrada[count] == '\0' && last_final!=0)){
            if(last_final==0){std::cout << "ERROR"<< "\n";current_state = 1;start = token;
            count = start;}

            else{
            for(int j = start; j < token;j++){
                std::cout << entrada[j];
            }
            printf("\n");
            

            last_final = 0;
            current_state = 1;
            
            start = token;
            count = start;
           
            if(entrada[count] != '\0'){count = start -1;}
            }
           
        }
        else if(entrada[count]==EOF){
            break;

        }
        else
        {
            current_state=0;
           
        }
        
      
    }
    
    
}
