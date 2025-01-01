#include <map>
#include <vector>
using namespace std;

class Solution
{
    public:
        bool nimGame(vector<int> & piles)
        {
            int n=piles.size();

            int remaining=n;

            map<vector<int>, bool> memo;

            return helper(memo, piles, n, remaining);
        }

        bool helper(map<vector<int>, bool> & memo, vector<int> & piles, int n, int remaining)
        {
            if(remaining==1)
            {
                return true;
            }

            if(memo.find(piles)!=memo.end())
            {
                return memo[piles];
            }

            bool subproblemSolution=false;

            for(int i=0;i<n;i++)
            {
                if(piles[i]==0)
                {
                    continue;
                }
                
                int stones=piles[i];

                for(int stone=1;stone<=stones;stone++)
                {
                    piles[i]-=stone;

                    if(piles[i]==0)
                    {
                        remaining-=1;
                    }

                    if(helper(memo, piles, n, remaining)==false)
                    {   
                        piles[i]+=stone;
                        
                        subproblemSolution=true;

                        memo[piles]=subproblemSolution;

                        return subproblemSolution;
                    }

                    if(piles[i]==0)
                    {
                        remaining+=1;
                    }

                    piles[i]+=stone;
                }
            }

            memo[piles]=subproblemSolution;

            return subproblemSolution;
        }
};