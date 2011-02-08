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
	switch ( event.type )
	{
	case ( SDL_QUIT ):
		Game.quit();
		break;
	case ( SDL_KEYDOWN ):
		switch( event.key.keysym.sym )
		{
		case ( SDLK_ESCAPE ):
			StatesManager.changeState("menu state");
			break;
		}
		break;
	}
}

void PlayState::quit()
{

}

void PlayState::init()
{

}
