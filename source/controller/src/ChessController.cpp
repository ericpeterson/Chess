#include <map>

#include "IChessView.h"
#include "ChessController.h"
#include "Modes.h"

using namespace std;

ChessController::ChessController (Modes gameMode): m_mode(gameMode),
  m_pView(NULL), m_chessMaster(new ChessMaster()), m_whitePlayer(NULL), m_blackPlayer(NULL)  {}


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
  delete m_chessMaster;
  m_chessMaster = new ChessMaster();

  Board* board = m_chessMaster->GetBoard();

  ChessController::DrawBoard(board);
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


void ChessController::DrawBoard (Board* board) {
  map<BoardPosition, ImageName>::iterator it;
  map<BoardPosition, ImageName> boardMap = board->GetBoardMap();
  map<BoardPosition, ImageName>::iterator endIt = boardMap.end();

  for (it = boardMap.begin(); it != endIt; it++) {
    BoardPosition currentPosition = it->first;
    int row = currentPosition.GetRow();
    int col = currentPosition.GetCol();
    ImageName currentPiece = it->second;

    m_pView->PlacePiece(row, col, currentPiece);
  }
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
