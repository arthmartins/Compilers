#include <iostream>

class Compilador
{
    public: void analyserLexic(std::string entrada);

    std::string getToken(int finalState);

    void printTokens(std::string entrada, int start, int token, int last_final);
};

