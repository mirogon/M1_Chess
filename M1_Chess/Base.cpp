#include "Base.h"

namespace m1
{

	Base::Base():

		//Intializing the mainWindow
		mainWindow{ SDL_CreateWindow(_WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_RESOLUTION_X, WINDOW_RESOLUTION_Y, 0) },

		//Intializing the mainRenderer
		mainRenderer{SDL_CreateRenderer(mainWindow, -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)}

	{
		if(!mainWindow)
		{
			std::cout << "Window could not be created!" << std::endl;;
		}

		if(!mainRenderer)
		{
			std::cout << "mainRenderer could not be created!" << std::endl;
		}

		//Set the default renderer color
		SDL_SetRenderDrawColor(mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	};

	Base::~Base(){

		//Destroy the mainWindow
		SDL_DestroyWindow(this->mainWindow);

		//Destroy the mainRenderer
		SDL_DestroyRenderer(this->mainRenderer);

	};

};