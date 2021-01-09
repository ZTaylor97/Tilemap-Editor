#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <map>

#include "Application.h"

int main(int argc, char* argv[])
{
	Application* app = new Application();

	app->Initialise();

	 

	while (app->IsRunning())
	{
		app->ProcessInput();
		app->Update();
		app->Render();
	}

	app->OutputFile();

	app->Close();

	return 0;
}
