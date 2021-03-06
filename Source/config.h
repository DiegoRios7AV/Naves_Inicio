#ifndef _CONFIG_H_
#define _CONFIG_H_

#define WIDTH_SCREEN 640
#define HEIGHT_SCREEN 480

#define BORDE_IZQUIERDO		1<<0
#define BORDE_DERECHO		1<<2
#define BORDE_INFERIOR		1<<3
#define BORDE_SUPERIOR		1<<4

#define FPS_LIMIT 30.0f
#define FPS_DELAY 1000.0f / FPS_LIMIT

#define MAXIMO_BALAS    500

#define NAVE_PROPIA     0
#define NAVE_ENEMIGO    1

#define MODULO_MINAVE_NAVE				0
#define MODULO_MENU_FONDO				1
#define MODULO_ENEMIGO_NAVE				2
#define MODULO_TEXTO_TITULO				3
#define MODULO_TEXTO_OPCION1			4
#define MODULO_TEXTO_OPCION2			5
#define MODULO_TEXTO_DECORADO			6
#define MODULO_TEXTO_NOMBRE				7
#define MODULO_TEXTO_OPCION1_SELEC		8
#define MODULO_TEXTO_OPCION2_SELEC		9
#define MODULO_BALAS_BALA1				10
 
#endif
