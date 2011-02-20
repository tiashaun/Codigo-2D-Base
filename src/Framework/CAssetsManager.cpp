#include "CAssetsManager.h"
#include <iostream>
using namespace std;

CAssetsManager* CAssetsManager::instance;

CAssetsManager& CAssetsManager::getInstance()
{
	if(!instance)
	{
		instance = new CAssetsManager();
		IMG_Init(IMG_INIT_PNG);
	}
	return *instance;
}

SDL_Surface* CAssetsManager::loadImage(const char* img)
{
	SDL_Surface* tmpImg = NULL;
	SDL_Surface* optimizedImg = NULL;
	tmpImg = IMG_Load(img);
	if(tmpImg != NULL)
	{
		optimizedImg = SDL_DisplayFormatAlpha(tmpImg);
	}
	SDL_FreeSurface(tmpImg);
	return(optimizedImg);
}

SDL_Surface* CAssetsManager::loadImage(const char* img, SDL_Rect area)
{
	SDL_Surface* image = NULL;
	SDL_Surface* blank = NULL;
	SDL_Surface* tmp = NULL;

	image = AssetsManager.loadImage(img);
	if ( image != NULL )
	{
		if( !(area.w + area.x > image->clip_rect.w
			|| area.h + area.y > image->clip_rect.h) )
		{
			tmp = SDL_CreateRGBSurface(Screen->flags, area.w, area.h,
					Screen->format->BitsPerPixel, Screen->format->Rmask, Screen->format->Gmask,
					Screen->format->Bmask, Screen->format->Amask);
			if( tmp != NULL )
			{
				if( SDL_BlitSurface(image, &area, tmp, NULL) != -1)
				{
					blank = SDL_DisplayFormatAlpha(tmp);
				}
			}
		}
	}
	SDL_FreeSurface(image);
	SDL_FreeSurface(tmp);
	return(blank);
}

SDL_Surface* CAssetsManager::loadImage(const char* img, SDL_Rect area, int borderX, int borderY, int intervalX, int intervalY)
{
	SDL_Surface* image = NULL;
	SDL_Surface* blank = NULL;
	SDL_Surface* tmp = NULL;
	SDL_Rect tmpRect = {area.x, area.y, intervalX, intervalY};
	SDL_Rect surfRect = {0, 0,intervalX, intervalY};
	image = AssetsManager.loadImage(img);
	if ( image != NULL )
	{
		if( !( area.w  + area.x > image->clip_rect.w
			|| area.h  + area.y > image->clip_rect.h) )
		{
			tmp = SDL_CreateRGBSurface(Screen->flags, area.w - (area.w % intervalX), area.h - (area.h % intervalY),
					Screen->format->BitsPerPixel, Screen->format->Rmask, Screen->format->Gmask,
					Screen->format->Bmask, Screen->format->Amask);
			if ( tmp != NULL)
			{
				while( tmpRect.y <= area.y + area.h - intervalY )
				{
					while( tmpRect.x <= area.x + area.w - intervalX )
					{
						SDL_BlitSurface ( image, &tmpRect, tmp, &surfRect );
						tmpRect.x += intervalX + borderX;
						surfRect.x +=intervalX;
					}
					tmpRect.y += intervalY + borderY;
					surfRect.y += intervalY;
					tmpRect.x = area.x;
					surfRect.x = 0;
				}
				blank = SDL_DisplayFormatAlpha(tmp);
			}
		}
	}
	SDL_FreeSurface(image);
	SDL_FreeSurface(tmp);
	return(blank);
}

SDL_Surface* CAssetsManager::loadWindowIcon(const char* img)
{
	SDL_Surface* tmp = NULL;
	tmp = SDL_LoadBMP(img);
	if(tmp != NULL)
	{
		SDL_SetColorKey(tmp, SDL_SRCCOLORKEY, SDL_MapRGB(tmp->format,255, 0, 255));
	}
	return(tmp);
}

CAssetsManager::CAssetsManager()
{

}
