#include "Global.h"

namespace m1
{

	const unsigned int WINDOW_RESOLUTION_X = 720;
	const unsigned int WINDOW_RESOLUTION_Y = 720;

	void Log(std::string str, int delay)
	{
		if (delay > 0) {
			SDL_Delay(delay);
		}
		std::cout << str << std::endl;
	}

	long stol(const std::string& str)
	{
		std::stringstream sstr(str);
		long rt;
		sstr >> rt;
		return rt;
	}

	bool ChessPosition::SetPosition(unsigned int newXPos, unsigned int newYPos)
	{
		if (ValidPosition(newXPos, newYPos))
		{
			xPos = newXPos;
			yPos = newYPos;
			SetPositionName();
			return true;
		}
		std::cout << "INVALID POS!" << std::endl;
		return false;
	}

	std::array<unsigned int, 2> ChessPosition::GetPosition()
	{
		return std::array<unsigned int, 2>{ xPos, yPos };
	}

	bool ChessPosition::ValidPosition(unsigned int x, unsigned int y)
	{
		if (x > 7 || x < 0)
		{
			std::cout << "Invalid position!" << std::endl;
			return false;
		}
		if (y > 7 || y < 0)
		{
			std::cout << "Invalid position!" << std::endl;
			return false;
		}
		return true;
	}

	void ChessPosition::SetPositionName()
	{
		static char characterRow;
		uint8_t numberRow = yPos + 1;

		characterRow = 65 + xPos;

		positionName = characterRow + to_string(numberRow);
	}

};