/*
 This tutorial shows how to display a simple hello world window made with 
 sdl2.

 Compilation commands:
 ====================
	 Linux ==>  gcc sdl_collision.c -o collision -lSDL2 && ./collision
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

	SDL_Rect red_rect = {100,100,100,100};
	SDL_Rect blue_rect = {100, 200, 100,100};


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
			if (ev.type == SDL_KEYDOWN)
			{
				if (ev.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}

			}

		}

		// collision detection code
		if (SDL_HasIntersection(&red_rect, &blue_rect))
		{
			printf("collision has occured\n");
			printf("enemy down\n");
		}
		// collision detection code



		// get mouse position
		SDL_GetMouseState(&blue_rect.x, &blue_rect.y);

		SDL_SetRenderDrawColor(render, 255,255,0,255);
		SDL_RenderClear(render);

		// red rectangle draw
		SDL_SetRenderDrawColor(render, 255,0,0,255);
		SDL_RenderFillRect(render, &red_rect);

		// blue rect
		SDL_SetRenderDrawColor(render, 0,0,255,255);
		SDL_RenderFillRect(render,&blue_rect); 

		SDL_RenderPresent(render);
	}

	// clean up resources 
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	SDL_Quit();
}















