#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

CGame::CGame(){
	estado = Estado::estado_Iniciando;
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case Estado::estado_Iniciando: //INICIALIZAR
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
    }
	return true;
}
