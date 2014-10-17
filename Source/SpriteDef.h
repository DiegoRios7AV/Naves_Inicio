#include <SDL.h>

#ifndef __SPRITEDEF_H__
#define __SPRITEDEF_H__

class SpriteDef{
	struct Modulo{
		int id;
		int x;
		int y;
		int w;
		int h;
	};

public:
	Modulo modulos [5];
	SpriteDef(); //constructor
};


#endif

