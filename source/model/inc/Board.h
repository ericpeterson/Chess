#ifndef _BOARD_H_
#define _BOARD_H_

#include <map>

#include "ChessGuiDefines.h"

#include "BoardPosition.h"

class Board {
  public:

    // Default constructor
    Board ();


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
     *  @return The piece at the board position
     */ 
    ImageName PieceAtPosition (const short row, const short col);


    /**
     *  Adds a piece to the board
     *
     *  @param IN `row` The row of the board position
     *  @param IN `col` The column of the board position
     *  @param IN `piece` The piece to add to the board
     *  @return true if the piece was successfully added to the board; false
     *    otherwise.
     */
    bool AddPiece (const short row, const short col, const ImageName & piece);


    /**
     *  Removes a piece from the board
     *
     *  @param IN `piece` The piece to remove from the board
     *  @return true if the piece was successfully removed from the board;
     *    false otherwise.
     */
    bool RemovePiece (const ImageName & piece);


    // @return The map representation of this board
    std::map<BoardPosition, ImageName> & GetBoardMap ();

  private:

    // A mapping of piece location (Square) to each game piece
    std::map<BoardPosition, ImageName> m_board;


    /**
     *  Helper function for overloaded assignment operator and copy constructor
     *
     *  @param IN `board` The Board object to be copied
     *  @return A reference to this Board object.
     */
    Board & copy (const Board & board);
};

#endif
