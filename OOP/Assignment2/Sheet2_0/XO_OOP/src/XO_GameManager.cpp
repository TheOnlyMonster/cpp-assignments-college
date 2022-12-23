// Class definition for XO_GameManager class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"../include/XO_Classes.hpp"
using namespace std;

void GameManager::run() {
    Board x_o;
    int x, y;
    int choice;
    cout<<"Do you want to play against AI or against another player?"<<endl;
    cout<<"Type '1' to play against AI or Type '0' to play against another player...  ";
    cin>>choice;
    Player* players[2];
    if(choice==0){
        players[0]=new Player (1, 'x');
        players[1]=new Player(2,'o');
    }
    else{
        players[0]=new Player (1, 'X');
        players[1]=new Computer('O');
    }
    x_o.display_board();
    while (true) {
        for (int i:{0,1}) {
            players[i]->get_new_board(x_o);
            players[i]->get_move(x, y);
            while (!x_o.update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y);
            }
            x_o.display_board();
            if (x_o.is_winner()){
                cout  << players[i]->to_string() << " wins\n";
                return;
            }
            if (x_o.is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
}
