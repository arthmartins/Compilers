#include <iostream>
#include "lexico.hpp"

int main(){

    std::string entrada = "";
    char c;
    while ((c = getchar()) != EOF) {
        entrada += c;
    }
    Lexico lexico;
    lexico.analyserLexic(entrada);


}