#include <vector>
using namespace std;

/*
Solution: based on this resource --> https://www.youtube.com/watch?v=OsPXsE8qhOc

Time complexity: O(n) [where n=length of nums]
Space complexity: O(1)
*/

class Solution
{
    public:
        long long minimumReplacement(vector<int> & nums)
        {
            long long result=0;

            int n=nums.size();

            int previousLarger=nums[n - 1];

            for(int i=n-2;i>=0;i--)
            {
                int current=nums[i];

                if(current > previousLarger)
                {
                    int sizeOfSplit=current / previousLarger;

                    if((current % previousLarger)!=0)
                    {
                        sizeOfSplit+=1;
                    }

                    previousLarger=current / sizeOfSplit;

                    int operations=sizeOfSplit - 1;

                    result+=operations;
                }
                else
                {
                    previousLarger=current;
                }
            }

            return result;
        }
};