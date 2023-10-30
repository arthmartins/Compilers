#include <vector>
#ifndef AUTOMATO_HPP
#define AUTOMATO_HPP

#define alphabet 128
#define states 174

extern int transitions[states][alphabet];

extern bool final_states[174];

enum TokenType {
    ERRO,                 // 0
    ID,                   // 1
    NUM_INTEIRO,          // 2
    NUM_REAL,             // 3
    PONTO,                // 4
    E,                    // 5
    ATE,                  // 6
    OU,                   // 7
    ALGORITMO,            // 8
    PARA,                 // 9
    PASSO,                // 10
    REPITA,               // 11
    DE,                   // 12
    DIV,                  // 13
    SE,                   // 14
    SENAO,                // 15
    VARIAVEIS,            // 16
    VERDADEIRO,           // 17
    TIPO,                 // 18
    NAO,                  // 19
    MATRIZ,               // 20
    FALSO,                // 21
    FACA,                 // 22
    FIM,                  // 23
    FUNCAO,               // 24
    ENTAO,                // 25
    ENQUANTO,             // 26
    LEIA,                 // 27
    LOGICO,               // 28
    IMPRIMA,              // 29
    INTEIRO,              // 30
    MAIOR,                // 31
    MENOR,                // 32
    MAIS,                 // 33
    MENOS,                // 34
    VEZES,                // 35
    DIVISAO,              // 36
    MAIOR_IGUAL,          // 37
    MENOR_IGUAL,          // 38
    STRING,               // 39
    COMENTARIO_BLOCO,     // 40
    COMENTARIO_LINHA,     // 41
    WHITESPACE,           // 42
    DIFERENTE,            // 43
    ATRIBUICAO,           // 44
    IGUAL,                // 45
    PONTO_VIRGULA,        // 46
    DOIS_PONTOS,          // 47
    INICIO,               // 48
    VIRGULA,              // 49
    ABRE_COLCH,           // 50
    FECHA_COLCH,          // 51
    ABRE_PAREN,           // 52
    FECHA_PAREN,          // 53
    VETOR,               // 54
    REAL,                //55
    PROCEDIMENTO,          //56
    CARACTERE,             //57
}; 

extern std::vector<std::string> tokens;

extern TokenType tokensEnum[states];

#endif