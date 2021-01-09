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
	SDL_Rect GetTileCoord() { return tileCoord; }

	friend std::ostream& operator<<(std::ostream& os, const Tile& tile);
};

