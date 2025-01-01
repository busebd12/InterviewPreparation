#include <vector>
using namespace std;

/*
Solution 1: recursion

Time complexity: O(2^n) [where n is the length of piles]
Space complexity: O(n)
*/

class Solution
{
    public:
        bool stoneGame(vector<int> & piles)
        {
            bool result=false;
            
            int n=piles.size();

            int alicesStones=0;

            int bobsStones=0;

            int left=0;

            int right=n - 1;

            bool alicesTurn=true;

            result=helper(piles, n, alicesStones, bobsStones, left, right, alicesTurn);

            return result;
        }

        bool helper(vector<int> & piles, int n, int alicesStones, int bobsStones, int left, int right, bool alicesTurn)
        {
            if(left > right)
            {
                return alicesStones > bobsStones;
            }

            bool subproblemSolution=false;

            bool aliceWins=false;

            bool bobWins=false;

            if(alicesTurn==true)
            {
                alicesTurn=false;
                
                bool aliceTakesFirstPile=helper(piles, n, alicesStones + piles[left], bobsStones, left + 1, right, alicesTurn);

                bool aliceTakesLastPile=helper(piles, n, alicesStones + piles[right], bobsStones, left, right - 1, alicesTurn);

                aliceWins=aliceTakesFirstPile or aliceTakesLastPile;
            }
            else
            {
                alicesTurn=true;

                bool bobTakesFirstPile=helper(piles, n, alicesStones, bobsStones + piles[left], left + 1, right, alicesTurn);

                bool bobTakesLastPile=helper(piles, n, alicesStones, bobsStones + piles[right], left, right - 1, alicesTurn);

                bobWins=bobTakesFirstPile or bobTakesLastPile;
            }

            subproblemSolution=(bobWins==true ? false : true);

            return subproblemSolution;
        }
};

/*
Solution 2: recursion + memoization

Time complexity: O(n) [where n is the length of piles]
Space complexity: O(n^2)
*/

class Solution
{
    public:
        bool stoneGame(vector<int> & piles)
        {
            bool result=false;
            
            int n=piles.size();

            int alicesStones=0;

            int bobsStones=0;

            int left=0;

            int right=n - 1;

            bool alicesTurn=true;

            vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));

            result=helper(piles, memo, n, alicesStones, bobsStones, left, right, alicesTurn);

            return result;
        }

        bool helper(vector<int> & piles, vector<vector<int>> & memo, int n, int alicesStones, int bobsStones, int left, int right, int alicesTurn)
        {
            if(left > right)
            {
                return alicesStones > bobsStones;
            }

            if(memo[left][right]!=-1)
            {
                return memo[left][right];
            }

            bool subproblemSolution=false;

            bool aliceWins=false;

            bool bobWins=false;

            if(alicesTurn==1)
            {
                alicesTurn=0;
                
                bool aliceTakesFirstPile=helper(piles, memo, n, alicesStones + piles[left], bobsStones, left + 1, right, alicesTurn);

                bool aliceTakesLastPile=helper(piles, memo, n, alicesStones + piles[right], bobsStones, left, right - 1, alicesTurn);

                aliceWins=aliceTakesFirstPile or aliceTakesLastPile;
            }
            else
            {
                alicesTurn=1;

                bool bobTakesFirstPile=helper(piles, memo, n, alicesStones, bobsStones + piles[left], left + 1, right, alicesTurn);

                bool bobTakesLastPile=helper(piles, memo, n, alicesStones, bobsStones + piles[right], left, right - 1, alicesTurn);

                bobWins=bobTakesFirstPile or bobTakesLastPile;
            }

            subproblemSolution=(bobWins==true ? false : true);

            memo[left][right]=subproblemSolution;

            return subproblemSolution;
        }
};