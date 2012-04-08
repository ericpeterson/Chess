#include "Board.h"
#include "ChessColor.h"
#include "ChessMaster.h"


ChessMaster::ChessMaster () : m_board(new Board()), m_turn(WHITE) {}


ChessMaster::ChessMaster (const ChessMaster & chessMaster) {
  copy(chessMaster);
}


ChessMaster::~ChessMaster () {
  free();
}


ChessMaster & ChessMaster::operator = (const ChessMaster & chessMaster) {
  free();
  return copy(chessMaster);
}


bool ChessMaster::IsCheckMate () {
  return true;
}


bool ChessMaster::IsStaleMate () {
  return true;
}


Board* ChessMaster::GetBoard () const {
  return m_board;
}


ChessColor ChessMaster::GetTurn () const {
  return m_turn;
}


ChessMaster & ChessMaster::copy (const ChessMaster & chessMaster) {
  if (this != &chessMaster) {
    m_board = chessMaster.m_board;
    m_turn = chessMaster.m_turn;
  }

  return *this;
}


void ChessMaster::free () {
  delete m_board;
}
