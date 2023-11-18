//
// Created by Jonas Schwab on 11/16/23.
//

#include <iostream>
#include "ticTacToeGame.h"

using namespace std;

//char** ticTacToeGame::board = nullptr;

ticTacToeGame::ticTacToeGame(): gameBase(5, 5){}


char * ticTacToeGame::winner(){ //need to change whole program
    int rangeMin = 1; //FIXME this needs to be a prefifined int for all 1's etc...
    int rangeMax = height-1;
    char* tempBlank = new char[2];
    strcpy(tempBlank, "_"); //fixme move these to be member variables
    char* tempBorder = new char[2];
    strcpy(tempBorder, " ");

    for (int i = rangeMin; i < rangeMax; ++i){
        if (strcmp(board[i*height +1], tempBlank)!=0 && board[i*height+1] == board[i*height +2] && board[i*height +2] == board[i*height +3]){
            return board[i*height +1];
        }
        if (strcmp(board[1*height +i], tempBlank)!=0 && board[1*height + i] == board[2*height + i] && board[2*height + i] == board[3*height +i]){
            return board[2*height +i];
        }
    }

    if (strcmp(board[1*height + 1], tempBorder) != 0 && board[1*height +1] == board[2*height +2] && board[1*height +1] == board[3*height + 3]){
        return board[1*height + 1];
    }
    if (strcmp(board[1*height + 3], tempBorder) != 0 && board[1*height + 3] == board[2*height + 2] && board[1*height + 3] == board[3*height + 1]){
        return board[1*height + 3];
    }
    return tempBorder;
}

bool ticTacToeGame::done () {
    bool check = false;
    char* tempX = new char[2];
    strcpy(tempX, "X"); //fixme move these to be member variables
    char* tempO = new char[2];
    strcpy(tempO, "O");
    if (strcmp(winner(),tempX)==0){
        check = true;
        cout << "Player X won." << endl;
    }
    if (strcmp(winner(),tempO)==0){
        check = true;
        cout << "Player O won." << endl;
    }
    return check;
}
bool ticTacToeGame::draw() {  // assume called after done() is called
    char* tempBlank = new char[2];
    strcpy(tempBlank, "_"); //fixme move these to be member variables
    char* tempO = new char[2];
    strcpy(tempO, "O");

    bool checkOpen = true;    // does not address whether a player has won
    for (int i = 1; i < height-2; i++) { //FIXME need to fix the height -1
        for (int j = 1; j < width-2; j++) {
            if (strcmp(board[i*height +j], tempBlank)==0){
                checkOpen = false;
            }
        }
    }
    return checkOpen;
}
int ticTacToeGame::play(ticTacToeGame game) {
    int result;
    bool gameOver = true;
    int turnsPlayed = 1;

    while (gameOver) {
        cout << game << endl;
        result = game.yourTurn();
        if (result == playerQuit){
            return result;
        }
        if (!game.done() && !game.draw()) {
        } else {
            if (game.draw()){
                result = drawError;
                cout << "Turns Played: " << turnsPlayed << endl;
                cout << "No winning moves remain." << endl;
                cout << game;

            } else {
                result = success;
                cout << "Turns Played: " << turnsPlayed << endl;
                cout << game;
            }
            gameOver = false;
        }
        turnsPlayed++;
    }
    return result;
}

int ticTacToeGame::yourTurn() {
    xcoord = 0;
    ycoord = 0;
    char* tempX = new char[2];
    strcpy(tempX, "X");
    char* tempO = new char[2];
    strcpy(tempO, "O");
    bool validInput = false;

    if (turn){
        cout << "It is Player X's turn" << endl;
        if(prompt()){
            board[ycoord*height +xcoord] = tempX;
            longestInput = 1;
            turn = false;
            return success;
        } else {
            cout << "Player 'X' quit.";
            return playerQuit; //player wanted to quit
        }
    } else {
        cout << "It is Player O's turn" << endl;
        if (prompt()) {
            board[ycoord*height +xcoord] = tempO;
            longestInput = 1;
            turn = true;
            return success;
        } else {
            cout << "Player 'O' quit.";
            return playerQuit;
        }
    }
}

void ticTacToeGame::print() {
    cout << this << endl;
}

void ticTacToeGame::printGameBoard() {
    int YaxisCount = height-1;

    string XaxisCount;
    XaxisCount += " ";
    for (int i = 0; i < height; i++) {
        XaxisCount += to_string(i);
        for (int k = 0; k <= longestInput - 1; k ++){
            XaxisCount += " ";
        }

    }

    for (int i = height-1; i > 0; i--) {
        cout << YaxisCount;
        YaxisCount--;

        for (int j = 0; j < width; j++) {
            cout << board[i*height +j];
            for (int k = 0; k < longestInput; k ++){ //fixme so that it is based on the inputs length
                cout << " "; //fixme change the char to char* so this is implementable
            }
        }
        cout <<  endl;
    }
    cout <<  YaxisCount << endl;
    cout << XaxisCount;
}

ostream &operator << (ostream &outStream, ticTacToeGame& game) {
    game.printGameBoard();
    return outStream;
}