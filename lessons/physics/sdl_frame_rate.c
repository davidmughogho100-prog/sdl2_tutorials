/*
 This tutorial shows how to capture keyboard input in
 sdl2.

 Compilation commands:
 ====================
	 Linux ==>  gcc sdl_delta_time.c -o delta -lSDL2  && ./delta
	 Mac OS ==> 
	 Windows ==>
*/
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_framerate.h>


int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *win = SDL_CreateWindow("sdl frame rate control operation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900,600,0);
	SDL_Renderer *render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	// frame rate management
	FPSmanager fpsMgr;
	SDL_initFramerate(&fpsMgr);

	// set the frame rate
	SDL_setFramerate(&fpsMgr, 60);
	// frame rate management

	bool running = true;
	SDL_Event ev;
	while (running)
	{

		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT) 
			{
				running = false;
			}

			// keyboard input in sdl2
			if (ev.type == SDL_KEYDOWN)
			{

				if (ev.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}
			}
		}
		printf("this loop is running at 60 frames per second\n");

		SDL_SetRenderDrawColor(render, 0,0,0,255);
		SDL_RenderClear(render);

		SDL_RenderPresent(render);

		// control the speed of the game loop using the frame rate
		SDL_framerateDelay(&fpsMgr);
	}

	// be sure to clean up
	// hope you remember we are using c
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

