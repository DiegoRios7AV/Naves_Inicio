#include "nave.h"
#include "config.h"

Nave::Nave(SDL_Surface * screen, char * rutaImagen){
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	x=(WIDTH_SCREEN/2)-(sprite->widthModule(SPRITE_MODULE_MI_NAVE)/2);
	y=(HEIGHT_SCREEN-80-(sprite->heightModule(SPRITE_MODULE_MI_NAVE)));
};

Nave::~Nave(){
	delete sprite;
};

void Nave::Pintar(){
	sprite->PintarModulo(SPRITE_MODULE_MI_NAVE,x,y);
};

void Nave::moverR(int posicion){
	x += posicion;
};

void Nave::moverL(int posicion){
	x -= posicion;

};