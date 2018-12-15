#pragma once
#include "Global.h"

namespace m1
{

	extern const unsigned int WINDOW_RESOLUTION_X;
	extern const unsigned int WINDOW_RESOLUTION_Y;

	#define _GetWindow Base::getInstance()->GetWindow()
	#define _GetRenderer Base::getInstance()->GetRenderer()

	class Base
	{

	public:

		//INLINE

		static Base* getInstance();

		SDL_Window* GetWindow();

		SDL_Renderer* GetRenderer();

	private:

		Base();

		~Base();

		SDL_Window* mainWindow;

		SDL_Renderer* mainRenderer;

	};

	inline Base* Base::getInstance()
	{
		static Base instance;
		return &instance;
	}



	inline SDL_Window* Base::GetWindow() {

		return mainWindow;

	};

	inline SDL_Renderer* Base::GetRenderer() {

		return mainRenderer;

	};

};

