// Class definition for XO game classes
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#ifndef _BoardGame_CLASSES_H
#define _BoardGame_CLASSES_H
#include "string"
using namespace std;

class Board {
protected:
    int n_rows, n_cols;
    char** board;
    int  n_moves = 0;

public:
    // Return true  if move is valid and put it on board
    // within board boundaries in empty cell
    // Return false otherwise
    virtual bool update_board (int x, int y, char symbol) = 0;
    // Returns true if there is any winner
    // either X or O
    // Written in a complex way. DO NOT DO LIKE THIS.
    virtual bool is_winner() = 0;
    // Return true if all moves are done and no winner
    virtual bool is_draw() = 0;
    // Display the board and the pieces on it
    virtual void display_board() = 0;
    // Return true if game is over
    virtual bool game_is_over() = 0;
};

///////////////////////////////////////////
// This class represents a 3 x 3 board
// used in X_O game
class X_O_Board:public Board {
public:
    X_O_Board ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};
// This class represents a 7 x 6 board
// used in Four-in-a-row(connect4) game
class Connect4_Board:public Board{
public:
    Connect4_Board();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();


};

// This class represents a 5 x 5 board
// used in X_O game
class _x_o_board:public Board{
public:
    _x_o_board();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();

};
///////////////////////////////////////////
// This class represents a player who has
// a name and a symbol to put on board
class Player {
protected:
    string name;
    char symbol;
    int a;

public:

    // Two constructors to initiate player
    // Give player a symbol to use in playing
    // It can be X or O or others
    // Optionally, you can give him ID or order
    // Like Player 1 and Player 2
    Player (char symbol); // Needed for computer players
    Player (int order, char symbol,int x);
    // Get desired move: x y (each between 0 and 2)
    // Virtual (can change for other player types)
    virtual void get_move(int& x, int& y);
    // Give player info as a string
    string to_string();
    // Get symbol used by player
    char get_symbol();
    friend int select_game();
};

///////////////////////////////////////////
// This class represents a random computer player
// that generates random positions x y (0 to 2)
// If invalid, game manager asks to regenerate
class RandomPlayer: public Player {
protected:
    int dimension;
public:
    // Take a symbol and pass it to parent
    RandomPlayer (char symbol, int dimension);
    // Generate a random move
    void get_move(int& x, int& y);
};

///////////////////////////////////////////
class GameManager {
private:
    Board* boardPtr;
    Player* players[2];
public:
    GameManager(Board*, Player* playerPtr[2]);
    void run();
    // This method creates board and players
    // It displays board
    // While True
    //   For each player
    //      It takes a valid move as x, y pair (between 0 - 2)
    //      It updates board and displays otit
    //      If winner, declare so and end
    //      If draw, declare so and end

};
// /////////////////////////////////////////////////////////////////////////////////////////////////////////

class Board_p {
protected:
    int n_rows = 3 , n_cols = 5 ;
    string** board;
    int  n_moves = 0;

public:
    virtual bool CheckValidMove(int x , int y) = 0 ;
    virtual void update_board (int x, int y, string symbol) = 0;
    virtual bool is_winner() = 0;
    virtual bool is_draw() = 0;
    virtual void display_board() = 0;
    virtual bool game_is_over() = 0;
    virtual string WhoWon() = 0 ;
    virtual void updateNumberOfMoves() = 0 ;
};
class PyramicX_O_Board:public Board_p {
public:
    PyramicX_O_Board();
    bool CheckValidMove(int x , int y) override ;
    void update_board (int x, int y, string mark) override ;
    void display_board() override;
    bool is_winner() override;
    bool is_draw() override;
    bool game_is_over() override;
    string WhoWon() override ;
    void updateNumberOfMoves() ;
    ~PyramicX_O_Board() ;
};
class Player_p {
protected:
    string PlayerName;
    string symbol;
public:
    Player_p() ;
    Player_p (char symbol);
    virtual void get_move(Board_p &board);
    void SetPlayerName(string name);
    string GetPlayersName() const ;
    string get_symbol() const ;
};
class RandomPlayer_p: public Player_p {
protected:
    int dimension1 ;
    int dimension2 ;
public:
    RandomPlayer_p() ;
    RandomPlayer_p (char symbol , int d1 , int d2);
    void get_move(Board_p &board);
};
class GameManager_p {
private:
    Board_p* boardPtr;
    Player_p* players[2];
    int current_turn = 0 ;
public:
    GameManager_p() ;
    GameManager_p(Board_p*, Player_p* playerPtr[2]);
    void run();
};


#endif