#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution

Submission result: accepted.

Time complexity: O(n + m) [where n=length of nums1 and m=length of nums2]
Space complexity: O(u + v) [where u=unique values in nums1 and v=unique values in nums2]
*/

class Solution
{
    public:
        vector<vector<int>> findDifference(vector<int> & nums1, vector<int> & nums2)
        {
            vector<vector<int>> result;

            unordered_map<int, int> nums1Hashmap;

            unordered_map<int, int> nums2Hashmap;

            for(int number : nums1)
            {
                nums1Hashmap[number]+=1;
            }

            for(int number : nums2)
            {
                nums2Hashmap[number]+=1;
            }

            vector<int> first;

            for(auto & [number, frequency] : nums1Hashmap)
            {
                if(nums2Hashmap.find(number)==nums2Hashmap.end())
                {
                    first.push_back(number);
                }
            }

            vector<int> second;

            for(auto & [number, frequency] : nums2Hashmap)
            {
                if(nums1Hashmap.find(number)==nums1Hashmap.end())
                {
                    second.push_back(number);
                }
            }

            result.push_back(first);

            result.push_back(second);

            return result;
        }
};