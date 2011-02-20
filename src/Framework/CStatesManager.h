#ifndef CSTATESMANAGER_H_
#define CSTATESMANAGER_H_
#define StatesManager CStatesManager::getInstance()
#include <vector>
#include <string>
#include <SDL/SDL.h>
using namespace std;
class CGameState;

class CStatesManager {
private:
	CStatesManager();
	static CStatesManager* instance;
	CGameState* currState;
	vector<CGameState*> statesList;
public:
	static CStatesManager& getInstance();
	void changeState(const char* stateName);
	void addState(CGameState* state);
	void handleEvents(SDL_Event event);
	void update(Uint32 dt);
	void draw();
};

class CGameState {
public:
	virtual void init() = 0;
	virtual void quit() = 0;
	virtual void handleEvents(SDL_Event event) = 0;
	virtual void update(Uint32 dt) = 0;
	virtual void draw() = 0;
	std::string getName(){return this->name;};
protected:
	string name;
};
#endif /* CSTATESMANAGER_H_ */
