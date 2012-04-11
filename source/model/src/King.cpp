#include <iostream>
#include <set>

#include "ChessGuiDefines.h"
#include "UnitTest.h"

#include "ChessColor.h"
#include "IPiece.h"
#include "King.h"

using namespace std;

King::King (ChessColor c, ImageName t) {
  m_color = c;
  m_type = t;
}


King::King (const King & king) {
  copy(king);
}


King::~King () {}


King & King::operator = (const King & king) {
  return copy(king);
}


set<ChessMove> King::GetMoves (Board* board, BoardPosition* position) {
  set<ChessMove> moves;

  return moves;
}


bool King::Test (std::ostream & os) {
  bool success = true;

  return success;
}


King & King::copy (const King & king) {
  if (this != &king) {
    m_color = king.m_color;
    m_type = king.m_type;
  }

  return *this;
}

