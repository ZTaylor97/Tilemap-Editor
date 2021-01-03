#pragma once
#include <iostream>
#include <SDL.h>
#include <vector>
#include <string>

#include "AssetManager.h"
#include "Tile.h"

#include "libs/lua/lua.hpp"
#include "libs/lua/sol.hpp"
class Application
{
private:
	bool isRunning;

	const int WindowWidth = 1920;
	const int WindowHeight = 1080;

	const int gridHeight = 960;

	const unsigned int FPS = 60;
	const float FRAME_TIME = 1000.0f / (float)FPS;

	int mouseX, mouseY;
	int currentTileX = 0;
	int currentTileY = 0;

	std::string activeTexture;

	AssetManager *assetManager;
	std::vector<Tile*> tiles;
public:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

	inline bool IsRunning() const { return isRunning; }

	void PlaceTile();
	void Initialise();
	void ProcessInput();
	void Update();
	void Render();
	void ParseInputFile(const char* filePath);
	void Close();
	void DrawGrid();
};

