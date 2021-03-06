#ifndef SPRITE_H_
#define SPRITE_H_
#include "CGame.h"
#include <SDL/SDL_rotozoom.h>
class CSprite {
public:
	CSprite(SDL_Surface* img, int posX = 0, int posY = 0);
	~CSprite();
	virtual void draw();
	int getX() {return posX;}
	int getY() {return posY;}
	int getW() {return width;}
	int getH() {return height;}
	void rotate( double angle );
	void scale( double scaleFactorX, double scaleFactorY );
protected:
	SDL_Surface* img;
	int posX, posY, width, height;
};
#endif /* SPRITE_H_ */