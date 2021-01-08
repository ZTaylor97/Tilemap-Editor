#pragma once

#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "libs/lua/lua.hpp"
#include "libs/lua/sol.hpp"
class Texture
{
private:
	SDL_Texture* texture;
	int drawLocation[2] = {100,984};

public:
	SDL_Renderer* renderer;

	int tileWidth, tileHeight;
	int tilesPerRow, tilesPerColumn;
	int numTiles;

	void setDrawLocation(int x, int y) { drawLocation[0] = x; drawLocation[1] = y;}

	Texture(SDL_Renderer* renderer, SDL_Texture* texture, sol::table fileTable);
	void GetTextureDimensions(int *w, int *h);
	void Draw();

	SDL_Rect GetDrawLocation() { return { drawLocation[0], drawLocation[1], tilesPerRow * tileWidth, tilesPerColumn * tileHeight }; }

	SDL_Texture* GetTexture() const { return texture; }
};

