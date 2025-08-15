#include <iostream>
#include <fstream>
#include "cstring"
#include "Player.h"
#include "Reversi.h"
#include "League.h"
#include "Registration.h"
#define N 30
using namespace std;


int main() {
    int num, num1, counter=0, count=0, i, j, sizeOfBoard, numOfPlayers = 0;
    string username, password, type, symbol, str;
    Player *p[N];
    Registration r;
    League l;
    for(i=0; i<N; i++)
        p[i]= nullptr;
    while (true) {
        cout << "1. Sign up to register" << endl;
        cout << "2. Sign in" << endl;
        cout << "3. Enter to league" << endl;
        cout << "4. Printing top players" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter one of the options" << endl;
        cin >> num;
        switch (num) {
            case 1:
            {
                r.regist(p, &numOfPlayers);
                break;
            }
            case 2:
            {
                r.connection(p, &numOfPlayers, &username, &password);
                //send the player to a game
                break;
            }
            case 3:
            {
                if(r.connection(p, &numOfPlayers, &username, &password)==0)
                    break;
                ifstream fs("league.txt", ios::in);
                if (!fs)
                    cout << "file not found";
                fs>> str;
                if(str.compare(" ")!=0)
                {
                    cout<< "There is no active league"<< endl;
                    cout<< "Choose which league you want to play in:"<<endl;
                    cout<< "1- All players\n 2- same symbol\n 3- same family"<<endl;
                    cin>> num1;
                    int count=0;
                    switch (num1)
                    {
                        case 1:
                        {
                            while(true) {
                                cout << "Enter size of the board above 4" << endl;
                                cin >> sizeOfBoard;
                                if (sizeOfBoard < 4)
                                    continue;
                                else break;
                            }
                            Player* p1[numOfPlayers];
                            for(i=0; i<numOfPlayers; i++)
                            {
                                p1[i]=p[i];
                            }
                            l.allPlayers(p1, numOfPlayers, sizeOfBoard);
                            break;
                        }
                        case 2:
                        {
                            for(i=0; i<numOfPlayers; i++)
                            {
                                if(p[i]->getUsername().compare(username)==0)
                                {
                                    str= p[i]->getSymbol();
                                    break;
                                }
                            }
                            for(i=0; i<numOfPlayers; i++)
                            {
                                if(p[i]->getSymbol().compare(str)==0)
                                {
                                    count++;
                                }
                            }
                            Player* newp[count];
                            for(i=0; i<numOfPlayers; i++)
                            {
                                if(p[i]->getSymbol().compare(str)==0)
                                    newp[i]=p[i];
                            }
                            l.allPlayers(newp, count, sizeOfBoard);
                            count=0;

                            break;
                        }
                        case 3:
                        {
                            for(i=0; i<numOfPlayers; i++)
                            {
                                if(p[i]->getUsername().compare(username)==0)
                                {
                                    str= p[i]->getType();
                                    break;
                                }
                            }
                            for(i=0; i<numOfPlayers; i++)
                            {
                                if(p[i]->getType().compare(str)==0)
                                {
                                    count++;
                                }
                            }
                            Player* newp[count];
                            for(i=0; i<numOfPlayers; i++)
                            {
                                if(p[i]->getType().compare(str)==0)
                                    newp[i]=p[i];
                            }
                            l.allPlayers(newp, count, sizeOfBoard);
                            count=0;
                            break;
                        }
                    }
                }
                break;
            }
            case 4:
                for(i=0; i<numOfPlayers; i++)
                {
                    if(p[i]->champ>=0)
                        cout << p[i]->getUsername() << "champ" <<p[i]->champ << endl;
                }
                break;
            case 5:
                counter=6;
                break;
            default:
                cout<< "WRONG CHOICE, try again" << endl;
                cin >> num;
                continue;
        }
        if (counter==6)
            break;
        }
    return 0;
}



