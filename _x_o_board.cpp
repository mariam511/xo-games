#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.h"
using namespace std;
_x_o_board::_x_o_board() {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool _x_o_board:: update_board (int x, int y, char mark){
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)&&n_moves<24) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;

}
void _x_o_board::display_board(){
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;

}
bool _x_o_board::is_winner(){
    char winner;
    if(n_moves<24){return false;}
    vector<char>row_win(15,'*'), col_win(15,'*'), diag_win(18,'*');
    int rc=0,cc=0;
    int xwins=0,owins=0;
    for (int i = 0; i < 5; ++i) {
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]){row_win[rc]=board[i][0];}
        rc++;
        if(board[i][1]==board[i][2]&&board[i][2]==board[i][3]){row_win[rc]=board[i][1];}
        rc++;
        if(board[i][2]==board[i][3]&&board[i][3]==board[i][4]){row_win[rc]=board[i][2];}
        rc++;

    }
    for (int i = 0; i < 5; ++i) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) { col_win[cc] = board[0][i]; }
        cc++;
        if (board[1][i] == board[2][i] && board[2][i] == board[3][i]) { col_win[cc] = board[1][i]; }
        cc++;
        if (board[2][i] == board[3][i] && board[3][i] == board[4][i]) { col_win[cc] = board[2][i]; }
        cc++;
    }
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]){diag_win[0]=board[0][0];}
    if(board[0][1]==board[1][2]&&board[1][2]==board[2][3]){diag_win[1]=board[0][1];}
    if(board[0][2]==board[1][3]&&board[1][3]==board[2][4]){diag_win[2]=board[0][2];}
    if(board[0][4]==board[1][3]&&board[1][3]==board[2][2]){diag_win[3]=board[0][4];}
    if(board[0][3]==board[1][2]&&board[1][2]==board[2][1]){diag_win[4]=board[0][3];}
    if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]){diag_win[5]=board[0][2];}
    //
    if(board[2][0]==board[3][1]&&board[3][1]==board[4][2]){diag_win[6]=board[2][0];}
    if(board[2][1]==board[3][2]&&board[3][2]==board[4][3]){diag_win[7]=board[2][1];}
    if(board[2][2]==board[3][3]&&board[3][3]==board[4][4]){diag_win[8]=board[2][2];}
    if(board[2][4]==board[3][3]&&board[3][3]==board[4][2]){diag_win[9]=board[2][4];}
    if(board[2][3]==board[3][2]&&board[3][2]==board[4][1]){diag_win[10]=board[2][3];}
    if(board[2][2]==board[3][1]&&board[3][1]==board[4][0]){diag_win[11]=board[2][2];}
    //
    if(board[1][2]==board[2][2]&&board[2][2]==board[3][1]){diag_win[12]=board[1][2];}
    if(board[1][0]==board[2][1]&&board[2][1]==board[3][3]){diag_win[13]=board[1][0];}
    if(board[1][1]==board[2][2]&&board[2][2]==board[3][3]){diag_win[14]=board[1][1];}
    if(board[1][2]==board[2][3]&&board[2][3]==board[3][4]){diag_win[15]=board[1][2];}
    if(board[1][4]==board[2][3]&&board[2][3]==board[3][2]){diag_win[16]=board[1][4];}
    if(board[1][3]==board[2][2]&&board[2][2]==board[3][1]){diag_win[17]=board[1][3];}

    for (int i = 0; i<15; ++i) {
        if(row_win[i]=='X'){xwins+=1;}
        else if(row_win[i]=='O'){owins+=1;}
    }
    for (int i = 0; i <15; ++i) {
        if(col_win[i]=='X'){xwins+=1;}
        else if(col_win[i]=='O'){owins+=1;}
    }
    for (int i = 0; i <18; ++i) {
        if(diag_win[i]=='X'){xwins+=1;}
        else if(diag_win[i]=='O'){owins+=1;}
    }
    if(xwins>owins){
        winner='X';
        cout<<"xwins "<<xwins<<'\n';
        cout<<"owins "<<owins<<'\n';
        cout<<"The winner is the player with symbol"<<winner;
        return true;
    }
    else if(xwins<owins){
        winner='O';
        cout<<"xwins "<<xwins<<'\n';
        cout<<"owins "<<owins<<'\n';
        cout<<"The winner is the player with symbol"<<winner<<"\n";
        return true;
    }
    else{return false;}



}
bool _x_o_board:: is_draw(){
    if (n_moves == 24 && !is_winner()){
        cout<<"draw!!!\n";
    }
}
bool  _x_o_board::game_is_over(){
    return n_moves >= 24;

}