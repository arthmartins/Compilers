#include <iostream>

class Lexico
{
    public:
        int coluna_token;
        int linha_token;
        void setColuna_token();
        int getColuna_token();
        void setLinha_token();
        int getLinha_token();
        int getSimboloErro();
        void setToken(std::string entrada, int inicio_token, int fim_token);
        std::string getToken();
        void setVariaveis();
        int analyserLexic(std::string entrada);

        std::string getToken(int finalState);

};

