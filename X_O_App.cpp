// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include "BoardGame_Classes.h"
#include "_x_o_board.cpp"
#include "PyramicXO.cpp"
#include "Connect4_Board.cpp"
#include "GameManager.cpp"
#include "Player.cpp"
#include "RandomPlayer.cpp"
#include "X_O_Board.cpp"
using namespace std;
int choose_game;
int main() {
    cout<<"choose the game you want \n 1-X_O_(3*3_Board). \n 2-Pyramic_Tic-Tac-Toe. \n 3-Four-in-a-row_connect4). \n 4-X_O_(5*5)_Tic_Tac_Toe. :";
    cin>>choose_game;
    if (choose_game==1){
        int choice;
        Player* players[2];
        players[0] = new Player (1, 'x',choose_game);

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o',choose_game);
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 3);

        GameManager x_o_game (new X_O_Board(), players);
        x_o_game.run();
        system ("pause");
    }
    else if(choose_game==2){

        Player_p player1('x') ;
        RandomPlayer_p player2('o' , 5 , 3) ;
        Player_p* players[2];
        players[0] = &player1 ;
        players[1] = &player2 ;
        PyramicX_O_Board b ;
        GameManager_p game(&b ,players) ;
        game.run() ;
    }

    else if (choose_game==3){
        int choice;
        Player* players[2];
        players[0] = new Player (1, 'x',choose_game);

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o',choose_game);
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 3);

        GameManager x_o_game (new Connect4_Board(), players);
        x_o_game.run();
        system ("pause");
    }
    else if(choose_game==4){
        int choice;
        Player* players[2];
        players[0] = new Player (1, 'x',choose_game);

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o',choose_game);
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 5);

        GameManager x_o_game (new _x_o_board, players);
        x_o_game.run();
        system ("pause");
    }
    return 0;

}

//0000
