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
	assetManager->LoadTexture("./Tilesets/jungle.png", "test");

	SDL_GetMouseState(&mouseX, &mouseY);

	SDL_Rect sourceRect = {
		0, 0, 32,32
	};

	SDL_Rect destRect = {
	mouseX, mouseY, 32,32
	};

	Tile* newTile = new Tile(assetManager->GetTexture("test"), sourceRect, destRect);

	tiles.push_back(newTile);

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
		default: {
			break;
		}
	}
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

	SDL_RenderPresent(renderer);
}