#ifndef _BOARD_H_
#define _BOARD_H_

#include <map>

#include "ChessGuiDefines.h"

#include "BoardPosition.h"
#include "IPiece.h"

class IPiece;

class Board {
  public:

    // Default constructor
    Board ();


    Board (const std::map<BoardPosition, IPiece*> & newBoard);


    /**
     *  Copy constructor
     *
     *  @param IN `board` The Board object to be copied
     */
    Board (const Board & board);


    // Destructor
    ~Board ();


    /**
     *  Overloaded assignment operator
     *
     *  @param IN `board` The Board object to be copied
     *  @return A reference to this Board object.
     */
    Board & operator = (const Board & board);


    /**
     *  Returns the chess piece at a given board location
     *
     *  @param IN `row` The row of the board position
     *  @param IN `col` The column of the board position
     *  @return The piece at the board position; NULL if no piece at position
     */ 
    IPiece* PieceAtPosition (const short row, const short col);


    /**
     *  Adds a piece to the board
     *
     *  @param IN `row` The row of the board position
     *  @param IN `col` The column of the board position
     *  @param IN `piece` The piece to add to the board
     *  @return true if the piece was successfully added to the board; false
     *    otherwise.
     */
    bool AddPiece (const short row, const short col, IPiece* piece);


    /**
     *  Removes a piece from the board
     *
     *  @param IN `position` The position of the piece to remove
     *  @return true if the piece was successfully removed from the board;
     *    false otherwise.
     */
    IPiece* RemovePiece (const BoardPosition & position);


    // @return The map representation of this board
    std::map<BoardPosition, IPiece*> & GetBoardMap ();

  private:

    // A mapping of piece location (Square) to each game piece
    std::map<BoardPosition, IPiece*> m_board;


    /**
     *  Helper function for overloaded assignment operator and copy constructor
     *
     *  @param IN `board` The Board object to be copied
     *  @return A reference to this Board object.
     */
    Board & copy (const Board & board);

    
    /**
     *  Deletes heap memory used by this Board object
     */
    void free ();
};

#endif
