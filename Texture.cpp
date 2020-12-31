#include "Texture.h"

Texture::Texture(SDL_Renderer *renderer, SDL_Texture* texture)
	:renderer(renderer), texture(texture)
{
	sourceRect =
	{
		0,0,32,32
	};
}

void Texture::GetTextureDimensions(int* w, int* h)
{
	if (SDL_QueryTexture(texture, NULL, NULL, w, h) != 0)
	{
		std::cerr << "Could not retrieve texture information" << std::endl;
	}
}

void Texture::Draw(int x, int y)
{

	SDL_Rect destination;
	destination.x = x; destination.y = y;
	destination.w = 32*10; destination.h = 32*3;

	if (SDL_RenderCopy(renderer, texture, NULL, &destination) == -1)
	{
		std::cout << "Texture drawing failed." << std::endl;
	}
}
