//============================================================================
// Name        : ArcadeApp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>
using namespace std;


const int SCREEN_WIDTH= 224;
const int  SCREEN_HEIGHT = 288;
int main() {

	if (SDL_Init(SDL_INIT_VIDEO)){


		std::cout << "Error SDL_Init Failed" <<std::endl;
		return 1;
	}

	SDL_Window *optrWindow = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);


	if (optrWindow == nullptr){

		std::cout << "Could not create window, got error : " << SDL_GetError() << std::endl;
		return 1;
	}


	SDL_Event sdlEvent;

	bool running = true;

	while(running){

		while( SDL_PollEvent(&sdlEvent)){

			switch(sdlEvent.type){
			case SDL_QUIT:
				running = false;
				break;
			}
		}
	}


	SDL_DestroyWindow(optrWindow);
	SDL_Quit();





		return 0;
}
