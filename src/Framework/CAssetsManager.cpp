#include "CAssetsManager.h"
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
			tmp = SDL_CreateRGBSurface(Screen->flags, area.w - area.x, area.h - area.y,
					Screen->format->BitsPerPixel, Screen->format->Rmask, Screen->format->Gmask,
					Screen->format->Bmask, Screen->format->Amask);
			if( tmp != NULL )
			{
				if( SDL_BlitSurface(image, &area, tmp, NULL) != -1)
				{
					blank = SDL_DisplayFormat(tmp);
				}
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

void CAssetsManager::loadAnimation(const char* img, int frameX, int frameY)
{
}

CAssetsManager::CAssetsManager()
{

}
