#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::run()
{
	initialise();

	while (true)
	{
		update();
		draw();
	}
	
}

void Game::initialise()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Starter kit", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
}

void Game::update()
{

}

void Game::draw()
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);


	SDL_RenderClear(renderer);


	SDL_RenderPresent(renderer);
}