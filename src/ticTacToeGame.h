//
// Created by Jonas Schwab on 11/16/23.
//

#ifndef CSE332LAB_TICTACTOEGAME_H
#define CSE332LAB_TICTACTOEGAME_H
#include "gameBase.h"

using namespace std;

class ticTacToeGame : public gameBase {
private:
public:


    explicit ticTacToeGame();
    //~ticTacToeGame();
    void printGameBoard();
    void print() override;
    static int play(ticTacToeGame game); // this might need to be implemented in gmaeBase
    char* winner();
    bool done() override;
    bool draw() override;
    int yourTurn() override;
    friend ostream &operator << (ostream &outStream, ticTacToeGame& game);



};

#endif //CSE332LAB_TICTACTOEGAME_H
