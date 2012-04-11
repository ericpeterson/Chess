#include <cassert>

#include "ChessGuiDefines.h"

#include "Square.h"
#include "BoardPosition.h"

BoardPosition::BoardPosition () {}

BoardPosition::BoardPosition (short row, short col) : m_positionSquare(row, col) {}


BoardPosition::BoardPosition (const BoardPosition & boardPosition) {
  copy(boardPosition);
}


BoardPosition::~BoardPosition () {}


BoardPosition & BoardPosition::operator = (const BoardPosition & boardPosition) {
  return copy(boardPosition);
}


bool BoardPosition::operator < (const BoardPosition & boardPosition) const {
  int thisValue = (m_positionSquare.row * NUM_COL) + m_positionSquare.col;
  int otherValue = (boardPosition.m_positionSquare.row * NUM_COL) +
    boardPosition.m_positionSquare.col;

  return thisValue < otherValue;
}


bool BoardPosition::operator == (const BoardPosition & boardPosition) const {
  int thisValue = (m_positionSquare.row * NUM_COL) + m_positionSquare.col;
  int otherValue = (boardPosition.m_positionSquare.row * NUM_COL) +
    boardPosition.m_positionSquare.col;

  return thisValue == otherValue;
}


BoardPosition BoardPosition::MoveUp (const short numTimes) {
  short newRow = m_positionSquare.row - numTimes;
  short newCol = m_positionSquare.col;

  // we can't move off the board
  if (newRow < 0) {
    return *this;
  } else {
    BoardPosition newPosition(newRow, newCol);
    return newPosition;
  }
}


BoardPosition BoardPosition::MoveDown (const short numTimes) {
  short newRow = m_positionSquare.row + numTimes;
  short newCol = m_positionSquare.col;

  // we can't move off the board
  if (newRow > (NUM_ROW - 1)) {
    return *this;
  } else {
    BoardPosition newPosition(newRow, newCol);
    return newPosition;
  }
}


BoardPosition BoardPosition::MoveLeft (const short numTimes) {
  short newCol = m_positionSquare.col - numTimes;
  short newRow = m_positionSquare.row;

  // we can't move off the board
  if (newCol < 0) {
    return *this;
  } else {
    BoardPosition newPosition(newRow, newCol);
    return newPosition;
  }
}


BoardPosition BoardPosition::MoveRight (const short numTimes) {
  short newCol = m_positionSquare.col + numTimes;
  short newRow = m_positionSquare.row;

  // we can't move off the board
  if (newCol > (NUM_COL - 1)) {
    return *this;
  } else {
    BoardPosition newPosition(newRow, newCol);
    return newPosition;
  }
}


BoardPosition BoardPosition::MoveUpLeft (const short numTimes) {
  short newRow = m_positionSquare.row - numTimes;
  short newCol = m_positionSquare.col - numTimes;

  if (newRow < 0 || newCol < 0) {
    return *this;
  } else {
    BoardPosition newPosition(newRow, newCol);
    return newPosition;
  }
}


BoardPosition BoardPosition::MoveUpRight (const short numTimes) {
  short newRow = m_positionSquare.row - numTimes;
  short newCol = m_positionSquare.col + numTimes;

  if (newRow < 0 || newCol > (NUM_COL - 1)) {
    return *this;
  } else {
    BoardPosition newPosition(newRow, newCol);
    return newPosition;
  }
}


BoardPosition BoardPosition::MoveDownLeft (const short numTimes) {
  short newRow = m_positionSquare.row + numTimes;
  short newCol = m_positionSquare.col - numTimes;

  if (newRow > (NUM_ROW - 1) || newCol < 0) {
    return *this;
  } else {
    BoardPosition newPosition(newRow, newCol);
    return newPosition;
  }
}


BoardPosition BoardPosition::MoveDownRight (const short numTimes) {
  short newRow = m_positionSquare.row + numTimes;
  short newCol = m_positionSquare.col + numTimes;

  if (newRow > (NUM_ROW - 1) || newCol > (NUM_COL - 1)) {
    return *this;
  } else {
    BoardPosition newPosition(newRow, newCol);
    return newPosition;
  }
}


short BoardPosition::GetRow () {
  return m_positionSquare.row;
}


short BoardPosition::GetCol () {
  return m_positionSquare.col;
}


BoardPosition & BoardPosition::copy (const BoardPosition & boardPosition) {
  if (this != &boardPosition) {
    m_positionSquare = boardPosition.m_positionSquare;
  }

  return *this;
}
