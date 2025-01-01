#include <array>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(rows * columns)
Space complexity: O(rows * columns)
*/

class Solution
{
    private:
        array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

        const int HIT=-1;

        const int BRICK=1;

        const int STABLE=2;
    
    public:
        vector<int> hitBricks(vector<vector<int>> & grid, vector<vector<int>> & hits)
        {
            vector<int> result;

            int rows=grid.size();

            int columns=grid[0].size();

            int h=hits.size();

            result.resize(h, 0);

            //Iterate through hits
            for(vector<int> hit : hits)
            {
                int row=hit[0];

                int column=hit[1];

                //Mark brick as hit
                if(grid[row][column]==BRICK)
                {
                    grid[row][column]=HIT;
                }
            }

            //Iterate through all columns in the top row
            for(int column=0;column<columns;column++)
            {
                //If this column contains a brick
                if(grid[0][column]==BRICK)
                {
                    //Use DFS to mark this brick as well as all other bricks directly or indirectly connected to this brick as stable
                    markAllStableBricks(grid, rows, columns, 0, column);
                }
            }

            //Iterate through hits backwards so that we don't lose any information about the grid as we iterate
            //If we iterated forward, we would lose information as bricks (1s) would be changed to a different value
            for(int i=h-1;i>=0;i--)
            {
                int row=hits[i][0];

                int column=hits[i][1];

                //If we are at a hit brick
                if(grid[row][column]==HIT)
                {
                    //Change the brick from hit back to not hit
                    grid[row][column]=BRICK;

                    //If, originally, this brick was stable, then all bricks connected to this brick are also stable and we fall when this brick gets hit
                    if(isStable(grid, rows, columns, row, column)==true)
                    {
                        //Count the number of bricks that fall when this brick gets hit
                        //We are essentially counting the number of bricks in this connected component
                        int bricksThatFall=countBricksThatFall(grid, rows, columns, row, column);

                        //IMPORTANT: don't forget to subtract one from the total since the brick that was hit doens't count towards the total
                        result[i]=bricksThatFall - 1;
                    }
                }
            }

            return result;
        }

        void markAllStableBricks(vector<vector<int>> & grid, int rows, int columns, int row, int column)
        {
            if(row >= rows or row < 0 or column >= columns or column < 0 or grid[row][column]!=BRICK)
            {
                return;
            }

            grid[row][column]=STABLE;

            for(auto & [rowOffset, columnOffset] : directions)
            {
                int nextRow=row + rowOffset;

                int nextColumn=column + columnOffset;

                markAllStableBricks(grid, rows, columns, nextRow, nextColumn);
            }
        }

        int countBricksThatFall(vector<vector<int>> & grid, int rows, int columns, int row, int column)
        {
            if(row >= rows or row < 0 or column >= columns or column < 0 or grid[row][column]!=BRICK)
            {
                return 0;
            }

            int subproblemSolution=1;

            grid[row][column]=STABLE;

            for(auto & [rowOffset, columnOffset] : directions)
            {
                int nextRow=row + rowOffset;

                int nextColumn=column + columnOffset;

                subproblemSolution+=countBricksThatFall(grid, rows, columns, nextRow, nextColumn);
            }

            return subproblemSolution;
        }

        bool isStable(vector<vector<int>> & grid, int rows, int columns, int row, int column)
        {
            if(row==0)
            {
                return true;
            }

            for(auto & [rowOffset, columnOffset] : directions)
            {
                int nextRow=row + rowOffset;

                int nextColumn=column + columnOffset;

                bool inBounds=((nextRow >= 0 and nextRow < rows) and (nextColumn >= 0 and nextColumn < columns));

                if(inBounds==true and grid[nextRow][nextColumn]==STABLE)
                {
                    return true;
                }
            }

            return false;
        }
};