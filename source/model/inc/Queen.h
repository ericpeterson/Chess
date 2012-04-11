#ifndef _QUEEN_H_
#define _QUEEN_H_

#include <iostream>
#include <set>

#include "ChessGuiDefines.h"

#include "ChessColor.h"
#include "ChessMove.h"
#include "BoardPosition.h"
#include "IPiece.h"

class Queen: public IPiece {
  public:

    /**
     *  Constructor
     *
     *  @param IN `c` The color of this piece
     *  @param IN `t` The type of this piece
     */
    Queen (ChessColor c, ImageName t);


    /**
     *  Copy constructor
     *
     *  @param IN `queen` The Queen object to be copied
     */
    Queen (const Queen & queen);


    // Destructor
    virtual ~Queen ();


    /**
     *  Overloaded assignment operator
     *
     *  @param IN `queen` The Queen object to be copied
     *  @return A reference to this Queen object
     */
    Queen & operator = (const Queen & queen);
   

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
     *  Helper function for overloaded = operator and copy constructor
     * 
     *  @param IN `queen` The Queen object to be copied
     *  @return A reference to this Queen object
     */
    Queen & copy (const Queen & queen);
}; 

#endif

