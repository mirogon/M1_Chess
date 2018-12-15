#pragma once

//C++
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <array>
#include <deque>
#include <memory>

//SDL
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

//M1
#include <M1Random\include\M1Random.h>

namespace m1
{

	#define _WINDOW_TITLE "M1Chess"
	#define _TEXTURE_SIZE_PIECE 90

	//Paths
	#define _FontPath "opensans.ttf"
	#define _BACKGROUND_TEXTURE_PATH "data\\images\\background.png"
	#define _BLACK_KING_TEXTURE_PATH "data\\images\\black_king.png"
	#define _WHITE_KING_TEXTURE_PATH "data\\images\\white_king.png"
	#define _BLACK_QUEEN_TEXTURE_PATH "data\\images\\black_queen.png"
	#define _WHITE_QUEEN_TEXTURE_PATH "data\\images\\white_queen.png"
	#define _BLACK_ROOK_TEXTURE_PATH "data\\images\\black_rook.png"
	#define _WHITE_ROOK_TEXTURE_PATH "data\\images\\white_rook.png"
	#define _BLACK_BISHOP_TEXTURE_PATH "data\\images\\black_bishop.png"
	#define _WHITE_BISHOP_TEXTURE_PATH "data\\images\\white_bishop.png"
	#define _BLACK_KNIGHT_TEXTURE_PATH "data\\images\\black_knight.png"
	#define _WHITE_KNIGHT_TEXTURE_PATH "data\\images\\white_knight.png"
	#define _BLACK_PAWN_TEXTURE_PATH "data\\images\\black_pawn.png"
	#define _WHITE_PAWN_TEXTURE_PATH "data\\images\\white_pawn.png"

	extern const unsigned int WINDOW_RESOLUTION_X;
	extern const unsigned int WINDOW_RESOLUTION_Y;

	void Log(std::string str, int delay = 0);

	long stol(const std::string& str);

	template <typename T>
	std::string to_string(T value)
	{
		std::ostringstream os;
		os << value;
		return os.str();
	}

	template<typename T>
	void SafeDelete(T* t)
	{
		if (t != nullptr) {
			delete t;
			t = nullptr;
		}
	}

	struct ChessPosition
	{

	public:

		//Functions
		bool SetPosition(unsigned int newXPos, unsigned int newYPos);

		const unsigned int X() const{ return xPos; };
		const unsigned int Y() const{ return yPos; } ;

		std::array<unsigned int,2> GetPosition();

	protected:

		//Member
		unsigned int xPos = 0;
		unsigned int yPos = 0;

		std::string positionName = "";

	private:

		/**
		* This function checks, if the current position is valid or not and resets the position, if it is invalid
		*/
		bool ValidPosition(unsigned int x, unsigned int y);
		/**
		* This function translates the current position to the chess naming scheme and saves it in positionName
		*/
		void SetPositionName();
	};

	enum ChessPieceType
	{
		Undefined = -1,
		King = 0,
		Queen = 1,
		Rook = 2,
		Bishop = 3,
		Knight = 4,
		Pawn = 5
	};

};