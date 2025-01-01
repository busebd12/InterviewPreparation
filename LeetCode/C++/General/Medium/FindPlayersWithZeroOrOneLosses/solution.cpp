#include <vector>
using namespace std;

/*
Time complexity: O(m) [where m is the length of matches]
Space complexity: O(100001) --> O(1)
*/

class Solution
{
    public:
        vector<vector<int>> findWinners(vector<vector<int>> & matches)
        {
            vector<vector<int>> result;

            const int limit=1e5 + 1;

            vector<int> losses(limit, 0);

            vector<bool> playedAtLeastOneMatch(limit, false);

            for(vector<int> match : matches)
            {
                int winner=match[0];

                int loser=match[1];

                playedAtLeastOneMatch[winner]=true;

                playedAtLeastOneMatch[loser]=true;
            }

            for(vector<int> match : matches)
            {
                int winner=match[0];

                int loser=match[1];

                losses[loser]+=1;
            }

            vector<int> playersWithNoLosses;

            for(int player=0;player<limit;player++)
            {
                if(losses[player]==0 and playedAtLeastOneMatch[player]==true)
                {
                    playersWithNoLosses.push_back(player);
                }
            }

            result.push_back(playersWithNoLosses);

            vector<int> playersWithOneLoss;

            for(int player=0;player<limit;player++)
            {
                if(losses[player]==1 and playedAtLeastOneMatch[player]==true)
                {
                    playersWithOneLoss.push_back(player);
                }
            }
            
            result.push_back(playersWithOneLoss);

            return result;
        }
};