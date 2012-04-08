#ifndef _BOARD_POSITION_H_
#define _BOARD_POSITION_H_

#include "Square.h"

class BoardPosition {
  public:

    // Default constructor
    BoardPosition ();


    /**
     *  Constructor
     *
     *  @param IN `row` The row of the board position
     *  @param IN `col` The column of the board position
     */
    BoardPosition (const short row, const short col);


    /**
     *  Copy constructor
     *
     *  @param IN `boardPosition` The BoardPosition object to copy
     */
    BoardPosition (const BoardPosition & boardPosition);


    // Destructor
    ~BoardPosition ();


    /**
     *  Overloaded assignment operator
     *
     *  @param IN `boardPosition` The BoardPosition object to copy
     *  @return A reference to this BoardPosition object
     */
    BoardPosition & operator = (const BoardPosition & boardPosition);

    /**
     *  Overloaded less than operator
     *
     *  @param IN `boardPosition` The BoardPosition object to copy
     *  @return true if this BoardPosition is less than `boardPosition`; false
     *    otherwise.
     */
    bool operator < (const BoardPosition & boardPosition) const;


    /**
     *  Translates this boards position up a number of squares
     *
     *  @param IN `numTimes` The number of times to move this board position
     *  @return true if the position was successfully translated; false
     *    otherwise.
     */
    bool MoveUp (const short numTimes);


    /**
     *  Translates this boards position down a number of squares
     *
     *  @param IN `numTimes` The number of times to move this board position
     *  @return true if the position was successfully translated; false
     *    otherwise.
     */
    bool MoveDown (const short numTimes);


    /**
     *  Translates this boards position left a number of squares
     *
     *  @param IN `numTimes` The number of times to move this board position
     *  @return true if the position was successfully translated; false
     *    otherwise.
     */
    bool MoveLeft (const short numTimes);


    /**
     *  Translates this boards position right a number of squares
     *
     *  @param IN `numTimes` The number of times to move this board position
     *  @return true if the position was successfully translated; false
     *    otherwise.
     */
    bool MoveRight (const short numTimes);


    /**
     *  Translates this boards position up and left a number of squares
     *
     *  @param IN `numTimes` The number of times to move this board position
     *  @return true if the position was successfully translated; false
     *    otherwise.
     */
    bool MoveUpLeft (const short numTimes);


    /**
     *  Translates this boards position up and right a number of squares
     *
     *  @param IN `numTimes` The number of times to move this board position
     *  @return true if the position was successfully translated; false
     *    otherwise.
     */
    bool MoveUpRight (const short numTimes);


    /**
     *  Translates this boards position down and left a number of squares
     *
     *  @param IN `numTimes` The number of times to move this board position
     *  @return true if the position was successfully translated; false
     *    otherwise.
     */
    bool MoveDownLeft (const short numTimes);


    /**
     *  Translates this boards position down and right a number of squares
     *
     *  @param IN `numTimes` The number of times to move this board position
     *  @return true if the position was successfully translated; false
     *    otherwise.
     */
    bool MoveDownRight (const short numTimes);

  private:
  
    // row-column pair
    Square m_positionSquare;


    /**
     *  Helper function for overloaded assignment operator and copy constructor
     *
     *  @param IN `boardPosition` The BoardPosition object to be copied
     *  @return A reference to this BoardPosition object.
     */
    BoardPosition & copy (const BoardPosition & boardPosition);
};

#endif
