//******************************************************************************
//Aqui se añadiran las funciones personales
//******************************************************************************

#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED

//******************************************************************************
// INCLUDES

#include <stdint.h>

//******************************************************************************
// FUNCTIONS

//******************************************************************************
// NAVE
void mov_arriba(int *n, int *m);
void mov_abajo(int *n, int *m);
void mov_izq(int *n, int *m);
void mov_der(int *n, int *m);
void dash_izq(int *n, int *m);
void dash_der(int *n, int *m);
void dib_nave(int *n, int *m);
void borr_nave(int *n, int *m);
void disparo(int *a, int *b, int *c, int *d, int *e, int *f);
void comprobar_nave(int *a, int *b, int *c, int *d);

//******************************************************************************
// METEORITO
void dib_met(int *n, int *m);
void borr_met(int *n, int *m);
void met_anim(int *a, int *b, int *c, int *d);

//******************************************************************************
// INTERFAZ
void dib_bal_un();
void dib_bal_do();
void dib_bal_tr();

void dib_dash();

void dib_bordes();

void borr_num_ant(int *n, int*m);
void dib_cero(int n_pos_x, int n_pos_y);
void dib_uno(int n_pos_x, int n_pos_y);
void dib_dos(int n_pos_x, int n_pos_y);
void dib_tres(int n_pos_x, int n_pos_y);
void dib_cuatro(int n_pos_x, int n_pos_y);
void dib_cinco(int n_pos_x, int n_pos_y);
void dib_seis(int n_pos_x, int n_pos_y);
void dib_siete(int n_pos_x, int n_pos_y);
void dib_ocho(int n_pos_x, int n_pos_y);
void dib_nueve(int n_pos_x, int n_pos_y);
void contador(int *a, int *b, int *c, int *d, int *e, int *f, int *g);

#endif
