#include "MenuState.h"
#include <iostream>
using namespace std;
MenuState::MenuState()
{
	this->name = "menu state";
	StatesManager.addState(this);
}

void MenuState::draw()
{
	SDL_FillRect(Screen, NULL, SDL_MapRGB(Screen->format, 111, 111, 111));
	SDL_BlitSurface(this->mainMenu, &this->mainMenu->clip_rect, Screen, NULL);
	SDL_BlitSurface(this->cursor, &this->cursor->clip_rect, Screen, &this->cursorPos);
	this->fuleira->draw();
	SDL_Flip(Screen);
}

void MenuState::update( Uint32 dt)
{
	this->fuleira->update( dt );
	switch(currOption)
	{
		case(OPT_START):
			this->cursorPos.y = 340;
			break;
		case(OPT_CREDITS):
			this->cursorPos.y = 410;
			break;
		case(OPT_INSTRUCTIONS):
			this->cursorPos.y = 480;
			break;
		case(OPT_QUIT):
			this->cursorPos.y = 550;
			break;
	}
}

void MenuState::handleEvents(SDL_Event event)
{
	switch(event.type)
	{
		case(SDL_QUIT):
			Game.quit();
			break;
		case(SDL_KEYDOWN):
			if(event.key.keysym.sym == SDLK_ESCAPE)
			{
				Game.quit();
			}
			if(event.key.keysym.sym == SDLK_DOWN)
			{
				if(this->currOption<3)
					this->currOption++;
			}
			else if(event.key.keysym.sym == SDLK_UP)
			{
				if(this->currOption>0)
					this->currOption--;
			}
			else if(event.key.keysym.sym == SDLK_RETURN)
			{
				switch(this->currOption)
				{
				case(OPT_START):
					StatesManager.changeState("play state");
					break;
				case(OPT_CREDITS):
					StatesManager.changeState("credits state");
					break;
				case(OPT_INSTRUCTIONS):
					StatesManager.changeState("instructions state");
					break;
				case(OPT_QUIT):
					Game.quit();
					break;
				}
			}
			break;
	}
}

void MenuState::init()
{
	this->mainMenu = AssetsManager.loadImage("menu.png");
	this->cursor = AssetsManager.loadImage("seta.png");
	this->fuleira = new CAnimatedSprite(AssetsManager.loadImage("teste.png"), 20, 20, 24);
	this->currOption = 0;
	this->cursorPos.x = 480;
}

void MenuState::quit()
{
	SDL_FreeSurface(this->mainMenu);
	SDL_FreeSurface(this->cursor);
	delete this->fuleira;
}