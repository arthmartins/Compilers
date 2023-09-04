#include <iostream>
#include "lexic.hpp"

#define alphabet 38
#define states 9

int main(){

    std::string entrada = "";
    char c;
    while ((c = getchar()) != EOF) {
        entrada += c;
    }

    Compilador Aito;
    Aito.analyserLexic(entrada);
}