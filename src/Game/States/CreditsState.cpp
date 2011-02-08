#include "CreditsState.h"

CreditsState::CreditsState()
{
	this->name = "credits state";
	StatesManager.addState(this);
}

void CreditsState::handleEvents(SDL_Event e)
{
	if ( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE )
	{
		StatesManager.changeState("menu state");
	}
}
void CreditsState::init()
{
	this->background = AssetsManager.loadImage("creditos.png");
}

void CreditsState::quit()
{
	SDL_FreeSurface(this->background);
}

void CreditsState::update(unsigned int dt)
{

}

void CreditsState::draw()
{
	SDL_FillRect(Screen, &Screen->clip_rect, SDL_MapRGB(Screen->format,111,111,111));
	SDL_BlitSurface(this->background, NULL, Screen, NULL);
	SDL_Flip(Screen);
}
