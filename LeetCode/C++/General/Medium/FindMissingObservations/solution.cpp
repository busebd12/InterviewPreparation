#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/find-missing-observations/solutions/1500805/c-easy-to-understand-solution-with-comments-and-explanations-in-points/

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
        vector<int> missingRolls(vector<int> & rolls, int mean, int n)
        {
            vector<int> result;

            int m=rolls.size();

            int totalObservations=m + n;

            int sum=accumulate(rolls.begin(), rolls.end(), 0);

            int multiple=0;

            while((multiple / totalObservations)!=mean)
            {
                multiple+=totalObservations;
            }

            int sumNeeded=multiple - sum;

            if(sumNeeded < n or sumNeeded > 6 * n)
            {
                return result;
            }

            int remaining=sumNeeded % n;

            int distribution=sumNeeded / n;

            result.resize(n, distribution);

            for(int i=0;i<remaining;i++)
            {
                result[i]+=1;
            }

            return result;
        }
};