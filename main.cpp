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
		SDL_Init( SDL_INIT_EVERYTHING );
		SDL_Quit(); 
		return 0;
	}
}