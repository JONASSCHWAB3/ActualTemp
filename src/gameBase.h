//
// Created by Jonas Schwab on 11/16/23.
//

#ifndef CSE332LAB_GAMEBASE_H
#define CSE332LAB_GAMEBASE_H
#include "lab4.h"
#include <sstream>

using namespace std;

class gameBase {
protected:
    int longestInput;
    int xcoord;
    int ycoord;
    bool turn;
    int width;
    int height;
    vector<char*> board;
private:
    //char* gameType;
public:
    gameBase(int tempwidth, int tempheight);
    ~gameBase();
    //gameBase(string gameType);
    virtual void print() = 0;
    bool prompt();
    //virtual int play(gameBase& game) = 0;
    //virtual char* winner();


    virtual bool done() = 0;
    virtual bool draw() = 0;

    virtual int yourTurn() = 0;
    //friend ostream &operator << (ostream &outStream, gameBase &game);

};

#endif //CSE332LAB_GAMEBASE_H
