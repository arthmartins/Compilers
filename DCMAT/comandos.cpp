#include "comandos.hpp"


float h_view_lo;
float h_view_hi;
float v_view_lo;
float v_view_hi;
int float_precision;
int integral_steps;
bool draw_axix;
bool erase_plot;
bool connect_dots;

std::vector<std::vector<float>>* matriz;

std::vector<std::vector<float>>* matriz_2;

char matriz_plot[25][80];



vector<vector<int>> matriz_aa(25, vector<int>(80, 0));

std::vector<int>* casas_decimais;

static bool trocouVorH_view = false;

bool break_matriz = false;

bool not_existId = false;

std::string idName = "";

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
        trocouVorH_view = true;
    } else
        printf("\nERROR: h_view_lo must be smaller than h_view_hi\n\n");
}



void setV_view(float v_lo, float v_hi){
    if(v_lo < v_hi){
        v_view_lo = v_lo;
       
        v_view_hi = v_hi;
        
        trocouVorH_view = true;
    } else
        printf("\nERROR: v_view_lo must be smaller than v_view_hi\n\n");
}

void setAxis(int valor){
    draw_axix = valor;
}

void setErase(int valor){
    erase_plot = valor;
}


void setFloatPrecision(int valor){
    if(valor >= 0 && valor <= 8){
        float_precision = valor;
    }else{
        printf("\nERROR: float precision must be from 0 to 8\n\n");
    }
}

void setIntegralSteps(float valor){
    if(valor < 0)
        printf("\nERROR: integral_steps must be a positive non-zero integer\n\n");
    else if(valor - (int)valor != 0)
        printf("\nERROR: integral_steps must be a positive non-zero integer\n\n");
    else
        integral_steps = valor;
}

void printAbout(){
    std::cout << "\n+----------------------------------------------+\n";
    std::cout << "|                                              |\n";
    std::cout << "|                202100560241                  |\n";
    std::cout << "|         Arthur Henrique Gomes Martins        |\n";
    std::cout << "|                                              |\n";
    std::cout << "+----------------------------------------------+\n\n";
}



std::vector<std::vector<float>>* createMatriz(std::list<float>& listaMatriz, std::list<int>& ElementsPLinha, int numerodeColunas) {

  
    linhasMatriz = ElementsPLinha.size();
    colunasMatriz = numerodeColunas;


    if(linhasMatriz > 10 || colunasMatriz >10){
        printf("\nERROR: Matrix limits out of boundaries.\n\n");
        break_matriz = true;
        return matriz;
    }
    
    //std::vector<std::vector<float>> matriz_aa(linhasMatriz, std::vector<float>(colunasMatriz));

    //matriz.resize(ElementsPLinha.size(), std::vector<float>(numerodeColunas));
    matriz = new std::vector<std::vector<float>>(linhasMatriz, std::vector<float>(colunasMatriz));

    auto it = ElementsPLinha.begin();
    auto itList = listaMatriz.begin();

    for (int i = 0; i < linhasMatriz; ++i) {
        int quantElementLinha = *it++;
        for (int j = 0; j < colunasMatriz; ++j) {
            if (quantElementLinha <= j) {
                
                (*matriz)[i][j] = 0;
            } else {
                (*matriz)[i][j] = *itList++;
                
            }
        }
    }
    listaMatriz.clear();
    ElementsPLinha.clear();

    
    return matriz;
}


void showMatriz()
{
    if(matriz==NULL){
        printf("\nNo matrix defined!\n\n");
        return;
    }
    printMatriz(*matriz);
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
            int num_casas_decimais = contar_casas_decimais(std::to_string(matriz_aux[i][j]));
            if(num_casas_decimais > variavel_contadora){
                variavel_contadora = num_casas_decimais;
            }
        }
        (*casas_decimais).push_back(variavel_contadora);
        variavel_contadora = 0;
    }
}

void printMatriz(std::vector<std::vector<float>> matriz_aux)
{
    casas_decimais = new std::vector<int>;
    int casas_float = 0;

    int espacos_p_pular = 0;
    contaCasasDecimais(matriz_aux);
    for (int elemento : *casas_decimais) {
        espacos_p_pular += elemento-1;
    }
    
    int k = 0;
    if(float_precision == 0){
        casas_float = 1;
    }else
        casas_float = float_precision + 2;

    printf("\n+-");
    for(int i = 0; i < (((casas_float)*matriz_aux[0].size())+matriz_aux[0].size()-1+espacos_p_pular) ; i++){
        printf(" ");
    }
    printf("-+\n");

    for (int i = 0; i < matriz_aux.size(); ++i) {
        printf("| ");
        for (int j = 0; j < matriz_aux[0].size(); ++j) {
            for(int l = 0; l < (*casas_decimais)[k]-contar_casas_decimais(std::to_string(matriz_aux[i][j])); l++){
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
    for(int i = 0; i < (((casas_float)*matriz_aux[0].size())+matriz_aux[0].size()-1+espacos_p_pular) ; i++){
        printf(" ");
    }
    printf("-+\n\n");
    
    delete (casas_decimais);
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
    int tamanho = (*matriz).size();

    if (tamanho == 0 || (*matriz)[0].size() != tamanho) {
        
        std::cerr << std::endl << "Matrix format incorrect!" << std::endl << std::endl;
        
    }else
        printf("\n%.*f\n\n",float_precision, determinanteSubmatriz((*matriz), tamanho));

}

void solveLinearSystem() {
    
    std::vector<std::vector<float>> matriz_aux((*matriz));

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


    std::cout << std::endl << "Matrix x:" << std::endl << std::endl;
    for (int i = 0; i < linhasMatriz; ++i) {
        printf("%.*f\n",float_precision, solucao[i]);
    }
    printf("\n");

    
}

void printValorSimbolo(std::string name, HashTable hash){

    
    int valor = hash.getType(name);

    if(valor == -1){
        printf("\nUndefined symbol [");
        std::cout << name << "]";
        printf("\n\n");
    }else if(valor == 0){
        printf("\n");
        std::cout << name << " = ";
        printf("%.*f \n\n",float_precision, *(static_cast<float*>(hash.search(name))));
        
    }else if (valor == 1){
        
        printMatriz(*(static_cast<std::vector<std::vector<float>>*>(hash.search(name))));
    }

}



void integrate(float a, float b, TreeNode* ast, HashTable hash) {
    float sum = 0.0;
    if(b<a){
        printf("\nERROR: lower limit must be smaller than upper limit\n\n");
        return;
    }
    float dx = (b - a) / integral_steps;
    RPN_Walk_Errors_2(ast, hash);
    if(not_existId){
        printf("\n\n");
        return;
    }
    for (int i = 0; i < integral_steps; i++) {
        float xi = a + i * dx;
        sum += RPN_Walk_calculatinge(ast, xi,hash) * dx;
    }
    printf("\n%.*f\n\n",float_precision, sum);
    
}

void RpnFunc(TreeNode* ast){
    printf("\n");
    printf("Expression in RPN format:\n\n");
    RPN_Walk(ast, float_precision);
    printf("\n\n");
}

void somatorio(std::string variavel,float a, float b, TreeNode* ast, HashTable hash){
    float sum = 0.0;
    RPN_Walk_Errors_sum(ast,variavel,hash);
    if(not_existId){
        printf("\n\n");
        return;
    }
    for (int i = a; i <= b; i++) {
        sum += RPN_Walk_somatorio(ast, variavel,i,hash); 
    }
    printf("\n%.*f\n\n",float_precision, sum);
}

float calculate_Exp(TreeNode* ast, HashTable hash){
    RPN_Walk_Errors(ast, hash);
    if(not_existId){
        printf("\n\n");
        return 0;
    }else{
        setContador();
        float valor = RPN_Walk_calculatinge(ast,0.0,hash);
        
        return valor;
    }
}

void printValorCalculoExp(float valor){
    printf("\n%.*f\n\n",float_precision, valor);
}

void multiplyMatrixByScalar(std::vector<std::vector<float>>& matrix, int scalar) {
    for (auto& row : matrix) {
        for (float& element : row) {
            element *= scalar;
        }
    }
}


std::vector<std::vector<float>>* solve_Matriz_expressao(TreeNode* ast, HashTable hash){
    RPN_Walk_Errors(ast, hash);
    if(not_existId){
    printf("\n\n");
    return matriz_2;   
    }else{
        setContador();
        matriz_2 = RPN_Walk_matriz(ast,hash);
        
        return matriz_2;
    }

}

std::vector<std::vector<float>>* addMatrices(std::vector<std::vector<float>> matrix1, std::vector<std::vector<float>> matrix2) {
    std::vector<std::vector<float>>* result = new std::vector<std::vector<float>>;;

    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
        std::cerr << "\nIncorrect dimensions for operator '+' - have MATRIX [" << matrix1.size() <<"] ["<< matrix1[0].size() <<"] and MATRIX ["<< matrix2.size() << "] ["<< matrix2[0].size() <<"]\n\n";
        break_matriz = true;
        return result; 
    }

    for (size_t i = 0; i < matrix1.size(); ++i) {
        std::vector<float> new_row;
        for (size_t j = 0; j < matrix1[i].size(); ++j) {
            float sum = matrix1[i][j] + matrix2[i][j];
            new_row.push_back(sum);
        }
        result->push_back(new_row);
    }

    return result;
}

std::vector<std::vector<float>>* subtractMatrices(std::vector<std::vector<float>> matrix1, std::vector<std::vector<float>> matrix2) {
    std::vector<std::vector<float>>* result = new std::vector<std::vector<float>>;

    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
        std::cerr << "\nIncorrect dimensions for operator '-' - have MATRIX [" << matrix1.size() <<"] ["<< matrix1[0].size() <<"] and MATRIX ["<< matrix2.size() << "] ["<< matrix2[0].size() <<"]\n\n";
        break_matriz = true;
        return nullptr; 
    }


    for (size_t i = 0; i < matrix1.size(); ++i) {
        std::vector<float> new_row;
        for (size_t j = 0; j < matrix1[i].size(); ++j) {
            float diff = matrix1[i][j] - matrix2[i][j];
            new_row.push_back(diff);
        }

        result->push_back(new_row);
    }

    return result;
}

std::vector<std::vector<float>>* multiplyMatrices(const std::vector<std::vector<float>>& matrix1, const std::vector<std::vector<float>>& matrix2) {
    int m1_rows = matrix1.size();
    int m1_cols = matrix1[0].size();
    int m2_rows = matrix2.size();
    int m2_cols = matrix2[0].size();


    if (m1_cols != m2_rows) {
        std::cerr << "\nIncorrect dimensions for operator '*' - have MATRIX [" << m1_rows <<"]["<<m1_cols <<"] and MATRIX ["<< m2_rows <<"]["<< m2_cols <<"]\n\n";
  
        break_matriz = true;
        return nullptr;
    }

  
    std::vector<std::vector<float>>* result = new std::vector<std::vector<float>>(m1_rows, std::vector<float>(m2_cols, 0));

  
    for (int i = 0; i < m1_rows; ++i) {
        for (int j = 0; j < m2_cols; ++j) {
            for (int k = 0; k < m1_cols; ++k) {
                (*result)[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

std::vector<std::vector<float>>* multiplyByNumber(const std::vector<std::vector<float>>& matrix, float scalar) {
   
    std::vector<std::vector<float>>* result = new std::vector<std::vector<float>>(matrix.size(), std::vector<float>(matrix[0].size()));

   
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            (*result)[i][j] = matrix[i][j] * scalar;
        }
    }

    return result;
}

void asterisco_plot(int j, double x , double stepY, double minY, double maxY){
    
    for(int i = 25; i > 0; i--){
        double y = ((double)i / (25+1)) * (maxY - minY) + minY;
            if (std::abs(x - y ) < stepY/2){
                matriz_plot[i][j] = '*';
                break;
            }
    }
}

void plotGraph(TreeNode *plot, double minX, double maxX, double minY, double maxY, int resolutionX, int resolutionY, HashTable hash) {

    double stepX = (maxX - minX) / (resolutionX);
    double stepY = (maxY - minY) / (resolutionY);
    double aux_lo = minX;
    double aux_hi = maxX;
    double aux_lo_y = minY;
    double aux_hi_y = maxY;

    bool printx = false;
    


    for (int i = resolutionY; i > 0; i--) {
        double y = minY + i * stepY;
         
        for (int j = 1; j <= resolutionX; j++) {
            double x = minX + j * stepX;
            setContador();
            
            asterisco_plot(j, RPN_Walk_calculatinge(plot,x,hash), stepY, minY, maxY);
        }

            continue;
        
        
    }
    printf("\n");
    for (int i = resolutionY; i > 0; i--) {
        for (int j = 1; j <= resolutionX; j++) {
            printf("%c", matriz_plot[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void withdrawAxis(){
    for (int i = 25; i > 0; i--) {
        for (int j = 1; j <= 80; j++) {
            if(matriz_plot[i][j] == '|' || matriz_plot[i][j] == '-'){
                matriz_plot[i][j] = ' ';
            }
        }
    }
}

void putAxis(double minX, double maxX, double minY, double maxY, int resolutionX, int resolutionY){
    double stepX = (maxX - minX) / (resolutionX);
    double stepY = (maxY - minY) / (resolutionY);
    bool printx = false;
    double menory = abs(maxY);
    double menorx= abs(maxX);
    int i_menory;
    int j_menorx;

    for (int i = resolutionY; i > 0 ; i--) {
        double y = minY + i * stepY;
        if(abs(y) < menory){
            if(menory-abs(y) < 0.0000001){
                if(y > 0){
                    menory = abs(y);
                    i_menory = i;
                }
            }else{
            menory = abs(y);
            i_menory = i;
            }
        }
        

        for (int j = 1; j <= resolutionX; j++) {
            double x = minX + j * stepX;
            if(abs(x) < menorx){
                menorx = abs(x);
                j_menorx = j;
            }
             if(matriz_plot[i][j] != '*'){
           
                     matriz_plot[i][j] = ' ';
            
            }       
    }
    
}
    for(int k = 1; k <= 25; k++){
        matriz_plot[k][j_menorx] = '|';
    }
    for(int k = 1; k <= 80; k++){
        matriz_plot[i_menory][k] = '-';
    }
    
}

void plotarGrafico(TreeNode *plot, HashTable hash){
    if(plot == NULL){
        printf("\nNo function defined! \n\n");
        return;
    }else{
        RPN_Walk_Errors_2(plot, hash);
        if(not_existId){
            printf("\n\n");
            return;
        }else{
            if(erase_plot || trocouVorH_view){
                
                for (int i = 25; i >0 ; i--) {
                    for (int j = 1; j <= 80; j++) {
                        matriz_plot[i][j] = ' ';
                    }
                }
                trocouVorH_view = false;
            }
            if(!draw_axix){
                withdrawAxis();
            }else{
                putAxis(h_view_lo, h_view_hi, v_view_lo, v_view_hi, 80, 25);

            }
            plotGraph(plot, h_view_lo, h_view_hi, v_view_lo, v_view_hi, 80, 25, hash);
        }
    }
    
}