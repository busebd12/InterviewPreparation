#include <iostream>
#include <vector>
using namespace std;

bool hasShip(vector<vector<char>> & board, int x, int y)
{
    if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
    {
        return false;
    }

    return (board[x][y] == 'X');
}

int countBattleships(vector<vector<char>>& board)
{
    int rows=int(board.size());

    int cols=int(board[0].size());

    int ships=0;

    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<cols;++j)
        {
            if(board[i][j]=='.')
            {
                continue;
            }

            if(hasShip(board, i-1, j) || hasShip(board, i, j-1))
            {
                continue;
            }

            ships++;
        }
    }

    return ships;
}