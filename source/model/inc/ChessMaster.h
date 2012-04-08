#ifndef _CHESS_MASTER_H_
#define _CHESS_MASTER_H_

#include "Board.h"
#include "ChessColor.h"

class ChessMaster {
  public:

    // Default constructor
    ChessMaster ();


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


    // @return BLACK if is the black player's turn; WHITE if it is the white
    // player's turn.
    ChessColor GetTurn () const;

  private:

    // The current board layout
    Board* m_board;

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
