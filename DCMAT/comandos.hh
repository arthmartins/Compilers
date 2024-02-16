#ifndef COMANDOS_HH
#define COMANDOS_HH

#define H_VIEW_LO_DEFAULT -6.5
#define H_VIEW_HI_DEFAULT 6.5
#define V_VIEW_LO_DEFAULT -3.5
#define V_VIEW_HI_DEFAULT 3.5
#define FLOAT_PRECISION_DEFAULT 6
#define INTEGRAL_STEPS_DEFAULT 1000

#define DRAW_AXIX_DEFAULT true
#define ERASE_PLOT_DEFAULT true
#define CONNECT_DOTS_DEFAULT false

void setDefaultValues();

void showSettings();

void printAbout();

void setH_view(float h_lo, float h_hi);

void setV_view(float v_lo, float v_hi);

void setAxis(int valor);

void setErase(int valor);

void setConnectDots(int valor);

void setFloatPrecision(int valor);

void setIntegralSteps(int valor);

#endif