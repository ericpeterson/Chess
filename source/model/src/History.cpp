#include <stack>

#include "CS240Exception.h"

#include "ChessMove.h"
#include "History.h"

using namespace std;

History::History (): m_history(NULL) {
  m_history = new stack<ChessMove>();
}


History::History (const History & history) {
  copy(history);
}


History::~History () {
  free();
}


History & History::operator = (const History & history) {
  free();
  return copy(history);
}


bool History::IsEmpty () const {
  return m_history->empty();
}


const ChessMove & History::pop () {
  if (this->IsEmpty()) {
    throw CS240Exception("Cannot pop an empty history."); 
  }

  this->UpdateLastMove();
  m_history->pop();

  return m_lastMove;
}


void History::push (const ChessMove & move) {
  m_history->push(move);
}


void History::UpdateLastMove () {
  m_lastMove = m_history->top();
}


History & History::copy (const History & history) {
  if (this != &history) {
    m_history = history.m_history;
  }

  return *this;
}


void History::free () {
  delete m_history;
}

