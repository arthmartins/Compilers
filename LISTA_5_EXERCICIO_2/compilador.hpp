#include <iostream>

class Compilador
{
    public: void analyserLexic(std::string entrada);

    std::string getToken(int finalState);
};

