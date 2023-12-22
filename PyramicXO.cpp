#include <bits/stdc++.h>
#include "BoardGame_Classes.h"
using namespace std ;
PyramicX_O_Board ::PyramicX_O_Board(){
    board = new string *[n_rows] ;
    for(int i = 0 ; i < n_rows ; ++i){
        board[i] = new string[n_cols] ;
    }
    board[0][2] = "(0 , 2)" ;
    board[1][1] = "(1 , 1)" ;
    board[1][2] = "(1 , 2)" ;
    board[1][3] = "(1 , 3)" ;
    board[2][0] = "(2 , 0)" ;
    board[2][1] = "(2 , 1)" ;
    board[2][2] = "(2 , 2)" ;
    board[2][3] = "(2 , 3)" ;
    board[2][4] = "(2 , 4)" ;
}
bool PyramicX_O_Board ::CheckValidMove(int x , int y) {
    if(x == 0 and y == 2 and board[x][y] != "x" and board[x][y] != "o")
        return true ;
    if(x == 1 and y >= 1 and y <= 3 and board[x][y] != "x" and board[x][y] != "o")
        return true ;
    if(x == 2 and y >= 0 and y <= 4 and board[x][y] != "x" and board[x][y] != "o")
        return true ;
    return false ;
}
void PyramicX_O_Board ::update_board(int x, int y, string mark) {
    if(CheckValidMove(x , y)){
        board[x][y] = mark ;
    }
}
void PyramicX_O_Board ::display_board() {
    cout << "                    " << board[0][2] << "    " << endl ;
    cout << "          " << board[1][1] << " | " << board[1][2] << " | " << board[1][3] << endl ;
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " | " << board[2][3] << " | " << board[2][4] << endl;
}
bool PyramicX_O_Board ::is_winner() {
    if(board[0][2] == board[1][1] and board[1][1] == board[2][0]){
        return true;
    }
    if(board[1][1] == board[1][2] and board[1][2] == board[1][3]){
        return true;
    }
    if(board[0][2] == board[1][3] and board[1][3] == board[2][4]){
        return true;
    }
    if(board[2][0] == board[2][1] and board[2][1] == board[2][2]){
        return true;
    }
    if(board[2][1] == board[2][2] and board[2][2] == board[2][3]){
        return true;
    }
    if(board[2][2] == board[2][3] and board[2][3] == board[2][4]){
        return true;
    }
    if(board[0][2] == board[1][2] and board[1][2] == board[2][2]){
        return true;
    }
    return false ;
}
string PyramicX_O_Board ::WhoWon() {
    if(board[0][2] == board[1][1] and board[1][1] == board[2][0]) {
        return board[0][2] ;
    }
    if(board[1][1] == board[1][2] and board[1][2] == board[1][3]){
        return board[1][2] ;
    }
    if(board[0][2] == board[1][3] and  board[1][3] == board[2][4]){
        return board[0][2] ;
    }
    if(board[2][0] == board[2][1] and board[2][1] == board[2][2]){
        return board[2][2] ;
    }
    if(board[2][1] == board[2][2] and board[2][2] == board[2][3]){
        return board[2][2] ;
    }
    if(board[2][2] == board[2][3] and board[2][3] == board[2][4]){
        return board[2][2] ;
    }
    if(board[0][2] == board[1][2] and board[1][2] == board[2][2]){
        return board[2][2] ;
    }
    return " " ;
}
bool PyramicX_O_Board ::is_draw() {
    if(n_moves == 9 and !is_winner()) {
        return true ;
    }
    return false ;
}
bool PyramicX_O_Board ::game_is_over() {
    if(n_moves == 9){
        cout << "Game is over!" << endl;
        return true ;
    }
    return false ;
}
void PyramicX_O_Board ::updateNumberOfMoves() {
    n_moves++;
}
Player_p ::Player_p(char s) {
    symbol = s ;
}
void Player_p ::SetPlayerName(string name) {
    PlayerName = name ;
}
string Player_p ::GetPlayersName() const {
    return PlayerName ;
}
void Player_p ::get_move(Board_p &board) {
    int x = 0 , y = 0;
    while (!board.CheckValidMove(x , y)) {
        cout << GetPlayersName() << " , Please Enter valid  cell dimensions to play : " << endl;
        cin >> x >> y;
        if(board.CheckValidMove(x , y)) {
            board.update_board(x, y, get_symbol());
            break;
        }
    }
}
string Player_p ::get_symbol() const {
    return symbol ;
}
RandomPlayer_p ::RandomPlayer_p(char symbol , int d1 , int d2) : Player_p(symbol){
    this->dimension1 = d1 ;
    this->dimension2 = d2 ;
    PlayerName = "Computer Player" ;
}
void RandomPlayer_p ::get_move(Board_p &board) {
    int x , y ;
    bool flag = true ;
    while (flag){
        x = (int) (rand()/(RAND_MAX + 1.0) * dimension1);
        y = (int) (rand()/(RAND_MAX + 1.0) * dimension2);
        if(board.CheckValidMove(x , y)){
            board.update_board(x , y , get_symbol()) ;
            flag = false ;
        }
    }
}
GameManager_p::GameManager_p(Board_p* bPtr, Player_p* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}
void GameManager_p::run() {
    string name ;
    cout << "Enter Your Name : " << endl;
    cin >> name ;
    players[0]->SetPlayerName(name) ;
    while (!boardPtr->game_is_over()){
        boardPtr->display_board() ;
        Player_p* CurrentPlayer = players[current_turn] ;
        CurrentPlayer->get_move(*boardPtr) ;
        if(boardPtr->is_winner()) {
            if(boardPtr->WhoWon() == CurrentPlayer->get_symbol() and current_turn == 0){
                boardPtr->display_board() ;
                cout << "Player " << CurrentPlayer->GetPlayersName() << " WON!\n" ;
            }
            else if (boardPtr->WhoWon() == CurrentPlayer->get_symbol() and current_turn == 1){
                boardPtr->display_board() ;
                cout << "Computer Player WON!\n" ;
            }
            boardPtr->game_is_over() ;
            break;
        }
        if(boardPtr->is_draw()){
            cout << "NO ONE WON , GAME IS OVER" << endl;
            boardPtr->game_is_over() ;
        }
        current_turn ^= 1 ;
        boardPtr->updateNumberOfMoves() ;
    }
}
PyramicX_O_Board :: ~PyramicX_O_Board() {
    for(int i = 0 ; i < n_rows ; ++i){
        delete [] board[i] ;
    }
    delete board ;
}