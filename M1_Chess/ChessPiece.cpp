#include "ChessPiece.h"

namespace m1
{
		
	ChessPiece::ChessPiece()
	{
		Init(ChessPieceType::Pawn, true);
	}
		
	ChessPiece::ChessPiece(ChessPieceType initType, bool isWhitePiece)
	{
		Init(initType, isWhitePiece);		
	}

	void ChessPiece::Init(ChessPieceType initType, bool isWhitePiece)
	{

		texture = Texture();
		type = initType;
		position = ChessPosition();

		isWhite = false;
		if (isWhitePiece)
		{
			isWhite = true;
		}

		switch (type)
		{
		case ChessPieceType::King:

			if (isWhite)
			{
				texture.InitTexture(_WHITE_KING_TEXTURE_PATH);
			}
			else
			{
				texture.InitTexture(_BLACK_KING_TEXTURE_PATH);
			}
			break;

		case ChessPieceType::Queen:
			if (isWhite)
			{
				texture.InitTexture(_WHITE_QUEEN_TEXTURE_PATH);
			}
			else
			{
				texture.InitTexture(_BLACK_QUEEN_TEXTURE_PATH);
			}
			break;
		case ChessPieceType::Rook:
			if (isWhite)
			{
				texture.InitTexture(_WHITE_ROOK_TEXTURE_PATH);
			}
			else
			{
				texture.InitTexture(_BLACK_ROOK_TEXTURE_PATH);
			}
			break;
		case ChessPieceType::Bishop:
			if (isWhite)
			{
				texture.InitTexture(_WHITE_BISHOP_TEXTURE_PATH);
			}
			else
			{
				texture.InitTexture(_BLACK_BISHOP_TEXTURE_PATH);
			}
			break;
		case ChessPieceType::Knight:
			if (isWhite)
			{
				texture.InitTexture(_WHITE_KNIGHT_TEXTURE_PATH);
			}
			else
			{
				texture.InitTexture(_BLACK_KNIGHT_TEXTURE_PATH);
			}
			break;
		case ChessPieceType::Pawn:
			if (isWhite)
			{
				texture.InitTexture(_WHITE_PAWN_TEXTURE_PATH);
			}
			else
			{
				texture.InitTexture(_BLACK_PAWN_TEXTURE_PATH);
			}
			break;
		default:
			Log("Invalid ChessPieceType (ChessPiece.cpp)");
			break;
		}

		if (texture.GetTexture() == nullptr)
		{
			std::cout << "TEXTURE NULLPTR!(ChessPiece.cpp)" << std::endl;
		}
	}
	
	bool ChessPiece::SetPosition(uint8_t xPos, uint8_t yPos)
	{
		if (!position.SetPosition(xPos, yPos))
		{
			return false;
		}

		return true;
	}

	void ChessPiece::Render()
	{
		texture.RenderTexture(position.X() * _TEXTURE_SIZE_PIECE, 720 - (position.Y() * _TEXTURE_SIZE_PIECE)  - _TEXTURE_SIZE_PIECE);
	}

	void ChessPiece::RenderDirect(int& x_, int& y_)
	{
		texture.RenderTexture(x_, y_);
	}

};