// Class definition for XO_Board class
// Author:  Abdelrahman Adel
// Date:    21/12/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/XO_Classes.hpp"
using namespace std;

void Computer::find_best_move(){
    static int fbest = -1000;
    string res;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(b.board[i][j]==0){
                b.board[i][j]='O';
                int fvalue = minmax(0);
                b.board[i][j]=0;
                if(fvalue>=fbest){
                    fbest = fvalue;
                    best_col_move = j;
                    best_row_move = i;
                }
            }
        }
    }
}
int Computer::minmax(bool isMax){
    char win = calculate();
    // if game over
    if (win != 'A') {
        // if AI wins, return 2 * number of spaces left
        // did this to make AI prioritize
        // the first move that makes him win if there's multiple winning moves
        if (win == symbol) return 2;
        // if player wins return -1 * number of spaces left
        else if (win == 'X') return -1;
        // if draw, return 1 * spaces left
        else return 1;
    }
    int value;
    int best = isMax ? -1000 : 1000;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(b.board[i][j]==0){
                if(isMax){
                    b.board[i][j] = 'O';
                    value = minmax(!isMax);
                    if(value>best){
                        best = value;
                    }
                    b.board[i][j] = 0;
                }
                else{
                    b.board[i][j] = 'X';
                    value = minmax(!isMax);
                    if(value<best){
                        best = value;
                    }
                    b.board[i][j] = 0;
                }
            }
        }
    }
    return best;
}
Computer::Computer(char symbol):Player(symbol){

}
void Computer::get_move(int& x, int& y){
    find_best_move();
    x = best_row_move;
    y = best_col_move;
}
void Computer::get_new_board(Board t){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            b.board[i][j] = t.board[i][j];
        }
        
    }
    
}
char Computer::calculate() {
    // default winner to 'A' means game not finished or tie
    char winner = 'A';
    
    // Checking for Rows for X or O victory.
    for (int i = 0; i < 3; i++) {
        if (b.board[i][0] == b.board[i][1] &&
            b.board[i][1] == b.board[i][2]) {
            if (b.board[i][0] == symbol)
                winner = symbol;
            else if (b.board[i][0] == 'X')
                winner = 'X';
        }
    }

    // Checking for Columns for X or O victory.
    for (int j = 0; j < 3; j++) {
        if (b.board[0][j] == b.board[1][j] &&
            b.board[1][j] == b.board[2][j]) {
            if (b.board[0][j] == symbol)
                winner = symbol;

            else if (b.board[0][j] == 'X')
                winner = 'X';
        }
    }

    // Checking for Diagonals for X or O victory.
    if (b.board[0][0] == b.board[1][1]
        && b.board[1][1] == b.board[2][2]) {
        if (b.board[0][0] == symbol)
            winner = symbol;
        else if (b.board[0][0] == 'X')
            winner = 'X';
    }

    if (b.board[0][2] == b.board[1][1]
        && b.board[1][1] == b.board[2][0]) {
        if (b.board[0][2] == symbol)
            winner = symbol;
        else if (b.board[0][2] == 'X')
            winner = 'X';
    }

    // count number of spaces left
    bool cnt = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b.board[i][j] == 0) {
                cnt = 0;
                break;
            }
        }
    }
    // cout << winner << endl;
    if (winner == 'A' && cnt) return 't';
    else if (winner == 'A' && !cnt) return 'A';
    else return winner;
}