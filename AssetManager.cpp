#include "AssetManager.h"

AssetManager::AssetManager(SDL_Renderer* renderer)
	: renderer(renderer)
{
}

Texture* AssetManager::GetTexture(std::string textureId)
{
	return textures.at(textureId);
}

void AssetManager::LoadTexture(const char* filePath, std::string textureId)
{
	SDL_Surface* surface = IMG_Load(filePath);

	if (surface == NULL)
	{
		std::cerr << "Image loading failed" << std::endl;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	Texture* newTexture = new Texture(renderer, texture);
	
	textures.emplace(textureId, newTexture);
}

void AssetManager::Draw()
{
}
