#include <iostream>
#include <set>

#include "ChessGuiDefines.h"

#include "ChessColor.h"
#include "ChessMove.h"
#include "BoardPosition.h"
#include "IPiece.h"
#include "Bishop.h"

using namespace std;


Bishop::Bishop (ChessColor c, ImageName t) {
  m_color = c;
  m_type = t;
}


Bishop::Bishop (const Bishop & bishop) {
  copy(bishop);
}


Bishop::~Bishop () {}


Bishop & Bishop::operator = (const Bishop & bishop) {
  return copy(bishop);
}


set<BoardPosition> Bishop::GetMoves (Board* board, const BoardPosition & position) {
  set<BoardPosition> moves;

  return moves;
}


bool Bishop::Test (std::ostream & os) {
  bool success = true;

  return success;
}


Bishop & Bishop::copy (const Bishop & bishop) {
  if (this != &bishop) {
    m_color = bishop.m_color;
    m_type = bishop.m_type;
  }

  return *this;
}

