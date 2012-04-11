#include <iostream>
#include <set>

#include "ChessGuiDefines.h"

#include "ChessColor.h"
#include "ChessMove.h"
#include "BoardPosition.h"
#include "Knight.h"

using namespace std;

Knight::Knight (ChessColor c, ImageName t) {
  m_color = c;
  m_type = t;
}


Knight::Knight (const Knight & knight) {
  copy(knight);
}


Knight::~Knight () {}


Knight & Knight::operator = (const Knight & knight) {
  return copy(knight);
}


std::set<BoardPosition> Knight::GetMoves (Board* board, const BoardPosition & position) {
  set<BoardPosition> moves;

  return moves;
}


bool Knight::Test (std::ostream & os) {
  bool success = true;  

  return success;
}


Knight & Knight::copy (const Knight & knight) {
  if (this != &knight) {
    m_color = knight.m_color;
    m_type = knight.m_type;
  }

  return *this; 
}

