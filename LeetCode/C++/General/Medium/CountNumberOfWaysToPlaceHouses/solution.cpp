#include <vector>
using namespace std;

/*
Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    private:
        const int MOD=1e9 + 7;
    
    public:
        int countHousePlacements(int n)
        {
            long result=0;

            vector<long> memo(n + 1, -1);

            long half=helper(memo, n);

            half=half % MOD;

            result=half * half;

            return result % MOD;
        }

        long helper(vector<long> & memo, int n)
        {
            if(n==1)
            {
                return 2;
            }

            if(n==2)
            {
                return 3;
            }

            if(memo[n]!=-1)
            {
                return memo[n];
            }

            long first=helper(memo, n - 1) % MOD;

            long second=helper(memo, n - 2) % MOD;

            long subproblemSolution=first + second;

            memo[n]=subproblemSolution;

            return subproblemSolution;
        }
};