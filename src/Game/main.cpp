#include "../Framework/CGame.h"
#include "../Framework/CStatesManager.h"
#include "States/MenuState.h"
#include "States/InstructionsState.h"
#include "States/CreditsState.h"
#include "States/PlayState.h"
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char* argv[])
{
	Game.init(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF, SDL_INIT_VIDEO);
	MenuState* menu = new MenuState();
	InstructionsState* ins = new InstructionsState();
	CreditsState* cre = new CreditsState();
	PlayState* pla  = new PlayState();
	StatesManager.changeState("menu state");
	Game.run();
	delete &Game;
	delete menu;
	delete ins;
	delete cre;
	delete pla;
	cout << "Limpei tudo, rs!";
	return 0;
}
