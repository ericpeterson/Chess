#ifndef _CHESS_CONTROLLER_H_
#define _CHESS_CONTROLLER_H_

#include "IChessView.h"
#include "IChessController.h"
#include "Modes.h"
#include "IChessPlayer.h"
#include "ChessMaster.h"

class ChessController: public IChessController {
  public:

    /**
     *  Constructor
     *
     *  @param `gameMode` The mode of the game: Human vs. Computer, Computer vs.
     *    Human, Human vs. Human, or Computer vs. Computer.
     */
    ChessController (Modes gameMode);


    /**
     *  Copy constructor
     *
     *  @param IN `chessController` The ChessController object to copy
     */
    ChessController (const ChessController & chessController);
    

    /**
     * Destructor
     */
    virtual ~ChessController();

   
    /**
     *  Overloaded assignment operator
     *
     *  @param IN `chessController` The ChessController object to copy
     *  @return A reference to this ChessController object
     */
    ChessController & operator = (const ChessController & chessController);

 
    /**
     * Indicate to the player that the user clicked on the given
     * row and column with the mouse.
     */
    virtual void on_CellSelected(int row, int col, int button);

    
    ///@param row where drag began
    ///@param col where drag began
    virtual void on_DragStart(int row,int col);


    ///@param row where drag ended
    ///@param col where drag ended
    ///@return true if the drag resulted in a successful drop
    virtual bool on_DragEnd(int row,int col);


    /**
     * Handle when the user selected the new game button.
     */
    virtual void on_NewGame();


    /**
     * Handle when the user selected the save game button.
     */
    virtual void on_SaveGame();


    /**
     * Handle when the user selected the save game as button.
     */
    virtual void on_SaveGameAs();


    /**
     * Handle when the user selected the load game button.
     */
    virtual void on_LoadGame();


    /**
     * Handle when the user selected the undo move button.
     */
    virtual void on_UndoMove();

      
    /**
     * Handle when the user selects to quit the game, either through the
     * quit button, the close X button, or the file menu.
     */
    virtual void on_QuitGame();

      
    /**
     * Handle when a timer event has been signaled.
     */
    virtual void on_TimerEvent();

    
    /**
     * Set the IChessView that this IChessController will handle inputs for.
     */
    virtual void SetView(IChessView* view);

  private:

    // The mode of the chess game that this controller directs
    Modes m_mode;

    // A pointer to the view (GUI layer) of this games
    IChessView* m_pView;

    // A pointer to the facade class
    ChessMaster* m_chessMaster;

    // Pointer to the white player
    IChessPlayer* m_whitePlayer;

    // Pointer to the black player
    IChessPlayer* m_blackPlayer;


    /**
     *  Helper function for copy constructor and overloaded = operator
     *
     *  @param IN `chessController` The ChessController object to copy
     *  @return A reference to this ChessController object
     */
    ChessController & copy (const ChessController & chessController);


    /**
     *  Helper function for destructor and overloaded = operator. Frees heap
     *  memory used by ChessController.
     */
    void free ();
};

#endif

