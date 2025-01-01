#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

/*
Solution: recursion + memoization.

Time complexity: O(n) [where n=length of stoneValue]
Space complexity: O(n)
*/

class Solution
{
    public:
        string stoneGameIII(vector<int> & stoneValue)
        {
            string result="";

            int n=stoneValue.size();

            vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(2, vector<int>(2, -1)));

            int total=accumulate(stoneValue.begin(), stoneValue.end(), 0);

            bool alice=true;

            bool bob=false;

            int index=0;

            int aliceScore=helper(stoneValue, memo, n, alice, bob, index);

            int remaining=total - aliceScore;

            if(remaining > aliceScore)
            {
                result="Bob";
            }
            else if(remaining < aliceScore)
            {
                result="Alice";
            }
            else
            {
                result="Tie";
            }

            return result;
        }

        int helper(vector<int> & stoneValue, vector<vector<vector<int>>> & memo, int n, bool alice, bool bob, int index)
        {
            if(index >= n)
            {
                return 0;
            }

            if(memo[index][alice][bob]!=-1)
            {
                return memo[index][alice][bob];
            }

            int subproblemSolution;

            int sum=0;

            //Alice's turn
            if(alice==true)
            {
                subproblemSolution=numeric_limits<int>::min();

                //Try choosing each of the next three stones (if possible)
                for(int i=index;i<index+3 and i<n;i++)
                {
                    sum+=stoneValue[i];

                    //Note: since it's Alice's turn, we want to maximize the score so Alice can win
                    subproblemSolution=max(subproblemSolution, sum + helper(stoneValue, memo, n, false, true, i + 1));
                }
            }
            
            //Bob's turn
            if(bob==true)
            {
                subproblemSolution=numeric_limits<int>::max();

                //Skip each of the next three stones
                for(int i=index;i<index+3 and i<n;i++)
                {
                    sum+=stoneValue[i];

                    //Note: since it's Bob's turn, we want to minimize Alice's score (minimizing Alice's score means that Bob's score is maximized),
                    //so we don't add sum to the helper recursive call like we did when it was Alice's score
                    subproblemSolution=min(subproblemSolution, helper(stoneValue, memo, n, true, false, i + 1));
                }
            }

            memo[index][alice][bob]=subproblemSolution;

            return subproblemSolution;
        }
};