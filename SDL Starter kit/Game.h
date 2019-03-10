#include "SDL.h"
#include <iostream>
class Game
{
public:
	Game();
	~Game();

	void run();
	void initialise();
	void update();
	void draw();

	void loadMedia();
	void close();

	//While true, program keeps running
	bool gameloop;

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	SDL_Surface *gScreenSurface = NULL;
	SDL_Surface *gHelloWorld = NULL;
};

