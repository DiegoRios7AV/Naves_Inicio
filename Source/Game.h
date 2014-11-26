#include <SDL.h>
#include <SDL_image.h>
#include "Objeto.h"
#include "Nave.h"




class CGame
{
public:

	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZANDO,
	};

	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();


private:
	void Iniciando();
	void MoverEnemigo();
	bool esLimitePantalla(Objeto*objeto, int bandera);
	bool isPointInRect(int x, int y,Objeto*enemigo);
	bool checkCollision(Objeto*objeto, Objeto*enemigo);
	bool estaSeleccionado;
	int opcion;
	
Uint8*keys;
SDL_Event event;
SDL_Surface *screen;
Nave *nave;
//Nave *enemigo;
Objeto**enemigoArreglo;
Objeto *menu;
Objeto *texto;
Objeto *fondo;
Objeto * textonombre;
Objeto * texnoinicio;
Objeto * textosalir;
Objeto * textoalumno;
Objeto* tecxtoamarilloinicio;
Objeto * textoamarillosalir;
Objeto * fondojuego;

Objeto *textos;





	Estado estado;
	float  enemigoParabola;
	unsigned int frames;
	unsigned int tiempoFrameInicio;
	unsigned int tiempoFrameFinal;

};