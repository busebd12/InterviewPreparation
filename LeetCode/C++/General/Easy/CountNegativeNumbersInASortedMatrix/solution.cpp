#include <vector>
using namespace std;

class Solution
{
    public:
        int countNegatives(vector<vector<int>> & grid)
        {
            int result=0;

            int rows=grid.size();

            int columns=grid[0].size();

            for(int row=0;row<rows;row+=1)
            {
                for(int column=0;column<columns;column+=1)
                {
                    if(grid[row][column] < 0)
                    {
                        result+=1;
                    }
                }
            }

            return result;
        }
};