/*
 This tutorial shows how to capture keyboard input in
 sdl2.

 Compilation commands:
 ====================
	 Linux ==>  gcc sdl_keyboard_event.c -o keyboard -lSDL2  && ./keyboard
	 Mac OS ==> 
	 Windows ==>
*/

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *win = SDL_CreateWindow("sdl keyboard input", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900,600,0);
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

			// keyboard input in sdl2
			if (ev.type == SDL_KEYDOWN)
			{

				if (ev.key.keysym.sym == SDLK_LEFT)
				{
					printf("left key pressed\n");
				}

				if (ev.key.keysym.sym == SDLK_RIGHT)
				{
					printf("right key pressed\n");
				}
				// lets take advantage of this to quit the
				// app when escape key is pressed

				if (ev.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}

			}

			if (ev.type == SDL_KEYUP)
			{
				
				if (ev.key.keysym.sym == SDLK_LEFT)
				{
					printf("left key released\n");
				}

				if (ev.key.keysym.sym == SDLK_RIGHT)
				{
					printf("right key released\n");
				}

			}

		}
		SDL_SetRenderDrawColor(render, 0,0,0,255);
		SDL_RenderClear(render);
		SDL_RenderPresent(render);


		// be sure to clean up
		// hope you remember we are using c
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(win);
		SDL_Quit();
	}
}






