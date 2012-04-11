#ifndef _WHITE_PLAYER_H_
#define _WHITE_PLAYER_H_

#include "IChessPlayer.h"

class WhitePlayer: public IChessPlayer {
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
};

#endif
