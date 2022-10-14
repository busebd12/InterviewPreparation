#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(rows * columns)
Space complexity: O(rows * columns)
*/

class Solution
{
    public:
        vector<vector<int>> restoreMatrix(vector<int> & rowSum, vector<int> & colSum)
        {
            vector<vector<int>> result;
            
            int rows=rowSum.size();
            
            int columns=colSum.size();
            
            result.resize(rows, vector<int>(columns, 0));
            
            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    int minSum=min(rowSum[row], colSum[column]);
                    
                    result[row][column]=minSum;
                    
                    rowSum[row]-=minSum;
                    
                    colSum[column]-=minSum;
                }
            }
            
            return result;
        }
};