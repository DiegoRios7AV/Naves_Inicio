//este es el bueno que esta en suoruce

#include "SpriteDef.h"
#include "config.h"

SpriteDef::SpriteDef(){
	//nave
	modulos[0].id=MODULO_ENEMIGO_NAVE;
	modulos[0].x=0;
	modulos[0].y=0;
	modulos[0].w=64;
	modulos[0].h=64;

	//fondo
	modulos[1].id=MODULO_MENU_FONDO;
	modulos[1].x=0;
	modulos[1].y=0;
	modulos[1].w=WIDTH_SCREEN;
	modulos[1].h=HEIGHT_SCREEN;

	//enemigo
	modulos[2].id=MODULO_ENEMIGO_NAVE;
	modulos[2].x=0;
	modulos[2].y=0;
	modulos[2].w=54;
	modulos[2].h=61;

	//texto Titulo
	modulos[3].id=MODULO_TEXTO_TITULO;
	modulos[3].x=61;
	modulos[3].y=26;
	modulos[3].w=487;
	modulos[3].h=69;

	//texto iniciar
	modulos[4].id=MODULO_TEXTO_OPCION1;
	modulos[4].x=248;
	modulos[4].y=107;
	modulos[4].w=140;
	modulos[4].h=50;


	//texto Salir
	modulos[5].id=MODULO_TEXTO_OPCION2;
	modulos[5].x=248;
	modulos[5].y=153;
	modulos[5].w=116;
	modulos[5].h=47;


	//texto Deco
	modulos[6].id=MODULO_TEXTO_DECORADO;
	modulos[6].x=165;
	modulos[6].y=317;
	modulos[6].w=294;
	modulos[6].h=48;

	//texto Nombre
	modulos[7].id=MODULO_TEXTO_NOMBRE;
	modulos[7].x=213;
	modulos[7].y=379;
	modulos[7].w=213;
	modulos[7].h=44;

	//texto iniciarHover
	modulos[8].id=MODULO_TEXTO_OPCION1_SELEC;
	modulos[8].x=249;
	modulos[8].y=203;
	modulos[8].w=141;
	modulos[8].h=48;


	//texto SalirHover
	modulos[9].id=MODULO_TEXTO_OPCION2_SELEC;
	modulos[9].x=249;
	modulos[9].y=250;
	modulos[9].w=115;
	modulos[9].h=45;

//bala
	modulos[10].id= MODULO_BALAS_BALA1;
	modulos[10].x=0;
	modulos[10].y=0;
	modulos[10].w=5;
	modulos[10].h=5;

}

