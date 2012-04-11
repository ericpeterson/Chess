#include <iostream>
#include <set>

#include "ChessGuiDefines.h"
#include "UnitTest.h"

#include "ChessColor.h"
#include "ChessMove.h"
#include "BoardPosition.h"
#include "Pawn.h"

using namespace std;


Pawn::Pawn (ChessColor c, ImageName t) {
  m_color = c;
  m_type = t;
}


Pawn::Pawn (const Pawn & pawn) {
  copy(pawn);
}


Pawn::~Pawn () {}


Pawn & Pawn::operator = (const Pawn & pawn) {
  return copy(pawn);
}


set<BoardPosition> Pawn::GetMoves (Board* board, BoardPosition & position) {
  set<BoardPosition> moves;
  ChessColor color = this->GetColor();
  int row = position.GetRow();

  if (color == WHITE) {
    BoardPosition twoMove(position.MoveUp(2));

    // white pawn first move
    if (row == 6 && !IsPieceAtPosition(twoMove.GetRow(), twoMove.GetCol(), board) && 
      !IsPositionOffBoard(twoMove.GetRow(), twoMove.GetCol())) {
      moves.insert(twoMove);
    }

    BoardPosition oneMove(position.MoveUp(1));
    if (!IsPieceAtPosition(oneMove.GetRow(), oneMove.GetCol(), board) &&
      !IsPositionOffBoard(oneMove.GetRow(), oneMove.GetCol())) {
      moves.insert(oneMove);
    }
  } else if (color == BLACK) {
    // black pawn first move
    BoardPosition twoMove(position.MoveDown(2));
    if (row == 1 && !IsPieceAtPosition(twoMove.GetRow(), twoMove.GetCol(), board) &&
      !IsPositionOffBoard(twoMove.GetRow(), twoMove.GetCol())) {
      moves.insert(twoMove);
    }

    BoardPosition oneMove(position.MoveDown(1));
    if (!IsPieceAtPosition(oneMove.GetRow(), oneMove.GetCol(), board) &&
      !IsPositionOffBoard(oneMove.GetRow(), oneMove.GetCol())) {
      moves.insert(oneMove);
    }
  }

  return moves;
}


bool Pawn::Test (std::ostream & os) {
  bool success = true;

  return success;
}


Pawn & Pawn::copy (const Pawn & pawn) {
  if (this != &pawn) {
    m_color = pawn.m_color;
    m_type = pawn.m_type;
  }

  return *this;
}


bool Pawn::IsPieceAtPosition (int row, int col, Board* board) {
  IPiece* piece = board->PieceAtPosition(row, col);
  return piece != NULL;      
}

