#pragma once
#include "Base.h"

namespace m1
{
	class Texture
	{
	public:
		//METHODS
		Texture();
		//Deep copy constructor
		Texture(const Texture& texture_) = delete;
		virtual ~Texture();

		bool InitTexture(std::string path, float scale_w = 1, float scale_h = 1);
		/*bool InitTextureFromText(std::string text, float scale = (SCALE_W + SCALE_H) / 2 , SDL_Color = {0,0,0,0});*/
		void FreeTexture();

		//INLINE

		void RenderTexture(int x, int y);
		void RenderTexture(int x, int y, SDL_Rect* clip);
		void RenderTexture(int x, int y, SDL_Rect* clip, SDL_Rect* clip1);
		void RenderTextureRotated(int x, int y, SDL_Rect* clip, double degree = 0);
		SDL_Rect GetRect() const;

		SDL_Texture* GetTexture()
		{
			return texture;
		}

	protected:

		SDL_Rect* textureRect;
		SDL_Texture* texture;

	};

	inline void Texture::RenderTexture(int x, int y)
	{

		textureRect->x = x;
		textureRect->y = y;

		SDL_RenderCopy(_GetRenderer, texture, NULL, textureRect);

	}


	inline void Texture::RenderTexture(int x, int y, SDL_Rect* clip)
	{

		textureRect->x = x;
		textureRect->y = y;

		SDL_RenderCopy(_GetRenderer, texture, clip, textureRect);

	}

	inline void Texture::RenderTexture(int x, int y, SDL_Rect* clip, SDL_Rect* clip2)
	{

		textureRect->x = x;
		textureRect->y = y;

		SDL_RenderCopy(_GetRenderer, texture, clip, clip2);

	}

	inline void Texture::RenderTextureRotated(int x, int y, SDL_Rect* clip, double degree)
	{

		textureRect->x = x;
		textureRect->y = y;

		SDL_RenderCopyEx(_GetRenderer, texture, clip, textureRect, degree, NULL, SDL_FLIP_NONE);

	}

	inline SDL_Rect Texture::GetRect() const
	{
		return *textureRect;
	}

};

