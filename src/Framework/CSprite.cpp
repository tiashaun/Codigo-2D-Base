#include "CSprite.h"

CSprite::CSprite(SDL_Surface* img, int posX, int posY)
{
	this->img = img;
	this->posX = posX;
	this->posY = posY;
	this->width = this->img->clip_rect.w;
	this->height = this->img->clip_rect.h;
}

CSprite::~CSprite()
{
	SDL_FreeSurface(this->img);
}

void CSprite::draw()
{
	SDL_BlitSurface(this->img, NULL, Screen, &Screen->clip_rect);
}
