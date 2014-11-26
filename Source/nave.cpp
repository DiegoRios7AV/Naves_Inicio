#include "Nave.h"
#include "Config.h"

void Nave::Pintar(){
	nave ->Pintar ();
}

Nave::Nave(SDL_Surface* screen, char *rutaImagen,int x, int y, int module){
	nave= new Objeto(screen, rutaImagen, x, y, module);
	bala = new Objeto(screen,"../Data/balas.bmp",0,0,MODULO_BALAS_BALA1);
	bala->setVisible(false);
	
}

void Nave::MoverAbajo(){
	nave->Moverab(8);
}

void Nave::MoverArriba(){
		nave->Movera(8);
}

void Nave::MoverDerecha(){
	nave->Mover(8);
}

void Nave::MoverIzquierda(){
	nave->Moverl(8);
}

Objeto* Nave::GetNaveObjeto(){
	return nave;
}

void Nave::Disparar(){
	bala->setVisible(true);
	bala->ponerEn(nave->obtenerX()+((nave->obtenerW()/2)-1.2),nave->obtenerY());
};

void Nave::Actualizar(){
	bala->Pintar();
	bala->Movera(8);
};