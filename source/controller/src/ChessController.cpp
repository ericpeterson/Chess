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
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "Pawn.h"

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

  this->ClearBoard();
  this->DrawBoard();
}


void ChessController::on_DragStart(int row,int col) {}


bool ChessController::on_DragEnd(int row,int col) {
  return true;
}


void ChessController::on_NewGame() {
  delete m_chessMaster;
  m_chessMaster = new ChessMaster();

  m_whitePlayer->DisplayTurn();
  this->ClearBoard();
  this->DrawBoard();
}


IPiece* ChessController::createNewPiece(std::string type, std::string color) {
  IPiece* piece = NULL;
  // use new
  if (type == "rook") {
    if (color == "white")
      piece = new Rook(WHITE, W_ROOK);
    else
      piece = new Rook(BLACK, B_ROOK);
  } else if (type == "knight") {
    if (color == "white")
      piece = new Knight(WHITE, W_KNIGHT);
    else
      piece = new Knight(BLACK, B_KNIGHT);
  } else if (type == "bishop") {
    if (color == "white")
      piece = new Bishop(WHITE, W_BISHOP);
    else
      piece = new Bishop(BLACK, B_BISHOP);
  } else if (type == "king") {
    if (color == "white")
      piece = new King(WHITE, W_KING);
    else
      piece = new King(BLACK, B_KING);
  } else if (type == "queen") {
    if (color == "white")
      piece = new Queen(WHITE, W_QUEEN);
    else
      piece = new Queen(BLACK, B_QUEEN);
  } else if (type == "pawn") {
    if (color == "white")
      piece = new Pawn(WHITE, W_PAWN);
    else
      piece = new Pawn(BLACK, B_PAWN);
  }

  return piece;
}


BoardPosition ChessController::createPosition(std::string row, std::string col) {
  std::stringstream rowStream;
  std::stringstream colStream;

  rowStream << row;
  colStream << col;

  int rowInt;
  int colInt;

  rowStream >> rowInt;
  colStream >> colInt;

  return BoardPosition (rowInt, colInt);
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
  m_whitePlayer->DisplayTurn();
}


void ChessController::on_UndoMove() {
  /*m_chessMaster->Undo();
  this->ClearBoard();
  this->DrawBoard();
  m_whitePlayer->DisplayTurn();*/
}

  
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
  for (int i = 0; i < NUM_ROW; i++) {
    for (int j = 0; j < NUM_COL; j++) {
      m_pView->ClearPiece(i, j);
    }
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
  bool inBoard = false;
  bool inMove = false;
  bool firstMovePiece = true;
  bool secondMovedPiece = false;
  bool thirdMovedPiece = false;

  map<BoardPosition, IPiece*> newBoard;
  stack<ChessMove>* newHistory = new stack<ChessMove>();

  string currentTurnStr;
  ChessColor currentTurn;

  ChessMove move;

  while (tokenizer.HasNextToken()) {
    token = tokenizer.GetNextToken();
    value = token.GetValue();
 
    switch (token.GetType()) {
      case TAG_START:
        if (value == "board") {
          cout << "Start of board" << endl;
          inBoard = true;
          inMove = false;
        }

        if (value == "piece" && inBoard) {
          BoardPosition pos = createPosition(token.GetAttribute("row"), token.GetAttribute("column"));
          IPiece* piece = createNewPiece(token.GetAttribute("type"), token.GetAttribute("color"));
          pair<BoardPosition, IPiece*> posPair(pos, piece);

          newBoard.insert(posPair);
          cout << "Piece element" << endl;
        }

        if (value == "piece" && inMove) {
          if (firstMovePiece) {
            currentTurnStr = token.GetAttribute("color");

            firstMovePiece = false;
            secondMovedPiece = true;
            thirdMovedPiece = false;
          }

          if (secondMovedPiece) {
            firstMovePiece = false;
            secondMovedPiece = false;
            thirdMovedPiece = true;
          }

          if (thirdMovedPiece) {
            firstMovePiece = true;
            secondMovedPiece = false;
            thirdMovedPiece = false;
          }
        }
        
        if (value == "move") {
          inBoard = false;
          inMove = true;
          firstMovePiece = true;
          secondMovedPiece = false;
          thirdMovedPiece = false;
          
          cout << "Move element" << endl;
        }

        break;
      case TAG_END:
      case COMMENT:
      case TEXT:
      case END:
        cout << "" << endl;
    }
  }


  if (currentTurnStr == "white") {
    currentTurn = BLACK; 
  } else {
    currentTurn = WHITE;
  } 

  // delete old memory
  delete m_chessMaster;
  m_chessMaster = new ChessMaster(newBoard, newHistory);
  m_chessMaster->SetTurn(currentTurn);
}

