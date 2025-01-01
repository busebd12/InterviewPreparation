#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
    public:
        int bestTeamScore(vector<int> & scores, vector<int> & ages)
        {
            int result=0;

            int n=scores.size();

            vector<pair<int, int>> scoresAndAges;

            for(int i=0;i<n;i++)
            {
                int score=scores[i];

                int age=ages[i];

                scoresAndAges.emplace_back(score, age);
            }

            auto compareLikeThis=[] (const pair<int, int> & lhs, const pair<int, int> & rhs)
            {
                if(lhs.first!=rhs.first)
                {
                    return lhs.first < rhs.first;
                }
                else
                {
                    return lhs.second < rhs.second;
                }
            };

            sort(scoresAndAges.begin(), scoresAndAges.end(), compareLikeThis);

            int limit=1000;

            vector<vector<int>> memo(limit + 1, vector<int>(limit + 1, -1));

            int index=0;

            int previousMaxAge=0;

            result=helper(scoresAndAges, memo, n, index, previousMaxAge);

            return result;
        }

        int helper(vector<pair<int, int>> & scoresAndAges, vector<vector<int>> & memo, int n, int index, int previousMaxAge)
        {
            if(index >= n)
            {
                return 0;
            }

            if(memo[index][previousMaxAge]!=-1)
            {
                return memo[index][previousMaxAge];
            }

            int subproblemSolution=0;

            int take=0;

            int currentAge=scoresAndAges[index].second;

            int currentScore=scoresAndAges[index].first;

            if(currentAge >= previousMaxAge)
            {
                take=currentScore + helper(scoresAndAges, memo, n, index + 1, max(currentAge, previousMaxAge));
            }

            int skip=helper(scoresAndAges, memo, n, index + 1, previousMaxAge);

            subproblemSolution=max(take, skip);

            memo[index][previousMaxAge]=subproblemSolution;

            return subproblemSolution;
        }
};