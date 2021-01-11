#include "Texture.h"

Texture::Texture(SDL_Renderer *renderer, SDL_Texture* texture, sol::table fileTable)
	:renderer(renderer), texture(texture)
{
	tileWidth = fileTable["tiledimensions"]["x"];
	tileHeight = fileTable["tiledimensions"]["y"];
	numTiles = fileTable["totaltiles"];
	tilesPerRow = fileTable["filedimensions"]["xtiles"];
	tilesPerColumn = fileTable["filedimensions"]["ytiles"];
}

void Texture::GetTextureDimensions(int* w, int* h)
{
	if (SDL_QueryTexture(texture, NULL, NULL, w, h) != 0)
	{
		std::cerr << "Could not retrieve texture information" << std::endl;
	}
}

void Texture::Draw(int scale)
{
	this->scale = scale; // Set scale so that the application knows about it
	SDL_Rect destination;
	destination.x = drawLocation[0]; destination.y = drawLocation[1];
	destination.w = tileWidth*tilesPerRow*scale; destination.h = tileHeight*tilesPerColumn*scale;

	if (SDL_RenderCopy(renderer, texture, NULL, &destination) == -1)
	{
		std::cout << "Texture drawing failed." << std::endl;
	}
}
