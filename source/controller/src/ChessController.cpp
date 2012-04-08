#include "IChessView.h"
#include "ChessController.h"
#include "Modes.h"


ChessController::ChessController (Modes gameMode): m_mode(gameMode),
  m_pView(NULL), m_chessMaster(new ChessMaster), m_whitePlayer(NULL), m_blackPlayer(NULL)  {}


ChessController::ChessController(const ChessController & chessController) {
  copy(chessController);
}


ChessController::~ChessController() {
  free();
}


ChessController & ChessController::operator = (const ChessController & chessController) {
  free();
  return copy(chessController);
}


void ChessController::on_CellSelected(int row, int col, int button) {}


void ChessController::on_DragStart(int row,int col) {}


bool ChessController::on_DragEnd(int row,int col) {
  return true;
}


void ChessController::on_NewGame() {
  
}


void ChessController::on_SaveGame() {}


void ChessController::on_SaveGameAs() {}


void ChessController::on_LoadGame() {}


void ChessController::on_UndoMove() {}

  
void ChessController::on_QuitGame() {}

  
void ChessController::on_TimerEvent() {}


void ChessController::SetView(IChessView* view) {
  m_pView = view;
}


ChessController & ChessController::copy (const ChessController & chessController) {
  if (this != &chessController) {
    m_mode = chessController.m_mode;
    m_pView = chessController.m_pView;
    m_chessMaster = chessController.m_chessMaster;
    m_whitePlayer = chessController.m_whitePlayer;
    m_blackPlayer = chessController.m_blackPlayer;
  }

  return *this;
}


void ChessController::free () {
  delete m_chessMaster;
}
