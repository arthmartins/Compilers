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
    // Lexico lexico;
    // lexico.analyserLexic(entrada);


}