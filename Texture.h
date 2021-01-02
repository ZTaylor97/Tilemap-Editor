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
public:
	SDL_Renderer* renderer;

	int tileWidth, tileHeight;
	int tilesPerRow, tilesPerColumn;
	int numTiles;

	Texture(SDL_Renderer* renderer, SDL_Texture* texture, sol::table fileTable);
	void GetTextureDimensions(int *w, int *h);
	void Draw(int x, int y);

	SDL_Texture* GetTexture() const { return texture; }
};

