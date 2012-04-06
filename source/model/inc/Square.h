#ifndef _SQUARE_H_
#define _SQUARE_H_

struct Square {

  // Default constructor
  Square ();

  /**
   *  Constructor
   *
   *  @param IN `r` The row
   *  @param IN `c` The column
   */
  Square (const short r, const short c);

  // The row coordinate of a board position
  short row;

  // The column coordinate of a board position
  short col;
};

#endif
