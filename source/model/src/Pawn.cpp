#include <iostream>
#include <set>

#include "ChessGuiDefines.h"
#include "UnitTest.h"

#include "ChessColor.h"
#include "ChessMove.h"
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


set<ChessMove> Pawn::GetMoves (Board* board, BoardPosition* position) {
  set<ChessMove> moves;

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

