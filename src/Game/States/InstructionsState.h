#ifndef INSTRUCTIONSSTATE_H_
#define INSTRUCTIONSSTATE_H_
#include <SDL/SDL.h>
#include "../../Framework/CStatesManager.h"
#include "../../Framework/CAssetsManager.h"
#include "../../FrameWork/CGame.h"

class InstructionsState: public CGameState {
public:
	InstructionsState();
	void draw();
	void init();
	void quit();
	void handleEvents(SDL_Event event);
	void update(unsigned int dt);
private:
	SDL_Surface* background;
};

#endif /* INSTRUCTIONSSTATE_H_ */
