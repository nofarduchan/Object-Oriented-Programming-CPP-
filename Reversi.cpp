
#include "Reversi.h"
#include <iostream>
#include <fstream>
#include "cstring"

using namespace std;


void Reversi::printBoard(char** board, int size) {
    int i, j;
    cout<< "Board:"<< endl;
    cout<< "     ";
    for(j=0; j<size; j++)
    {
        cout<< j << "     ";
    }
    cout<< endl;
    cout<< "    ";
    for(j=0; j<size; j++)
        cout<< "___" << "   ";
    cout << endl;
    for(i=0; i<size; i++)
    {
        cout<< i<< " |  ";
        for(j=0; j<size; j++)
        {
            if (board[i][j] == 'X' || board[i][j] =='O')
                cout<< board[i][j] << "  |  ";
            else
                cout<< '.' << "  |  ";
        }
        cout<< endl;
        cout<< "    ";
        for(j=0; j<size; j++)
            cout<< "___" << "   ";
        cout<< endl;
    }
}

Player* Reversi:: LigaPlay(char** board, int size, Player* player1, Player* player2 ) {
    int row, col;
    cout<< player1->getUsername()<< " VS " << player2->getUsername()<< endl;
    printBoard(board, size);
    int points1=0, points2=0;
    cout<< player1->getUsername()<< " VS " << player2->getUsername() <<endl;
    cout<< player1->getUsername()<<"'s turn(X):"<<endl;
    while(true)
    {
        //x plays
        while(true)
        {
            cout<< "Enter numbers of row and col:"<<endl;
            cin>> row>> col;
            if (createMove(row, col, size, 'X')==0) //false
                continue;
            else
                break;
        }
        printBoard(board, size);
        calculate(&points1, &points2, size);
        cout<< player1->getUsername()<< ": " <<points1<< "  VS  " << player2->getUsername()<< ": " <<points2<< endl;
        points1=0;
        points2=0;
        if ((gameOver(size, 'O')==0)) //false-there is no legal moves to play
            break;
        cout<< player2->getUsername()<<"'s turn(O): "<<endl;

        //0 plays
        while(true)
        {
            cout<< "Enter numbers of row and col:"<<endl;
            cin>> row>> col;
            if (createMove(row, col, size, 'O')==0) //false
                continue;
            else
                break;
        }
        printBoard(board, size);
        calculate(&points1, &points2, size);
        cout<< player1->getUsername()<< ": " <<points1<< "  VS  " << player2->getUsername()<< ": " <<points2<< endl;
        points1=0;
        points2=0;
        if ((gameOver(size, 'X')==0)) //false-there is no legal moves to play
            break;
        cout<< player1->getUsername()<<"'s turn(X):"<<endl;
    }
    calculate(&points1, &points2, size);
    if(points1>points2)
    {
        cout<< player1->getUsername()<< " is the winner" <<endl;
        player1->score++;
        points1=0;
        points2=0;
        for (int i=0; i<size; i++)
        {
            for(int j=0; j<size; j++)
            {
                if (i==(size/2)-1 && j==(size/2)-1 || i==(size)/2 && j==(size)/2)
                    board[i][j] = 'O';
                else if (i==(size/2)-1 && j==(size)/2 || i==(size)/2 && j==(size/2)-1)
                    board[i][j] = 'X';
                else
                    board[i][j]='.';
            }
        }
        return player1;
    }
    else if(points1<points2)
    {
        cout<< player2->getUsername()<< " is the winner" <<endl;
        player2->score++;
        points1=0;
        points2=0;
        for (int i=0; i<size; i++)
        {
            for(int j=0; j<size; j++)
            {
                if (i==(size/2)-1 && j==(size/2)-1 || i==(size)/2 && j==(size)/2)
                    board[i][j] = 'O';
                else if (i==(size/2)-1 && j==(size)/2 || i==(size)/2 && j==(size/2)-1)
                    board[i][j] = 'X';
                else
                    board[i][j]='.';
            }
        }
        return player2;
    }
    else if(points1==points2)
    {
        cout << "TEKO- let's play again"<< endl;
        for (int i=0; i<size; i++)
        {
            for(int j=0; j<size; j++)
            {
                if (i==(size/2)-1 && j==(size/2)-1 || i==(size)/2 && j==(size)/2)
                    board[i][j] = 'O';
                else if (i==(size/2)-1 && j==(size)/2 || i==(size)/2 && j==(size/2)-1)
                    board[i][j] = 'X';
                else
                    board[i][j]='.';
            }
        }
        LigaPlay(board, size, player1, player2);
    }
    return nullptr;
}

bool Reversi::legalMove(int row, int col, int size, char x) {
    char y;
    if (x=='O')
        y='X';
    else
        y='O';

    int i, j,r, c;

    if(row< 0 || row>=size || col< 0 || col>=size)
        return false;
    else if(board[row][col]== x || board[row][col]== y)
        return false;
    if(row!=0 && col!=0)
    {
        if (board[row-1][col-1]==y)
        {
            for(i=row, j=col; i>0 && i<size && j>0 && j<size; i--, j--)
            {
                if(i==row && j==col)
                {

                }
                else
                    if(board[i][j]== '.')
                        break;
                if (board[i][j]==x)
                    return true;
            }
        }
    }
    if (row!=size-1 && col!=size-1)
    {
        if (board[row+1][col+1]==y)
        {
            for(i=row, j=col; i>=0 && i<size && j>=0 && j<size; i++, j++)
            {
                if(i==row && j==col)
                {

                }
                else
                    if(board[i][j]== '.')
                        break;
                if (board[i][j]==x)
                    return true;
            }
        }
    }
    if(row!=size-1 && col!=0)
    {
        if (board[row+1][col-1]==y)
        {
            for(i=row, j=col; i>=0 && i<size && j>=0 && j<size; i++, j--)
            {
                if(i==row && j==col)
                {

                }
                else
                    if(board[i][j]== '.')
                        break;
                if (board[i][j]==x)
                    return true;
            }
        }
    }
    if(row!=0 && col!=size-1)
    {
        if (board[row-1][col+1]==y)
        {
            for(i=row, j=col; i>0 && i<size && j>0 && j<size; i--, j++)
            {
                if(i==row && j==col)
                {

                }
                else
                    if(board[i][j]== '.')
                        break;
                if (board[i][j]==x)
                    return true;
            }
        }
    }
    if (row!=size-1)
    {
        if (board[row+1][col]==y)
        {
            for(i=row, j=col; i>=0 && i<size && j<size; i++, j=j)
            {
                if(i==row && j==col)
                {

                }
                else
                    if(board[i][j]== '.')
                        break;
                if (board[i][j]==x)
                    return true;
            }
        }
    }
    if (col!=size-1)
    {
        if (board[row][col+1]==y)
        {
            for(i=row, j=col; i<size && j>=0 && j<size; i=i, j++)
            {
                if(i==row && j==col)
                {

                }
                else
                    if(board[i][j]== '.')
                        break;
                if (board[i][j]==x)
                    return true;
            }
        }
    }
    if(row!=0)
    {
        if (board[row-1][col]==y)
        {
            for(i=row, j=col; i>=0 && i<size && j<size; i--, j=j)
            {
                if(i==row && j==col)
                {

                }
                else
                    if(board[i][j]== '.')
                        break;
                if (board[i][j]==x)
                    return true;
            }
        }
    }
    if(col!=0)
    {
        if (board[row][col-1]==y)
        {
            for(i=row, j=col; i<size && j>=0 && j<size; i=i, j--)
            {
                if(i==row && j==col)
                {

                }
                else
                    if(board[i][j]== '.')
                        break;
                if (board[i][j]==x)
                    return true;
            }
        }
    }
    return false;
}

void Reversi::calculate(int* ppoints1, int* ppoints2, int size) {
    int i, j;
    int points1= *ppoints1;
    int points2= *ppoints2;
    for(i=0; i<size; i++)
    {
        for (j=0; j<size; j++)
        {
            if(board[i][j]== 'X')
                points1++;
            else if(board[i][j]== 'O')
                points2++;
        }
    }
    *ppoints1=points1;
    *ppoints2=points2;
}

bool Reversi::gameOver(int size, char xory) {
    int i, j;
    int count=0;
    int sum= size*size;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(legalMove(i, j, size, xory)==0)
            {
                count++;
            }
        }
    }
    if(count==sum)
        return false;
    return true;
}

bool Reversi::createMove(int row, int col, int size, char x) {
    char y;
    if (x=='O')
        y='X';
    else
        y='O';

    int i, j,r, c, count=0;

    if(row< 0 || row>=size || col< 0 || col>=size)
    {
        cout<< "OUT OF THE LIMITS, TRY AGAIN!"<<endl;
        return false;
    }
    else if(board[row][col]== x || board[row][col]== y)
    {
        cout<< "The place is not empty"<<endl;
        return false;
    }
    if(row!=0 && col!=0)
    {
        if (board[row-1][col-1]==y)
        {
            for(i=row, j=col; i>0 && i<size && j>0 && j<size; i--, j--)
            {
                if(i==row && j==col)
                {

                }
                else
                    if(board[i][j]== '.')
                        break;

                if (board[i][j]==x)
                {
                    for(r=i, c=j; c<=col && r<=row; r++, c++)
                        board[r][c]=x;
                    count=1;
                }
            }
        }
    }
    if (row!=size-1 && col!=size-1)
    {
        if (board[row+1][col+1]==y)
        {
            for(i=row, j=col; i>=0 && i<size && j>=0 && j<size; i++, j++)
            {
                if(i==row && j==col)
                {

                }
                else
                    if(board[i][j]== '.')
                        break;
                if (board[i][j]==x)
                {
                    for(r=i, c=j; c>=col && r>=row; r--, c--)
                        board[r][c]=x;
                    count=1;
                }
            }
        }
    }
    if(row!=size-1 && col!=0)
    {
        if (board[row+1][col-1]==y)
        {
            for(i=row, j=col; i>=0 && i<size && j>=0 && j<size; i++, j--)
            {
                if(i==row && j==col)
                {

                }
                else
                    if(board[i][j]== '.')
                        break;
                if (board[i][j]==x)
                {
                    for(r=i, c=j; c<=col && r>=row; r--, c++)
                        board[r][c]=x;
                    count=1;
                }
            }
        }
    }
    if(row!=0 && col!=size-1)
    {
        if (board[row-1][col+1]==y)
        {
            for(i=row, j=col; i>=0 && i<size && j>=0 && j<size; i--, j++)
            {
                if(i==row && j==col)
                {

                }
                else
                    if(board[i][j]== '.')
                        break;
                if (board[i][j]==x)
                {
                    for(r=i, c=j; c>=col && r<=row; r++, c--)
                        board[r][c]=x;
                    count=1;
                }
            }
        }
    }
    if (row!=size-1)
    {
        if (board[row+1][col]==y)
        {
            for(i=row, j=col; i>=0 && i<size && j<size; i++, j=j)
            {
                if(i==row && j==col)
                {

                }
                else
                    if(board[i][j]== '.')
                        break;
                if (board[i][j]==x)
                {
                    for(r=i, c=j; r>=row; r--, c=j)
                        board[r][c]=x;
                    count=1;
                }
            }
        }
    }
    if (col!=size-1)
    {
        if (board[row][col+1]==y)
        {
            for(i=row, j=col; i<size && j>=0 && j<size; i=i, j++)
            {
                if(i==row && j==col)
                {

                }
                else
                    if(board[i][j]== '.')
                        break;
                if (board[i][j]==x)
                {
                    for(r=i, c=j; c>=col; r=i, c--)
                        board[r][c]=x;
                    count=1;
                }
            }
        }
    }
    if(row!=0)
    {
        if (board[row-1][col]==y)
        {
            for(i=row, j=col; i>=0 && i<size && j<size; i--, j=col)
            {
                if(i==row && j==col)
                {

                }
                else
                    if(board[i][j]== '.')
                        break;
                if (board[i][j]==x)
                {
                    for(r=i, c=j; r<=row; r++, c=j)
                        board[r][c]=x;
                    count=1;
                }
            }
        }
    }
    if(col!=0)
    {
        if (board[row][col-1]==y)
        {
            for(i=row, j=col; i<size && j>=0 && j<size; i=i, j--)
            {
                if(i==row && j==col)
                {

                }
                else
                    if(board[i][j]== '.')
                        break;
                if (board[i][j]==x)
                {
                    for(r=i, c=j; c<=col; r=i, c++)
                        board[r][c]=x;
                    count=1;
                }
            }
        }
    }
    if(count==1)
        return true;
    cout<< "not a legal step, try again"<<endl;
    return false;
}
