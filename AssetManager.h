#pragma once

#include <iostream>
#include <map>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include "Texture.h"

class AssetManager
{
private:
	std::map<std::string, Texture*> textures;
	SDL_Renderer* renderer;
public:
	AssetManager(SDL_Renderer * renderer); 

	Texture* GetTexture(std::string textureId);
	void LoadTexture(sol::table textureTable);
	void Draw();

	void ClearTextures();
};

