#include "Game.h"

using namespace std;

#undef main
int main(int argc, char* argv[]){
    
    //Create SDL, IMG and TTF
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    //Start values for the bools
    bool quitPollEvent = false;
	bool leftMouseDown = false;

    //Event to check the current event
    SDL_Event e;
    
    m1::Game mainGame;
        
    while(quitPollEvent == false){
        
        static int fps = 0;
        static Uint32 lt = 0;
        
        //Sync the current event
        while( SDL_PollEvent(&e)!= 0 )
		{
            //Check if the application was closed
            if(e.type == SDL_QUIT)
			{
                //End the application loop
                quitPollEvent = true;
                
            }

			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
					case SDLK_ESCAPE: quitPollEvent = true; break;

				}
			}

			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if (e.button.button == SDL_BUTTON_LEFT)
				{
					leftMouseDown = true;
				}
			}

			if (e.type == SDL_MOUSEBUTTONUP)
			{
				if (e.button.button == SDL_BUTTON_LEFT)
				{
					leftMouseDown = false;
				}
			}
		}
        
        //Clear screen with the default render color
        SDL_RenderClear(m1::_GetRenderer);

        mainGame.Game_Play(leftMouseDown);
        
        //Sync the renderer
        SDL_RenderPresent(m1::_GetRenderer);

        ++fps;
        
        if(SDL_GetTicks() - lt >= 1000){
            
            lt = SDL_GetTicks();
			m1::Log("FPS: " + m1::to_string(fps));
            fps = 0;
        }
    }

    //CLEAN THE MEMORY
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    
    return 0;
}


