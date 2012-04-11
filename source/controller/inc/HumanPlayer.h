#ifndef _WHITE_PLAYER_H_
#define _WHITE_PLAYER_H_

#include "ChessMaster.h"
#include "IChessPlayer.h"
#include "ChessMove.h"


class HumanPlayer : public IChessPlayer {
  public:

    /**
     *  Constructor
     *
     *  @param IN `chessMaster` The game board
     *  @param IN `view` The GUI
     */
    HumanPlayer (ChessMaster* chessMaster, IChessView* view);  

   
    /**
     * Indicate to the player that the user clicked on the given
     * row and column with the mouse.
     */
    virtual void on_CellSelected(int row, int col, int button);


    /**
     * Handle when the timeout duration has passed.
     */
    virtual void on_TimerEvent();
};

#endif
