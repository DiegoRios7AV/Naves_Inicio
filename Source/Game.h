#include <SDL.h>

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
	SDL_Surface *screen;
	Estado estado;
};