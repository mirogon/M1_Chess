#include "Game.h"

namespace m1
{
	Game::Game() :
		whitePlayer{Player(true)},
		blackPlayer{Player(false)}
	{

		mousePosX = 0;
		mousePosY = 0;

		whitePlayersTurn = true;

		background = Texture();

		//Initialization
		background.InitTexture(_BACKGROUND_TEXTURE_PATH, 1, 1);

		heldPiece = std::shared_ptr<ChessPiece>( new ChessPiece(ChessPieceType::Undefined, true) );

	}

	Game::~Game()
	{
	}

	std::shared_ptr<ChessPiece> Game::CoordinateToChessPiece(int& x_, int& y_)
	{

		static std::vector<std::shared_ptr<ChessPiece>> rP;
		
		if (x_ < 0 || x_ > WINDOW_RESOLUTION_X || y_ < 0 || y_ > WINDOW_RESOLUTION_Y)
		{
			//No chess position at this coordinate
			return std::shared_ptr<ChessPiece>(new ChessPiece( ChessPieceType::Undefined, true)  );
		}

		else
		{
			if (whitePlayersTurn == true)
			{
				rP = whitePlayer.GetChessPieces();
			}
			else
			{
				rP = blackPlayer.GetChessPieces();
			}
			for (int i = 0; i < rP.size(); ++i)
			{
				if (x_ >= rP.at(i)->GetPosition().X() * _TEXTURE_SIZE_PIECE
					&& x_ <= rP.at(i)->GetPosition().X() * _TEXTURE_SIZE_PIECE + _TEXTURE_SIZE_PIECE)
				{
					if (WINDOW_RESOLUTION_Y - y_ >= rP.at(i)->GetPosition().Y() * _TEXTURE_SIZE_PIECE
						&& WINDOW_RESOLUTION_Y - y_ <= rP.at(i)->GetPosition().Y() * _TEXTURE_SIZE_PIECE + _TEXTURE_SIZE_PIECE)
					{
						return rP.at(i);
					}
				}
			}
		}

		return std::shared_ptr<ChessPiece>(new ChessPiece(ChessPieceType::Undefined, true));
	}

	ChessPosition Game::CoordinateToChessPosition(int& x_, int& y_)
	{
		static ChessPosition rP;
		rP.SetPosition(0, 0);

		if (x_ > WINDOW_RESOLUTION_X || x_ < 0 || y_ > WINDOW_RESOLUTION_Y || y_ < 0)
		{
			std::cout << "Invalid position!" << std::endl;
			return rP;
		}
	
		else
		{
			static unsigned int column;
			static unsigned int row;

			column = 0;
			row = 0;

			for (int i = 0; i < 8; ++i)
			{
				if (x_ >= i * _TEXTURE_SIZE_PIECE)
				{
					column = i;
				}
			}
			
			for (int i = 0; i < 8; ++i)
			{
				if (y_ >= i * _TEXTURE_SIZE_PIECE)
				{
					row = 7-i;
				}
			}

			rP.SetPosition(column, row);
			return rP;

		}

	}

	void Game::PickupAndPlacePiece(bool leftMouseDown)
	{
	
		static int lastMouseState = leftMouseDown;
		SDL_GetMouseState(&mousePosX, &mousePosY);

		if (lastMouseState == false && leftMouseDown == true)
		{
			Log("Pickup piece!");
			//Pick up piece
			heldPiece.reset();
			heldPiece = CoordinateToChessPiece(mousePosX, mousePosY);
			
		}

		else if (lastMouseState == true && leftMouseDown == false)
		{
			static ChessPosition chosenPosition;
			//no held piece anymore
			//heldPiece = std::shared_ptr<ChessPiece>(new ChessPiece(ChessPieceType::Undefined, true));
			
			chosenPosition = CoordinateToChessPosition(mousePosX, mousePosY);
			std::cout << "Chosen position: " << chosenPosition.X() << " " << chosenPosition.Y() << std::endl;
			
			//Check if the move was valid and set the new pos
			if (IsValidMovement(heldPiece->GetPosition(), chosenPosition, heldPiece->GetType()))
			{
				heldPiece->SetPosition(chosenPosition.X(), chosenPosition.Y());

				//Toggle black and white players turn
				whitePlayersTurn = !whitePlayersTurn;
			}
			
			heldPiece = std::shared_ptr<ChessPiece>(new ChessPiece(ChessPieceType::Undefined, true));
			
			
		}

		lastMouseState = leftMouseDown;
	}

	bool Game::IsValidMovement(const ChessPosition& oldPos, const ChessPosition& newPos, ChessPieceType pieceType)
	{
		switch (pieceType)
		{
		case ChessPieceType::King: return IsValidMovement_King(oldPos, newPos); break;
		case ChessPieceType::Queen: return true; break;
		case ChessPieceType::Rook: return true; break;
		case ChessPieceType::Bishop: return true; break;
		case ChessPieceType::Knight: return true; break;
		case ChessPieceType::Pawn: return true; break;
		case ChessPieceType::Undefined: return false;
		}

		return false;

	}

	bool Game::IsValidMovement_King(const ChessPosition& oldPos, const ChessPosition& newPos)
	{
		//check if position hasnt changed
		if (newPos.X() == oldPos.X() && newPos.Y() == oldPos.Y())
		{
			return false;
		}

		if (newPos.X() > oldPos.X())
		{
			if (newPos.X() > oldPos.X() + 1)
			{
				return false;
			}
		}

		if (newPos.X() < oldPos.X())
		{
			if (newPos.X() < oldPos.X() - 1)
			{
				return false;
			}
		}

		if (newPos.Y() > oldPos.Y())
		{
			if (newPos.Y() > oldPos.Y() + 1)
			{
				return false;
			}
		}

		if (newPos.Y() < oldPos.Y())
		{
			if (newPos.Y() < oldPos.Y() -1)
			{
				return false;
			}
		}


		return true;

	}

};



