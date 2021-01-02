#include "Application.h"

void Application::Initialise()
{
	// Initialise SDL window with video component activated, check for erros in initialisation
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "Error initialising SDL" << std::endl;
		return;
	}
	window = SDL_CreateWindow(
		NULL,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1920,
		1080,
		SDL_WINDOW_RESIZABLE
	);
	if (!window)
	{
		std::cerr << "Error creating SDL window." << std::endl;
		return;
	}
	// Error check the creation of the SDL renderer
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) 
	{
		std::cerr << "Error creating SDL renderer." << std::endl;
		return;
	}

	// Create a new asset manager
	assetManager = new AssetManager(renderer);

	ParseInputFile("./config.lua");
	activeTexture = "test";

	isRunning = true;
}

void Application::ProcessInput()
{
	SDL_PollEvent(&event);
	switch (event.type) 
	{
		case SDL_QUIT: 
		{
			isRunning = false;
			break;
		}
		case SDL_KEYDOWN: 
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				isRunning = false;
			}
			break;
		}
		case SDL_MOUSEBUTTONDOWN:
		{
			if (event.button.button == (SDL_BUTTON_LEFT))
			{
				SDL_GetMouseState(&mouseX, &mouseY);
				PlaceTile();
				
			}
			break;
		}
		case SDL_MOUSEWHEEL:
		{
			if (event.wheel.y > 0)
			{
				// Scroll to the right if there is room to scroll
				if (currentTileX <= assetManager->GetTexture(activeTexture)->tilesPerRow && 
					currentTileY < assetManager->GetTexture(activeTexture)->tilesPerColumn)
				{
					currentTileX++;
				}

				// Go down a row if scrolling past the rightmost tile
				if (currentTileX >= assetManager->GetTexture(activeTexture)->tilesPerRow && 
					currentTileY < assetManager->GetTexture(activeTexture)->tilesPerColumn)
				{
					currentTileX = 0;
					currentTileY++;
				}
				if (currentTileY >= assetManager->GetTexture(activeTexture)->tilesPerColumn)
				{
					currentTileX = assetManager->GetTexture(activeTexture)->tilesPerRow - 1;
					currentTileY--;
				}
	
			}
			if (event.wheel.y < 0)
			{
				// Scroll to the left if there is still room to move
				currentTileX--;
				// Go up a row if scrolling past leftmost tile
				if (currentTileX < 0 && currentTileY > 0)
				{
					currentTileX = assetManager->GetTexture(activeTexture)->tilesPerRow - 1;
					currentTileY--;
				}

				if (currentTileX < 0) currentTileX = 0;
			}
			// Reset wheel to 0 after every scroll
			event.wheel.y = 0;

			std::cout << currentTileX << " " << currentTileY << std::endl;
			break;
		}
		default: {
			break;
		}
	}
}

void Application::PlaceTile()
{
	Texture* currentTexture = assetManager->GetTexture(activeTexture);

	SDL_Rect sourceRect = {
		currentTileX*currentTexture->tileWidth, 
		currentTileY*currentTexture->tileHeight,
		currentTexture->tileWidth, 
		currentTexture->tileHeight
	};

	int xGrid = mouseX / currentTexture->tileWidth;
	int yGrid = mouseY / currentTexture->tileHeight;

	SDL_Rect destRect = {
		xGrid*currentTexture->tileWidth, 
		yGrid*currentTexture->tileHeight,
		currentTexture->tileHeight,
		currentTexture->tileHeight
	};

	Tile* newTile = new Tile(assetManager->GetTexture("test"), sourceRect, destRect);

	tiles.push_back(newTile);
}

void Application::Update()
{
	static int ticksLastFrame = 0;

	while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TIME));

	// Delta time is the difference in ticks from last frame converted to seconds
	float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

	// Clamp deltaTime to a maximum value
	deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

	// Sets the new ticks for the current frame to be used in the next pass
	ticksLastFrame = SDL_GetTicks();
}

void Application::Render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	assetManager->Draw();

	for (auto& tile : tiles)
	{
		tile->Draw();
	}

	assetManager->GetTexture("test")->Draw(0,800);

	SDL_RenderPresent(renderer);
}

void Application::ParseInputFile(const char* filePath)
{
	sol::state lua;
	lua.open_libraries(sol::lib::base, sol::lib::os, sol::lib::math);

	// Prepare to open the correct lua level file
	lua.script_file(filePath);

	sol::table texturelist = lua["textures"];

	size_t i = 0;

	// Check existence of sol table before using it in LoadTexture
	sol::optional<sol::table> existsTextureId = texturelist[i];
	while (1)
	{
		sol::optional<sol::table> existsTextureId = texturelist[i];
		if (existsTextureId == sol::nullopt)
		{
			break;
		}

		assetManager->LoadTexture(texturelist[i]);
		++i;
	}

}