
#pragma once
#include "Object.h"

namespace m1
{
	class ChessPiece
	{
	public:

		ChessPiece();
		ChessPiece(const ChessPiece& cp) = delete;
		ChessPiece(ChessPieceType initType, bool isWhitePiece);
		~ChessPiece() = default;

		//Same as constructor with the same parameter
		void Init(ChessPieceType initType, bool isWhitePiece);

		//Set the position of the ChessPiece from (0,0) to (7,7)
		bool SetPosition(uint8_t xPos, uint8_t yPos);

		void Render();
		void RenderDirect(int& x_, int& y_);

		ChessPieceType GetType() { return type; }
		ChessPosition GetPosition(){ return position; };

	private:

		m1::Texture	texture;

		bool isWhite;
		ChessPieceType type;
		ChessPosition position;
	};
};