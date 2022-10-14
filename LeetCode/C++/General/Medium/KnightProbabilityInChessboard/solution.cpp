#include <array>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
    private:
        array<pair<int, int>, 8> directions={{{-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {2, 1}, {2, -1}}};
        
        vector<vector<vector<double>>> memo;
    
    public:
        double knightProbability(int n, int k, int row, int column)
        {
            memo.resize(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
            
            return dfs(n, k, row, column);
        }
    
        double dfs(int n, int k, int row, int column)
        {
            if(row < 0 or row > n-1 or column < 0 or column > n-1)
            {
                return 0;
            }
            
            if(k==0)
            {
                return 1;
            }
            
            if(memo[row][column][k]!=-1)
            {
                return memo[row][column][k];
            }
            
            double subproblemSolution=0;
            
            for(auto & [rowOffset, columnOffset] : directions)
            {
                double pathProbability=0.125 * (dfs(n, k-1, row + rowOffset, column + columnOffset));
                
                subproblemSolution+=pathProbability;
            }
            
            memo[row][column][k]=subproblemSolution;
            
            return subproblemSolution;
        }
};