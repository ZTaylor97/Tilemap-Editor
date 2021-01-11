#pragma once
#include "Texture.h"

#include <SDL.h>
class Tile
{
private:
	Texture* sourceTexture;
	SDL_Rect tileSource;
	SDL_Rect tileCoord;
	SDL_Rect relativePos; // Position for use when map is moved
public:
	Tile(Texture* sourceTexture, SDL_Rect tileSource, SDL_Rect tileCoord);

	void Draw(const SDL_Rect camera);
	SDL_Rect GetTileCoord() { return tileCoord; }

	friend std::ostream& operator<<(std::ostream& os, const Tile& tile);
};

