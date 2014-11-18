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
	nave= new Nave(screen, "../Data/minave.bmp");
	//nave->CargarImagen("../Data/minave.bmp");
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
	int opc = 1;


          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case Estado::estado_Iniciando:
				//Iniciando();
			
				printf("\n1. ESTADO_INICIANDO");
			
				estado= estado_Menu;
				break;
		case Estado::estado_Menu:	//MENU	
				printf("\n2. ESTADO_MENU");

				if(opc == 1)
					estado= estado_Jugando;
				else
					estado= estado_Finalizado;
				
				break;
		case Estado::estado_Jugando: //JUGANDO
				
			
				printf("\n3. ESTADO_JUGANDO");
				estado= estado_Terminado;
				
				break;
		case Estado::estado_Terminado: //TERMINADO
			
				printf("\n4. ESTADO_TERMINADO");
				juegoTerminado=true;
				estado=estado_Menu;
				
				break;
		case Estado::estado_Finalizado: //SALIR
				
				printf("\n5. ESTADO_FINALIZADO");
				getchar();
				opc =2;
				salirJuego = true;
			break;
		};//endswitch

		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT){salirJuego=true;}
			if(event.type == SDL_KEYDOWN) { }

		};//endEVENTwhile

		//Este codigo esta provicionalmente aqui
		//SDL_Flip(screen);

    }//endWhile

	return true;

}//endGameStart
