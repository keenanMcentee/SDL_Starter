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
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_UP];
					break;
				case SDLK_DOWN:
					currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
					break;
				case SDLK_LEFT:
					currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
					break;
				case SDLK_RIGHT:
					currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
					break;
				default:
					currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
					break;
				}
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
	window = SDL_CreateWindow("Tutorial 04 Keyboard Control", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	screenSurface = SDL_GetWindowSurface(window);

	loadMedia();

	currentSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

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
	SDL_BlitSurface(currentSurface, NULL, screenSurface, NULL);
	SDL_UpdateWindowSurface(window);
}




void Game::loadMedia()
{
	keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("./img/press.bmp");
	keyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("./img/up.bmp");
	keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("./img/down.bmp");
	keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("./img/left.bmp");
	keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("./img/right.bmp");
}

SDL_Surface* Game::loadSurface(std::string path)
{
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL) 
	{ 
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
	return loadedSurface;
}

void Game::close()
{
	//SDL_FreeSurface(gHelloWorld);
	//gHelloWorld = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}

