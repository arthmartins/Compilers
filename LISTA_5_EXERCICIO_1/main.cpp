#include <iostream>

#define alphabet 38
#define states 9

int transitions[states][alphabet] ={
    /*       +,-,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,  0,1,2,3,4,5,6,7,8,9 */
    /* 0 */ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0},
    /* 1 */ {3,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,  5,5,5,5,5,5,5,5,5,5},
    /* 2 */ {0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,  2,2,2,2,2,2,2,2,2,2},
    /* 3 */ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0},
    /* 4 */ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,0},
    /* 5 */ {0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  5,5,5,5,5,5,5,5,5,5},
    /* 6 */ {7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  8,8,8,8,8,8,8,8,8,8},
    /* 7 */ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  8,8,8,8,8,8,8,8,8,8},
    /* 8 */ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  8,8,8,8,8,8,8,8,8,8},
};
bool final_states[states] = {false,false,true,true,true,true,false,false,true};

void lexer(std::string entrada){
    int last_final = 0;
    int current_state = 1;
    int start = 0;
    int token = 0;
    int count = 0;

    for(int i = 0 ; i <= entrada.length();i++){

        if(current_state==0 || entrada[i] == '\0'){
            for(int j = start; j < token;j++){
                std::cout << entrada[j];
            }
            printf("\n");
            last_final = 0;
            current_state = 1;
            
            start = token;
            count = start;
            if(entrada[i] != '\0'){i = start -1;}
           
        }
        else if(entrada[count]< 58 && entrada[count] > 47)
        {
            current_state = transitions[current_state][entrada[count]-20];
            if(final_states[current_state]){ last_final = current_state; token = i+1; }
            count++;

        }else if(entrada[count]<123  && entrada[count] > 96)
        {
            current_state = transitions[current_state][entrada[count]-95];
            if(final_states[current_state]){ last_final = current_state; token = i+1; }
            count++;

        }else if(entrada[count]==43)
        {
            current_state = transitions[current_state][entrada[count]-43];
            if(final_states[current_state]){ last_final = current_state; token = i+1; }
            count++;

        }else if(entrada[count]==45)
        {
            current_state = transitions[current_state][entrada[count]-44];
            if(final_states[current_state]){ last_final = current_state; token = i+1; }
            count++;
            
        }else if (last_final == 0)
        {
            std::cout << "ERROR";
        }
        
        
    }
    
    
    
     


}




int main(){

    std::string entrada = "";
    char c;
    while ((c = getchar()) != EOF) {
        entrada += c;
    }
    
    lexer(entrada);
}