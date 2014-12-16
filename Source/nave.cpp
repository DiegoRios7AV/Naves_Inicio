#include "Nave.h"
#include "Config.h"
#include "Game.h"

void Nave::Pintar(){
	if (visible)
	nave->Pintar();
}
Nave::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module){
     nave=new Objeto(screen,rutaImagen,x,y,module);

	 bala= new Objeto *[MAXIMO_BALAS];
	 for (int i=0;i<MAXIMO_BALAS;i++){
	 bala[i]=new Objeto(screen, "../Data/bala.bmp",0,0,MODULO_BALAS_BALA1);
	 bala[i]->SetVisible(false);
	 }
	 balasVisibles=0;
	 visible=true;
	 //simulacion colisiones**************variable
	colisionConBalas =false;
	 ///
}

void Nave::Mover(int valor){ //este es mover derecha
	nave->Mover(valor);
}
void Nave::MoverIzquierda(int valor){
	nave->MoverIzquierda(valor);
}
void Nave::MoverArriba(int valor){
	nave->MoverArriba(valor);
}
void Nave::MoverAbajo(int valor){
	nave->MoverAbajo(valor);
}

Objeto * Nave::GetNaveObjeto(){
return nave;
}

void Nave::Disparar(int tipo, int valor){
	
bala[balasVisibles]->SetVisible(true);
switch (tipo){
case NAVE_PROPIA:
	bala[balasVisibles]->ponerEn(nave->obtenerX()+nave->obtenerW()/2,nave->obtenerY());
	break;
case NAVE_ENEMIGO:
	bala[balasVisibles]->ponerEn(nave->obtenerX()+nave->obtenerW()/2,nave->obtenerY()+nave->obtenerH());
	break;
}

balasVisibles++;
if(balasVisibles>=valor)	//MAXIMO_BALAS por nivel
	balasVisibles=0;
}

void Nave::Actualizar(int tipo, int valor){
	if(visible)
	for (int i=0;i<MAXIMO_BALAS;i++){	
		bala[i]->Pintar();
		switch (tipo){
		case NAVE_PROPIA:
			bala[i]->MoverArriba(valor);//bala mover arriba
			break;
		case NAVE_ENEMIGO:
			bala[i]->MoverAbajo(valor);//balamover abajo
			break;
		}
	}
}
void Nave::AutoDisparar(int efectividad, int valor){
	if( rand() %100<efectividad)
	Disparar(NAVE_ENEMIGO, valor);
}

bool Nave::estaColisionandoConBalas(Objeto *nave){
		for (int i=0;i<MAXIMO_BALAS;i++)
			{
					if(isPointInRect(bala[i]->obtenerX(),bala[i]->obtenerY(),nave) == true ||
			isPointInRect(bala[i]->obtenerX()+bala[i]->obtenerW(),bala[i]->obtenerY(),nave) == true ||
			isPointInRect(bala[i]->obtenerX(),bala[i]->obtenerY()+bala[i]->obtenerH(),nave) == true ||
			isPointInRect(bala[i]->obtenerX()+bala[i]->obtenerW(),bala[i]->obtenerY()+bala[i]->obtenerH(),nave) == true)
			{
				return true;
			} else 
				return false;
		}
}

bool Nave::isPointInRect(int x, int y, Objeto*enemigo)
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

void Nave::setVisible(bool visible){
	this->visible=visible;
}
//metodo
void Nave::ColisionarConBala(bool colision){
	//variable
colisionConBalas=colision;
}
