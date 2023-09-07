#include <iostream>
#include "compilador.hpp"

int main(){

    std::string entrada = "";
    char c;
    while ((c = getchar()) != EOF) {
        entrada += c;
    }
    Compilador lexico;
    lexico.analyserLexic(entrada);


}