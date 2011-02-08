#include "InstructionsState.h"

InstructionsState::InstructionsState()
{
	this->name = "instructions state";
	StatesManager.addState(this);
}
void InstructionsState::draw()
{
	SDL_FillRect(Screen, &Screen->clip_rect, SDL_MapRGB(Screen->format,111,111,111));
	SDL_BlitSurface(this->background, NULL, Screen, NULL);
	SDL_Flip(Screen);
}

void InstructionsState::init()
{
	this->background = AssetsManager.loadImage("instrucao.png");
}

void InstructionsState::update(unsigned int dt)
{

}

void InstructionsState::handleEvents(SDL_Event event)
{
	if(event.type==SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
	{
		StatesManager.changeState("menu state");
	}
}

void InstructionsState::quit()
{
	SDL_FreeSurface(this->background);
}
