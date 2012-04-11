#ifndef _CHESS_MASTER_H_
#define _CHESS_MASTER_H_

#include <map>
#include <stack>

#include "Board.h"
#include "ChessColor.h"
#include "History.h"

class ChessMaster {
  public:

    // Default constructor
    ChessMaster ();


    ChessMaster (std::map<BoardPosition, IPiece*> newBoard,
      std::stack<ChessMove>* newHistory);


    /**
     *  Copy constructor
     *
     *  @param IN `chessMaster` The ChessMaster object to copy
     */
    ChessMaster (const ChessMaster & chessMaster);


    // Destructor
    ~ChessMaster ();


    /**
     *  Overloaded assignment operator
     *  
     *  @param IN `chessMaster` The ChessMaster object to copy
     *  @return A reference to this ChessMaster object
     */
    ChessMaster & operator = (const ChessMaster & chessMaster);


    /**
     *  Determines whether the game is a checkmate
     *
     *  @return true if the game is a checkmate; false otherwise
     */
    bool IsCheckMate ();


    /**
     *  Determines whether the game is a stalemate
     *
     *  @return true if the game is a stalemate; false otherwise
     */
    bool IsStaleMate ();


    // @return A pointer to the current chess board
    Board* GetBoard () const;


    // @return A pointer to the move history
    History* GetHistory () const;

    // @return BLACK if is the black player's turn; WHITE if it is the white
    // player's turn.
    ChessColor GetTurn () const;


    /**
     *  Toggles the turns from WHITE to BLACK and vice versa
     */
    void ToggleTurn ();

  private:

    // The current board layout
    Board* m_board;

    // The move history
    History* m_history;

    // Keeps tracks of whose turn it is
    ChessColor m_turn;


    /**
     *  Helper function for overloaded assignment operator and copy constructor
     *
     *  @param IN `chessMaster` The ChessMaster object to be copied
     */
    ChessMaster & copy (const ChessMaster & chessMaster);


    /**
     *  Helper function for overloaded assignment operator and destructor.
     *  Frees heap memory used by this ChessMaster object.
     */
    void free ();
};

#endif
