#pragma once
#include "ChessPiece.h"

namespace m1
{
	class Player
	{
	public:
		Player() = delete;
		Player(bool isWhite_);
		~Player() = default;

		//Render the chess pieces on the playfield
		void RenderPieces();

		void KingRookWasMoved() { kingRookMoved = true; };
		void QueenRookWasMoved() { queenRookMoved = true; };

		bool KingRookMoved() { return kingRookMoved; };
		bool QueenRookMoved() { return queenRookMoved; };

		//Get players chess pieces
		std::vector<std::shared_ptr<ChessPiece>> GetChessPieces() { return chessPieces; };

	private:

		//ChessPieces
		std::vector<std::shared_ptr<ChessPiece>> chessPieces;
	
		//important for castles
		bool kingRookMoved;
		bool queenRookMoved;


		bool isWhite;

	};
};



