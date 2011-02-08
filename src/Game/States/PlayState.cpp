#include "PlayState.h"
PlayState::PlayState()
{
	this->name = "play state";
	StatesManager.addState(this);
}

void PlayState::draw()
{

}

void PlayState::update(unsigned int dt)
{

}

void PlayState::handleEvents(SDL_Event event)
{

}

void PlayState::quit()
{

}

void PlayState::init()
{

}
