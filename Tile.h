#pragma once
#include "Texture.h"

#include <SDL.h>
class Tile
{
private:
	Texture* sourceTexture;
	SDL_Rect tileSource;
	SDL_Rect tileCoord;
public:
	Tile(Texture* sourceTexture, SDL_Rect tileSource, SDL_Rect tileCoord);

	void Draw();
};

