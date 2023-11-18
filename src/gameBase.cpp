/**
 * gameBase.h
 * CSE 332S
 * Lab Num: 4
 * Author: Jonas Schwab <j.g.schwab@wustl.edu>
 * Description:
*/
#include "gameBase.h"
#include <iostream>
#include <cstring>
//#include <sstream>


using namespace std;

gameBase::gameBase(int tempwidth, int tempheight) : xcoord(0), ycoord(0), turn(true), longestInput(0), board(){

    width = tempwidth;
    height = tempheight;
    //board<char*>(width*height);

    int rangeMin = 1; //FIXME this needs to be a predefined int
    int rangeMax = height-2;
    char* tempBlank = new char[2];
    strcpy(tempBlank, "_");
    char* tempBorder = new char[2];
    strcpy(tempBorder, " ");

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if ((i >= rangeMin && i <= rangeMax) && (j >= rangeMin && j <= rangeMax)) {
                board.push_back(tempBlank);
            } else {
                board.push_back(tempBorder);               // game board border
            }
        }
    }
    longestInput = 1;
}

bool gameBase::prompt(){
    char* tempBlank = new char[2];
    strcpy(tempBlank, "_");
    char* tempBorder = new char[2];
    strcpy(tempBorder, " ");
    bool validInput = false;
    string input;
    int maxInput = height-2;
    cout << "Please input coordinates for the *EMPTY* square you want to mark (Ex: '1,1'). Or quit (Ex: 'quit')." << endl;

    while (!validInput) {
        string errorMessage = "Input Incorrect re-enter using range (1 - ";
        errorMessage += to_string(maxInput);
        errorMessage += " in *EMPTY* square): (Ex: '1,1'). Or quit (Ex: 'quit').";
        getline(cin, input);
        if (input == "quit") {
            return validInput ;
        }

        istringstream parseString(input);
        vector<char> inputs;
        char c;
        while (parseString.get(c)){
            if (c != ' '){
                inputs.push_back(c);
            }
        }

        int inputCoordX;
        int inputCoordY;

        //FIXME need to work through how to make sure that there are three inputs (the coords) without going out of bounds

        if (inputs.size() == 3 && inputs[1] == ','){
            inputCoordX = inputs[0]- '0';
            inputCoordY = inputs[2]- '0';
            //cout << board[inputCoordY*height + inputCoordX + 1];

            if (inputCoordX <= maxInput && inputCoordX > 0 && inputCoordY <= maxInput && inputCoordY > 0 &&  strcmp(board[inputCoordY*height + inputCoordX + 1],tempBlank)==0) {

                xcoord = inputCoordX;
                ycoord = inputCoordY;
                validInput = true;

            } else {
                cout << errorMessage << endl;
            }
        } else {
            cout << errorMessage << endl;
        }
    }
    return validInput;
}


gameBase::~gameBase(){
    //for (char* str : board) {
        //delete[] str;
    //}
}

