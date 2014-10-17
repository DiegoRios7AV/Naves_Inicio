#include "sprite.h"
#include "SDL.h"

#ifndef __NAVE_H__
#define __NAVE_H__
#endif

class Nave{
	int x;
	int y;
	Sprite *sprite;
public:
	Nave(SDL_Surface * screen,char * rutaImagen);
	~Nave();
	void Pintar();
	void moverR(int posicion);
	void moverL(int posicion);

};