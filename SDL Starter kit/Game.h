#include "SDL.h"

class Game
{
public:
	Game();
	~Game();

	void run();
	void initialise();
	void update();
	void draw();

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
};

