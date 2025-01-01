#include <vector>
using namespace std;

/*
Solution: use binary search to find the minimum day.

Time complexity: O(n + (n * log(n))) [where n is the length of bloomDay]
Space complexity: O(1)
*/

class Solution
{
    public:
        int minDays(vector<int> & bloomDay, int m, int k)
        {
            int result=-1;

            int b=bloomDay.size();

            int high=*(max_element(bloomDay.begin(), bloomDay.end()));

            int low=1;

            while(low <= high)
            {
                int day=(low + (high - low)/2);

                if(canCreateBouquets(bloomDay, b, m, k, day)==true)
                {
                    result=day;

                    high=day - 1;
                }
                else
                {
                    low=day + 1;
                }
            }

            return result;
        }

        bool canCreateBouquets(vector<int> & bloomDay, int b, int m, int k, int day)
        {
            int bouquets=0;

            int consecutiveFlowers=0;

            for(int i=0;i<b;i++)
            {
                if(bloomDay[i] <= day)
                {
                    consecutiveFlowers+=1;

                    if((consecutiveFlowers % k)==0)
                    {
                        bouquets+=1;
                    }
                }
                else
                {
                    consecutiveFlowers=0;
                }
            }

            return bouquets >= m;
        }
};