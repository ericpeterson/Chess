#ifndef _CHESS_MOVE_H_
#define _CHESS_MOVE_H_

#include "BoardPosition.h"
#include "IPiece.h"

class IPiece;

struct ChessMove {

    // type of piece that was moved
    IPiece* m_movedPiece;
 
    // original position of piece that was moved
    BoardPosition m_originalPosition;

    // final position of piece that was moved
    BoardPosition m_finalPosition;

    // type of piece that was taken; NULL if no piece was taken
    IPiece* m_takenPiece;
};

#endif
