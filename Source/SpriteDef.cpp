#include "SpriteDef.h"
#include "Config.h"

SpriteDef::SpriteDef(){
//nave
	modulo[0].id=MODULO_ENEMIGO_NAVE;
	modulo[0].x=0;
	modulo[0].y=0;
	modulo[0].w=64;
	modulo[0].h=64;

	//fondo
	modulo[1].id=MODULO_MENU_FONDO;
	modulo[1].x=0;
	modulo[1].y=0;
	modulo[1].w=WIDTH_SCREEN;
	modulo[1].h=HEIGHT_SCREEN;

	//enemigo
	modulo[2].id=MODULO_ENEMIGO_NAVE;
	modulo[2].x=0;
	modulo[2].y=0;
	modulo[2].w=54;
	modulo[2].h=61;

	//texto Titulo
	modulo[3].id=MODULO_TEXTO_TITULO;
	modulo[3].x=61;
	modulo[3].y=26;
	modulo[3].w=487;
	modulo[3].h=69;

	//texto iniciar
	modulo[4].id=MODULO_TEXTO_OPCION1;
	modulo[4].x=248;
	modulo[4].y=107;
	modulo[4].w=140;
	modulo[4].h=50;


	//texto Salir
	modulo[5].id=MODULO_TEXTO_OPCION2;
	modulo[5].x=248;
	modulo[5].y=153;
	modulo[5].w=116;
	modulo[5].h=47;


	//texto Deco
	modulo[6].id=MODULO_TEXTO_DECORADO;
	modulo[6].x=165;
	modulo[6].y=317;
	modulo[6].w=294;
	modulo[6].h=48;

	//texto Nombre
	modulo[7].id=MODULO_TEXTO_NOMBRE;
	modulo[7].x=213;
	modulo[7].y=379;
	modulo[7].w=213;
	modulo[7].h=44;

	//texto iniciarHover
	modulo[8].id=MODULO_TEXTO_OPCION1_SELEC;
	modulo[8].x=249;
	modulo[8].y=203;
	modulo[8].w=141;
	modulo[8].h=48;


	//texto SalirHover
	modulo[9].id=MODULO_TEXTO_OPCION2_SELEC;
	modulo[9].x=249;
	modulo[9].y=250;
	modulo[9].w=115;
	modulo[9].h=45;

//bala
	modulo[10].id= MODULO_BALAS_BALA1;
	modulo[10].x=0;
	modulo[10].y=0;
	modulo[10].w=5;
	modulo[10].h=5;

}