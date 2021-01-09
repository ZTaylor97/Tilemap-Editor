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

	os	<< "\n\ttilesource = {\n"
		<< "\t\tx = " << tile.tileSource.x/ tile.tileSource.w << ",\n"
		<< "\t\ty = " << tile.tileSource.y/ tile.tileSource.h << ",\n"
		<< "\t\tw = " << tile.tileSource.w << ",\n"
		<< "\t\th = " << tile.tileSource.h << "\n\t},\n"
		<< "\ttiledest = {\n"
		<< "\t\tx = " << tile.tileCoord.x / tile.tileCoord.w << ",\n"
		<< "\t\ty = " << tile.tileCoord.y / tile.tileCoord.h << ",\n"
		<< "\t\tw = " << tile.tileCoord.w << ",\n"
		<< "\t\th = " << tile.tileCoord.h << "\n\t}\n";

	return os;
}
