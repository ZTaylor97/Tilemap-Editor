#include "Tile.h"

Tile::Tile(Texture* sourceTexture, SDL_Rect tileSource, SDL_Rect tileCoord)
	: sourceTexture(sourceTexture), tileSource(tileSource), tileCoord(tileCoord)
{
}

void Tile::Draw()
{
	SDL_RenderCopy(sourceTexture->renderer, sourceTexture->GetTexture(), &tileSource, &tileCoord);
}

std::ostream& operator<<(std::ostream& os, const Tile& tile)
{
	/* Format of output should be:
	* tileSource = {
		SourceX, SourceY, SourceW, SourceH
	},
	  tileDest = {
	  DestX, DestY, DestW, DestH
	 }
	*/


	os << "tilesource = {\n"
		<< "x" << tile.tileSource.x << ","
		<< "y" << tile.tileSource.y << ","
		<< "w" << tile.tileSource.w << ","
		<< "h" << tile.tileSource.h << "},\n"
		<< "tiledest = {\n"
		<< "x" << tile.tileCoord.x << ","
		<< "y" << tile.tileCoord.y << ","
		<< "w" << tile.tileCoord.w << ","
		<< "h" << tile.tileCoord.h << "}/n";
}
