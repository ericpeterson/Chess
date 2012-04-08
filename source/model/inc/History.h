#ifndef _HISTORY_H_
#define _HISTORY_H_

#include <stack>

#include "ChessMove.h"

class History {
  public:

    // Default constructor
    History ();

    
    /**
     *  Copy constructor
     *
     *  @param IN `history` The History object to copy
     */
    History (const History & history);


    // Destructor
    ~History ();


    /**
     *  Overloaded assignment operator
     *
     *  @param IN `history` The History object to copy
     *  @return A reference to this History object
     */
    History & operator = (const History & history);
 
    
    /**
     *  Indicates whether this History is empty
     *
     *  @return true if this History has no ChessMoves; false otherwise
     */
    bool IsEmpty () const;


    /**
     *  Removes the top element of this History
     *
     *  @return A reference to the ChessMove that was just popped
     *  @throws CS240Exception if history is empty
     */
    const ChessMove & pop ();


    /**
     *  Adds a new ChessMove to this History
     *
     *  @param IN `move` The ChessMove to add
     */
    void push (const ChessMove & move);


    /**
     *  Updates the latest move of the game
     *
     *  @return A reference to the ChessMove that is the latest move
     */
    void UpdateLastMove ();
 
  private:

    // The History is stored internally as a stack
    std::stack<ChessMove>* m_history;


    // The lastest move of the game
    ChessMove m_lastMove;

    /**
     *  Helper function for copy constructor and overloaded assignment operator
     *
     *  @param IN `history` The History object to copy
     *  @return A reference to this History object
     */
    History & copy (const History & history);


    /**
     *  Helper function for destructor and overloaded = operator. Frees heap
     *  memory used by this History object
     */
    void free ();
};

#endif
