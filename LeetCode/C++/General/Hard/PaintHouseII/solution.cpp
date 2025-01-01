#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

/*
Time complexity: O(n * m^2) [where n=number of rows in costs and m=number of columns in costs]
Space complexity: O(1)
*/

class Solution
{
    public:
        int minCostII(vector<vector<int>> & costs)
        {
            int result=0;

            int n=costs.size();

            for(int i=n-2;i>=0;i--)
            {
                int m=costs[i].size();
                
                for(int j=0;j<m;j++)
                {
                    int minValueFromNextRow=getMinValueFromNextRow(costs, m, i + 1, j);
                    
                    costs[i][j]+=minValueFromNextRow;
                }
            }

            result=*(min_element(costs[0].begin(), costs[0].end()));

            return result;
        }

        int getMinValueFromNextRow(vector<vector<int>> & costs, int m, int row, int index)
        {
            int minValue=numeric_limits<int>::max();

            if(index==0)
            {
                for(int k=index+1;k<m;k+=1)
                {
                    minValue=min(minValue, costs[row][k]);
                }
            }
            else if(index==m-1)
            {
                for(int k=0;k<m-1;k+=1)
                {
                    minValue=min(minValue, costs[row][k]);
                }
            }
            else
            {
                for(int k=0;k<index;k+=1)
                {
                    minValue=min(minValue, costs[row][k]);
                }

                for(int k=index+1;k<m;k+=1)
                {
                    minValue=min(minValue, costs[row][k]);
                }
            }

            return minValue;
        }
};