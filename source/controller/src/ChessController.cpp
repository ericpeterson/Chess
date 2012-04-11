#include <map>
#include <stack>
#include <fstream>
#include <iostream>

#include "HTMLTokenizer.h"
#include "HTMLToken.h"
#include "CS240Exception.h"

#include "IChessView.h"
#include "ChessView.h"
#include "ChessController.h"
#include "Modes.h"
#include "IChessPlayer.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "ChessMaster.h"
#include "ChessMove.h"
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
      m_whitePlayer = new HumanPlayer(m_chessMaster);
      m_blackPlayer = new ComputerPlayer();
      break;
    case ch:
      m_whitePlayer = new ComputerPlayer();
      m_blackPlayer = new HumanPlayer(m_chessMaster);
      break;
    case hh:
      m_whitePlayer = new HumanPlayer(m_chessMaster);
      m_blackPlayer = new HumanPlayer(m_chessMaster);
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

  if (WHITE == turn) {
    m_whitePlayer->on_CellSelected(row, col, button);
  } else if (BLACK == turn) {
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

  this->ClearBoard();
  this->DrawBoard();
}


void ChessController::on_SaveGame() {}


void ChessController::on_SaveGameAs() {}


void ChessController::on_LoadGame() {
  string fileName = m_pView->SelectLoadFile();

  if (fileName.empty()) {
    return;
  }

  ifstream loadFile(fileName.c_str());

  if (!loadFile.is_open()) {
    throw CS240Exception("Error: file was not opened");
  }


  // read in the file -- loadFile
  string xmlContents = ChessController::ReadFile(loadFile);

  // close the file
  loadFile.close();

  // parse xml tokens and update memory state
  this->UpdateState(xmlContents);

  // Redraw the board
  this->ClearBoard();
  this->DrawBoard();
}


void ChessController::on_UndoMove() {}

  
void ChessController::on_QuitGame() {}

  
void ChessController::on_TimerEvent() {
  
}


void ChessController::SetView(IChessView* view) {
  m_pView = view;
  m_whitePlayer->SetView(view);
  m_blackPlayer->SetView(view);
  m_whitePlayer->DisplayTurn();
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
  HTMLToken token("", TEXT);
  string value;

  map<BoardPosition, IPiece*> newBoard;
  stack<ChessMove>* newHistory = new stack<ChessMove>();

  while (tokenizer.HasNextToken()) {
    token = tokenizer.GetNextToken();
    value = token.GetValue();
 
    switch (token.GetType()) {
      case TAG_START:
        if (value == "board") {
          cout << "Start of board" << endl; 
        }

        if (value == "piece") {
          cout << "Piece element" << endl;
        }

        break;
      case TAG_END:
        break;
      case COMMENT:
        break;
      case TEXT:
        break;
      case END:
        break;
    }
  }

  // delete old memory
  delete m_chessMaster;
  m_chessMaster = new ChessMaster(newBoard, newHistory);
}

