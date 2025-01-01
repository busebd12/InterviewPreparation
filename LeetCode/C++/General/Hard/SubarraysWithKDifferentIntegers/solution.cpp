#include <unordered_map>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of nums]
Space complexity: O(k)
*/

class Solution
{
    public:
        int subarraysWithKDistinct(vector<int> & nums, int k)
        {
            int result=0;

            int n=nums.size();

            //Count of subarrays that have [1, 2, 3, ..., k] distinct numbers
            int subarraysWithAtMostKDistinct=getSubarraysWithAtMostXDistinct(nums, n, k);

            //Count of subarrays that have [1, 2, 3, ..., k-1] distinct numbers
            int subarraysWithAtMostKMinusOneDistinct=getSubarraysWithAtMostXDistinct(nums, n, k - 1);
            //When you subtract [1, 2, 3, ..., k] and [1, 2, 3, ..., k-1], all you're left with is the count of subarrays that have exactly k distinct numbers
            result=subarraysWithAtMostKDistinct - subarraysWithAtMostKMinusOneDistinct;

            return result;
        }

        int getSubarraysWithAtMostXDistinct(vector<int> & nums, int n, int x)
        {
            int subarrays=0;
            
            unordered_map<int, int> hashmap;

            int distinct=0;

            int left=0;

            for(int right=0;right<n;right++)
            {
                hashmap[nums[right]]+=1;

                while(hashmap.size() > x)
                {
                    hashmap[nums[left]]-=1;

                    if(hashmap[nums[left]]==0)
                    {
                        hashmap.erase(nums[left]);
                    }

                    left+=1;
                }

                int length=(right - left) + 1;

                subarrays+=length;
            }

            return subarrays;
        }
};