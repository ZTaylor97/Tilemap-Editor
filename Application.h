#pragma once
#include <iostream>
#include <SDL.h>
#include <vector>

#include "AssetManager.h"
#include "Tile.h"
class Application
{
private:
	bool isRunning;

	const unsigned int FPS = 60;
	const float FRAME_TIME = 1000.0f / (float)FPS;

	int mouseX, mouseY;

	AssetManager *assetManager;
	std::vector<Tile*> tiles;
public:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

	inline bool IsRunning() const { return isRunning; }

	void Initialise();
	void ProcessInput();
	void Update();
	void Render();
};

