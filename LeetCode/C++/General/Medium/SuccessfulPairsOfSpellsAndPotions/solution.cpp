#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> successfulPairs(vector<int> & spells, vector<int> & potions, long long success)
        {
            vector<int> result;

            int n=spells.size();

            int m=potions.size();

            result.resize(n, 0);

            sort(potions.begin(), potions.end());

            for(int i=0;i<n;i++)
            {
                int spell=spells[i];

                long long times=success / spell;

                long long remainder=success % spell;

                if(remainder==0)
                {
                    auto lowerBoundItr=lower_bound(potions.begin(), potions.end(), times);

                    if(lowerBoundItr!=potions.end())
                    {
                        int pairs=distance(lowerBoundItr, potions.end());

                        result[i]=pairs;
                    }
                }
                else
                {
                    auto upperBoundItr=upper_bound(potions.begin(), potions.end(), times);

                    if(upperBoundItr!=potions.end())
                    {
                        int pairs=distance(upperBoundItr, potions.end());

                        result[i]=pairs;
                    }
                }
            }

            return result;
        }
};

class Solution
{
    public:
        vector<int> successfulPairs(vector<int> & spells, vector<int> & potions, long long success)
        {
            vector<int> result;

            int n=spells.size();

            int m=potions.size();

            result.resize(n, 0);

            sort(potions.begin(), potions.end());

            for(int i=0;i<n;i++)
            {
                long long spell=spells[i];

                long long times=success / spell;

                long long remainder=success % spell;

                int pairs=binarySearch(potions, m, success, spell);

                result[i]=pairs;
            }

            return result;
        }

        int binarySearch(vector<int> & potions, int m, long long success, long long spell)
        {
            int pairs=0;

            int low=0;

            int high=m-1;

            int firstPotionIndex=m;

            while(low <= high)
            {
                int middle=(low + (high - low)/2);

                long long potion=potions[middle];

                long long product=spell * potion;

                if(product >= success)
                {
                    firstPotionIndex=middle;
                    
                    high=middle - 1;
                }
                else
                {
                    low=middle + 1;
                }
            }

            pairs=m - firstPotionIndex;

            return pairs;
        }
};