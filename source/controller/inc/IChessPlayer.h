#ifndef I_CHESS_PLAYER_H
#define I_CHESS_PLAYER_H

#include <set>
#include <string>

#include "Board.h"
#include "BoardPosition.h"
#include "IChessView.h"
#include "IPiece.h"
#include "ChessGuiDefines.h"
#include "ChessMaster.h"

enum State {FirstClick, SecondClick};

/**
 * The IChessPlayer class provides an interface for a ChessController implementation to interact
 * with the player through, regardless of whether the player is a human or a computer.
 */
class IChessPlayer
{
  public: //methods
    /**
     * Indicate to the player that the user clicked on the given
     * row and column with the mouse.
     */
    virtual void on_CellSelected(int row, int col, int button) = 0;

    /**
     * Handle when the timeout duration has passed.
     */
    virtual void on_TimerEvent() = 0;


    // @return A pointer to the ChessMaster
    virtual ChessMaster* GetChessMaster () {
      return m_chessMaster;
    } 


    // Displays the current turn on the GUI
    virtual void DisplayTurn () {
      std::string label;
      ChessColor turn = m_chessMaster->GetTurn();

      if (WHITE == turn) {
        label = "White's Turn";
      } else if (BLACK == turn) {
        label = "Black's Turn";
      }

      m_view->SetTopLabel(label);
    }

  protected:
    
    // pointer to the board
    ChessMaster* m_chessMaster;

    // pointer to the GUI
    IChessView* m_view;

    // Click state -- requires two clicks to move a piece
    State m_state;

    // Board position of current piece
    BoardPosition m_position;

    // pointer to the current piece
    IPiece* m_piece;

    // Set of currently legal moves
    std::set<BoardPosition> m_legalMoves;

  public:

    /**
     *  Sets the legal moves
     *
     *  @param IN `moves` The new set of legal moves
     */
    void SetLegalMoves (std::set<BoardPosition> moves) {
      m_legalMoves = moves;
    }


    /**
     *  Highlights all legal moves on the GUI
     */
    void HighlightLegalMoves () {
      std::set<BoardPosition>::iterator it;
      std::set<BoardPosition>::iterator itEnd = m_legalMoves.end();

      for (it = m_legalMoves.begin(); it != itEnd; it++) {
        BoardPosition current = *it;
        int row = current.GetRow();
        int col = current.GetCol();

        m_view->HighlightSquare(row, col, WHITE_SQUARE);
      }

      m_view->HighlightSquare(m_position.GetRow(), m_position.GetCol(), WHITE_SQUARE);
    }

  
    /**
     *  UnHighlights all legal moves on the GUI
     */
    void UnHighlightLegalMoves () {
      std::set<BoardPosition>::iterator it;
      std::set<BoardPosition>::iterator itEnd = m_legalMoves.end();

      for (it = m_legalMoves.begin(); it != itEnd; it++) {
        BoardPosition current = *it;
        int row = current.GetRow();
        int col = current.GetCol();

        m_view->UnHighlightSquare(row, col);
      }

      m_view->UnHighlightSquare(m_position.GetRow(), m_position.GetCol());
    }


    bool IsInLegalMoves (int row, int col) {
      BoardPosition position(row, col);
      bool isInLegalMoves = false;

      if (m_legalMoves.count(position) > 0) {
        isInLegalMoves = true;
      }

      return isInLegalMoves;
    }


    bool HasFriendlyPiece (int row, int col) {
      ChessColor friendlyColor = m_piece->GetColor();
      IPiece* currentPiece = m_chessMaster->GetBoard()->PieceAtPosition(row, col);

      if (NULL == currentPiece) {
        return false;
      }

      ChessColor currentColor = currentPiece->GetColor();

      bool hasFriendlyPiece = false;

      if (friendlyColor == currentColor) {
        hasFriendlyPiece = true;
      }
    
      return hasFriendlyPiece;
    }


    bool HasEnemyPiece (int row, int col) {
      ChessColor friendlyColor = m_piece->GetColor();
      IPiece* currentPiece = m_chessMaster->GetBoard()->PieceAtPosition(row, col);

      if (NULL == currentPiece) {
        return false;
      }

      ChessColor currentColor = currentPiece->GetColor();

      bool hasEnemyPiece = false;

      if (friendlyColor != currentColor) {
        hasEnemyPiece = true;
      }
    
      return hasEnemyPiece;
    }


    bool LeaveInCheck (int row, int col) {
      return false;
    }


    void AddToHistory (int row, int col, IPiece* removedPiece) {
      History* history = m_chessMaster->GetHistory();
      ChessMove move;
      BoardPosition finalPosition(row, col);

      move.m_movedPiece = m_piece;
      move.m_originalPosition = m_position;
      move.m_finalPosition = finalPosition;
      move.m_takenPiece = removedPiece;
      move.m_takenPosition = finalPosition;

      history->push(move);
    }

    virtual void SetView (IChessView* m_pView) = 0;
};

#endif
