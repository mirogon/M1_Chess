#include "Player.h"

namespace m1
{
	Player::Player(bool isWhite_)
	{

		kingRookMoved = false;
		queenRookMoved = false;

		isWhite = isWhite_;

		chessPieces = std::vector<std::shared_ptr<ChessPiece>>();
		
		//Create King
		chessPieces.push_back(std::shared_ptr<ChessPiece>(new ChessPiece(ChessPieceType::King, isWhite)));
		chessPieces[0]->Init(ChessPieceType::King, isWhite);
		//Position King
		if (isWhite)
		{
			chessPieces[0]->SetPosition(4, 0);
		}
		else
		{
			chessPieces[0]->SetPosition(4, 7);
		}
	
		//Create Queen
		chessPieces.push_back(std::shared_ptr<ChessPiece>(new ChessPiece(ChessPieceType::Queen, isWhite)));
		chessPieces[1]->Init(ChessPieceType::Queen, isWhite);
		//Position Queen
		if (isWhite)
		{
			chessPieces[1]->SetPosition(3, 0);
		}
		else
		{
			chessPieces[1]->SetPosition(3, 7);
		}

		//Create and position Rooks 
		for (int i = 0; i < 2; ++i)
		{
			chessPieces.push_back(std::shared_ptr<ChessPiece>(new ChessPiece(ChessPieceType::Rook, isWhite)));
			chessPieces[2+i]->Init(ChessPieceType::Rook, isWhite);
			if (isWhite)
			{
				chessPieces[2+i]->SetPosition(i * 7, 0);
			}
			else
			{
				chessPieces[2+i]->SetPosition(i * 7, 7);
			}
			
		}

		//Create and position Bishop1
		chessPieces.push_back(std::shared_ptr<ChessPiece>(new ChessPiece(ChessPieceType::Bishop, isWhite)));
		chessPieces[4]->Init(ChessPieceType::Bishop, isWhite);
		if (isWhite)
		{
			chessPieces[4]->SetPosition(2, 0);
		}
		else
		{
			chessPieces[4]->SetPosition(2, 7);
		}

		//Create and position Bishop2
		chessPieces.push_back( std::shared_ptr<ChessPiece>( new ChessPiece(ChessPieceType::Bishop, isWhite) ) );
		chessPieces[5]->Init(ChessPieceType::Bishop, isWhite);
		if (isWhite)
		{
			chessPieces[5]->SetPosition(5, 0);
		}
		else
		{
			chessPieces[5]->SetPosition(5, 7);
		}
		
		//Create and position Knight1
		chessPieces.push_back(std::shared_ptr<ChessPiece>(new ChessPiece(ChessPieceType::Knight, isWhite)));
		chessPieces[6]->Init(ChessPieceType::Knight, isWhite);
		if (isWhite)
		{
			chessPieces[6]->SetPosition(1, 0);
		}
		else
		{
			chessPieces[6]->SetPosition(1, 7);
		}

		//Create and position Knight2
		chessPieces.push_back(std::shared_ptr<ChessPiece>(new ChessPiece(ChessPieceType::Knight, isWhite)));
		chessPieces[7]->Init(ChessPieceType::Knight, isWhite);
		if (isWhite)
		{
			chessPieces[7]->SetPosition(6, 0);
		}
		else
		{
			chessPieces[7]->SetPosition(6, 7);
		}
		
		//Create and position Pawns
		for (int i = 0; i < 8; ++i)
		{
			chessPieces.push_back(std::shared_ptr<ChessPiece>(new ChessPiece(ChessPieceType::Pawn, isWhite)));
			chessPieces[8+i]->Init(ChessPieceType::Pawn, isWhite);
			if (isWhite)
			{
				chessPieces[8 + i]->SetPosition(i, 1);
			}
			else
			{
				chessPieces[8 + i]->SetPosition(i, 6);
			}
		}
		
	}

	void Player::RenderPieces()
	{
		for (int i = 0; i < 16; ++i)
		{
			chessPieces[i]->Render();
		}
		
	}

};
