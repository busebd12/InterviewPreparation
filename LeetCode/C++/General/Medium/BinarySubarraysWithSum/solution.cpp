#include <unordered_map>
#include <vector>
using namespace std;

/*
Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int numSubarraysWithSum(vector<int> & nums, int goal)
        {
            int result=0;

            int n=nums.size();

            unordered_map<int, int> hashmap;

            int prefixSum=0;

            for(int number : nums)
            {
                prefixSum+=number;

                if(prefixSum==goal)
                {
                    result+=1;
                }

                if(hashmap.find(prefixSum - goal)!=hashmap.end())
                {
                    result+=hashmap[prefixSum - goal];
                }

                if(hashmap.find(prefixSum)==hashmap.end())
                {
                    hashmap.emplace(prefixSum, 0);
                }

                hashmap[prefixSum]+=1;
            }

            return result;
        }
};