#define RED_COLOR  RGB565(255, 0, 0)
#define GREEN_COLOR RGB565(0, 188, 0)
#define YELLOW_COLOR RGB565(255, 255, 0)
#define BLUE_COLOR RGB565(0, 0, 255)
#define WHITE_COLOR RGB565(255, 255, 255)
#define BROWN_COLOR RGB565(128, 0, 0)
//******************************************************************************
// INCLUDES

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "global.h"
#include "hwplatform.h"
#include "tftdriver.h"
#include "scr_main.h"
#include "hwplatform.h"
#include <stdio.h>
#include "task_ui.h"

//******************************************************************************
// FUNCTIONS

//******************************************************************************
//NAVE

void dib_nave(int *n, int *m){
  int x_pos = *n, y_pos = *m;
  int scale = 3;
  int zeropos = 1;
  LCD_DrawRectangle(x_pos-(1*scale)-zeropos, y_pos-(5*scale), 3*scale, 2*scale, RED_COLOR); // Rectangulo superior
  LCD_DrawRectangle(x_pos-(2*scale)-zeropos, y_pos-(3*scale), 5*scale, 5*scale, RED_COLOR); // Tronco de la nave
  LCD_DrawRectangle(x_pos-(0*scale)-zeropos, y_pos-(7*scale), 1*scale, 12*scale, RED_COLOR); // Línea de central
  LCD_DrawRectangle(x_pos-(0*scale)-zeropos, y_pos-(4*scale), 1*scale, 3*scale, BLUE_COLOR); // Ventana de Arriba
  LCD_DrawRectangle(x_pos-(5*scale)-zeropos, y_pos+(2*scale), 11*scale, 2*scale, RED_COLOR); // Rectangulo inferior
  LCD_DrawRectangle(x_pos-(6*scale)-zeropos, y_pos+(3*scale), 2*scale, 2*scale, RED_COLOR); // Cuadrado de las patas izquierdo
  LCD_DrawRectangle(x_pos+(5*scale)-zeropos, y_pos+(3*scale), 2*scale, 2*scale, RED_COLOR); // Cuadrado de las patas derecho
  LCD_DrawRectangle(x_pos-(7*scale)-zeropos, y_pos+(4*scale), 2*scale, 2*scale, RED_COLOR); // Cuadrado de las patas izquierdo 2
  LCD_DrawRectangle(x_pos+(6*scale)-zeropos, y_pos+(4*scale), 2*scale, 2*scale, RED_COLOR); // Cuadrado de las patas derecho 2
  LCD_DrawRectangle(x_pos-(4*scale)-zeropos, y_pos+(1*scale), 1*scale, 1*scale, RED_COLOR); // Cañón izquierdo
  LCD_DrawRectangle(x_pos+(4*scale)-zeropos, y_pos+(1*scale), 1*scale, 1*scale, RED_COLOR); // Cañón derecho
  LCD_DrawRectangle(x_pos-(2*scale)-zeropos, y_pos+(4*scale), 5*scale, 1*scale, RED_COLOR); // Rectangulo del culo 1
  LCD_DrawRectangle(x_pos-(1*scale)-zeropos, y_pos+(5*scale), 3*scale, 1*scale, RED_COLOR); // Rectangulo del culo 2
  //LCD_DrawRectangle(x_pos-(7*scale)-zeropos, y_pos+(4*scale), 44, 3, WHITE_COLOR); //Prueba hitbox horizontal
  //LCD_DrawRectangle(x_pos-(0*scale)-zeropos, y_pos-(7*scale), 1*3, 12*3, WHITE_COLOR); //Prueba hitbox vertical
  *n = x_pos;
  *m = y_pos;

}

void borr_nave(int *n, int *m){
  int x_pos = *n, y_pos = *m;
  int scale = 3;
  int zeropos = 1;
  LCD_DrawRectangle(x_pos-(1*scale)-zeropos, y_pos-(5*scale), 3*scale, 2*scale, 0); // Rectangulo superior
  LCD_DrawRectangle(x_pos-(2*scale)-zeropos, y_pos-(3*scale), 5*scale, 5*scale, 0); // Tronco de la nave
  LCD_DrawRectangle(x_pos-(0*scale)-zeropos, y_pos-(7*scale), 1*scale, 12*scale, 0); // Línea de central
  LCD_DrawRectangle(x_pos-(0*scale)-zeropos, y_pos-(4*scale), 1*scale, 3*scale, 0); // Ventana de Arriba
  LCD_DrawRectangle(x_pos-(5*scale)-zeropos, y_pos+(2*scale), 11*scale, 2*scale, 0); // Rectangulo inferior
  LCD_DrawRectangle(x_pos-(6*scale)-zeropos, y_pos+(3*scale), 2*scale, 2*scale, 0); // Cuadrado de las patas izquierdo
  LCD_DrawRectangle(x_pos+(5*scale)-zeropos, y_pos+(3*scale), 2*scale, 2*scale, 0); // Cuadrado de las patas derecho
  LCD_DrawRectangle(x_pos-(7*scale)-zeropos, y_pos+(4*scale), 2*scale, 2*scale, 0); // Cuadrado de las patas izquierdo 2
  LCD_DrawRectangle(x_pos+(6*scale)-zeropos, y_pos+(4*scale), 2*scale, 2*scale, 0); // Cuadrado de las patas derecho 2
  LCD_DrawRectangle(x_pos-(4*scale)-zeropos, y_pos+(1*scale), 1*scale, 1*scale, 0); // Cañón izquierdo
  LCD_DrawRectangle(x_pos+(4*scale)-zeropos, y_pos+(1*scale), 1*scale, 1*scale, 0); // Cañón derecho
  LCD_DrawRectangle(x_pos-(2*scale)-zeropos, y_pos+(4*scale), 5*scale, 1*scale, 0); // Rectangulo del culo 1
  LCD_DrawRectangle(x_pos-(1*scale)-zeropos, y_pos+(5*scale), 3*scale, 1*scale, 0); // Rectangulo del culo 2
  
  *n = x_pos;
  *m = y_pos;

}

void mov_arriba(int *n, int *m){
  int x_pos = *n, y_pos = *m;
    if(y_pos >= 64 ){
      //Dibujo de la nave
      borr_nave(&x_pos,&y_pos);
      y_pos = y_pos - 32;
      dib_nave(&x_pos,&y_pos);
    }

  *n = x_pos;
  *m = y_pos;
}

void mov_abajo(int *n, int *m){
  int x_pos = *n, y_pos = *m;
  if(y_pos <= 224 ){
    borr_nave(&x_pos,&y_pos);
    y_pos = y_pos + 32;
    dib_nave(&x_pos,&y_pos);
  }
  *n = x_pos;
  *m = y_pos;
}

void mov_izq(int *n, int *m){
  int x_pos = *n, y_pos = *m;
  if(x_pos >= 48 ){
  
    //Dibujo de la nave
    borr_nave(&x_pos,&y_pos);
    x_pos = x_pos - 24;
    dib_nave(&x_pos,&y_pos);
  }
  *n = x_pos;
  *m = y_pos;  
}

void mov_der(int *n, int *m){
  int x_pos = *n, y_pos = *m;
  if(x_pos <= 192 ){
    //Dibujo de la nave
    borr_nave(&x_pos,&y_pos);
    x_pos = x_pos + 24;
    dib_nave(&x_pos,&y_pos);

  }
  *n = x_pos;
  *m = y_pos;  
}

void dash_izq(int *n, int *m){
  int x_pos = *n, y_pos = *m;
  if(x_pos >= 72 ){
    //Dibujo de la nave
    borr_nave(&x_pos,&y_pos);
    x_pos = x_pos - 48;
    dib_nave(&x_pos,&y_pos);
  }

  if(x_pos == 48){
    //Dibujo de la nave
    borr_nave(&x_pos,&y_pos);
    x_pos = x_pos - 24;
    dib_nave(&x_pos,&y_pos);
  }
  *n = x_pos;
  *m = y_pos;  
}

void dash_der(int *n, int *m){
  int x_pos = *n, y_pos = *m;
  if(x_pos <= 168 ){
    borr_nave(&x_pos,&y_pos);
    x_pos = x_pos + 48;
    dib_nave(&x_pos,&y_pos);
  }

  if(x_pos == 192){  
    borr_nave(&x_pos,&y_pos);
    x_pos = x_pos + 24;
    dib_nave(&x_pos,&y_pos);
  }
  *n = x_pos;
  *m = y_pos;  
}

void disparo(int *a, int *b, int *c, int *d, int *e, int *f){
  int disp_switch = *a;
  int disptemp = *b;
  int disp_pos_x = *c;
  int disp_pos_y = *d;
  int x_pos = *e;
  int y_pos = *f;
  if(disp_switch==1){
    if(++disptemp >= 2){
      disptemp = 0;
      LCD_DrawRectangle(disp_pos_x, disp_pos_y, 3, 6, 0);
      disp_pos_y = disp_pos_y - 8;
      LCD_DrawRectangle(disp_pos_x, disp_pos_y, 3, 6, YELLOW_COLOR);
      //Dibujamos otra nave por si se solapa
      dib_nave(&x_pos, &y_pos);
      if(disp_pos_y < 0){
        LCD_DrawRectangle(disp_pos_x, disp_pos_y, 3, 6, 0);
        disp_switch = 0;
      } 
    }   
  }
  if(disp_switch == 0){
    disp_pos_x = 0;
    disp_pos_y = 0;
  }  
  *a = disp_switch;
  *b = disptemp;
  *c = disp_pos_x;
  *d = disp_pos_y;
  *e = x_pos;
  *f = y_pos;
}

void comprobar_nave(int *a, int *b, int *c, int *d){
  int x_pos = *a, y_pos = *b, metpos_x = *c, metpos_y = *d;
  int i = 0;
  int j = 0;
  int k = 0;
  int var_comp;
  int vec_met_x[32];
  int vec_met_y[32];
  int vec_nav_x[44];  
  int vec_nav_y[21];
  //VALORES DE LA HITBOX DEL METEORITO
  for(i = 0;i <= 31;i++){
    var_comp = metpos_x - 16;
    vec_met_x[i] = var_comp + i;	
  }
  for(i = 0;i <= 31;i++){
    var_comp = metpos_y - 16;
    vec_met_y[i] = var_comp + i;	
  }

  //VALORES DE LA HITBOX DE LA NAVE
  for(i = 0;i<=43;i++){
    var_comp = x_pos - 22;
    vec_nav_x[i] = var_comp + i;
  }
  for(i = 0;i<=21;i++){
    var_comp = y_pos - 22;
    vec_nav_y[i] = var_comp + i;
  }
  //COMPARATIVA
  for(k = 0;k <= 43;k++){
    for(i = 0;i <= 31;i++){
      for(j = 0;j <= 21;j++){
        SysSleep(100);
        if(vec_met_y[i]==vec_nav_x[k] || vec_met_x[i] == vec_nav_y[j]){
        }
      }
    }  
  }

  *a = x_pos;
  *b = y_pos;
  *c = metpos_x;
  *d = metpos_y; 
}

//******************************************************************************
//METEORITO
void dib_met(int *n, int *m){
  int metpos_x = *n;
  int metpos_y = *m;
  int scale_met = 2;
  LCD_DrawRectangle(metpos_x-(8*scale_met), metpos_y-(3*scale_met), 16*scale_met, 6*scale_met, BROWN_COLOR);//<-rectangulo del medio 
  LCD_DrawRectangle(metpos_x-(7*scale_met), metpos_y-(5*scale_met), (16-2)*scale_met, 2*scale_met, BROWN_COLOR);//<-rectangulo superior 2
  LCD_DrawRectangle(metpos_x-(7*scale_met), metpos_y+(3*scale_met), (16-2)*scale_met, 2*scale_met, BROWN_COLOR);//<-rectangulo inferior 2
  LCD_DrawRectangle(metpos_x-(6*scale_met), metpos_y-(6*scale_met), (16-4)*scale_met, 1*scale_met, BROWN_COLOR);//<-rectangulo superior 3
  LCD_DrawRectangle(metpos_x-(6*scale_met), metpos_y+(5*scale_met), (16-4)*scale_met, 1*scale_met, BROWN_COLOR);//<-rectangulo inferior 3
  LCD_DrawRectangle(metpos_x-(5*scale_met), metpos_y-(7*scale_met), (16-6)*scale_met, 1*scale_met, BROWN_COLOR);//<-rectangulo superior 4
  LCD_DrawRectangle(metpos_x-(5*scale_met), metpos_y+(6*scale_met), (16-6)*scale_met, 1*scale_met, BROWN_COLOR);//<-rectangulo inferior 4
  LCD_DrawRectangle(metpos_x-(3*scale_met), metpos_y-(8*scale_met), (16-10)*scale_met, 1*scale_met, BROWN_COLOR);//<-rectangulo superior 5
  LCD_DrawRectangle(metpos_x-(3*scale_met), metpos_y+(7*scale_met), (16-10)*scale_met, 1*scale_met, BROWN_COLOR);//<-rectangulo inferior 5
  *n = metpos_x;
  *m = metpos_y; 
}
void borr_met(int *n, int *m){
  int metpos_x = *n;
  int metpos_y = *m;
  int scale_met = 2;
  LCD_DrawRectangle(metpos_x-(8*scale_met), metpos_y-(3*scale_met), 16*scale_met, 6*scale_met, 0);//<-rectangulo del medio 
  LCD_DrawRectangle(metpos_x-(7*scale_met), metpos_y-(5*scale_met), (16-2)*scale_met, 2*scale_met, 0);//<-rectangulo superior 2
  LCD_DrawRectangle(metpos_x-(7*scale_met), metpos_y+(3*scale_met), (16-2)*scale_met, 2*scale_met, 0);//<-rectangulo inferior 2
  LCD_DrawRectangle(metpos_x-(6*scale_met), metpos_y-(6*scale_met), (16-4)*scale_met, 1*scale_met, 0);//<-rectangulo superior 3
  LCD_DrawRectangle(metpos_x-(6*scale_met), metpos_y+(5*scale_met), (16-4)*scale_met, 1*scale_met, 0);//<-rectangulo inferior 3
  LCD_DrawRectangle(metpos_x-(5*scale_met), metpos_y-(7*scale_met), (16-6)*scale_met, 1*scale_met, 0);//<-rectangulo superior 4
  LCD_DrawRectangle(metpos_x-(5*scale_met), metpos_y+(6*scale_met), (16-6)*scale_met, 1*scale_met, 0);//<-rectangulo inferior 4
  LCD_DrawRectangle(metpos_x-(3*scale_met), metpos_y-(8*scale_met), (16-10)*scale_met, 1*scale_met, 0);//<-rectangulo superior 5
  LCD_DrawRectangle(metpos_x-(3*scale_met), metpos_y+(7*scale_met), (16-10)*scale_met, 1*scale_met, 0);//<-rectangulo inferior 5
  *n = metpos_x;
  *m = metpos_y; 
}

void met_anim(int *a, int *b, int *c, int *d){
  int cont_met = *a;
  int metpos_x = *b;
  int metpos_y = *c;
  int met_switch = *d;
  if(met_switch == 1){
    if(++cont_met >= 2){
      cont_met = 0;
      borr_met(&metpos_x, &metpos_y);
      metpos_y = metpos_y + 10;
      dib_met(&metpos_x, &metpos_y);
    }
  }
  if(metpos_y > 290){
    met_switch = 0;
  }
  if(met_switch == 0){
    metpos_y = 0;
  }      
  *a = cont_met;
  *b = metpos_x;
  *c = metpos_y;
  *d = met_switch; 
}

//******************************************************************************
//INTERFAZ

//BORDES
void dib_bordes(){
  LCD_DrawRectangle(0, 283, 240, 4, GREEN_COLOR);//Línea horizontal 1
  LCD_DrawRectangle(0, 283, 4, 37, GREEN_COLOR);//Borde izquierdo
  LCD_DrawRectangle(236, 284, 4, 37, GREEN_COLOR);//Borde derecho
  LCD_DrawRectangle(0, 316, 240, 4, GREEN_COLOR);//Borde bajo
  LCD_DrawRectangle(68, 283, 4, 37, GREEN_COLOR);//Pared 1
  LCD_DrawRectangle(116, 283, 4, 37, GREEN_COLOR);//Pared 2

}

//BALAS
void dib_bal_un(){
  LCD_DrawRectangle((4)*4, 300 - (2*4), 1*4, 5*4, GREEN_COLOR);// Centro
  LCD_DrawRectangle((4 - 1)*4, 300 - (1*4), 1*4, 3*4, GREEN_COLOR);// Lado izquierdo
  LCD_DrawRectangle((4 + 1)*4, 300 - (1*4), 1*4, 3*4, GREEN_COLOR);// Lado derecho
}
void dib_bal_do(){
  LCD_DrawRectangle((9)*4, 300 - (2*4), 1*4, 5*4, GREEN_COLOR);// Centro
  LCD_DrawRectangle((9 - 1)*4, 300 - (1*4), 1*4, 3*4, GREEN_COLOR);// Lado izquierdo
  LCD_DrawRectangle((9 + 1)*4, 300 - (1*4), 1*4, 3*4, GREEN_COLOR);// Lado derecho
}
void dib_bal_tr(){
  LCD_DrawRectangle((14)*4, 300 - (2*4), 1*4, 5*4, GREEN_COLOR);// Centro
  LCD_DrawRectangle((14 - 1)*4, 300 - (1*4), 1*4, 3*4, GREEN_COLOR);// Lado izquierdo
  LCD_DrawRectangle((14 + 1)*4, 300 - (1*4), 1*4, 3*4, GREEN_COLOR);// Lado derecho
}

//DASH

void  dib_dash(){
  LCD_DrawRectangle((23 - 4)*4, 300, 9*4, 1*4, GREEN_COLOR);// Línea centro
  LCD_DrawRectangle((23 - 2)*4, 300 - (2*4), 1*4, 5*4, GREEN_COLOR);// Ld1
  LCD_DrawRectangle((23 - 3)*4, 300 - (1*4), 1*4, 3*4, GREEN_COLOR);// Ld2
  LCD_DrawRectangle((23 + 2)*4, 300 - (2*4), 1*4, 5*4, GREEN_COLOR);// Li1
  LCD_DrawRectangle((23 + 3)*4, 300 - (1*4), 1*4, 3*4, GREEN_COLOR);// Li2
}
//NUMEROS
void borr_num_ant(int *n, int*m){ // BORRA EL NUMERO ANTERIOR
  int n_pos_x = *n;  
  int n_pos_y = *m;
LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 5*4, 0);
  *n = n_pos_x; 
  *m = n_pos_y;
}

void dib_cero(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 1*4, WHITE_COLOR);
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y + (2*4), 3*4, 1*4, WHITE_COLOR);
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (1*4), 1*4, 3*4, WHITE_COLOR);
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y - (1*4), 1*4, 3*4, WHITE_COLOR);
}

void dib_uno(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle(n_pos_x*4, n_pos_y - (1*4), 1*4, 1*4, WHITE_COLOR);
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y - (2*4), 1*4, 5*4, WHITE_COLOR);
}

void dib_dos(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 1*4, WHITE_COLOR);// barra arriba
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y + (2*4), 3*4, 1*4, WHITE_COLOR);// barra abajo
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 3*4, 1*4, WHITE_COLOR);              // barra medio
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y - (2*4), 1*4, 3*4, WHITE_COLOR);//unión arriba
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 1*4, 3*4, WHITE_COLOR);              //unión abajo
}

void dib_tres(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 1*4, WHITE_COLOR);// barra arriba
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y + (2*4), 3*4, 1*4, WHITE_COLOR);// barra abajo
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y - (2*4), 1*4, 5*4, WHITE_COLOR);// barra lateral der
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 3*4, 1*4, WHITE_COLOR);              // barra medio
}

void dib_cuatro(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 3*4, 1*4, WHITE_COLOR);              // barra medio
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y - (2*4), 1*4, 5*4, WHITE_COLOR);// barra lateral der    
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 1*4, 3*4, WHITE_COLOR);// media barra lateral izq
}

void dib_cinco(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 1*4, WHITE_COLOR);// barra arriba
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y + (2*4), 3*4, 1*4, WHITE_COLOR);// barra abajo
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 3*4, 1*4, WHITE_COLOR);              // barra medio
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 1*4, 3*4, WHITE_COLOR);//unión arriba
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y, 1*4, 3*4, WHITE_COLOR);              //unión abajo
}

void dib_seis(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 1*4, WHITE_COLOR);// barra arriba
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y + (2*4), 3*4, 1*4, WHITE_COLOR);// barra abajo
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 3*4, 1*4, WHITE_COLOR);              // barra medio
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 1*4, 3*4, WHITE_COLOR);//unión arriba
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y, 1*4, 3*4, WHITE_COLOR);              //unión abajo
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 1*4, 3*4, WHITE_COLOR);              //unión abajo
}

void dib_siete(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y - (2*4), 1*4, 5*4, WHITE_COLOR);// barra lateral der
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 1*4, WHITE_COLOR);// barra arriba
  LCD_DrawRectangle(n_pos_x*4, n_pos_y, 2*4, 1*4, WHITE_COLOR);              // barra medio
}

void dib_ocho(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y - (2*4), 1*4, 5*4, WHITE_COLOR);// barra lateral der
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 1*4, WHITE_COLOR);// barra arriba
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 3*4, 1*4, WHITE_COLOR);              // barra medio
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y + (2*4), 3*4, 1*4, WHITE_COLOR);// barra abajo    
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 1*4, 5*4, WHITE_COLOR);// media barra lateral izq
}

void dib_nueve(int n_pos_x, int n_pos_y){
  borr_num_ant(&n_pos_x,&n_pos_y);
  LCD_DrawRectangle((n_pos_x + 1)*4, n_pos_y - (2*4), 1*4, 5*4, WHITE_COLOR);// barra lateral der
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 3*4, 1*4, WHITE_COLOR);// barra arriba
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y, 3*4, 1*4, WHITE_COLOR);              // barra medio   
  LCD_DrawRectangle((n_pos_x - 1)*4, n_pos_y - (2*4), 1*4, 3*4, WHITE_COLOR);// media barra lateral izq
}

//******************************************************************************
//CONTADOR
void contador(int *a, int *b, int *c, int *d, int *e, int *f, int *g){
  int cont = *a;
  int cont_u = *b;
  int cont_d = *c;
  int cont_t = *d;
  int cont_cu = *e;
  int cont_ci = *f;
  int cont_se = *g;
  if(++cont >= 50){ //aumentara 1 valor por segundo
    cont = 0;
  // CONTADOR 1
    switch(cont_u){
      case 1:
      dib_uno(56, 300);
      cont_u++;
      break;
      case 2:
      dib_dos(56, 300);
      cont_u++;
      break;
      case 3:
      dib_tres(56, 300);
      cont_u++;
      break;
      case 4:
      dib_cuatro(56, 300);
      cont_u++;
      break;
      case 5:
      dib_cinco(56, 300);
      cont_u++;
      break;
      case 6:
      dib_seis(56, 300);
      cont_u++;
      break;
      case 7:
      dib_siete(56, 300);
      cont_u++;
      break;
      case 8:
      dib_ocho(56, 300);
      cont_u++;
      break;
      case 9:
      dib_nueve(56, 300);
      cont_u++;
      break;
      case 10:
      dib_cero(56, 300);
      cont_u = 1;
  // CONTADOR  2
        switch(cont_d){
        case 1:
        dib_uno(52, 300);
        cont_d++;
        break;
        case 2:
        dib_dos(52, 300);
        cont_d++;
        break;
        case 3:
        dib_tres(52, 300);
        cont_d++;
        break;
        case 4:
        dib_cuatro(52, 300);
        cont_d++;
        break;
        case 5:
        dib_cinco(52, 300);
        cont_d++;
        break;
        case 6:
        dib_seis(52, 300);
        cont_d++;
        break;
        case 7:
        dib_siete(52, 300);
        cont_d++;
        break;
        case 8:
        dib_ocho(52, 300);
        cont_d++;
        break;
        case 9:
        dib_nueve(52, 300);
        cont_d++;
        break;
        case 10:
        dib_cero(52, 300);
        cont_d = 1;
  //CONTADOR 3
        switch(cont_t){
          case 1:
          dib_uno(48, 300);
          cont_t++;
          break;
          case 2:
          dib_dos(48, 300);
          cont_t++;
          break;
          case 3:
          dib_tres(48, 300);
          cont_t++;
          break;
          case 4:
          dib_cuatro(48, 300);
          cont_t++;
          break;
          case 5:
          dib_cinco(48, 300);
          cont_t++;
          break;
          case 6:
          dib_seis(48, 300);
          cont_t++;
          break;
          case 7:
          dib_siete(48, 300);
          cont_t++;
          break;
          case 8:
          dib_ocho(48, 300);
          cont_t++;
          break;
          case 9:
          dib_nueve(48, 300);
          cont_t++;
          break;
          case 10:
          dib_cero(48, 300);
          cont_t = 1;
  // CONTADOR 4
            switch(cont_cu){
              case 1:
              dib_uno(44, 300);
              cont_cu++;
              break;
              case 2:
              dib_dos(44, 300);
              cont_cu++;
              break;
              case 3:
              dib_tres(44, 300);
              cont_cu++;
              break;
              case 4:
              dib_cuatro(44, 300);
              cont_cu++;
              break;
              case 5:
              dib_cinco(44, 300);
              cont_cu++;
              break;
              case 6:
              dib_seis(44, 300);
              cont_cu++;
              break;
              case 7:
              dib_siete(44, 300);
              cont_cu++;
              break;
              case 8:
              dib_ocho(44, 300);
              cont_cu++;
              break;
              case 9:
              dib_nueve(44, 300);
              cont_cu++;
              break;
              case 10:
              dib_cero(44, 300);
              cont_cu = 1;
  // CONTADOR 5
                switch(cont_ci){
                  case 1:
                  dib_uno(40, 300);
                  cont_ci++;
                  break;
                  case 2:
                  dib_dos(40, 300);
                  cont_ci++;
                  break;
                  case 3:
                  dib_tres(40, 300);
                  cont_ci++;
                  break;
                  case 4:
                  dib_cuatro(40, 300);
                  cont_ci++;
                  break;
                  case 5:
                  dib_cinco(40, 300);
                  cont_ci++;
                  break;
                  case 6:
                  dib_seis(40, 300);
                  cont_ci++;
                  break;
                  case 7:
                  dib_siete(40, 300);
                  cont_ci++;
                  break;
                  case 8:
                  dib_ocho(40, 300);
                  cont_ci++;
                  break;
                  case 9:
                  dib_nueve(40, 300);
                  cont_ci++;
                  break;
                  case 10:
                  dib_cero(40, 300);
                  cont_ci = 1;
  // CONTADOR 6
                switch(cont_se){
                  case 1:
                  dib_uno(36, 300);
                  cont_se++;
                  break;
                  case 2:
                  dib_dos(36, 300);
                  cont_se++;
                  break;
                  case 3:
                  dib_tres(36, 300);
                  cont_se++;
                  break;
                  case 4:
                  dib_cuatro(36, 300);
                  cont_se++;
                  break;
                  case 5:
                  dib_cinco(36, 300);
                  cont_se++;
                  break;
                  case 6:
                  dib_seis(36, 300);
                  cont_se++;
                  break;
                  case 7:
                  dib_siete(36, 300);
                  cont_se++;
                  break;
                  case 8:
                  dib_ocho(36, 300);
                  cont_se++;
                  break;
                  case 9:
                  dib_nueve(36, 300);
                  cont_se++;
                  break;
                  case 10:
                  dib_cero(36, 300);
                  cont_se = 1;
                  break;
                }
                break;  
              }
              break;
            }
            break;
          }
          break;
        }
        break;
      }
  }
  *a = cont;
  *b = cont_u;
  *c = cont_d;
  *d = cont_t;
  *e = cont_cu;
  *f = cont_ci;
  *g = cont_se;
}