#include "Tile.h"

Tile::Tile(Texture* sourceTexture, SDL_Rect tileSource, SDL_Rect tileCoord)
	: sourceTexture(sourceTexture), tileSource(tileSource), tileCoord(tileCoord)
{
}

void Tile::Draw()
{
	SDL_RenderCopy(sourceTexture->renderer, sourceTexture->GetTexture(), &tileSource, &tileCoord);
}
