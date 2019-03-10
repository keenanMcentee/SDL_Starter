#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

/// <summary>
/// Handles the core game loop.
/// </summary>
void Game::run()
{
	initialise();
	SDL_Event e;

	while (gameloop)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				gameloop = false;
			}

		}
		update();
		draw();
	}
	close();
	
}

/// <summary>
/// Initialises the game components.
/// </summary>
void Game::initialise()
{
	gameloop = true;

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Tutorial 2 & 3 Images & Events", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	gScreenSurface = SDL_GetWindowSurface(window);

	loadMedia();
}

/// <summary>
/// Handles updating the game components.
/// </summary>
void Game::update()
{

}

/// <summary>
/// Handles renderering components to the screen.
/// </summary>
void Game::draw()
{
	SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
	SDL_UpdateWindowSurface(window);
}




void Game::loadMedia()
{
	gHelloWorld = SDL_LoadBMP("./img/hello_world.bmp");
	if (gHelloWorld == NULL) 
	{ 
		printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
	}
}

void Game::close()
{
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}