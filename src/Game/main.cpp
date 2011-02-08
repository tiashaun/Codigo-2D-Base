#include "../Framework/CGame.h"
#include "../Framework/CStatesManager.h"
#include "States/MenuState.h"
#include "States/InstructionsState.h"
#include "States/CreditsState.h"
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char* argv[])
{
	Game.init(800, 600, 32, SDL_SWSURFACE, SDL_INIT_VIDEO);
	MenuState* menu = new MenuState();
	InstructionsState* ins = new InstructionsState();
	CreditsState* cre = new CreditsState();
	StatesManager.changeState("menu state");
	Game.run();
	delete &Game;
	delete menu;
	delete ins;
	delete cre;
	cout << "Limpei tudo, rs!";
	return 0;
}
