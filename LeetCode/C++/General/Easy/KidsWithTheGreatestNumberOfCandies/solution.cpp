#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<bool> kidsWithCandies(vector<int> & candies, int extraCandies)
        {
            vector<bool> result;

            int c=candies.size();

            result.resize(c, true);

            int maxCandies=candies[0];

            for(int i=1;i<c;i++)
            {
                maxCandies=max(maxCandies, candies[i]);
            }

            for(int i=0;i<c;i++)
            {
                int amount=candies[i];
                
                int newAmount=amount + extraCandies;

                result[i]=(newAmount >= maxCandies);
            }

            return result;
        }
};