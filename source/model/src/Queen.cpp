#include <iostream>
#include <set>

#include "ChessGuiDefines.h"

#include "ChessColor.h"
#include "ChessMove.h"
#include "BoardPosition.h"
#include "IPiece.h"
#include "Queen.h"

using namespace std;


Queen::Queen (ChessColor c, ImageName t) {
  m_color = c;
  m_type = t;
}


Queen::Queen (const Queen & queen) {
  copy(queen);
}


Queen::~Queen () {}


Queen & Queen::operator = (const Queen & queen) {
  return copy(queen);
}


set<BoardPosition> Queen::GetMoves (Board* board, const BoardPosition & position) {
  set<BoardPosition> moves;

  return moves;
}


bool Queen::Test (std::ostream & os) {
  bool success = true;

  return success;
}


Queen & Queen::copy (const Queen & queen) {
  if (this != &queen) {
    m_color = queen.m_color;
    m_type = queen.m_type;
  }

  return *this;
}

