#include <vector>
using namespace std;

/*
Solutions are based on this post --> https://leetcode.com/problems/number-of-music-playlists/solutions/1637225/recursive-definition-with-detailed-explanation/
*/

/*
Solution 1: depth-first search + recursion

Time complexity: O(2^n)
Space complexity: O(goal)
*/

class Solution
{
    public:
        int numMusicPlaylists(int n, int goal, int k)
        {
            long result=0;

            int totalSongs=0;

            int uniqueSongs=0;

            const int MOD=1e9 + 7;

            result=helper(n, goal, k, MOD, uniqueSongs, totalSongs);
            
            result%=MOD;

            return (int)result;
        }

        long helper(int n, int goal, int k, const int MOD, int uniqueSongs, int totalSongs)
        {
            if(totalSongs==goal)
            {
                return uniqueSongs==n;
            }

            long subproblemSolution=0;

            if(uniqueSongs < n)
            {
                long next=(n - uniqueSongs) * helper(n, goal, k, MOD, uniqueSongs + 1, totalSongs + 1) % MOD;

                subproblemSolution+=next;

                subproblemSolution%=MOD;
            }

            if(uniqueSongs > k)
            {
                long next=(uniqueSongs - k) * helper(n, goal, k, MOD, uniqueSongs, totalSongs + 1) % MOD;
                
                subproblemSolution+=next;

                subproblemSolution%=MOD;
            }

            return subproblemSolution % MOD;
        }
};

/*
Solution 2: recursion + memoization

Time complexity: O(n * goal)
Space complexity: O(n * goal)
*/

class Solution
{
    public:
        int numMusicPlaylists(int n, int goal, int k)
        {
            long result=0;

            int totalSongs=0;

            int uniqueSongs=0;

            const int MOD=1e9 + 7;

            vector<vector<long>> memo(n + 1, vector<long>(goal + 1, -1));

            result=helper(memo, n, goal, k, MOD, uniqueSongs, totalSongs);
            
            result%=MOD;

            return (int)result;
        }

        long helper(vector<vector<long>> & memo, int n, int goal, int k, const int MOD, int uniqueSongs, int totalSongs)
        {
            if(totalSongs==goal)
            {
                return uniqueSongs==n;
            }

            if(memo[uniqueSongs][totalSongs]!=-1)
            {
                return memo[uniqueSongs][totalSongs];
            }

            long subproblemSolution=0;

            if(uniqueSongs < n)
            {
                long next=(n - uniqueSongs) * helper(memo, n, goal, k, MOD, uniqueSongs + 1, totalSongs + 1) % MOD;

                subproblemSolution+=next;

                subproblemSolution%=MOD;
            }

            if(uniqueSongs > k)
            {
                long next=(uniqueSongs - k) * helper(memo, n, goal, k, MOD, uniqueSongs, totalSongs + 1) % MOD;
                
                subproblemSolution+=next;

                subproblemSolution%=MOD;
            }

            memo[uniqueSongs][totalSongs]=(subproblemSolution % MOD);

            return subproblemSolution % MOD;
        }
};