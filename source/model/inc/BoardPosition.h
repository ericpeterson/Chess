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
    BoardPosition (short row, short col);


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
     *  Overloaded == operator
     *
     *  @param IN `boardPosition` The BoardPosition object to copy
     *  @return true if this BoardPosition is equal to `boardPosition`; false
     *    otherwise.
     */
    bool operator == (const BoardPosition & boardPosition) const;


    /**
     *  Translates this boards position up a number of squares
     *
     *  @param IN `numTimes` The number of times to move this board position
     *  @return true if the position was successfully translated; false
     *    otherwise.
     */
    BoardPosition MoveUp (const short numTimes);


    /**
     *  Translates this boards position down a number of squares
     *
     *  @param IN `numTimes` The number of times to move this board position
     *  @return true if the position was successfully translated; false
     *    otherwise.
     */
    BoardPosition MoveDown (const short numTimes);


    /**
     *  Translates this boards position left a number of squares
     *
     *  @param IN `numTimes` The number of times to move this board position
     *  @return true if the position was successfully translated; false
     *    otherwise.
     */
    BoardPosition MoveLeft (const short numTimes);


    /**
     *  Translates this boards position right a number of squares
     *
     *  @param IN `numTimes` The number of times to move this board position
     *  @return true if the position was successfully translated; false
     *    otherwise.
     */
    BoardPosition MoveRight (const short numTimes);


    /**
     *  Translates this boards position up and left a number of squares
     *
     *  @param IN `numTimes` The number of times to move this board position
     *  @return true if the position was successfully translated; false
     *    otherwise.
     */
    BoardPosition MoveUpLeft (const short numTimes);


    /**
     *  Translates this boards position up and right a number of squares
     *
     *  @param IN `numTimes` The number of times to move this board position
     *  @return true if the position was successfully translated; false
     *    otherwise.
     */
    BoardPosition MoveUpRight (const short numTimes);


    /**
     *  Translates this boards position down and left a number of squares
     *
     *  @param IN `numTimes` The number of times to move this board position
     *  @return true if the position was successfully translated; false
     *    otherwise.
     */
    BoardPosition MoveDownLeft (const short numTimes);


    /**
     *  Translates this boards position down and right a number of squares
     *
     *  @param IN `numTimes` The number of times to move this board position
     *  @return true if the position was successfully translated; false
     *    otherwise.
     */
    BoardPosition MoveDownRight (const short numTimes);


    // @return The row of this position
    short GetRow ();


    // @return The column of this position
    short GetCol ();    

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
