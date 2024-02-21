#include "comandos.hh"

#include <cmath>
#include <iomanip>
#include <cstdio>
#include <string>
#include <iostream>


float h_view_lo;
float h_view_hi;
float v_view_lo;
float v_view_hi;
int float_precision;
int integral_steps;
bool draw_axix;
bool erase_plot;
bool connect_dots;

std::vector<std::vector<float>> matriz;
std::vector<int> casas_decimais;

int linhasMatriz;
int colunasMatriz;


void setDefaultValues(){

    h_view_hi = H_VIEW_HI_DEFAULT;
    h_view_lo = H_VIEW_LO_DEFAULT;
    v_view_hi = V_VIEW_HI_DEFAULT;
    v_view_lo = V_VIEW_LO_DEFAULT;
    float_precision =FLOAT_PRECISION_DEFAULT;
    integral_steps = INTEGRAL_STEPS_DEFAULT;
    draw_axix = DRAW_AXIX_DEFAULT;
    erase_plot = ERASE_PLOT_DEFAULT;
    connect_dots = CONNECT_DOTS_DEFAULT;

}

void showSettings(){
    
    printf("\nh_view_lo: %.6f \n", h_view_lo);
    printf("h_view_hi: %.6f\n",h_view_hi);
    printf("v_view_lo: %.6f\n",v_view_lo);
    printf("v_view_hi: %.6f\n",v_view_hi);
    printf("float precision: %d\n",float_precision);
    printf("integral_steps: %d\n\n",integral_steps);

    printf("Draw Axis: %s\n", draw_axix ? "ON" : "OFF");
    printf("Erase Plot: %s\n", erase_plot ? "ON" : "OFF");
    printf("Connect Dots: %s\n\n", connect_dots ? "ON" : "OFF");

}

void setH_view(float h_lo, float h_hi){
    if(h_lo < h_hi){
        h_view_lo = h_lo;
        h_view_hi = h_hi;
    } else
        printf("\nERROR: h_view_lo must be smaller than h_view_hi\n\n");
}

void setV_view(float v_lo, float v_hi){
    if(v_lo < v_hi){
    v_view_lo = v_lo;
    v_view_hi = v_hi;
    } else
        printf("\nERROR: v_view_lo must be smaller than v_view_hi\n\n");
}

void setAxis(int valor){
    draw_axix = valor;
}

void setErase(int valor){
    erase_plot = valor;
}

void setConnectDots(int valor){
    connect_dots = valor;
}

void setFloatPrecision(int valor){
    if(valor >= 0 && valor <= 8){
        float_precision = valor;
    }else{
        printf("\nERROR: float precision must be from 0 to 8\n\n");
    }

}

void setIntegralSteps(int valor){
    if(valor > 0)
        integral_steps = valor;
    else
        printf("\nERROR: integral_steps must be a positive non-zero integer\n\n");
}

void printAbout(){
    std::cout << "\n+----------------------------------------------+\n";
    std::cout << "|                                              |\n";
    std::cout << "|                202100560241                  |\n";
    std::cout << "|         Arthur Henrique Gomes Martins        |\n";
    std::cout << "|                                              |\n";
    std::cout << "+----------------------------------------------+\n\n";
}

std::vector<std::vector<float>> createMatriz(std::list<float>& listaMatriz, std::list<int>& ElementsPLinha, int numerodeColunas) {

    matriz.clear();
    linhasMatriz = ElementsPLinha.size();
    colunasMatriz = numerodeColunas;

    if(linhasMatriz > 10 || colunasMatriz >10){
        printf("\nERROR: Matrix limits out of boundaries.\n\n");
        return matriz;
    }

    matriz.resize(ElementsPLinha.size(), std::vector<float>(numerodeColunas));

    auto it = ElementsPLinha.begin();
    auto itList = listaMatriz.begin();

    for (int i = 0; i < linhasMatriz; ++i) {
        int quantElementLinha = *it++;
        for (int j = 0; j < colunasMatriz; ++j) {
            if (quantElementLinha <= j) {
                
                matriz[i][j] = 0;
            } else {
                matriz[i][j] = *itList++;
                
            }
        }
    }
    listaMatriz.clear();
    ElementsPLinha.clear();

    return matriz;
}


void showMatriz()
{
    printMatriz(matriz);
}

int contar_casas_decimais(std::string numero) {
    size_t ponto_pos = numero.find('.');
    return ponto_pos; 
}

void contaCasasDecimais(std::vector<std::vector<float>> matriz_aux){
    int col = matriz_aux[0].size();
    int lin = matriz_aux.size();

    int variavel_contadora = 0;

    for(int j =0; j < col; j++){
        for(int i = 0; i < lin; i++){
            int num_casas_decimais = contar_casas_decimais(std::to_string(matriz[i][j]));
            if(num_casas_decimais > variavel_contadora){
                variavel_contadora = num_casas_decimais;
            }
        }
        casas_decimais.push_back(variavel_contadora);
        variavel_contadora = 0;
    }
}

void printMatriz(std::vector<std::vector<float>> matriz_aux)
{
    int espacos_p_pular = 0;
    contaCasasDecimais(matriz_aux);
    for (int elemento : casas_decimais) {
        espacos_p_pular += elemento-1;
    }
    
    int k = 0;
    printf("%d\n",espacos_p_pular);
    printf("\n+-");
    for(int i = 0; i < (((float_precision+2)*matriz_aux[0].size())+matriz_aux[0].size()-1+espacos_p_pular) ; i++){
        printf(" ");
    }
    printf("-+\n");

    for (int i = 0; i < matriz_aux.size(); ++i) {
        printf("| ");
        for (int j = 0; j < matriz_aux[0].size(); ++j) {
            for(int l = 0; l < casas_decimais[k]-contar_casas_decimais(std::to_string(matriz[i][j])); l++){
                printf(" ");
            }
            printf("%.*f ",float_precision, matriz_aux[i][j]);
            k++;
        }
        printf("|");
        std::cout << std::endl;
        k = 0;
    }

    printf("+-");
    for(int i = 0; i < (((float_precision+2)*matriz_aux[0].size())+matriz_aux[0].size()-1+espacos_p_pular) ; i++){
        printf(" ");
    }
    printf("-+\n\n");

    casas_decimais.clear();
}


float determinanteSubmatriz(const std::vector<std::vector<float>>& matriz, int tamanho) {
    if (tamanho == 1) {
        return matriz[0][0];
    } else if (tamanho == 2) {
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    } else {
        float determinante = 0;
        std::vector<std::vector<float>> submatriz(tamanho - 1, std::vector<float>(tamanho - 1));

        for (int coluna = 0; coluna < tamanho; ++coluna) {
            int submatriz_i = 0;
            int submatriz_j = 0;

            for (int i = 1; i < tamanho; ++i) {
                for (int j = 0; j < tamanho; ++j) {
                    if (j != coluna) {
                        submatriz[submatriz_i][submatriz_j++] = matriz[i][j];
                        if (submatriz_j == tamanho - 1) {
                            submatriz_j = 0;
                            ++submatriz_i;
                        }
                    }
                }
            }

            determinante += matriz[0][coluna] * (coluna % 2 == 0 ? 1 : -1) * determinanteSubmatriz(submatriz, tamanho - 1);
        }

        return determinante;
    }
}


void determinanteMatriz() {
    int tamanho = matriz.size();
    if (tamanho == 0 || matriz[0].size() != tamanho) {
        
        std::cerr << std::endl << "Matrix format incorrect!" << std::endl << std::endl;
        
    }else
        printf("\n%.*f\n\n",float_precision, determinanteSubmatriz(matriz, tamanho));

}

void solveLinearSystem() {
    
    std::vector<std::vector<float>> matriz_aux(matriz);

    if(colunasMatriz != linhasMatriz + 1){
        std::cerr << std::endl << "Matrix format incorrect!" << std::endl << std::endl;
        return;
    }

    for (int i = 0; i < linhasMatriz; ++i) {
        
        int pivot = i;
        for (int j = i + 1; j < linhasMatriz; ++j) {
            if (std::abs(matriz_aux[j][i]) > std::abs(matriz_aux[pivot][i])) {
                pivot = j;
            }
        }

 
        if (pivot != i) {
            std::swap(matriz_aux[i], matriz_aux[pivot]);
        }



        if (matriz_aux[i][i] == 0) {
            bool todasZeroes = true;
            for (int k = i + 1; k < linhasMatriz; ++k) {
                if (matriz_aux[k][i] != 0) {
                    todasZeroes = false;
                    break;
                }
            }
            if (todasZeroes && matriz_aux[i][colunasMatriz - 1] != 0) {
             printf("\nSI - The Linear System has no solution\n\n");
                    return;
            break;
        }
        }

        for (int j = i + 1; j < linhasMatriz; ++j) {
            float fator = matriz_aux[j][i] / matriz_aux[i][i];
            for (int k = i; k < colunasMatriz; ++k) {
                matriz_aux[j][k] -= matriz_aux[i][k] * fator;
            }
        }
    }

    for (int i = 0; i < linhasMatriz; ++i) {
        bool allZeroes = true;
        for (int j = 0; j < colunasMatriz; ++j) {
            if (matriz_aux[i][j] != 0) {
                allZeroes = false;
                break;
            }
        }
        if (allZeroes) {
            printf("\nSPI - The Linear System has infinitely many solutions\n\n");
            return;
        }
    }

   
    std::vector<float> solucao(linhasMatriz, 0);
    for (int i = linhasMatriz - 1; i >= 0; --i) {
        float soma = 0;
        for (int j = i + 1; j < colunasMatriz - 1; ++j) {
            soma += matriz_aux[i][j] * solucao[j];
        }
        solucao[i] = (matriz_aux[i][colunasMatriz - 1] - soma) / matriz_aux[i][i];
    }


    std::cout << "Matrix x:" << std::endl;
    for (int i = 0; i < linhasMatriz; ++i) {
        std::cout << solucao[i] << std::endl;
    }

    
}

void printValorSimbolo(std::string name, HashTable hash){

    int valor = hash.getType(name);

    if(valor == -1){
        printf("\nUndefined symbol\n\n");
    }else if(valor == 0){
        printf("\n");
        std::cout << name << " = ";
        printf("%.*f \n\n",float_precision, *(static_cast<float*>(hash.search(name))));
        
    }else if (valor == 1){
        printMatriz(*(static_cast<std::vector<std::vector<float>>*>(hash.search(name))));
    }

}