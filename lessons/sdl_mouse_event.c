/*
 This tutorial shows how to capture keyboard input in
 sdl2.

 Compilation commands:
 ====================
	 Linux ==>  gcc sdl_mouse_event.c -o mouse -lSDL2 && ./mouse
	 Mac OS ==> 
	 Windows ==>
*/

#include <stdbool.h>
#include <SDL2/SDL.h>

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *win = SDL_CreateWindow("sdl mouse input", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900,600,0);
	SDL_Renderer *render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	bool running = true;

	int x_pos;
	int y_pos;


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
				// quit app when escape key is pressed
				if (ev.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}
			}

		}
		// captures the current mouse position and stores it in 
		// variables x_pos and y_pos
		SDL_GetMouseState(&x_pos, &y_pos);

		printf("mouse position x: %d y: %d\n", x_pos, y_pos);

		SDL_SetRenderDrawColor(render, 0,200,200,255);
		SDL_RenderClear(render);
		SDL_RenderPresent(render);
	}
	
}






