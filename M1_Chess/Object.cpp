#include "Object.h"

namespace m1
{
	Object::Object()
	{
	}

	Object::~Object()
	{

	}

	void Object::InitObject(std::string path)
	{
		InitTexture(path);
		textureRectDouble.w = textureRect->w;
		textureRectDouble.h = textureRect->h;
	}



	void Object::MoveObjectDirect(int x, int y)
	{
		textureRectDouble.x = x;
		textureRectDouble.y = y;

	}
};
