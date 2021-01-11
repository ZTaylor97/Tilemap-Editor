#include "Tile.h"

Tile::Tile(Texture* sourceTexture, SDL_Rect tileSource, SDL_Rect tileCoord)
	: sourceTexture(sourceTexture), tileSource(tileSource), tileCoord(tileCoord), relativePos(tileCoord)
{
}

void Tile::Draw(const SDL_Rect camera)
{

    if (relativePos.x + relativePos.w > camera.x + camera.w)
    {
        relativePos.x = camera.x + camera.w - relativePos.w;
    }

    if (relativePos.y + relativePos.h > camera.y + camera.h)
    {
        relativePos.y = camera.y + camera.h - relativePos.h;
    }

    if (relativePos.x < camera.x)
    {
        relativePos.x = camera.x;
    }

    if (relativePos.y < camera.y)
    {
        relativePos.y = camera.y;
    }

	SDL_RenderCopy(sourceTexture->renderer, sourceTexture->GetTexture(), &tileSource, &relativePos);
}

std::ostream& operator<<(std::ostream& os, const Tile& tile)
{

	os	<< "\n\t\ttilesource = {\n"
		<< "\t\t\tx = " << tile.tileSource.x/ tile.tileSource.w << ",\n"
		<< "\t\t\ty = " << tile.tileSource.y/ tile.tileSource.h << "\n\t\t},\n"
		<< "\t\ttiledest = {\n"
		<< "\t\t\tx = " << tile.tileCoord.x / tile.tileCoord.w << ",\n"
		<< "\t\t\ty = " << tile.tileCoord.y / tile.tileCoord.h << "\n\t\t}\n";

	return os;
}
