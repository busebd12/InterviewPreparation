#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * 1. Recursion + Depth-first search.
 *
 * Time complexity: O(N^2) [where N is the input number]
 * Space complexity: O(N)
 *
 * 2. Recursion + Depth-first search + memoization
 *
 * Time complexity: O(N^2)
 * Space complexity: O(N^2)
 *
 * 3. Bottom-up dynamic programming/tabulization
 *
 * Time complexity: O(N^2)
 * Space complexity: O(N)
 */

class Solution
{
    public:
        bool dfs(int N)
        {
            if(N==1)
            {
                return false;
            }

            bool subproblem=false;

            for(int number=1;number<N;number++)
            {
                if((N % number)==0)
                {
                    if(!dfs(N-number))
                    {
                        subproblem=true;

                        return subproblem;
                    }
                }
            }

            return subproblem;
        }

        bool divisorGame(int N)
        {
            if(N <= 1)
            {
                return false;
            }

            return dfs(N);
        }
};

class Solution
{
    public:
        bool memoization(int N, std::vector<int> & dp)
        {
            if(N==1)
            {
                return false;
            }

            if(dp[N]!=-1)
            {
                return dp[N];
            }

            bool subproblem=false;

            for(int number=1;number<N;number++)
            {
                if((N % number)==0)
                {
                    if(!memoization(N-number, dp))
                    {
                        subproblem=true;

                        return subproblem;
                    }
                }
            }

            dp[N]=subproblem;

            return subproblem;
        }

        bool divisorGame(int N)
        {
            if(N <= 1)
            {
                return false;
            }

            std::vector<int> dp(N + 1, -1);

            return memoization(N, dp);
        }
};

class Solution
{
    public:
        bool divisorGame(int N)
        {
            if(N <= 1)
            {
                return false;
            }

            std::vector<bool> dp(N + 1, false);

            for(int number=2;number<=N;number++)
            {
                for(int x=1;x<number;x++)
                {
                    if((number % x)==0)
                    {
                        dp[number]=dp[number] || !dp[number-x];
                    }
                }
            }

            return dp[N];
        }
};