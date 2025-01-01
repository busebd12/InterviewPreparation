#include <vector>
using namespace std;

/*
Time complexity: O(rows * columns)
Space complexity: O(1)
*/

class Solution
{
    public:
        vector<int> findBall(vector<vector<int>> & grid)
        {
            vector<int> result;

            int rows=grid.size();

            int columns=grid[0].size();

            result.resize(columns, -1);

            for(int column=0;column<columns;column++) //O(columns)
            {
                int currentRow=0;

                int currentColumn=column;

                while(currentRow < rows) //O(rows)
                {
                    int direction=grid[currentRow][currentColumn];

                    if(direction==1 and currentColumn + 1 < columns and grid[currentRow][currentColumn + 1]==1)
                    {
                        currentRow+=1;

                        currentColumn+=1;
                    }
                    else if(direction==-1 and currentColumn - 1 >= 0 and grid[currentRow][currentColumn - 1]==-1)
                    {
                        currentRow+=1;

                        currentColumn-=1;
                    }
                    else
                    {
                        break;
                    }
                }

                //If the balls makes it out of the grid, it didn't get stuck
                if(currentRow==rows)
                {
                    result[column]=currentColumn;
                }
            }

            return result;
        }
};