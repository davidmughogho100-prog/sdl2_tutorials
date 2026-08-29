/*
 This tutorial shows how to capture keyboard input in
 sdl2.

 Compilation commands:
 ====================
	 Linux ==>  gcc sdl_sound.c -o sound -lSDL2 -lSDL2_mixer && ./sound
	 Mac OS ==> 
	 Windows ==>
*/
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	Mix_Init(MIX_INIT_MP3);

	
   // 2. Open the audio device (44.1kHz, default format, stereo, 2048 byte chunk size)
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("sorry audio device could not start\n");
    }

	SDL_Window *win = SDL_CreateWindow("sdl mouse input", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900,600,0);
	SDL_Renderer *render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);


	Mix_Music *song = Mix_LoadMUS("../assets/song.mp3");

	// play song once and stop
	Mix_PlayMusic(song, 0);


	SDL_Event ev;
	bool running = true;
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

		SDL_SetRenderDrawColor(render, 0,200,200,255);
		SDL_RenderClear(render);
		SDL_RenderPresent(render);
	}
	
	// clean up resources
	Mix_FreeMusic(song);

	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	Mix_Quit();
	SDL_Quit();
}






