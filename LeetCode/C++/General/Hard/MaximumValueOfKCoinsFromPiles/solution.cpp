#include <algorithm>
#include <vector>
using namespace std;

class Solution
{   
    public:
        int maxValueOfCoins(vector<vector<int>> & piles, int k)
        {
            int result=0;

            int n=piles.size();

            vector<int> pilesIndex(n, 0);

            vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));

            int index=0;

            result=helper(piles, memo, pilesIndex, n, k, index);

            return result;
        }

        int helper(vector<vector<int>> & piles, vector<vector<int>> & memo, vector<int> & pilesIndex, int n, int k, int index)
        {
            if(index > n-1 or k==0)
            {
                return 0;
            }

            if(memo[index][k]!=-1)
            {
                return memo[index][k];
            }

            int subproblemSolution=0;

            int currentPileSum=0;

            for(int j=0;j<piles[index].size();j+=1)
            {
                currentPileSum+=piles[index][j];

                int coins=j + 1;
                
                if((k - coins) >= 0)
                {
                    int pickFromCurrentPile=currentPileSum + helper(piles, memo, pilesIndex, n, k - coins, index + 1);

                    subproblemSolution=max(subproblemSolution, pickFromCurrentPile);
                }
            }

            int skipCurrentPile=helper(piles, memo, pilesIndex, n, k, index + 1);

            subproblemSolution=max(subproblemSolution, skipCurrentPile);

            memo[index][k]=subproblemSolution;

            return subproblemSolution;
        }
};