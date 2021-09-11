#include <iostream>
#include <unordered_set>
#include <vector>

/*
 * Solution: check that the board obeys the following rules
 *
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 *
 * Time complexity: O(3 * 81) => O(243) => O(1)
 * Space complexity: O(3 * 81) => O(243) => O(1)
 */

bool isValidSudoku(std::vector<std::vector<char>> & board)
{
    const int rows=9;

    const int columns=9;

    for(int row=0;row<rows;++row)
    {
        std::unordered_set<int> cache({1, 2, 3, 4, 5, 6, 7, 8, 9});

        for(int column=0;column<columns;++column)
        {
            if(board[row][column]!='.')
            {
                if(cache.count(board[row][column]-'0'))
                {
                    cache.erase(board[row][column]-'0');
                }
                else
                {
                    return false;
                }
            }
        }
    }

    for(int row=0;row<rows;++row)
    {
        std::unordered_set<int> cache({1, 2, 3, 4, 5, 6, 7, 8, 9});

        for(int column=0;column<columns;++column)
        {
            if(board[column][row]!='.')
            {
                if(cache.count(board[column][row]-'0'))
                {
                    cache.erase(board[column][row]-'0');
                }
                else
                {
                    return false;
                }
            }
        }
    }

    for(int row=0;row+3<=rows;row+=3)
    {
        for(int column=0;column+3<=columns;column+=3)
        {
            std::unordered_set<int> cache({1, 2, 3, 4, 5, 6, 7, 8, 9});

            for(int i=row,count=0;count<3;++count,++i)
            {
                for(int j=column,counter=0;counter<3;counter++,++j)
                {
                    if(board[i][j]!='.')
                    {
                        if(cache.count(board[i][j]-'0'))
                        {
                            cache.erase(board[i][j]-'0');
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}