#include <unordered_map>
#include <vector>

/*
Solution: inspired by these posts

1) https://leetcode.com/problems/count-number-of-bad-pairs/solutions/2388121/Python-O(N)-solution-how-to-%22reverse%22-a-problem-to-make-it-easier-to-solve/

2) https://leetcode.com/problems/count-number-of-bad-pairs/solutions/2388149/java-y-x-f-y-f-x-linear-explained-ttt/

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(u) [where u is the number of unique differences]
*/

class Solution
{
    public:
        long long countBadPairs(vector<int> & nums)
        {
            long long result=0;

            int n=nums.size();

            unordered_map<int, int> hashmap;

            for(int i=0;i<n;i++)
            {
                int difference=i - nums[i];

                if(hashmap.find(difference)==hashmap.end())
                {
                    result+=i;
                }
                else
                {
                    result+=(i - hashmap[difference]);
                }

                if(hashmap.find(difference)==hashmap.end())
                {
                    hashmap.emplace(difference, 0);
                }

                hashmap[difference]+=1;
            }

            return result;
        }
};