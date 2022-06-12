#include <string>
#include <vector>
using namespace std;

/*

Solution: see comments.

Time Complexity: O(N!)
Space Complexity: O(N*N)
*/

class Solution
{
    public:
        bool canPlaceQueen(vector<string> & board, int rows, int columns, int row, int column)
        {
            //Make sure there aren't any queens above the one we are about to place in the current column
            for(int r=row;r>=0;r--)
            {
                if(board[r][column]=='Q')
                {
                    return false;
                }
            }
            
            //Make sure there aren't any queens to the left of the one we are about to place in the current row
            for(int c=column;c>=0;c--)
            {
                if(board[row][c]=='Q')
                {
                    return false;
                }
            }
            
            //Make sure there aren't any queens to the right of the one we are about to place in the current row
            for(int c=column;c<columns;c++)
            {
                if(board[row][c]=='Q')
                {
                    return false;
                }
            }
            
            //Make sure there aren't any queens in the diagonal going up in the left direction
            int r=row;
            
            int c=column;
            
            while(r >= 0 && c >= 0)
            {
                if(board[r][c]=='Q')
                {
                    return false;
                }
                
                r-=1;
                
                c-=1;
            }
            
            //Make sure there aren't any queens in the diagonal going up in the right direction
            r=row;
            
            c=column;
            
            while(r >= 0 && c < columns)
            {
                if(board[r][c]=='Q')
                {
                    return false;
                }
                
                r-=1;
                
                c+=1;
            }
            
            return true;
        }
    
        void dfs(int & result, vector<string> & board, int rows, int columns, int row)
        {
            //If we've reached the last row, then we have placed all N queens
            if(row==rows)
            {   
                //Increment the result
                result+=1;
                
                return;
            }
            
            //Loop through the columns
            for(int column=0;column<columns;column++)
            {
                //If we can place a queen in this column for the current row
                if(canPlaceQueen(board, rows, columns, row, column)==true)
                {   
                    //Place queen
                    board[row][column]='Q';
                    
                    //Recurse
                    dfs(result, board, rows, columns, row + 1);
                    
                    //Backtrack
                    board[row][column]='.';
                }
            }
        }
    
        int totalNQueens(int n)
        {
            int result=0;
            
            int rows=n;
            
            int columns=n;
            
            vector<string> board(rows, string(columns, '.'));
            
            int row=0;
            
            dfs(result, board, rows, columns, row);
            
            return result;
        }
};