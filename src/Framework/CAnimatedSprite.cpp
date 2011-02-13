#include "CAnimatedSprite.h"
#include <iostream>
CAnimatedSprite::CAnimatedSprite(SDL_Surface* img, int frameW, int frameH, float fps)
: CSprite::CSprite(img, 0, 0)
{
	this->fps = fps;
	this->currFrame = 0;
	this->elapsedTime = 0;
	this->img = img;
	if( this->img != NULL )
	{
		this->framesCount = ((this->img->clip_rect.w / frameW) * (this->img->clip_rect.h / frameH));
		this->clips = new SDL_Rect[framesCount];
		for(int i = 0, x = 0, y = 0; i < this->framesCount; i++ )
		{

			if( x == this->img->clip_rect.w )
			{
				x=0;
				y++;
			}
			this->clips[i].x = x;
			this->clips[i].y = y*frameH;
			this->clips[i].w = frameW;
			this->clips[i].h = frameH;
			x+=frameW;
		}
	}
	this->height = frameH;
	this->width = frameW;
}

void CAnimatedSprite::draw()
{
	SDL_Rect pos = {this->posX, this->posY}; //Poor SDL D:
	SDL_BlitSurface( this->img, &this->clips[this->currFrame], Screen, &pos);
}

void CAnimatedSprite::update( Uint32 dt )
{
	if ( this->elapsedTime > (1/this->fps) * 1000 )
	{
		if(this->currFrame != framesCount)
		{
			this->currFrame++;
		}
		else
		{
			this->currFrame = 0;
		}
		this->elapsedTime = 0;
	}
	this->elapsedTime += dt;
}

CAnimatedSprite::~CAnimatedSprite()
{
	delete[] this->clips;
}