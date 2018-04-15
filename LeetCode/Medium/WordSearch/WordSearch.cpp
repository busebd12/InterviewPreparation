#include <iostream>
#include <vector>
using namespace std;

bool search(vector<vector<char>> & board, string word, int i, int j, int position)
{
    if(position==word.size())
    {
        return true;
    }

    if((i < 0) || (i>=board.size()) || (j < 0) || (j>=board[i].size()))
    {
        return false;
    }

    char c=board[i][j];

    if(c==word[position])
    {
        board[i][j]='#';

        if(search(board, word, i-1, j, position+1))
        {
            return true;
        }

        if(search(board, word, i+1, j, position+1))
        {
            return true;
        }

        if(search(board, word, i, j+1, position+1))
        {
            return true;
        }

        if(search(board, word, i, j-1, position+1))
        {
            return true;
        }

        board[i][j]=c;
    }

    return false;
}

bool exist(vector<vector<char>> & board, string word)
{
    if(board.empty())
    {
        return false;
    }

    const int boardSize=int(board.size());

    const int rowSize=int(board[0].size());

    for(int row=0;row<boardSize;++row)
    {
        for(int column=0;column<rowSize;++column)
        {
            if(search(board, word, row, column, 0))
            {
                return true;
            }
        }
    }

    return false;
}