#include "CAnimatedSprite.h"

CAnimatedSprite::CAnimatedSprite(SDL_Surface* img, int frameX, int frameY, float fps)
: CSprite::CSprite(img)
{
	this->fps = fps;
	this->currFrame = 0;
	this->img = img;
	if( this->img != NULL )
	{
		this->framesCount = ((this->img->clip_rect.w / frameX) * (this->img->clip_rect.h / frameY));
		this->clips = new SDL_Rect[framesCount];
		for(int i = 0, x = 0, y = 0; i < this->framesCount; i++ )
		{

			if( x == this->img->clip_rect.w )
			{
				x=0;
				y++;
			}
			this->clips[i].x = x;
			this->clips[i].y = y*frameY;
			this->clips[i].w = frameX;
			this->clips[i].h = frameY;
			x+=frameX;
		}
	}
}

void CAnimatedSprite::draw()
{
	SDL_BlitSurface( this->img, &this->clips[this->currFrame], Screen, &this->pos);
}

void CAnimatedSprite::update( Uint32 dt )
{
	if ( this->elapsedTime > (1/this->fps) * 1000 )
	{
		if(!(this->currFrame == framesCount))
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
