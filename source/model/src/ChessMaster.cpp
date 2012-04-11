#include "Board.h"
#include "ChessColor.h"
#include "History.h"
#include "ChessMaster.h"

ChessMaster::ChessMaster () : m_board(NULL), m_history(NULL), m_turn(WHITE) {
  m_board = new Board();
  m_history = new History();
}


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


History* ChessMaster::GetHistory () const {
  return m_history;
}


ChessColor ChessMaster::GetTurn () const {
  return m_turn;
}


void ChessMaster::ToggleTurn () {
  if (WHITE == m_turn) {
    m_turn = BLACK;
  } else if (BLACK == m_turn) {
    m_turn = WHITE;
  }
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
  delete m_history;

  m_board = NULL;
  m_history = NULL;
}
