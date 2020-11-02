#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/*
 * Approach: we first find the position of the rook on the board and then we move up, down, left, and right.
 * While moving in those directions, we only stop moving if we reach a spot that is off the board, we capture a pawn,
 * or we encounter a friendly bishop.
 *
 * Time complexity: O(number of rows * number of columns) --> O(8 * 8) --> O(64)
 * Space complexity: O(1)
 */


bool isOnBoard(int rows, int columns, int row, int column)
{
    return (row >= 0 && row < rows) && (column >= 0 && column < columns);
}

int numRookCaptures(vector<vector<char>>& board)
{
    int captures=0;

    if(board.empty())
    {
        return captures;
    }

    pair<int, int> rookPosition(-1, -1);

    int rows=8;

    int columns=8;

    bool done=false;

    for(int row=0;row<rows;++row)
    {
        for(int column=0;column<columns;++column)
        {
            if(board[row][column]=='R')
            {
                rookPosition.first=row;

                rookPosition.second=column;

                done=true;
            }
        }

        if(done)
        {
            break;
        }
    }

    pair<int, int> current=rookPosition;

    while(isOnBoard(rows, columns, current.first, current.second))
    {
        if(board[current.first][current.second]=='p')
        {
            captures++;

            break;
        }
        else if(board[current.first][current.second]=='B')
        {
            break;
        }

        current.first--;
    }

    current=rookPosition;

    while(isOnBoard(rows, columns, current.first, current.second))
    {
        if(board[current.first][current.second]=='p')
        {
            captures++;

            break;
        }
        else if(board[current.first][current.second]=='B')
        {
            break;
        }

        current.first++;
    }

    current=rookPosition;

    while(isOnBoard(rows, columns, current.first, current.second))
    {
        if(board[current.first][current.second]=='p')
        {
            captures++;

            break;
        }
        else if(board[current.first][current.second]=='B')
        {
            break;
        }

        current.second--;
    }

    current=rookPosition;

    while(isOnBoard(rows, columns, current.first, current.second))
    {
        if(board[current.first][current.second]=='p')
        {
            captures++;

            break;
        }
        else if(board[current.first][current.second]=='B')
        {
            break;
        }

        current.second++;
    }

    return captures;
}