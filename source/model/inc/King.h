#ifndef _KING_H_
#define _KING_H_

#include <iostream>
#include <set>

#include "ChessGuiDefines.h"

#include "ChessColor.h"
#include "IPiece.h"

class King : public IPiece {
  public:

    /**
     *  Constructor
     *
     *  @param IN `c` The chess color of this piece
     *  @param IN `t` The type of this piece
     */
    King (ChessColor c, ImageName t);

    
    /**
     *  Copy constructor
     *
     *  @param IN `king` The King object to copy
     */
    King (const King & king);


    // Destructor
    virtual ~King ();


    /**
     *  Overloaded assignment operator
     *
     *  @param IN `king` The King object to copy
     *  @return A reference to this King object
     */
    King & operator = (const King & king);


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
     *  Helper function for overloaded = operator and copy constructor
     *
     *  @param IN `king` The King object to copy
     *  @return A reference to this King object
     */
    King & copy (const King & king);
}; 

#endif
