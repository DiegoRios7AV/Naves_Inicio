#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "Objeto.h"

CGame::CGame(){
	frames=0;
	tiempoFrameInicio=0;
	estado = Estado::ESTADO_INICIANDO;//ACT2: Mal, aqui debes de poner tu estado inicial, por eso te marcara error.
	atexit(SDL_Quit);
}
void CGame::Iniciando(){

	if (SDL_Init(SDL_INIT_VIDEO)){
		printf("Error %S ", SDL_GetError());
		exit (EXIT_FAILURE);
	}
	screen = SDL_SetVideoMode ( WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE | SDL_DOUBLEBUF );
	
	if (screen == NULL){
		printf("Error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_Flip (screen); // este codigo estara provicionalmente aqui.
	SDL_WM_SetCaption( "Mi primer juego", NULL);
	nave = new Nave(screen, "../Data/MiNave.bmp",(WIDTH_SCREEN / 2)/*-(w/2)*/,(HEIGHT_SCREEN-80)/*-(h)*/,0);
	menu= new Objeto(screen,"../Data/Menu.bmp",0,0,1);	
	textos= new Objeto(screen,"../Data/textos.bmp",0,0,-1);
	fondo=new Objeto(screen,"../Data/fondo_juego.bmp",0,0,MODULO_MENU_FONDO);



	/*
	menu = new Objeto(screen, "../Data/menu.bmp",0,0,1);
	//enemigo = new Nave(screen, "../Data/emuerte.bmp",0,0);
	//6+
	titulos= new Objeto(screen,"../Data/titulos.bmp",0,0,1);
	btnInicio= new Objeto(screen,"../Data/btnInicio.bmp",0,0,1);
	btnSalir= new Objeto(screen,"../Data/btnSalir.bmp",0,0,1);
	//6-
	//FONFO+
	fondo=new Objeto(screen, "../Data/fondo.bmp",0,0,1);
	//FONDO-
	*/

	enemigoArreglo = new Nave* [10];
	for	(int i=0;i<10;i++)
	enemigoArreglo[i] =new Nave(screen, "../Data/enemigo.bmp",i*65,0,2);

	//enemigoParabola=-100.0f;
	//enemigo->SetStep(4);
	for (int i=0;i<10;i++)
		enemigoArreglo[i]->GetNaveObjeto()->SetStep(4);
	///
	//nave->CargarImagen("../Data/MiNave.bmp");
}

// Con esta función eliminaremos todos los elementos en pantalla
////void CGame::Finalize(){
////	SDL_Quit();
////}
void CGame::Finalize()
{
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
			case Estado::ESTADO_INICIANDO: //INICIALIZAR
				//switch(estado){
				Iniciando();
				InicianilizandoStage();
				estado=ESTADO_MENU;
				break;
			/*	nave = SDL_LoadBMP("../Data/MiNave.bmp");
				SDL_Rect Fuente;
				Fuente.x =90;
				Fuente.y =152;
				Fuente.w =242;
				Fuente.h =76;
				SDL_Rect destino;
				destino.x =100;
				destino.y =100;
				destino.w =100;
				destino.h =100;
				SDL_BlitSurface(nave, &Fuente, screen, &destino);
				SDL_BlitSurface(nave, NULL, screen, NULL);
				SDL_FreeSurface(nave);
*/
				
			case Estado::ESTADO_MENU:
				keys= SDL_GetKeyState(NULL);
				menu->Pintar();
				textos->Pintar(MODULO_TEXTO_TITULO,75,15);
				//textonombre->Pintar();
				/******************   MENU     ***************/
	
		if(estaSeleccionado){
			textos->Pintar(MODULO_TEXTO_OPCION1_SELEC,247,110);
			textos->Pintar(MODULO_TEXTO_OPCION2,263,170);
		}else{
				textos->Pintar(MODULO_TEXTO_OPCION1,247,110);
				textos->Pintar(MODULO_TEXTO_OPCION2_SELEC,263,170);
			}

		if(keys[SDLK_DOWN])
					estaSeleccionado=false;
					
		if(keys[SDLK_UP])
					estaSeleccionado=true;
				
				if(keys[SDLK_RETURN])
				{					
					if(estaSeleccionado)
						estado=ESTADO_PRE_JUGANDO;
					else
						salirJuego=true;
				}

	/************************************************/
		textos->Pintar(MODULO_TEXTO_DECORADO,190,370);
		textos->Pintar(MODULO_TEXTO_NOMBRE,345,420);
			
			break;

			case Estado::ESTADO_PRE_JUGANDO:
				nivelActual=0;
				vidas=1;
				enemigosEliminados=0;
				estado=ESTADO_JUGANDO;
				break;
			
			case Estado::ESTADO_JUGANDO:	//JUGAR	
				//MENU
				////nave->PintarModulo (0,0,64,64);
			SDL_FillRect(screen, NULL, 0x000000);
			keys = SDL_GetKeyState(NULL);
			//enemigo->Actualizar();

			for (int i=0;i<niveles[nivelActual].cantidadEnemigosEnPantalla;i++)
				{
					enemigoArreglo[i]->GetNaveObjeto()->Actualizar();//////////////////////////////////
					checkCollision(nave->GetNaveObjeto(), enemigoArreglo[i]->GetNaveObjeto());
				}
							
			MoverEnemigo();

			if(keys[SDLK_RIGHT]&& !esLimitePantalla(nave->GetNaveObjeto(),BORDE_DERECHO)){

			//nave->PintarModulo(0,100,100);
			nave->Mover(niveles[nivelActual].velocidadBalasPropias);
			///Iniciando();
				///estado=ESTADO_MENU;
			}
			//
			if(keys[SDLK_LEFT]&& !esLimitePantalla(nave->GetNaveObjeto(),BORDE_IZQUIERDO)){
			nave->MoverIzquierda(niveles[nivelActual].velocidadBalasPropias);
			}
			if(keys[SDLK_UP]&& !esLimitePantalla(nave->GetNaveObjeto(),BORDE_SUPERIOR)){
			nave->MoverArriba(niveles[nivelActual].velocidadBalasPropias);
			}
			if(keys[SDLK_DOWN]&& !esLimitePantalla(nave->GetNaveObjeto(),BORDE_INFERIOR)){
			nave->MoverAbajo(niveles[nivelActual].velocidadBalasPropias);
			}
						//SIMULcion colicion
			if(keys[SDLK_x]){//bala nuestra y bala enemigo
			//PONER FOR
				nave->ColisionarConBala(true);
			}
			if(keys[SDLK_c]){
				int naveAEliminar=rand()%niveles[nivelActual].cantidadEnemigosEnPantalla;
				enemigoArreglo[naveAEliminar]->ColisionarConBala(true);
			}
			if(keys[SDLK_v]){

			}
			//////
			if (vidas<=0)
			//estado = ESTADO_TERMINANDO;// DESCOM
			estado = ESTADO_PRE_JUGANDO;//SOLO PRUEVAS

			//COLISIONES///
			for(int i=0;i<niveles[nivelActual].cantidadEnemigosEnPantalla;i++){
				if (enemigoArreglo[i]->estaColisionandoConBalas(nave->GetNaveObjeto()))
				{
					printf("Collision propia con bala enemiga detected\n");
					//vidas--;
				}
				
			}
			if (enemigosEliminados >= niveles[nivelActual].cantidadEnemigosAEliminar){
				enemigosEliminados=0;
				//aqui va fondo 2;
				nivelActual++;
			}
			//////FOR AMEDIAS POR SIMULAR COLICIONES

			//fondo+
			fondo->Pintar();
			//fondo-
			//
			nave->Pintar();
			//enemigo->Pintar();
			nave->Actualizar(NAVE_PROPIA,niveles[nivelActual].velocidadBalasPropias);
			//este for tenia 10 //niveles[nivelActual].cantidadEnemigosEnPantalla
			for (int i=0;i<niveles[nivelActual].cantidadEnemigosEnPantalla;i++)
				enemigoArreglo[i]->Pintar();
		/*
			if (modulo[0] && !collision (&nave,&enemigoArreglo))
			estado=ESTADO_FINALIZADO;
			*/
			//bala+
			if(keys[SDLK_SPACE]){
			nave->Disparar(NAVE_PROPIA, niveles[nivelActual].limiteBalasPropias);
			//nave->Actualizar();
			}
			// enemigo disparar+
			for (int i=0;i<niveles[nivelActual].cantidadEnemigosEnPantalla;i++){
				enemigoArreglo[i]->Pintar();
				enemigoArreglo[i]->AutoDisparar(niveles[nivelActual].efectividad,MAXIMO_BALAS);
				enemigoArreglo[i]->Actualizar(NAVE_ENEMIGO, niveles[nivelActual].velocidadBalasEnemigo);
			if (nave->estaColisionandoConBalas(enemigoArreglo[i]->GetNaveObjeto())){
				/*enemigoArreglo[i]->setVisible(false);
				enemigosEliminados++;*/
					printf("Collision enemigo con bala propia detected\n");
				}
			}

			//enemigo disparar-

			//bala-
			break;
			case Estado::ESTADO_TERMINADO:	//TERMINAR
			break;
			case Estado::ESTADO_FINALIZADO: //SALIR
				salirJuego = true;
			break;
		};
				while (SDL_PollEvent(&event))//aqui SDL creara una lista de eventos ocurr
				{
					if (event.type == SDL_QUIT){salirJuego =true;}//si se detecta una
						if (event.type == SDL_KEYDOWN){}
				}
		SDL_Flip(screen); //imprime en pantalla variable screen

		frames++;
		tiempoFrameFinal = SDL_GetTicks();
		while(tiempoFrameFinal<(tiempoFrameInicio + FPS_DELAY)){
			tiempoFrameFinal =SDL_GetTicks();
		SDL_Delay(1);
		}
		//printf("Frame:%d Tiempo:%d TiempoPorFrame:%d FPS:%f\n",frames, tiempoFrameInicio, tiempoFrameFinal-tiempoFrameInicio,1000.0f /(float)(tiempoFrameFinal-tiempoFrameInicio));
		tiempoFrameInicio= tiempoFrameFinal;
    }
	return true;
}
bool CGame::esLimitePantalla(Objeto *objeto, int bandera){
	if(bandera & BORDE_IZQUIERDO)
		if (objeto->obtenerX() <=0)
			return true;
	if(bandera & BORDE_SUPERIOR)
		if (objeto->obtenerY() <=0)
			return true;
	if(bandera & BORDE_DERECHO)
		if (objeto->obtenerX() >=(WIDTH_SCREEN-objeto->obtenerW()))
			return true;
	if(bandera & BORDE_INFERIOR)
		if (objeto->obtenerY() >=(HEIGHT_SCREEN-objeto->obtenerH()))
			return true;
	return false;
}

bool CGame::isPointInRect(int x, int y, Objeto*enemigo)
{
	if(x>=enemigo->obtenerX() &&
		y>=enemigo->obtenerY() &&
		x<=enemigo->obtenerX()+enemigo->obtenerW() &&
		y<=enemigo->obtenerY()+enemigo->obtenerH())
	{
			return true;
	}
			return false;
}

bool CGame::checkCollision(Objeto*nave, Objeto*enemigo)
{
	
		if(isPointInRect(nave->obtenerX(),nave->obtenerY(),enemigo) == true ||
			isPointInRect(nave->obtenerX()+nave->obtenerW(),nave->obtenerY(),enemigo) == true ||
			isPointInRect(nave->obtenerX(),nave->obtenerY()+nave->obtenerH(),enemigo) == true ||
			isPointInRect(nave->obtenerX()+nave->obtenerW(),nave->obtenerY()+nave->obtenerH(),enemigo) == true
			)
			{
				printf("Collision detected\n");
				nave->resetPosition();
				nave->Pintar();
				estado=ESTADO_MENU;
				return true;
			}
		return false;
}


void CGame::MoverEnemigo(){
//	if(!esLimitePantalla(enemigo,BORDE_DERECHO))
	//enemigo->Mover(1,50);
	/*
	switch(enemigo->ObtenerStepActual()){
	case 0:
		if(!enemigo->IsRunningAnimacion())
			//enemigo->IncrementarStep();
		enemigo->Mover(1,WIDTH_SCREEN-enemigo->obtenerW());
		break;
	case 1:
		enemigo->IncrementarStep();
		break;
	case 2:

	  if (!enemigo->IsRunningAnimacion())
		  
		  enemigo->Mover(-1,WIDTH_SCREEN-enemigo->obtenerW());
		//enemigo->IncrementarSenemigo->Mover(-1,150);
		  // enemigo->IncrementarStep();

		break;
	case 3:
		enemigo->IncrementarStep();
		break;
	}
	*/
	//enemigo->ponerEn(enemigoParabola*enemigoParabola,enemigoParabola);
	//enemigoParabola+=0.1f;
	//copia sw-------------
	for (int i=0;i<10;i++)
		switch(enemigoArreglo[i]->GetNaveObjeto()->ObtenerStepActual()){
	case 0:
		if(!enemigoArreglo[i]->GetNaveObjeto()->IsRunningAnimacion())
			//enemigo->IncrementarStep();

		enemigoArreglo[i]->GetNaveObjeto()->Mover(niveles[nivelActual].velocidadEnemigo,WIDTH_SCREEN-enemigoArreglo[i]->GetNaveObjeto()->obtenerW());
		
	

		if(esLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(),BORDE_DERECHO))
			enemigoArreglo[i]->GetNaveObjeto()->TerminarAnimacion();

		break;
	case 1:
		enemigoArreglo[i]->GetNaveObjeto()->IncrementarStep();
		break;
	case 2:
		 if (!enemigoArreglo[i]->GetNaveObjeto()->IsRunningAnimacion())
		  enemigoArreglo[i]->GetNaveObjeto()->Mover(-niveles[nivelActual].velocidadEnemigo,WIDTH_SCREEN-enemigoArreglo[i]->GetNaveObjeto()->obtenerW());

		 
		
		if(esLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(),BORDE_IZQUIERDO))
			enemigoArreglo[i]->GetNaveObjeto()->TerminarAnimacion();

		break;
	case 3:
		enemigoArreglo[i]->GetNaveObjeto()->IncrementarStep();
		break;
	}

}