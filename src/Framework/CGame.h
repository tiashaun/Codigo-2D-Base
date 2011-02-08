#ifndef CGAME_H_
#define CGAME_H_
#include <SDL/SDL.h>
#include "CStatesManager.h"
#define Game CGame::getInstance()
#define Screen Game.getScreen()

class CGame {

public:
	//void setRunning(int running);
	void run();
	static void init(int resX, int resY, int bpp, unsigned int videoFlags, unsigned int initFlags);
	void quit();
	static CGame& getInstance();
	SDL_Surface* getScreen();

private:
	int running;
	SDL_Surface* screen;
	static CGame* instance;
	CGame(int resX, int resY, int bpp, unsigned int videoFlags, unsigned int initFlags);
};



#endif /* CGAME_H_ */
