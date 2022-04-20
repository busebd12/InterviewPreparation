#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(rows * columns)
Space complexity: O(1)

*/
class Solution
{
    public:
        int countBattleships(vector<vector<char>> & board)
        {
            int result=0;
            
            int rows=board.size();
            
            int columns=board[0].size();
            
            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    //If we see an X, we assume that this 'X' is the first X in a horizontal or vertical battleship
                    //and check to make sure that there are no adjacent battleships horizontally or vertically.
                    //If this is the case, then we increment our result variable. All the bookkeeping that is required
                    //is to check the appropriate horizontal and/or vertical squares around the current square to make sure
                    //that there are no adjacent horizontal or vertical battleships.
                    if(board[row][column]=='X')
                    {
                        if(row==0)
                        {
                            if(column==0)
                            {
                                result+=1;
                            }
                            else
                            {
                                if(board[row][column-1]!='X')
                                {
                                    result+=1;
                                }
                            }
                        }
                        else if(row > 0)
                        {
                            if(column==0)
                            {
                                if(board[row-1][column]!='X')
                                {
                                    result+=1;
                                }
                            }
                            else if(column > 0)
                            {
                                if(board[row-1][column]!='X' && board[row][column-1]!='X')
                                {
                                    result+=1;
                                }
                            }
                        }
                        else if(column==0)
                        {
                            if(row > 0)
                            {
                                if(board[row-1][column]!='X')
                                {
                                    result+=1;
                                }
                            }
                        }
                        else if(column > 0)
                        {
                            if(board[row][column-1]!='X' && board[row-1][column]!='X')
                            {
                                result+=1;
                            }
                        }
                    }
                }
            }
            
            return result;
        }
};