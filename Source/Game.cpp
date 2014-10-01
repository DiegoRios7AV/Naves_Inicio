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
			//manda llamar el metodo iniciando
			/*Iniciando();{
				screen = SDL_SetVideoMode(640,480,24,SDL_SWSURFACE);
				//nave= SDL_LoadBMP("../Data/minave.bmp");
				nave = IMG_LoadJPG_RW(SDL_RWFromFile("../Data/cuadro.jpg","rb"));
				SDL_Rect fuente;
				fuente.x=90;
				fuente.y=152;
				fuente.w=242;
				fuente.h=76;
				SDL_Rect destino;
				destino.x = 100;
				destino.y= 100;
				destino.w= 100;
				destino.h=100;

				SDL_BlitSurface(nave,&fuente,screen,&destino);
				SDL_FreeSurface(nave);

				//IMG_LoadJPG_RW(SDL_RWFromFile("direccion del archivo.jpg","rb"));
				//IMG_LoadPNG_RW(SDL_RWFromFile("direccion del archivo.png","rb"));
				

			}*/
			
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
