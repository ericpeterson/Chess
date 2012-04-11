#include <set>

#include "HumanPlayer.h"
#include "IPiece.h"
#include "BoardPosition.h"
#include "IChessView.h"
#include "ChessMaster.h"

using namespace std;

HumanPlayer::HumanPlayer (ChessMaster* master, IChessView* view) {
  m_chessMaster = master;
  m_view = view;
  m_state = FirstClick;
}


void HumanPlayer::on_CellSelected (int row, int col, int button) {
  Board* board = m_chessMaster->GetBoard();

  BoardPosition position(row, col);
  set<BoardPosition> moves;

  switch (m_state) {
    case FirstClick:
      m_piece = board->PieceAtPosition(row, col);

      if (NULL == m_piece) {
        return;
      }

      m_position = position;
      moves = m_piece->GetMoves(board, position);
      this->SetLegalMoves(moves);
      this->HighlightLegalMoves();
      m_state = SecondClick;
      break;
    case SecondClick:
      if (IsInLegalMoves(row, col) && !HasFriendlyPiece(row, col) &&
        !LeaveInCheck(row, col)) {

        IPiece* removedPiece = NULL;
        if (HasEnemyPiece(row, col)) {
          removedPiece = board->RemovePiece(BoardPosition(row, col));
        }

        board->RemovePiece(m_position);
        board->AddPiece(row, col, m_piece);
        this->AddToHistory(row, col, removedPiece);

        // Change turns
        m_chessMaster->ToggleTurn();
        this->DisplayTurn();
      }

      this->UnHighlightLegalMoves();

      m_state = FirstClick;
      break;
  }
}


void HumanPlayer::on_TimerEvent() {}


void HumanPlayer::SetView (IChessView* m_pView) {
  m_view = m_pView;
}

