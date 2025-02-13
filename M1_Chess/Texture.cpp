#include "Texture.h"

namespace m1
{
	Texture::Texture()
	{
		textureRect = new SDL_Rect;
		textureRect->x = 0;
		textureRect->y = 0;
		textureRect->w = 0;
		textureRect->h = 0;

		texture = nullptr;

	}

	Texture::~Texture()
	{
		static unsigned int numDestructor = 0;
		++numDestructor;
		FreeTexture();
		//SafeDelete(textureRect);

	}

	void Texture::FreeTexture()
	{
		if (texture != nullptr)
		{
			SDL_DestroyTexture(texture);
		}
	}

	bool Texture::InitTexture(std::string path, float scale_w, float scale_h)
	{

		FreeTexture();

		SDL_Surface* surface = IMG_Load(path.c_str());

		if (surface == nullptr)
		{
			Log("Surface could not be created (Texture.cpp) ");
		}

		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 255, 255));

		texture = SDL_CreateTextureFromSurface(_GetRenderer, surface);
		if (texture == nullptr)
		{
			Log("Texture could not be created (Texture.cpp)");
		}

		textureRect->w = surface->w * scale_w;
		textureRect->h = surface->h * scale_h;

		SDL_FreeSurface(surface);
		return texture != nullptr;

	}

	/*bool Texture::InitTextureFromText(std::string text, float scale, SDL_Color color){

		FreeTexture();

		SDL_Surface* loadText = TTF_RenderText_Solid(_GetFont, text.c_str(), color);
		if(loadText==nullptr){

			//std::cout<<"TTF Surface konnte nicht erstellt werden"<<std::endl;

		}

		SDL_SetColorKey(loadText, SDL_TRUE, SDL_MapRGB(loadText->format, 0, 255, 255));

		texture = SDL_CreateTextureFromSurface(_GetRenderer, loadText);

		textureRect->w = loadText->w * scale;
		textureRect->h = loadText->h * scale;

		SDL_FreeSurface(loadText);

		return texture != nullptr;

	}*/
};

