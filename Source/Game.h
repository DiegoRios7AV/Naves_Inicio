#include <SDL.h>
#include "nave.h"

class CGame
{
public:
	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();

	enum Estado{
		estado_Iniciando,
		estado_Menu,
		estado_Jugando,
		estado_Terminado,
		estado_Finalizado
	};

private:
	void Iniciando();

	Uint8 *keys; //Esta variable nos servira para ver si determinadas teclas de nuestro keyboard estan precionadas
	SDL_Event event; //la variable event de tipo evento de SDL nos servira para manejar los eventos de nuestro programa.
	SDL_Surface *screen;
	Nave *nave;
	Estado estado;
};