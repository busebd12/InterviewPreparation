#include <vector>
using namespace std;

class Solution
{
    private:
        int MOD=1e9 + 7;
    
    public:
        int countGoodStrings(int low, int high, int zero, int one)
        {
            int result=0;

            for(int length=low;length<=high;length++)
            {
                int numberOfStrings=helper(zero, one, length) % MOD;

                result+=numberOfStrings;

                result%=MOD;
            }

            return result;
        }

        int helper(int zero, int one, int length)
        {
            if(length < 0)
            {
                return 0;
            }

            if(length==0)
            {
                return 1;
            }

            int subproblemSolution=0;

            int addZeros=helper(zero, one, length - zero) % MOD;

            int addOnes=helper(zero, one, length - one) % MOD;

            subproblemSolution+=addZeros;

            subproblemSolution%=MOD;

            subproblemSolution+=addOnes;

            subproblemSolution%=MOD;

            return subproblemSolution;
        }
};

class Solution
{
    private:
        vector<int> memo;
        
        int MOD=1e9 + 7;
    
    public:
        int countGoodStrings(int low, int high, int zero, int one)
        {
            int result=0;

            memo.resize(high + 1, -1);

            for(int length=low;length<=high;length++)
            {
                int numberOfStrings=helper(zero, one, length) % MOD;

                result+=numberOfStrings;

                result%=MOD;
            }

            return result;
        }

        int helper(int zero, int one, int length)
        {
            if(length < 0)
            {
                return 0;
            }

            if(length==0)
            {
                return 1;
            }

            if(memo[length]!=-1)
            {
                return memo[length];
            }

            int subproblemSolution=0;

            int addZeros=helper(zero, one, length - zero) % MOD;

            int addOnes=helper(zero, one, length - one) % MOD;

            subproblemSolution+=addZeros;

            subproblemSolution%=MOD;

            subproblemSolution+=addOnes;

            subproblemSolution%=MOD;

            memo[length]=subproblemSolution;

            return subproblemSolution;
        }
};