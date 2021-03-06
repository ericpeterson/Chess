#include <map>

#include "ChessGuiDefines.h"

#include "BoardPosition.h"
#include "Board.h"
#include "IPiece.h"
#include "ChessColor.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "Pawn.h"

using namespace std;

Board::Board () {
  IPiece* bRookLeft = new Rook(BLACK, B_ROOK);
  IPiece* bRookRight = new Rook(BLACK, B_ROOK);
  IPiece* bKnightLeft = new Knight(BLACK, B_KNIGHT);
  IPiece* bKnightRight = new Knight(BLACK, B_KNIGHT);
  IPiece* bBishopLeft = new Bishop(BLACK, B_BISHOP);
  IPiece* bBishopRight = new Bishop(BLACK, B_BISHOP);
  IPiece* bQueen = new Queen(BLACK, B_QUEEN);
  IPiece* bKing = new King(BLACK, B_KING);

  IPiece* blackPawns[NUM_COL];
  for (int i = 0; i < NUM_COL; i++) {
    blackPawns[i] = new Pawn(BLACK, B_PAWN);
  }

  IPiece* wRookLeft = new Rook(WHITE, W_ROOK);
  IPiece* wRookRight = new Rook(WHITE, W_ROOK);
  IPiece* wKnightLeft = new Knight(WHITE, W_KNIGHT);
  IPiece* wKnightRight = new Knight(WHITE, W_KNIGHT);
  IPiece* wBishopLeft = new Bishop(WHITE, W_BISHOP);
  IPiece* wBishopRight = new Bishop(WHITE, W_BISHOP);
  IPiece* wQueen = new Queen(WHITE, W_QUEEN);
  IPiece* wKing = new King(WHITE, W_KING);

  IPiece* whitePawns[NUM_COL];
  for (int i = 0; i < NUM_COL; i++) {
    whitePawns[i] = new Pawn(WHITE, W_PAWN);
  }

  // Black piece board order
  IPiece* blackPieces [NUM_COL] = {bRookLeft, bKnightLeft, bBishopLeft,
    bQueen, bKing, bBishopRight, bKnightRight, bRookRight};

  // White piece board order
  IPiece* whitePieces [NUM_COL] = {wRookLeft, wKnightLeft, wBishopLeft,
    wQueen, wKing, wBishopRight, wKnightRight, wRookRight};

  for (int i = 0; i < NUM_COL; i++) {
    this->AddPiece(0, i, blackPieces[i]);
    this->AddPiece(7, i, whitePieces[i]);
    this->AddPiece(1, i, blackPawns[i]);
    this->AddPiece(6, i, whitePawns[i]);
  }
}


Board::Board (const std::map<BoardPosition, IPiece*> & newBoard) : m_board(newBoard) {}


Board::Board (const Board & board) {
  copy(board);
}


Board::~Board () {
  free();
}


Board & Board::operator = (const Board & board) {
  free();
  return copy(board);
}


IPiece* Board::PieceAtPosition (const short row, const short col) {
  BoardPosition position(row, col);
  IPiece* piece = NULL;

  if (m_board.count(position) > 0) {
    piece = m_board[position];
  }

  return piece;
}


bool Board::AddPiece (const short row, const short col, IPiece* piece) {
  if (NULL == piece) {
    return false;
  }

  pair<BoardPosition, IPiece*> position(BoardPosition(row, col), piece);
  pair<map<BoardPosition, IPiece*>::iterator, bool> resultPair =
    m_board.insert(position);

  bool result = resultPair.second;

  return result;
}


IPiece* Board::RemovePiece (const BoardPosition & position) {
  if (m_board.count(position) == 0) {
    return NULL;
  }

  IPiece* removedPiece = m_board[position];

  // Remove the piece from the map
  m_board.erase(position);

  return removedPiece;
}


map<BoardPosition, IPiece*> & Board::GetBoardMap () {
  return m_board;
}


Board & Board::copy (const Board & board) {
  if (this != &board) {
    m_board = board.m_board;
  }

  return *this;
}


void Board::free () {
  map<BoardPosition, IPiece*>::iterator it;
  map<BoardPosition, IPiece*>::iterator itEnd = m_board.end();

  for (it = m_board.begin(); it != itEnd; it++) {
    delete it->second;
  }
}

