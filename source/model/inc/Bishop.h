#ifndef _BISHOP_H_
#define _BISHOP_H_

#include <iostream>
#include <set>

#include "ChessGuiDefines.h"

#include "ChessColor.h"
#include "ChessMove.h"
#include "IPiece.h"

class Bishop : public IPiece {
  public:

    /**
     *  Constructor
     *
     *  @param IN `c` The color of this piece
     *  @param IN `t` The type of this piece
     */
    Bishop (ChessColor c, ImageName t);


    /**
     *  Copy constructor
     *
     *  @param IN `bishop` The Bishop object to be copied
     */
    Bishop (const Bishop & bishop);


    // Destructor
    virtual ~Bishop ();


    /**
     *  Overloaded assignment operator
     *
     *  @param IN `bishop` The Bishop object to be copied
     *  @return A reference to this Bishop
     */
    Bishop & operator = (const Bishop & bishop);


    /**
     *  Gets all the legal moves of this piece
     *
     *  @param IN `board` A pointer to the current board
     *  @param IN `position` A pointer to this piece's position
     *  @return The set fo all legal moves
     */
    virtual std::set<ChessMove> GetMoves (Board* board, BoardPosition* position);


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
     *  @param IN `bishop` The Bishop object to be copied
     *  @return A reference to this Bishop
     */
    Bishop & copy (const Bishop & bishop);
}; 

#endif
