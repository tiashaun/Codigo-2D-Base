#ifndef CANIMATEDSPRITE_H_
#define CANIMATEDSPRITE_H_
#include "CAssetsManager.h"
#include "CSprite.h"
#include <string>
using namespace std;

class CAnimatedSprite: public CSprite
{
public:
	CAnimatedSprite(SDL_Surface* img, int frameX, int frameY, float fps);
	~CAnimatedSprite();
	void draw();
	void update( Uint32 dt);
private:
	SDL_Rect* clips;
	int framesCount;
	int currFrame;
	int elapsedTime;
	float fps;
};

#endif /* CANIMATEDSPRITE_H_ */
