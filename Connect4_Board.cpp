
// File name: A3-Task2-Four-in-a-row
// Purpose: Four-in-a-row_Game
// Author: josiane usama
// ID:20220502
// Section:19
// Date:15/12/2023
// Version: 1.0

#include "BoardGame_Classes.h"
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
using namespace std;

// Set the board
Connect4_Board::Connect4_Board(){

    n_rows = 6;
    n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise

bool Connect4_Board::update_board (int x, int y, char mark) {
    int A=5; // row index
    bool rec=true; //recursion
    // Only update if move is valid
    while (rec) {
        if (board[A][x] != 0) {
            A--;
        }
        else {
            board[A][x]=toupper(mark);
            rec=false;
            A=5;
            return true;
        }

    }
}

void Connect4_Board::display_board(){
    cout<<"x:";
    for(int i=0;i<7;i++){
        cout<<" --"<<i<<"-- ";
    }
    cout<<endl;
    for(int i=0;i<6;i++){
        cout<<"  ";
        for(int j=0;j<7;j++){
            if (board[i][j]==0){
                cout<<"|     |";
            }
            else{
                cout<<"|  "<<board[i][j]<<"  |";
            }

        }
        cout<<endl;
    }
    cout<<"=================================================="<<endl;
}

bool Connect4_Board::is_winner(){
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            if(board[i][j]=='X' && board[i][j-1]=='X' && board[i][j-2]=='X' && board[i][j-3]=='X'){
                return true;
            }
            else if(board[i][j]=='O' && board[i][j-1]=='O' && board[i][j-2]=='O' && board[i][j-3]=='O'){
                return true;
            }
            else if(board[i][j]=='X' && board[i-1][j]=='X' && board[i-2][j]=='X' && board[i-3][j]=='X'){
                return true;
            }
            else if(board[i][j]=='O' && board[i-1][j]=='O' && board[i-2][j]=='O' && board[i-3][j]=='O'){
                return true;
            }
            else if(board[i][j]=='X' && board[i-1][j-1]=='X' && board[i-2][j-2]=='X' && board[i-3][j-3]=='X'){
                return true;
            }
            else if(board[i][j]=='O' && board[i-1][j-1]=='O' && board[i-2][j-2]=='O' && board[i-3][j-3]=='O'){
                return true;
            }
            else if(board[i][j]=='X' && board[i-1][j+1]=='X' && board[i-2][j+2]=='X' && board[i-3][j+3]=='X'){
                return true;
            }
            else if(board[i][j]=='O' && board[i-1][j+1]=='O' && board[i-2][j+2]=='O' && board[i-3][j+3]=='O'){
                return true;
            }



        }
    }

}
bool Connect4_Board::is_draw(){
    return (n_moves == 42 && !is_winner());
}
bool Connect4_Board::game_is_over(){
    return n_moves >= 42;

}