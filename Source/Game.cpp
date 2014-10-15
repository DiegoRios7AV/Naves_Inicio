#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>
#include "config.h"

CGame::CGame(){
	estado = Estado::estado_Iniciando;
	atexit(SDL_Quit);
}

void CGame::Iniciando(){
	if(SDL_Init(SDL_INIT_VIDEO)<0){
		printf("error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	screen = SDL_SetVideoMode(WIDTH_SCREEN,HEIGHT_SCREEN,24,SDL_SWSURFACE);

	if(screen == NULL){	
		printf("error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("Mi primer juego", NULL);
	nave= new Sprite(screen);
	nave->CargarImagen("../Data/minave.bmp");
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case Estado::estado_Iniciando:
				Iniciando();
				estado= estado_Menu;
			break;
		case Estado::estado_Menu:	//MENU	
				nave->PintarModulo(SPRITE_MODULE_MI_NAVE,100,100);
			break;
		case Estado::estado_Jugando: //JUGANDO	
			break;
		case Estado::estado_Terminado: //TERMINADO
			break;
		case Estado::estado_Finalizado: //SALIR
				salirJuego = true;
			break;
		};

		//Este codigo esta provicionalmente aqui
		SDL_Flip(screen);
    }
	return true;
}
