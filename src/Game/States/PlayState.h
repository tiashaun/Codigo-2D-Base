#ifndef PLAYSTATE_H_
#define PLAYSTATE_H_
#include <SDL/SDL.h>
#include "../../Framework/CStatesManager.h"
#include "../../Framework/CAssetsManager.h"
#include "../../FrameWork/CGame.h"

class PlayState: public CGameState {
public:
	PlayState();
	void run();
	void handleEvents(SDL_Event event);
	void update(unsigned int dt);
	void draw();
	void init();
	void quit();
};

#endif /* PLAYSTATE_H_ */
