#ifndef SPRITE_H_
#define SPRITE_H_
#include "CGame.h"
class CSprite {
public:
	CSprite(SDL_Surface* img, int posX = 0, int posY = 0);
	~CSprite();
	virtual void draw();
	virtual void update(Uint32 dt) = 0;

protected:
	SDL_Surface* img;
	SDL_Rect pos;

};
#endif /* SPRITE_H_ */
