#include <iostream>
#include <set>

#include "ChessGuiDefines.h"

#include "ChessColor.h"
#include "ChessMove.h"
#include "BoardPosition.h"
#include "IPiece.h"
#include "Rook.h"

using namespace std;

Rook::Rook (ChessColor c, ImageName t) {
  m_color = c;
  m_type = t;
}


Rook::Rook (const Rook & rook) {
  copy(rook);
}


Rook::~Rook () {}


Rook & Rook::operator = (const Rook & rook) {
  return copy(rook);
}


set<BoardPosition> Rook::GetMoves (Board* board, const BoardPosition & position) {
  set<BoardPosition> moves;

  return moves;
}


bool Rook::Test (std::ostream & os) {
  bool success = true;

  return success;
}


Rook & Rook::copy (const Rook & rook) {
  if (this != &rook) {
    m_color = rook.m_color;
    m_type = rook.m_type;
  }

  return *this;
}

