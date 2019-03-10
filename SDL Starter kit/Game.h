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
	SDL_Surface* loadSurface(std::string path);
	void close();

	//While true, program keeps running
	bool gameloop;

	enum KeyPressSurfaces
	{
		KEY_PRESS_SURFACE_DEFAULT,
		KEY_PRESS_SURFACE_UP,
		KEY_PRESS_SURFACE_DOWN,
		KEY_PRESS_SURFACE_LEFT,
		KEY_PRESS_SURFACE_RIGHT,
		KEY_PRESS_SURFACE_TOTAL
	};

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	SDL_Surface *screenSurface = NULL;
	SDL_Surface *keyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
	SDL_Surface *currentSurface = NULL;



	
};

