#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>

CGame::CGame(){
	estado = Estado::estado_Iniciando;
	atexit(SDL_Quit);
}

void CGame::Iniciando(){
	if(SDL_Init(SDL_INIT_VIDEO)<0){
		printf("error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	screen = SDL_SetVideoMode(640,480,24,SDL_SWSURFACE);
	//screen = SDL_SetVideoMode(640,480,24,SDL_HWACCEL);

	if(screen == NULL){
		printf("error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("Mi primer juego", NULL);
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
			CGame::Iniciando();	//INICIALIZAR
			break;
		case Estado::estado_Menu:	//MENU	
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
