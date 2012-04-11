#ifndef _IPIECE_H_
#define _IPIECE_H_

#include <iostream>
#include <set>

#include "ChessGuiDefines.h"

#include "ChessColor.h"
#include "ChessMove.h"
#include "Board.h"
#include "BoardPosition.h"

class Board;
struct ChessMove;

class IPiece {
  public:

    // Destructor
    virtual ~IPiece () {};


    /**
     *  Gets all the legal moves of this piece
     *
     *  @param IN `board` A pointer to the current board
     *  @param IN `position` A pointer to this piece's position
     *  @return The set fo all legal moves
     */
    virtual std::set<ChessMove> GetMoves (Board* board, BoardPosition* position) = 0;


    /**
     *  Unit test for this class
     *
     *  @return true if all tests pass; false otherwise
     */
    static bool Test (std::ostream & os);


    // @return The type of this piece
    virtual ImageName GetType () const {
      return m_type;
    }; 


    // @return The color of this piece
    virtual ChessColor GetColor () const {
      return m_color;
    }

  protected:

    // This piece's color 
    ChessColor m_color;

    // This piece's type
    ImageName m_type;
}; 

#endif
