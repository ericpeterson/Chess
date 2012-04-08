#ifndef _CHESS_MOVE_H_
#define _CHESS_MOVE_H_

#include "ChessGuiDefines.h"

#include "BoardPosition.h"

struct ChessMove {

    // type of piece that was moved
    ImageName m_movedPiece;
 
    // original position of piece that was moved
    BoardPosition m_originalPosition;

    // final position of piece that was moved
    BoardPosition m_finalPosition;

    // type of piece that was taken; NO_IMAGE if no piece was taken
    ImageName m_takenPiece;

    // position of piece that was taken; an invalid board position if no piece was taken
    BoardPosition m_takenPosition;
};

#endif
