#ifndef SPRITE_H_
#define SPRITE_H_
#include "CGame.h"
class Sprite {
public:
	Sprite();
	~Sprite();
	virtual void draw();
	virtual void update(Uint32 dt) = 0;

private:
	SDL_Surface* img;
	SDL_Rect pos;

};
#endif /* SPRITE_H_ */
