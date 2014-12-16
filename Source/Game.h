
#include <SDL.h>
#include <SDL_image.h>
#include "Objeto.h"
#include "Nave.h"
#include "Stage.h"

class CGame 
{
public:
	bool Start();
	static CGame instanceGame;

	CGame();
	bool isPointInRect(int x, int y,Objeto*enemigo);
	bool checkCollision(Objeto*objeto, Objeto*enemigo);
	void Finalize();  //ACT2: Mal, Aqui dejaste un error, tu codigo debe ser compilable correctamente.
	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_PRE_JUGANDO,
		ESTADO_JUGANDO,
		ESTADO_TERMINADO,
		ESTADO_FINALIZADO,
		};

private:
	//crearmetodos
	void InicianilizandoStage();
	void Iniciando();
	void MoverEnemigo();
	bool esLimitePantalla(Objeto *objeto, int bandera);
	bool estaSeleccionado;


	//crear variables
	int nivelActual;
	int enemigosEliminados;
	int vidas;
	//
	//unsigned int x;

	Uint8 *keys;//esta variable para ver si determinadas teclas esta
	SDL_Event event;//la variable event de tipo evento de sdl nosservira para

	SDL_Surface *screen;
	Nave *nave;
	//Nave *enemigo;
	Nave **enemigoArreglo;
	//arreglo de 4 elementos estilo stage+
	Stage niveles[4];
	//arreglo de 4 elementos estilo stage-
	//5+
	Objeto *menu;
	Objeto *textos;
	Objeto *fondo;
	Objeto * fondojuego;
	//5-
//6+
	Objeto *btnInicio;
	Objeto *btnSalir;
	//6-

	Estado estado;
	

	float enemigoParabola;
	unsigned int frames;
	unsigned int tiempoFrameInicio;
	unsigned int tiempoFrameFinal;

};