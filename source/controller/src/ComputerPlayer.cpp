#include "ComputerPlayer.h"

void ComputerPlayer::on_CellSelected(int row, int col, int button) {}


void ComputerPlayer::on_TimerEvent() {}


void ComputerPlayer::SetView (IChessView* m_pView) {
  m_view = m_pView;
}
