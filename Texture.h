#pragma once

#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
class Texture
{
private:
	SDL_Rect sourceRect;
	SDL_Texture* texture;
public:
	SDL_Renderer* renderer;
	Texture(SDL_Renderer* renderer, SDL_Texture* texture);
	void GetTextureDimensions(int *w, int *h);
	void Draw(int x, int y);

	SDL_Texture* GetTexture() const { return texture; }
};

