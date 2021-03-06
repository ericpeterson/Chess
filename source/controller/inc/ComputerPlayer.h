#ifndef _BLACK_PLAYER_H_
#define _BLACK_PLAYER_H_

#include "IChessPlayer.h"

class ComputerPlayer : public IChessPlayer {
public:
 
	/**
	 * Indicate to the player that the user clicked on the given
	 * row and column with the mouse.
	 */
	virtual void on_CellSelected(int row, int col, int button);


	/**
	 * Handle when the timeout duration has passed.
	 */
	virtual void on_TimerEvent();


  virtual void SetView (IChessView* m_pView);
};

#endif
