#include "CGame.h"
CGame* CGame::instance;
#include <iostream>
using namespace std;
CGame& CGame::getInstance()
{
	return *instance;
}

CGame::CGame(int resX, int resY, int bpp, unsigned int videoFlags, unsigned int initFlags)
{
	SDL_Init(initFlags);
	this->screen = SDL_SetVideoMode(resX, resY, bpp, videoFlags);
}

void CGame::run()
{
	SDL_Event e;
	instance->running = 1;
	Uint32 dt = 0;
	Uint32 startTime = 0;
	while(instance->running)
	{
		startTime = SDL_GetTicks();
		while(SDL_PollEvent(&e))
		{
			StatesManager.handleEvents(e);
		}
		StatesManager.update(dt);
		StatesManager.draw();
		dt = SDL_GetTicks() - startTime;

	}
	SDL_Quit();
}

void CGame::init(int resX, int resY, int bpp, unsigned int videoFlags, unsigned int initFlags)
{
	if(!instance)
	{
		instance = new CGame(resX, resY, bpp, videoFlags, initFlags);
	}
}

SDL_Surface* CGame::getScreen()
{
	return(instance->screen);
}

void CGame::quit()
{
	instance->running = 0;
}
