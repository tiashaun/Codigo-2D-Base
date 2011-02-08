#include "CSprite.h"

CSprite::CSprite(SDL_Surface* img, int posX, int posY)
{
	this->img = img;
	this->pos.x = posX;
	this->pos.y = posY;
}

CSprite::~CSprite()
{
	SDL_FreeSurface(this->img);
}

void CSprite::draw()
{
	SDL_BlitSurface(this->img, NULL, Screen, &Screen->clip_rect);
}
