#include <iostream>
#include <vector>
using namespace std;

//Scan through the board and if we find an 'O' check to see if any of the spots around it are a '1'.
//If that is true, then make the current spot a 1
//Check if we didn't make all the changes in one pass and recurse if not
void checkForOnes(vector<vector<char>> & board, int rows, int columns, bool & stop)
{
    if(stop)
    {
        return;
    }

    for(int row=0;row<rows;++row)
    {
        for(int column=0;column<columns;++column)
        {
            if(board[row][column]=='O')
            {
                if(board[row+1][column]=='1' || board[row-1][column]=='1' || board[row][column+1]=='1' || board[row][column-1]=='1')
                {
                    board[row][column]='1';
                }
            }
        }
    }

    stop=true;

    for(int row=0;row<rows;++row)
    {
        for(int column=0;column<columns;++column)
        {
            if(board[row][column]=='O')
            {
                if(board[row+1][column]=='1' || board[row-1][column]=='1' || board[row][column+1]=='1' || board[row][column-1]=='1')
                {
                    stop=false;
                }
            }
        }
    }

    checkForOnes(board, rows, columns, stop);
}

void solve(vector<vector<char>> & board)
{
    if(board.size()<=2)
    {
        return;
    }

    int rows=int(board.size());

    int columns=int(board[0].size());

    //scan the top row and if we find an 'O', make it and all its neighbors 1s
    for(int i=0,row=0;i<board[0].size();++i)
    {
        if(board[row][i]=='O')
        {
            board[row][i]='1';
        }
    }

    //scan the bottom row and if we find an 'O', make it and all its neighbors 1s
    for(int i=0,row=rows-1;i<board[rows-1].size();++i)
    {
        if(board[row][i]=='O')
        {
            board[row][i]='1';
        }
    }

    //check the left-most column and if we find 'O's, make it and its neighbors 1s
    for(int i=0,column=0;i<rows;++i)
    {
        if(board[i][column]=='O')
        {
            board[i][column]='1';
        }
    }

    //check right-most column and if we find 'O's, make it and its neighbors 1s
    for(int i=0,column=columns-1;i<rows;++i)
    {
        if(board[i][column]=='O')
        {
            board[i][column]='1';
        }
    }

    bool stop=false;

    checkForOnes(board, rows, columns, stop);

    for(int row=0;row<rows;++row)
    {
        for(int column=0;column<columns;++column)
        {
            if(board[row][column]=='O')
            {
                board[row][column]='X';
            }

            if(board[row][column]=='1')
            {
                board[row][column]='O';
            }
        }
    }
}