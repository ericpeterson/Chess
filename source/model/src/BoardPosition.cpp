#include <cassert>

#include "ChessGuiDefines.h"

#include "Square.h"
#include "BoardPosition.h"

BoardPosition::BoardPosition () {}

BoardPosition::BoardPosition (const short row, const short col) : m_positionSquare(row, col) {}


BoardPosition::BoardPosition (const BoardPosition & boardPosition) {
  copy(boardPosition);
}


BoardPosition::~BoardPosition () {}


BoardPosition & BoardPosition::operator = (const BoardPosition & boardPosition) {
  return copy(boardPosition);
}


bool BoardPosition::operator < (const BoardPosition & boardPosition) const {
  return true;
}


bool BoardPosition::MoveUp (const short numTimes) {
  bool wasMoved = true;
  short newPosition = m_positionSquare.row - numTimes;

  // we can't move off the board
  if (newPosition < 0) {
    wasMoved = false;
  } else {
    m_positionSquare.row = newPosition;
  }

  return wasMoved;
}


bool BoardPosition::MoveDown (const short numTimes) {
  bool wasMoved = true;
  short newPosition = m_positionSquare.row + numTimes;

  // we can't move off the board
  if (newPosition > (NUM_ROW - 1)) {
    wasMoved = false;
  } else {
    m_positionSquare.row = newPosition;
  }

  return wasMoved;
}


bool BoardPosition::MoveLeft (const short numTimes) {
  bool wasMoved = true;
  short newPosition = m_positionSquare.col - numTimes;

  // we can't move off the board
  if (newPosition < 0) {
    wasMoved = false;
  } else {
    m_positionSquare.col = newPosition;
  }

  return wasMoved;
}


bool BoardPosition::MoveRight (const short numTimes) {
  bool wasMoved = true;
  short newPosition = m_positionSquare.col + numTimes;

  // we can't move off the board
  if (newPosition > (NUM_COL - 1)) {
    wasMoved = false;
  } else {
    m_positionSquare.col = newPosition;
  }

  return wasMoved;
}


bool BoardPosition::MoveUpLeft (const short numTimes) {
  bool wasMoved = true;
  short newPositionRow = m_positionSquare.row - numTimes;
  short newPositionCol = m_positionSquare.col - numTimes;

  if (newPositionRow < 0 || newPositionCol < 0) {
    wasMoved = false;
  } else {
    bool upResult = BoardPosition::MoveUp(numTimes);
    bool leftResult = BoardPosition::MoveLeft(numTimes);
    assert(upResult);
    assert(leftResult);
  }

  return wasMoved;
}


bool BoardPosition::MoveUpRight (const short numTimes) {
  bool wasMoved = true;
  short newPositionRow = m_positionSquare.row - numTimes;
  short newPositionCol = m_positionSquare.col + numTimes;

  if (newPositionRow < 0 || newPositionCol > (NUM_COL - 1)) {
    wasMoved = false;
  } else {
    bool upResult = BoardPosition::MoveUp(numTimes);
    bool rightResult = BoardPosition::MoveRight(numTimes);
    assert(upResult);
    assert(rightResult);
  }

  return wasMoved;
}


bool BoardPosition::MoveDownLeft (const short numTimes) {
  bool wasMoved = true;
  short newPositionRow = m_positionSquare.row + numTimes;
  short newPositionCol = m_positionSquare.col - numTimes;

  if (newPositionRow > (NUM_ROW - 1) || newPositionCol < 0) {
    wasMoved = false;
  } else {
    bool downResult = BoardPosition::MoveDown(numTimes);
    bool leftResult = BoardPosition::MoveLeft(numTimes);
    assert(downResult);
    assert(leftResult);
  }
  
  return wasMoved;
}


bool BoardPosition::MoveDownRight (const short numTimes) {
  bool wasMoved = true;
  short newPositionRow = m_positionSquare.row + numTimes;
  short newPositionCol = m_positionSquare.col + numTimes;

  if (newPositionRow > (NUM_ROW - 1) || newPositionCol > (NUM_COL - 1)) {
    wasMoved = false;
  } else {
    bool downResult = BoardPosition::MoveDown(numTimes);
    bool rightResult = BoardPosition::MoveRight(numTimes);
    assert(downResult);
    assert(rightResult);
  }

  return wasMoved;
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
