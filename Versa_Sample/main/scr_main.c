//******************************************************************************
// File: scr_main.c
// Description: Main menu
// Author: Juan Ramon Vadillo (Versa Design S.L.)
// Licencia: Creative Commons No Comercial (CC BY-NC)
//
// Este archivo está sujeto a la Licencia Creative Commons No Comercial (CC BY-NC).
// Esto significa que puedes compartir, copiar, modificar y distribuir este archivo
// siempre y cuando sea para uso personal y no comercial, y siempre que se proporcione
// atribución al autor original. No se permite el uso comercial de este archivo ni la
// creación de obras derivadas sin el consentimiento expreso del autor.
//
// Para más detalles sobre la Licencia Creative Commons No Comercial (CC BY-NC), puedes
// consultar: [https://creativecommons.org/licenses/by-nc/4.0/]
//******************************************************************************

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
#include "misfunciones.h"

//******************************************************************************
// DEFINES & TYPEDEFS

#define RED_COLOR  RGB565(255, 0, 0)
#define GREEN_COLOR RGB565(0, 188, 0)
#define YELLOW_COLOR RGB565(255, 255, 0)
#define BLUE_COLOR RGB565(0, 0, 255)
#define WHITE_COLOR RGB565(255, 255, 255)
#define BROWN_COLOR RGB565(128, 0, 0)
//Nave
int y_line = 24;
int x_line = 32;
int y_pos = 160;
int x_pos = 120;
int scale = 3;
int zeropos = 1;
int disp_switch = 0;
int disptemp;
int disp_pos_y, disp_pos_x;
int vec_disp[6];

//Interfaz (posiciones en x)
int i_pos_y = 300;
int scale_i = 4;

//Posición balas
int b_u_pos = 4;
int b_d_pos = 9;
int b_t_pos = 14;

// Posición dash
int dash_pos = 23;

//PROVISIONALES  
int vec_nav_y[6];

//Meteorito
int metpos_x = 119, metpos_y = 64, scale_met = 2, var_comp = 0;
int vec_met_y[20];
int met_switch = 0;

//Temporizadores
int i = 0, j = 0, k = 0;
int cont = 0, cont_u = 1, cont_d = 1, cont_t = 1, cont_cu = 1, cont_ci = 1 ,cont_se = 1, cont_met = 0;  

//******************************************************************************
// FUNCTIONS

//******************************************************************************
static void EmphasizeButton(tUIEvent button)
//******************************************************************************
// Description: Emphasize a button setting it to green
// Parameters: button - button to emphasize
// Returns: none
//******************************************************************************
{
// Grid

   while(y_line < 240){
    LCD_DrawRectangle(y_line, 0, 1, 320, GREEN_COLOR);
    y_line=y_line + 24;
  }
    while(x_line < 320){
    LCD_DrawRectangle(0, x_line, 240, 1, GREEN_COLOR);
    x_line = x_line + 32;
  }
  
  switch (button)
  {
  case EV_FULL_REDRAW:
  case EV_PARTIAL_REDRAW: 
    
    // Interfaz
    
    // Bordes
    dib_bordes();

    //Disparos
    // D1
    dib_bal_un();

    //D2
    dib_bal_do();

    //D3
    dib_bal_tr();

    //Dash
    dib_dash();       

    //Modelo de la nave
    dib_met(&metpos_x, &y_pos);
    dib_nave(&x_pos,&y_pos);
    
    LCD_DrawRectangle(metpos_x, y_pos - 10, 1, 20, WHITE_COLOR);
    LCD_DrawRectangle(x_pos-1, y_pos - 10, 1, 17, GREEN_COLOR);

    break;

  case EV_KEY_UP_PRESS:
    mov_arriba(&x_pos, &y_pos);
    break;

  case EV_KEY_DOWN_PRESS:
    mov_abajo(&x_pos, &y_pos);
    break;

  case EV_KEY_LEFT_PRESS:
    mov_izq(&x_pos, &y_pos);
    break;

  case EV_KEY_RIGHT_PRESS:
    mov_der(&x_pos,&y_pos);
    break;

  case EV_KEY_OK_PRESS:
    metpos_y = 64;
    met_switch = 1;
    
    break;

  case EV_KEY_RETURN_PRESS:  
    if(disp_switch == 0){
    disp_switch = 1;
    disp_pos_y = y_pos - 20;
    disp_pos_x = x_pos - 1;
  }
    break;

  case EV_KEY_L_TRIGGER_PRESS: 
  //Diseñar dash izquierdo
  dash_izq(&x_pos, &y_pos);
    break;
  case EV_KEY_R_TRIGGER_PRESS:
  //Diseñar dash derecho
  dash_der(&x_pos, &y_pos);
    break;
  default:
    break;
  }
}

//******************************************************************************
void MainMenuScreenHandler(void)
//******************************************************************************
// Description: Main screen handler
//******************************************************************************
{
  tUIEvent event;

  UIForceFullRedraw(); // When we enter this menu, we have to force full redraw

  for (;;)
  {
    event = GetUserInterfaceEvent();
    switch (event)
    {
    case EV_INIT: break;// Initialization event
    case EV_FULL_REDRAW:
    case EV_PARTIAL_REDRAW:
      // Clear screen
      LCD_DrawRectangle(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);

      EmphasizeButton(event);
      break;
    case EV_TIMER_20MS:
      contador(&cont, &cont_u, &cont_d, &cont_t, &cont_cu, &cont_ci, &cont_se);
      //DISPARO
      disparo(&disp_switch, &disptemp, &disp_pos_x, &disp_pos_y, &x_pos, &y_pos);
      //Comprobación del disparo y el meteorito
      met_anim(&cont_met, &metpos_x, &metpos_y, &met_switch);
      if(disp_switch==1){ 
        for(i = 0;i <= 19;i++){
          var_comp = metpos_y - 10;
          vec_met_y[i] = var_comp + i;	
        }
        for(j = 0;j<=5;j++){
          vec_disp[j] = disp_pos_y + j;
        }
        for(i = 0;i <= 19;i++){
          for(j = 0;j <= 5;j++){
            if(vec_met_y[i] == vec_disp[j] && metpos_x == disp_pos_x){
              //Eliminar asteroide
              borr_met(&metpos_x, &metpos_y);
              //Frenar disparo
              LCD_DrawRectangle(disp_pos_x, disp_pos_y, 1*scale, 2*scale, 0);
              disp_switch = 0;
              met_switch = 0;
            }
          }
        }
      }
  
  
  if(met_switch == 1){
    if(metpos_x == (x_pos - 1)){
      if(++k >= 20){
        k=0;
        for(i = 0;i <= 19;i++){
          var_comp = metpos_y - 10;
          vec_met_y[i] = var_comp + i;	
        }
        for(j = 0;j<=15;j++){
          var_comp = y_pos - 8;
          vec_nav_y[j] = var_comp + j;
        }
        for(i = 0;i <= 19;i++){
          for(j = 0;j <= 15;j++){
            if(vec_met_y[i] == vec_nav_y[j]){
              LCD_DrawRectangle(metpos_x,metpos_y,1,10,WHITE_COLOR);
              LCD_DrawRectangle(x_pos - 1,y_pos,1,10,WHITE_COLOR);
              
            }
          }	
        }
      }
    }  
  }
  
      break;

    case EV_KEY_UP_PRESS:
      EmphasizeButton(event);
      break;
    case EV_KEY_DOWN_PRESS:
      EmphasizeButton(event);
      break;
    case EV_KEY_LEFT_PRESS:
      EmphasizeButton(event);
      break;
    case EV_KEY_RIGHT_PRESS:
      EmphasizeButton(event);
      break;
    case EV_KEY_OK_PRESS:
      EmphasizeButton(event);
      break;
    case EV_KEY_RETURN_PRESS:
      EmphasizeButton(event);
      break;
    case EV_KEY_L_TRIGGER_PRESS:
      EmphasizeButton(event);
      break;
    case EV_KEY_R_TRIGGER_PRESS:
      EmphasizeButton(event);
      break;
    case EV_KEY_START_PRESS:
      // Apagar
      LCD_DrawRectangle(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
      DisablePower();
      SysSleep(500);
      break;
    case EV_KEY_SELECT_PRESS:
      // Apagar
      LCD_DrawRectangle(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
      DisablePower();
      SysSleep(500);
      break;
    default: UIIdle();
    }
  }
}

