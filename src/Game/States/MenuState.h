#ifndef MENUSTATE_H_
#define MENUSTATE_H_
#include <SDL/SDL.h>
#include "../../Framework/CStatesManager.h"
#include "../../Framework/CAssetsManager.h"
#include "../../Framework/CGame.h"
#include "../../Framework/CAnimatedSprite.h"

class MenuState: public CGameState {
public:
	MenuState( );
	void draw( );
	void init( );
	void quit( );
	void handleEvents( SDL_Event event );
	void update( Uint32 );
private:
	SDL_Surface* mainMenu;
	SDL_Surface* cursor;
	SDL_Rect cursorPos;
	CAnimatedSprite* fuleira;
	int currOption;
	const static int OPT_START = 0, OPT_CREDITS = 1, OPT_INSTRUCTIONS = 2, OPT_QUIT = 3;
};

#endif /* MENUSTATE_H_ */
