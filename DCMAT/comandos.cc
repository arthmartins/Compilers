#include "comandos.hh"
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
    
    printf("\nh_view_lo: %.*f \n",float_precision, h_view_lo);
    printf("h_view_hi: %.*f\n",float_precision, h_view_hi);
    printf("v_view_lo: %.*f\n",float_precision, v_view_lo);
    printf("v_view_hi: %.*f\n",float_precision, v_view_hi);
    printf("float precision: %d\n",float_precision);
    printf("integral_steps: %d\n\n",integral_steps);

    printf("Draw Axis: %s\n", draw_axix ? "ON" : "OFF");
    printf("Erase Plot: %s\n", erase_plot ? "ON" : "OFF");
    printf("Connect Dots: %s\n\n", connect_dots ? "ON" : "OFF");

}

void setH_view(float h_lo, float h_hi){
    h_view_lo = h_lo;
    h_view_hi = h_hi;
}

void setV_view(float v_lo, float v_hi){
    v_view_lo = v_lo;
    v_view_hi = v_hi;
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
    float_precision = valor;
}

void setIntegralSteps(int valor){
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