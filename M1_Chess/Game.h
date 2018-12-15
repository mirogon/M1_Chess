#pragma once
#include "Player.h"

namespace m1
{

	class Game
	{

	public:

		Game();
		~Game();

		void Game_Play(bool leftMouseDown);
		void Game_Menu();

	private:

		void RenderPieces();
		void PickupAndPlacePiece(bool leftMouseDown);

		std::shared_ptr<ChessPiece> CoordinateToChessPiece(int& x_, int& y_);
		ChessPosition CoordinateToChessPosition(int& x_, int& y_);

		bool IsValidMovement(const ChessPosition& oldPos, const ChessPosition& newPos, ChessPieceType pieceType);
		bool IsValidMovement_King(const ChessPosition& oldPos, const ChessPosition& newPos);
		//Member

	private:

		Texture background;

		Player blackPlayer;
		Player whitePlayer;

		int mousePosX;
		int mousePosY;

		std::shared_ptr<ChessPiece> heldPiece;
		bool whitePlayersTurn;

	};

	inline void Game::Game_Play(bool leftMouseDown)
	{
		background.RenderTexture(0, 0);
		
		PickupAndPlacePiece(leftMouseDown);

		RenderPieces();


	}

	inline void Game::Game_Menu()
	{


	}

	inline void Game::RenderPieces()
	{
		for (int i = 0; i < whitePlayer.GetChessPieces().size(); ++i)
		{
			//If the piece is currently held up, dont render it normally
			if (whitePlayer.GetChessPieces().at(i)->GetPosition().X() == heldPiece->GetPosition().X()
				&& whitePlayer.GetChessPieces().at(i)->GetPosition().Y() == heldPiece->GetPosition().Y()
				&& heldPiece->GetType() != ChessPieceType::Undefined)
			{

			}
			else
			{
				whitePlayer.GetChessPieces().at(i)->Render();
			}
		}

		for (int i = 0; i < blackPlayer.GetChessPieces().size(); ++i)
		{
			//If the piece is currently held up, dont render it normally
			if (blackPlayer.GetChessPieces().at(i)->GetPosition().X() == heldPiece->GetPosition().X()
				&& blackPlayer.GetChessPieces().at(i)->GetPosition().Y() == heldPiece->GetPosition().Y()
				&& heldPiece->GetType() != ChessPieceType::Undefined)
			{

			}
			else
			{
				blackPlayer.GetChessPieces().at(i)->Render();
			}
		}

		SDL_GetMouseState(&mousePosX, &mousePosY);
		static int hX = mousePosX - _TEXTURE_SIZE_PIECE/2;
		static int hY = mousePosY - _TEXTURE_SIZE_PIECE / 2;
		hX = mousePosX - _TEXTURE_SIZE_PIECE / 2;
		hY = mousePosY - _TEXTURE_SIZE_PIECE / 2;
		heldPiece->RenderDirect(hX, hY);

	}
};
