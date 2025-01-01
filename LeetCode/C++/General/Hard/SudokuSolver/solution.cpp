#include <vector>
using namespace std;

/*
Time complexity: O(9^b) [where b=number of blank spaces on the board]
Space complexity: O(b) recursive stack space
*/

class Solution
{
    public:
        void solveSudoku(vector<vector<char>> & board)
        {
            int rows=9;

            int columns=9;

            backtracking(board, rows, columns);
        }

        bool backtracking(vector<vector<char>> & board, int rows, int columns)
        {
            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    //Found an empty cell
                    if(board[row][column]=='.')
                    {
                        //Try all possible replacement values 1-9
                        for(char c='1';c<='9';c++)
                        {
                            //If adding the replacement character c produces a valid board
                            if(isValid(board, rows, columns, row, column, c)==true)
                            {
                                //Do the replacement
                                board[row][column]=c;

                                //If choosing this particular replacement character c leads to a valid solved board
                                if(backtracking(board, rows, columns)==true)
                                {
                                    return true;
                                }

                                //Undo our change so we can try another replacement character
                                board[row][column]='.';
                            }
                        }

                        //If none of the replacement characters lead to a solved board, then we can't solve the board
                        return false;
                    }
                }
            }

            return true;
        }

        bool isValid(vector<vector<char>> & board, int rows, int columns, int row, int column, char c)
        {
            //Check entire row to make sure our chosen character only appears once
            for(int col=0;col<columns;col++)
            {
                if(board[row][col]==c)
                {
                    return false;
                }
            }

            //Check entire column to make sure our chosen character only appears once
            for(int r=0;r<rows;r++)
            {
                if(board[r][column]==c)
                {
                    return false;
                }
            }

            //Starting row for the sub-square we need to check
            int startRow=(row / 3) * 3;

            //Starting column for the sub-square we need to check
            int startColumn=(column / 3) * 3;

            //Check the sub-square to make sure our chosen character only appears once
            for(int r=startRow;r<startRow + 3;r++)
            {
                for(int col=startColumn;col<startColumn + 3;col++)
                {
                    if(board[r][col]==c)
                    {
                        return false;
                    }
                }
            }

            return true;
        }
};