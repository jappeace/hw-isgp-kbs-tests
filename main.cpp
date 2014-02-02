/* 
 * File:   main.cpp
 * Author: jappie
 *
 * Created on January 31, 2014, 9:10 AM
 */

#include <cstdlib>
#include <iostream>
#include <SDL/SDL.h>
#include "Grid.h"
using namespace std;
namespace isgp{
	/*
	 * open a window
	 */
	int main(int argc, char** argv) {
		SDL_Surface *screen;
		SDL_Event event;

		if (SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0)
		{
			fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
			exit(1);
		}

		screen = SDL_SetVideoMode(640, 480, 16, SDL_SWSURFACE);
		if (screen == NULL)
		{
			fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
			exit(1);
		}

		SDL_WaitEvent(&event);

		while(1)
		{
			while(SDL_PollEvent(&event))
			{     
				switch (event.type)
				{
					case SDL_QUIT:
						exit(0);
						break;
				}
			}
		}

		SDL_Quit();

		return 1;
	}
}