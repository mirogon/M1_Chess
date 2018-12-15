#pragma once
#include "Texture.h"

namespace m1
{

	struct double_Rect {
		double x;
		double y;
		int w;
		int h;
	};

	class Object : public Texture {

	public:


		//METHODS

		Object();
		virtual ~Object();

		void InitObject(std::string path);
		void MoveObjectDirect(int x, int y);

		//INLINE

		const double_Rect GetObjectRect();
		void MoveObject(double x, double y);
		void RenderObject();

	protected:

		double_Rect textureRectDouble;

	}; // CLASS

	inline void Object::MoveObject(double x, double y)
	{
		textureRectDouble.x += x;
		textureRectDouble.y += y;
	}

	inline void Object::RenderObject()
	{

		textureRect->x = textureRectDouble.x;
		textureRect->y = textureRectDouble.y;

		SDL_RenderCopy(_GetRenderer, this->texture, NULL, textureRect);

	}

	inline const double_Rect Object::GetObjectRect()
	{
		return textureRectDouble;
	}

}
