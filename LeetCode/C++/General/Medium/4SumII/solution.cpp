#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n^2) [where n is the length of nums1, nums2, nums3, and nums4]
Space complexity: O(s) [where s is the total number of sums]
*/

class Solution
{
    public:
        int fourSumCount(vector<int> & nums1, vector<int> & nums2, vector<int> & nums3, vector<int> & nums4)
        {
            int result=0;

            //Store the frequencies of sums
            unordered_map<int, int> frequencies;

            //Calculate the frequency of all two sums from nums1 and nums2
            for(int & num1 : nums1)
            {
                for(int & num2 : nums2)
                {
                    frequencies[num1 + num2]+=1;
                }
            }

            //So, if the two sum coming from nums1 and nums2 is x, then for each two sum value from nums3 and nums4, we just negate it and if the negative value is in the hashtable, we just add the frequency of that value to our result
            //x + -x = 0
            for(int & num3 : nums3)
            {
                for(int & num4 : nums4)
                {
                    int target=num3 + num4;

                    target*=-1;

                    if(frequencies.count(target))
                    {
                        result+=frequencies[target];
                    }
                }
            }

            return result;
        }
};