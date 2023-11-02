#include <iostream>
#include "Sintatico.hpp"

int main(){

    std::string entrada = "";
    char c;
    while ((c = getchar()) != EOF) {
        entrada += c;
    }
    
    Sintatico sintatico;
    sintatico.setEntrada(entrada);
    sintatico.Programa();
    
    std::cout << "PROGRAMA CORRETO.";


}