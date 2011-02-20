#include "CStatesManager.h"
#include <iostream>
using namespace std;
CStatesManager* CStatesManager::instance;
CStatesManager& CStatesManager::getInstance()
{
	if(!instance)
	{
		instance = new CStatesManager();
		instance->currState=NULL;
	}
	return *instance;
}

void CStatesManager::draw()
{
	if( this->currState != NULL )
	{
		this->currState->draw();
	}
}

void CStatesManager::update( Uint32 dt)
{
	if ( this->currState != NULL )
	{
		this->currState->update(dt);
	}
}

void CStatesManager::handleEvents(SDL_Event event)
{
	if ( this->currState != NULL )
	{
		this->currState->handleEvents(event);
	}
}

void CStatesManager::changeState(const char* stateName)
{
	CGameState* state = NULL;
	for(unsigned int i =0; i < instance->statesList.size(); i++ )
	{
		if( instance->statesList[i]->getName() == stateName )
		{
			state =  instance->statesList[i];
		}
	}
	if ( currState != NULL )
	{
		currState->quit();
	}

	if ( state != NULL )
	{
		currState = state;
		currState->init();
	}
}

void CStatesManager::addState(CGameState* state)
{
	for(unsigned int i =0; i < instance->statesList.size(); i++ )
	{
		if( instance->statesList[i]->getName() == state->getName() )
		{
			return;
		}
	}
	instance->statesList.push_back(state);
}

CStatesManager::CStatesManager()
{

}
