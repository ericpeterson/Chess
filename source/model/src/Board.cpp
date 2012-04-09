#include <map>

#include "ChessGuiDefines.h"

#include "BoardPosition.h"
#include "Board.h"

using namespace std;

Board::Board () {
  // Black piece board order
  const ImageName blackPieces [NUM_COL] = {B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN,
    B_KING, B_BISHOP, B_KNIGHT, B_ROOK};

  // White piece board order
  const ImageName whitePieces [NUM_COL] = {W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN,
    W_KING, W_BISHOP, W_KNIGHT, W_ROOK};

  for (int i = 0; i < NUM_COL; i++) {
    Board::AddPiece(0, i, blackPieces[i]);
    Board::AddPiece(7, i, whitePieces[i]);
    Board::AddPiece(1, i, B_PAWN);
    Board::AddPiece(6, i, W_PAWN);
  }
}


Board::Board (const Board & board) {
  copy(board);
}


Board::~Board () {}


Board & Board::operator = (const Board & board) {
  return copy(board);
}


ImageName Board::PieceAtPosition (const short row, const short col) {
  BoardPosition position(row, col);

  return m_board[position];
}


bool Board::AddPiece (const short row, const short col, const ImageName & piece) {
  pair<BoardPosition, ImageName> position(BoardPosition(row, col), piece);
  pair<map<BoardPosition, ImageName>::iterator, bool> resultPair =
    m_board.insert(position);

  bool result = resultPair.second;

  return result;
}


bool Board::RemovePiece (const ImageName & piece) {

  // start with an invalid board position
  BoardPosition positionOfPiece(-1, -1);
  map<BoardPosition, ImageName>::iterator it;
  map<BoardPosition, ImageName>::iterator endIt = m_board.end();

  for (it = m_board.begin(); it != endIt; it++) {
    if (it->second == piece) {
      positionOfPiece = it->first;
      break;
    }
  }

  short resultCount = m_board.erase(positionOfPiece);
  bool result = true;

  // The piece was not in the map if the count is 0
  if (resultCount == 0) {
    result = false;
  } else {
    result = true;
  }

  return result;
}


map<BoardPosition, ImageName> & Board::GetBoardMap () {
  return m_board;
}


Board & Board::copy (const Board & board) {
  if (this != &board) {
    m_board = board.m_board;
  }

  return *this;
}

