/*
 This tutorial shows how to display a simple hello world window made with 
 sdl2.

 Compilation commands:
 ====================
	 Linux ==>  gcc sdl_text.c -o text -lSDL2 -lSDL2_ttf && ./text
	 Mac OS ==> 
	 Windows ==>
*/

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 600



int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	
	SDL_Window *win = SDL_CreateWindow("sdl text display", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT,0);
	SDL_Renderer *render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	TTF_Font *arial_font = TTF_OpenFont("../assets/arial.ttf", 30);
	SDL_Color text_color = {55,55,255,255};
	SDL_Color text_color_bg = {255,55,255,255};

	SDL_Surface *text_surface = TTF_RenderText(arial_font, "text in c with sdl2", text_color, text_color_bg);
	SDL_Texture *text_texture = SDL_CreateTextureFromSurface(render, text_surface);
	SDL_FreeSurface(text_surface);

	int text_width;
	int text_height;
	SDL_QueryTexture(text_texture,NULL,NULL, &text_width, &text_height);

	// this allows us to position the text in the center of the screen
	SDL_Rect text_rectangle = { (SCREEN_WIDTH - text_width) / 2, (SCREEN_HEIGHT - text_height) / 2, text_width, text_height};


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
		SDL_RenderCopy(render, text_texture, NULL, &text_rectangle);
		SDL_RenderPresent(render);
	}

	// clean up resources 
	// trick here is to destroy the resources in reverse order of their creation
	SDL_DestroyTexture(text_texture);
	TTF_CloseFont(arial_font);

	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	TTF_Quit();
	SDL_Quit();
}















