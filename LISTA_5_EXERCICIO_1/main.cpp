#include <iostream>
#include "lexic.hpp"


int main(){

    std::string entrada = "";
    char c;
    while ((c = getchar()) != EOF) {
        entrada += c;
    }

    Compilador Automato;
    Automato.analyserLexic(entrada);
}