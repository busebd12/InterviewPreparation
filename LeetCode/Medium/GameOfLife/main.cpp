#include <array>
#include <iostream>
#include <utility>
#include <vector>

/*
 * Solutions:
 *
 * 1. Use an copy of the input grid to maintain the final state for the original board since changing the squares of the
 * original board as we go will mess-up future squares.
 *
 * Time complexity: O(rows * columns) [where rows is the number of rows in the input board and columns is the number of columns in the original board]
 * Space complexity: O(rows * columns)
 *
 * 2. Inspired by this solution: https://leetcode.com/problems/game-of-life/discuss/468108/Use-the-tens-digit-as-a-counter-Python-O(1)-Space-O(mn)-Time
 *
 * Time complexity: O(rows * columns)
 * Space complexity: O(1)
 */

bool isValid(int rows, int columns, int row, int column)
{
    return ((row >=0 && row < rows) && (column >= 0 && column < columns));
}

void gameOfLife(std::vector<std::vector<int>> & board)
{
    if(board.empty())
    {
        return;
    }

    std::vector<std::vector<int>> copy=board;

    int rows=int(board.size());

    int columns=int(board[0].size());

    for(int row=0;row<rows;++row)
    {
        for(int column=0;column<columns;++column)
        {
            std::array<std::pair<int, int>, 8> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}}};

            int liveNeighbours=0;

            int deadNeighbours=0;

            for(auto & direction : directions)
            {
                if(isValid(rows, columns, row + direction.first, column + direction.second))
                {
                    if(copy[row + direction.first][column + direction.second]==1)
                    {
                        liveNeighbours++;
                    }
                    else
                    {
                        deadNeighbours++;
                    }
                }
            }

            if(board[row][column]==1)
            {
                if(liveNeighbours < 2 || liveNeighbours > 3)
                {
                    board[row][column]=0;
                }
            }
            else
            {
                if(liveNeighbours==3)
                {
                    board[row][column]=1;
                }
            }
        }
    }
}

void gameOfLife(std::vector<std::vector<int>> & board)
{
    if(board.empty())
    {
        return;
    }

    int rows=int(board.size());

    int columns=int(board[0].size());

    for(int row=0;row<rows;++row)
    {
        for(int column=0;column<columns;++column)
        {
            std::array<std::pair<int, int>, 8> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}}};

            int liveNeighbours=0;

            for(auto & direction : directions)
            {
                if(isValid(rows, columns, row + direction.first, column + direction.second))
                {
                    if((board[row + direction.first][column + direction.second] % 10)==1)
                    {
                        liveNeighbours++;
                    }
                }
            }

            board[row][column]=(board[row][column]) + (10 * liveNeighbours);
        }
    }

    for(int row=0;row<rows;++row)
    {
        for(int column=0;column<columns;++column)
        {
            int livingNeighbours=board[row][column]/10;

            int state=board[row][column] % 10;

            if(state==1)
            {
                if(livingNeighbours==2 || livingNeighbours==3)
                {
                    board[row][column]=1;
                }

                if(livingNeighbours < 2 || livingNeighbours > 3)
                {
                    board[row][column]=0;
                }
            }
            else
            {
                if(livingNeighbours==3)
                {
                    board[row][column]=1;
                }
                else
                {
                    board[row][column]=0;
                }
            }
        }
    }
}