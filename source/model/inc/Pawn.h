#ifndef _PAWN_H_
#define _PAWN_H_

#include <iostream>
#include <set>

#include "ChessGuiDefines.h"

#include "ChessColor.h"
#include "ChessMove.h"
#include "BoardPosition.h"


class Pawn: public IPiece {
  public:

    /**
     *  Constructor
     *
     *  @param IN `c` The color of this piece
     *  @param IN `t` The type of this piece
     */
    Pawn (ChessColor c, ImageName t);


    /**
     *  Copy constructor
     *
     *  @param IN `pawn` The Pawn object to be copied
     */
    Pawn (const Pawn & pawn);
   

    // Destructor
    virtual ~Pawn ();


    /**
     *  Overloaded assignment operator
     *
     *  @param IN `pawn` The Pawn object to be copied
     *  @return A reference to this Pawn
     */
    Pawn & operator = (const Pawn & pawn);


    /**
     *  Gets all the legal moves of this piece
     *
     *  @param IN `board` A pointer to the current board
     *  @param IN `position` A pointer to this piece's position
     *  @return The set fo all legal moves
     */
    virtual std::set<BoardPosition> GetMoves (Board* board, BoardPosition & position);


    /**
     *  Unit test for this class
     *
     *  @return true if all tests pass; false otherwise
     */
    static bool Test (std::ostream & os);


    virtual bool IsPieceAtPosition (int row, int col, Board* board);
  private:

    /**
     *  Helper function for overloaded = and copy constructor
     *
     *  @param IN `pawn` The Pawn object to be copied
     *  @return A reference to this Pawn
     */
    Pawn & copy (const Pawn & pawn);
}; 

#endif
