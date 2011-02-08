#ifndef CREDITSSTATE_H_
#define CREDITSSTATE_H_
#include <SDL/SDL.h>
#include "../../Framework/CStatesManager.h"
#include "../../Framework/CAssetsManager.h"
#include "../../FrameWork/CGame.h"

class CreditsState: public CGameState {
public:
	CreditsState();
	void draw();
	void init();
	void quit();
	void handleEvents(SDL_Event event);
	void update(unsigned int dt);
private:
	SDL_Surface* background;
};

#endif /* CREDITSSTATE_H_ */
