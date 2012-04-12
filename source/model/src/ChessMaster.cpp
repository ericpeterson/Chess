#include <map>
#include <stack>

#include "ChessColor.h"
#include "Board.h"
#include "History.h"
#include "ChessMaster.h"

using namespace std;

ChessMaster::ChessMaster () : m_board(NULL), m_history(NULL), m_turn(WHITE) {
  m_board = new Board();
  m_history = new History();
}


ChessMaster::ChessMaster (map<BoardPosition, IPiece*> newBoard,
  stack<ChessMove>* newHistory) : m_board(NULL), m_history(NULL), m_turn(WHITE) {
  m_board = new Board(newBoard);
  m_history = new History(newHistory);
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


void ChessMaster::Undo () {
  ChessMove lastMove = m_history->pop();
  int row = lastMove.m_originalPosition.GetRow();
  int col = lastMove.m_originalPosition.GetCol();
  int rowTaken = lastMove.m_finalPosition.GetRow();
  int colTaken = lastMove.m_finalPosition.GetCol();

  m_board->RemovePiece(lastMove.m_finalPosition);
  m_board->AddPiece(row, col, lastMove.m_movedPiece);
  m_board->AddPiece(rowTaken, colTaken, lastMove.m_takenPiece);
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
