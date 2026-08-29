/*
 This tutorial shows how to capture keyboard input in
 sdl2.

 Compilation commands:
 ====================
	 Linux ==>  gcc sdl_textures.c -o texture -lSDL2 -lSDL2_image && ./texture
	 Mac OS ==> 
	 Windows ==>
*/
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	// initialise library for loading png images
	IMG_Init(IMG_INIT_PNG);

	SDL_Window *win = SDL_CreateWindow("sdl image loading", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900,600,0);
	SDL_Renderer *render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	SDL_Surface *img_surface = IMG_Load("../assets/run.png");
	SDL_Texture *img_texture = SDL_CreateTextureFromSurface(render, img_surface);
	SDL_FreeSurface(img_surface);

	// make a running character
	SDL_Rect srect = {0,0,120,80};
	SDL_Rect drect = {100,100,120*2,80*2};

	// animation configuration
	int FRAM_TIME = 150;
	int TOTAL_FRAMES = 5;
	int FRAME_SIZE = 120; //pixles;

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
				// quit app when escape key is pressed
				if (ev.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}
			}

		}
		// how long in miliseconds has sdl2 been  runnig
		uint32_t sdl_time = SDL_GetTicks();
		// formula for looping over spritesheet frames
		int current_frame = (sdl_time / FRAM_TIME) % TOTAL_FRAMES;

		// scroll the source rectangle for the spritesheet
		srect.x = current_frame * FRAME_SIZE;


		SDL_SetRenderDrawColor(render, 200,200,200,255);
		SDL_RenderClear(render);
		// texture rendering code here
		SDL_RenderCopy(render, img_texture, &srect, &drect);
		SDL_RenderPresent(render);

	}
	// clean up resources
	SDL_DestroyTexture(img_texture);

	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	SDL_Quit();
}





