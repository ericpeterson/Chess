#ifndef _KNIGHT_H_
#define _KNIGHT_H_

#include <iostream>
#include <set>

#include "ChessGuiDefines.h"

#include "ChessColor.h"
#include "ChessMove.h"
#include "BoardPosition.h"

class Knight: public IPiece {
  public:

    /**
     *  Constructor
     *
     *  @param IN `c` The color of this piece
     *  @param IN `t` The type of this piece
     */
    Knight (ChessColor c, ImageName t);


    /**
     *  Copy constructor
     *
     *  @param IN `knight` The Knight object to be copied
     */
    Knight (const Knight & knight);


    // Destructor
    virtual ~Knight ();


    /**
     *  Overloaded assignment operator
     *
     *  @param IN `knight` The Knight object to be copied
     *  @return A reference to this Knight
     */
    Knight & operator = (const Knight & knight);


    /**
     *  Gets all the legal moves of this piece
     *
     *  @param IN `board` A pointer to the current board
     *  @param IN `position` A pointer to this piece's position
     *  @return The set fo all legal moves
     */
    virtual std::set<BoardPosition> GetMoves (Board* board, const BoardPosition & position);


    /**
     *  Unit test for this class
     *
     *  @return true if all tests pass; false otherwise
     */
    static bool Test (std::ostream & os);

  private:

    /**
     *  Helper function for overloaded = and copy constructor
     *
     *  @param IN `knight` The Knight object to be copied
     *  @return A reference to this Knight
     */
    Knight & copy (const Knight & knight);
}; 

#endif
