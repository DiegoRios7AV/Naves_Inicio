#ifndef _NAVE_H_
#define _NAVE_H_
#include "Objeto.h"
 
class Nave{
	Objeto *nave;
	Objeto **bala;
	int balasVisibles;
	bool visible;

public:
	Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module);
	//crear metodos
	void Pintar();
	void Disparar(int tipo, int valor);
	void AutoDisparar(int efectividad, int valor);//para que dispare el enemigo
	void Actualizar(int tipo, int valor);//le da vida a la bala
	void Mover(int valor);
	void MoverIzquierda(int valor);
	void MoverArriba(int valor);
	void MoverAbajo(int valor);
	void setVisible(bool visible);
	bool isPointInRect(int x, int y, Objeto*enemigo);
	//simular colision///
	void ColisionarConBala(bool colision);
    bool colisionConBalas;
		/////////////
	bool estaColisionandoConBalas(Objeto *nave);

	Objeto * GetNaveObjeto();
};
#endif