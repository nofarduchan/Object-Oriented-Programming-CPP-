
#include "League.h"
#include "Player.h"
#include "Reversi.h"

void League::allPlayers(Player** p, int size, int sizeOfBoard) {
    if (size==1)
    {
        p[0]->champ++;
        cout<< "added point to champion"<< endl;
        return;
    }
    int i, j;
    if(size%2==0)
    {
        Player* newp1[size];
        for(i=0; i<size; i++)
            newp1[i]=p[i];
        for(i=0; i<size; i++)
        {
            p[i]= nullptr;
        }
        Reversi game;
        game.board= new char*[sizeOfBoard];
        for(i=0; i<sizeOfBoard; i++)
            game.board[i]= new char [sizeOfBoard];
        for(i=0; i<sizeOfBoard; i++)
        {
            for(j=0; j<sizeOfBoard; j++)
            {
                if (i==(sizeOfBoard/2)-1 && j==(sizeOfBoard/2)-1 || i==(sizeOfBoard)/2 && j==(sizeOfBoard)/2)
                    game.board[i][j] = 'O';
                else if (i==(sizeOfBoard/2)-1 && j==(sizeOfBoard)/2 || i==(sizeOfBoard)/2 && j==(sizeOfBoard/2)-1)
                    game.board[i][j] = 'X';
            }
        }
        int size1 = size/2;
        Player *newp2[size1];
        cout<< "Lets play"<<endl;
        for(i=0; i<size1;i++)
            newp2[i] = game.LigaPlay(game.board, sizeOfBoard, newp1[i], newp1[size-(i+1)]);
        for(i=0; i<size; i++)
            newp1[i]= nullptr;
        allPlayers(newp2, size1, sizeOfBoard);
    }

    else if(size%2!=0) {
        Player *newp1[size];
        for (i = 0; i < size; i++)
            newp1[i] = p[i];
        Reversi game;
        game.board = new char *[sizeOfBoard];
        for (i = 0; i < sizeOfBoard; i++)
            game.board[i] = new char[sizeOfBoard];
        for (i = 0; i < sizeOfBoard; i++) {
            for (j = 0; j < sizeOfBoard; j++) {
                if (i == (sizeOfBoard / 2) - 1 && j == (sizeOfBoard / 2) - 1 ||
                    i == (sizeOfBoard) / 2 && j == (sizeOfBoard) / 2)
                    game.board[i][j] = 'O';
                else if (i == (sizeOfBoard / 2) - 1 && j == (sizeOfBoard) / 2 ||
                         i == (sizeOfBoard) / 2 && j == (sizeOfBoard / 2) - 1)
                    game.board[i][j] = 'X';
            }
        }
        int size1 = size / 2 + 1;
        Player *newp2[size1];
        cout << "Lets play" << endl;
        for (i = 0; i < size1 - 1; i++)
            newp2[i] = game.LigaPlay(game.board, sizeOfBoard, newp1[i], newp1[size - (i + 1)]);
        newp2[i] = newp1[size1 - 1];
        for (i = 0; i < size; i++)
            newp1[i] = nullptr;
        allPlayers(newp2, size1, sizeOfBoard);
    }
}
