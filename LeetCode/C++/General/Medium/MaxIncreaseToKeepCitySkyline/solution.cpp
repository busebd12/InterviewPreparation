#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(n^2)
Space complexity: O(n)
*/

class Solution
{
    public:
        int maxIncreaseKeepingSkyline(vector<vector<int>> & grid)
        {
            int result=0;
            
            int n=grid.size();

            vector<int> rowMaxes(n, 0);

            vector<int> columnMaxes(n, 0);

            for(int row=0;row<n;row++)
            {
                int rowMax=*(max_element(grid[row].begin(), grid[row].end()));

                rowMaxes[row]=rowMax;
            }

            for(int column=0;column<n;column++)
            {
                int columnMax=-1;
                
                for(int row=0;row<n;row++)
                {
                    columnMax=max(columnMax, grid[row][column]);
                }

                columnMaxes[column]=columnMax;
            }

            for(int row=0;row<n;row++)
            {
                for(int column=0;column<n;column++)
                {
                    int replacement=min(rowMaxes[row], columnMaxes[column]);

                    int current=grid[row][column];
                    
                    int difference=(replacement >= current) ? replacement - current : current - replacement;

                    result+=difference;
                }
            }

            return result;
        }
};