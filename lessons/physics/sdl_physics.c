/*
 This tutorial shows how to capture keyboard input in
 sdl2.

 Compilation commands:
 ====================
	 Linux ==>  gcc sdl_physics.c -o physics -lSDL2  && ./physics
	 Mac OS ==> 
	 Windows ==>
*/

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

int GRAVITY = 1;

void player_jump(SDL_Rect *player)
{
	player->y -= 300;
}

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *win = SDL_CreateWindow("sdl simple physics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900,600,0);
	SDL_Renderer *render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	// player
	SDL_Rect player = {10, 800,20,40};


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

				if (ev.key.keysym.sym == SDLK_SPACE && player.y == 600 -50)
				{
					player_jump(&player);
				}

				if (ev.key.keysym.sym == SDLK_LEFT && player.x > 0)
				{
					player.x -= 5;
				}

				if (ev.key.keysym.sym == SDLK_RIGHT && player.x < 900)
				{
					player.x += 5;
				}


				if (ev.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}

			}
		}


		// lets pull the player down by gravity
		player.y += GRAVITY;
		// then the gravity itself should be increasing

		if (player.y >= 600 - 50)
		{
			player.y = 600 - 50;
		}

		SDL_SetRenderDrawColor(render, 0,0,0,255);
		SDL_RenderClear(render);

		// draw the white player
		SDL_SetRenderDrawColor(render, 0,0,255,255);
		SDL_RenderFillRect(render, &player);

		SDL_RenderPresent(render);
	}

	// be sure to clean up
	// hope you remember we are using c
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	SDL_Quit();
}






