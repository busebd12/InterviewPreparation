#include <vector>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> getFactors(int n)
        {
            vector<vector<int>> result;
            
            vector<int> combination;
            
            int start=2;
            
            dfs(combination, result, n, start);
            
            return result;
        }
    
        void dfs(vector<int> & combination, vector<vector<int>> & result, int n, int start)
        {
            if(n <= 1)
            {
                if(!combination.empty() and combination.size() > 1)
                {   
                    result.push_back(combination);
                }
            }
            
            for(int number=start;number<=n;number++)
            {
                if((n % number)==0)
                {
                    combination.push_back(number);
                    
                    dfs(combination, result, n / number, number);
                    
                    combination.pop_back();
                }
            }
        }
};