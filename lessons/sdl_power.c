/*
 This tutorial shows how to display a simple hello world window made with 
 sdl2.

 Compilation commands:
 ====================
	 Linux ==>  gcc sdl_power.c -o power -lSDL2 && ./power
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

	// battery checks code
	int percentage;
	SDL_PowerState battery_state = SDL_GetPowerInfo(NULL, &percentage);
	printf("battery percentage: %d\n", percentage);

	// getting battery states is fun lets use a switch
	switch(battery_state)
	{
		case SDL_POWERSTATE_ON_BATTERY:
			printf("charger is not plugged in and pc is using internal battery\n");
			break;
		case SDL_POWERSTATE_CHARGED:
			printf("charger is connected but battery is full\n");
			break;
		case SDL_POWERSTATE_CHARGING:
			printf("charger is plugged in and battery is charging\n");
			break;
		case SDL_POWERSTATE_UNKNOWN:
			printf("cannot determine power state of the battery\n");
			break;
		default:
			break;
	}



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
		SDL_SetRenderDrawColor(render, 255,255,0,255);
		SDL_RenderClear(render);
		SDL_RenderPresent(render);
	}

	// clean up resources 
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	SDL_Quit();
}















