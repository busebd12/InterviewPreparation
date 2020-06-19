#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/*
 * Solution: the algorithm is as follows
 *
 * 1. Count the number of Xs.
 * 2. Count the number of Os.
 * 3. Check if the Xs can win.
 * 4. Check if the Os can win.
 * 5. If both Xs and Os can win, then the board is not valid.
 * 6. If only the Xs can win, then, since Xs play first, there needs to be one more X than there are Os.
 * 7. If only the Os can win, then, since the Os play second, there needs to be an equal amount of Xs and Os.
 * 8. If there is no winning state, then there needs to be either an equal number of Xs and Os or one more X than Os.
 *
 * Time complexity: O(1)
 * Space complexity: O(1)
 */

class Solution
{
    public:
        bool validTicTacToe(std::vector<std::string> & board)
        {
            if(board.empty())
            {
                return false;
            }

            int n=int(board.size());

            if(n > 3 || n < 3)
            {
                return false;
            }

            for(const auto & row : board)
            {
                if(row.size() > 3)
                {
                    return false;
                }
            }

            int numberOfXs=countCharacters(board, 'X');

            int numberOfOs=countCharacters(board, 'O');

            bool xWin=win(board, 'X');

            bool oWin=win(board, 'O');

            if(xWin && oWin)
            {
                return false;
            }

            if(xWin)
            {
                return numberOfXs==numberOfOs + 1;
            }

            if(oWin)
            {
                return numberOfXs==numberOfOs;
            }

            return numberOfXs==numberOfOs || numberOfXs==numberOfOs + 1;
        }

        int countCharacters(std::vector<std::string> & board, char c)
        {
            int total=0;

            for(const auto & row : board)
            {
                total+=std::count(row.begin(), row.end(), c);
            }

            return total;
        }

        bool win(std::vector<std::string> & board, char c)
        {
            int count=0;

            for(int row=0;row<3;row++)
            {
                if(board[row][0]==c && board[row][1]==c && board[row][2]==c)
                {
                    return true;
                }
            }

            for(int column=0;column<3;column++)
            {
                if(board[0][column]==c && board[1][column]==c && board[2][column]==c)
                {
                    return true;
                }
            }

            if(board[0][0]==c && board[1][1]==c && board[2][2]==c)
            {
                return true;
            }

            if(board[2][0]==c && board[1][1]==c && board[0][2]==c)
            {
                return true;
            }

            return false;
        }
};
