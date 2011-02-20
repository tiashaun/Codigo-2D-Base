#include "Framework\CGame.h"
#include "Carrinho\CPlayState.h"
#include "Framework\CStatesManager.h"

int main(int argc, char* argv[])
{
	Game.init(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF, SDL_INIT_VIDEO | SDL_INIT_TIMER);
	CPlayState* ps = new CPlayState();
	StatesManager.changeState("play_state");
	Game.run();
	return 0;
}