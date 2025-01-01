#include <vector>
using namespace std;

/*
Time complexity: O(3^n) [where n is the total cells without obstacles]
Space complexity: O(n)
*/

class Solution
{
    private:
        array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    
    public:
        int uniquePathsIII(vector<vector<int>> & grid)
        {
            int result=0;

            int rows=grid.size();

            int columns=grid[0].size();

            int emptySquares=1;

            int startRow=-1;

            int startColumn=-1;

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(grid[row][column]==1)
                    {
                        startRow=row;

                        startColumn=column;
                    }
                    else if(grid[row][column]==0)
                    {
                        emptySquares+=1;
                    }
                }
            }

            int visitedEmptySquares=0;

            explore(grid, rows, columns, result, emptySquares, visitedEmptySquares, startRow, startColumn);

            return result;
        }

        void explore(vector<vector<int>> & grid, int rows, int columns, int & result, int emptySquares, int visitedEmptySquares, int row, int column)
        {
            if(row < 0 or row >= rows or column < 0 or column >= columns or grid[row][column]==-1)
            {
                return;
            }

            if(grid[row][column]==2)
            {
                if(visitedEmptySquares==emptySquares)
                {
                    result+=1;
                }

                return;
            }

            grid[row][column]=-1;

            for(auto & [rowOffset, columnOffset] : directions)
            {
                int nextRow=row + rowOffset;

                int nextColumn=column + columnOffset;

                explore(grid, rows, columns, result, emptySquares, visitedEmptySquares + 1, nextRow, nextColumn);
            }

            grid[row][column]=0;
        }
};