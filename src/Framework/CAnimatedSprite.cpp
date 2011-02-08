#include "CAnimatedSprite.h"

CAnimatedSprite::CAnimatedSprite(const char* img, int frameX, int frameY, float fps)
{
	this->fps = fps;
	this->currFrame = 0;
	this->image = AssetsManager.loadImage(img);
	if( this->image != NULL )
	{
		this->framesCount = ((this->image->clip_rect.w / frameX) * (this->image->clip_rect.h / frameY));
		this->clips = new SDL_Rect[framesCount];
		for(int i = 0, x = 0, y = 0; i < this->framesCount; i++ )
		{

			if( x == this->image->clip_rect.w )
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
	SDL_BlitSurface( this->image, &this->clips[this->currFrame], Screen, NULL);
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
	SDL_FreeSurface(this->image);
}
