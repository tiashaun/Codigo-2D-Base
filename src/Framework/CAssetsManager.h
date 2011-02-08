#ifndef CASSETSMANAGER_H_
#define CASSETSMANAGER_H_
#define AssetsManager CAssetsManager::getInstance()
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "CGame.h"

class CAssetsManager {

private:
	CAssetsManager();
	static CAssetsManager* instance;
public:
	static CAssetsManager& getInstance();
	SDL_Surface* loadImage(const char *img);
	SDL_Surface* loadWindowIcon(const char *img);
	SDL_Surface* loadImage(const char* img, SDL_Rect area);
	void loadAnimation(const char* img, int frameX, int frameY);
};

#endif /* CASSETSMANAGER_H_ */
