
#ifndef FINALPROJECTCPP_REVERSI_H
#define FINALPROJECTCPP_REVERSI_H
#include <iostream>
#include <fstream>
#include "cstring"
#include "Player.h"

class Reversi {
public:
    Reversi() { }
    Player * LigaPlay(char**, int, Player*, Player*);
    void printBoard(char**, int);
    char** board= nullptr;
private:
    bool legalMove(int, int, int, char);
    void calculate(int*, int*, int);
    bool gameOver(int, char);
    bool createMove(int, int, int, char);
};


#endif //FINALPROJECTCPP_REVERSI_H
