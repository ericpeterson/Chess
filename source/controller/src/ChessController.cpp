#include <map>
#include <fstream>

#include "HTMLTokenizer.h"
#include "CS240Exception.h"

#include "IChessView.h"
#include "ChessView.h"
#include "ChessController.h"
#include "Modes.h"
#include "IChessPlayer.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "ChessMaster.h"
#include "ChessGuiDefines.h"
#include "IPiece.h"
#include "ChessColor.h"
#include "Board.h"

using namespace std;

ChessController::ChessController (Modes gameMode): m_mode(gameMode),
  m_pView(NULL), m_chessMaster(NULL), m_whitePlayer(NULL), m_blackPlayer(NULL)  {

  m_chessMaster = new ChessMaster();

  switch(gameMode) {
    case hc:
      m_whitePlayer = new HumanPlayer(m_chessMaster, m_pView);
      m_blackPlayer = new ComputerPlayer();
      break;
    case ch:
      m_whitePlayer = new ComputerPlayer();
      m_blackPlayer = new HumanPlayer(m_chessMaster, m_pView);
      break;
    case hh:
      m_whitePlayer = new HumanPlayer(m_chessMaster, m_pView);
      m_blackPlayer = new HumanPlayer(m_chessMaster, m_pView);
      break;
    case cc:
      m_whitePlayer = new ComputerPlayer();
      m_blackPlayer = new ComputerPlayer();
      break;
  }
}


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


void ChessController::on_CellSelected(int row, int col, int button) {
  ChessColor turn =  m_chessMaster->GetTurn();
  Board* board = m_chessMaster->GetBoard();
  IPiece* piece = board->PieceAtPosition(row, col);
  ChessColor pieceColor = piece->GetColor();

  if ((WHITE == turn) && (WHITE == pieceColor)) {
    m_whitePlayer->on_CellSelected(row, col, button);
  } else if ((BLACK == turn) && (BLACK == pieceColor)) {
    m_blackPlayer->on_CellSelected(row, col, button);
  }
}


void ChessController::on_DragStart(int row,int col) {}


bool ChessController::on_DragEnd(int row,int col) {
  return true;
}


void ChessController::on_NewGame() {
  delete m_chessMaster;
  m_chessMaster = new ChessMaster();

  this->DrawBoard();
}


void ChessController::on_SaveGame() {}


void ChessController::on_SaveGameAs() {}


void ChessController::on_LoadGame() {
  string fileName = m_pView->SelectLoadFile();
  ifstream loadFile(fileName.c_str());

  if (!loadFile.is_open()) {
    throw CS240Exception("Error: file was not opened");
  }

  // read in the file -- loadFile
  string xmlContents = ChessController::ReadFile(loadFile);

  // close the file
  loadFile.close();

  // parse xml tokens and update memory state
  ChessController::UpdateState(xmlContents);

  // Redraw the board
  ChessController::ClearBoard();
  this->DrawBoard();
}


void ChessController::on_UndoMove() {}

  
void ChessController::on_QuitGame() {}

  
void ChessController::on_TimerEvent() {
  
}


void ChessController::SetView(IChessView* view) {
  m_pView = view;
}


void ChessController::DrawBoard () {
  Board* board = m_chessMaster->GetBoard();
  map<BoardPosition, IPiece*> boardMap = board->GetBoardMap();
  map<BoardPosition, IPiece*>::iterator endIt = boardMap.end();
  map<BoardPosition, IPiece*>::iterator it;

  for (it = boardMap.begin(); it != endIt; it++) {
    BoardPosition currentPosition = it->first;
    int row = currentPosition.GetRow();
    int col = currentPosition.GetCol();
    IPiece* currentPiece = it->second;
    ImageName currentPieceType = currentPiece->GetType();

    m_pView->PlacePiece(row, col, currentPieceType);
  }
}


void ChessController::ClearBoard () {

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
  delete m_whitePlayer;
  delete m_blackPlayer;

  m_chessMaster = NULL;
  m_whitePlayer = NULL;
  m_blackPlayer = NULL;
}


string ChessController::ReadFile (ifstream & file) {
  string fileContents;
  string buffer;

  while (file.good()) {
    getline(file, buffer);
    fileContents.append(buffer);
  }

  return fileContents;
}


void ChessController::UpdateState (std::string xmlFile) {
  HTMLTokenizer tokenizer(xmlFile);

  while (tokenizer.HasNextToken()) {
    // tokenizer.GetNextToken();
  }
}

