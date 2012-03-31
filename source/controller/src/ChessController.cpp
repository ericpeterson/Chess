#include "IChessView.h"
#include "ChessController.h"
#include "Modes.h"


ChessController::ChessController (Modes gameMode) {}


ChessController::~ChessController() {}


void ChessController::on_CellSelected(int row, int col, int button) {}


void ChessController::on_DragStart(int row,int col) {}


bool ChessController::on_DragEnd(int row,int col) {
  return true;
}


void ChessController::on_NewGame() {}


void ChessController::on_SaveGame() {}


void ChessController::on_SaveGameAs() {}


void ChessController::on_LoadGame() {}


void ChessController::on_UndoMove() {}

  
void ChessController::on_QuitGame() {}

  
void ChessController::on_TimerEvent() {}


void ChessController::SetView(IChessView* view) {}

