/*
 This tutorial shows how to display a simple hello world window made with 
 sdl2.

 Compilation commands:
 ====================
	 Linux ==>  gcc sdl_window.c -o window -lSDL2 && ./window
	 Mac OS ==> 
	 Windows ==>
*/

#include <SDL2/SDL.h>
#include <stdbool.h>

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *win = SDL_CreateWindow("hello sdl2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900,600,0);
	SDL_Renderer *render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

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

		}
		SDL_SetRenderDrawColor(render, 255,255,0,255);
		SDL_RenderClear(render);
		SDL_RenderPresent(render);
	}

	// clean up resources 
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	SDL_Quit();
}















