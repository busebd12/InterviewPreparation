#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/count-pairs-in-two-arrays/solutions/2028458/c-greedy-two-pointers-simple-solution-with-explanation/?orderBy=most_votes

Time complexity: O(n * log(n))
Space complexity: O(1)
*/

class Solution
{
    public:
        long long countPairs(vector<int> & nums1, vector<int> & nums2)
        {
            long long result=0;

            int n=nums1.size();

            for(int i=0;i<n;i++)
            {
                nums1[i]-=nums2[i];
            }

            sort(nums1.begin(), nums1.end());

            int i=0;

            int j=n-1;

            while(i < j)
            {
                int sum=nums1[i] + nums1[j];

                if(sum > 0)
                {
                    long long pairs=j - i;

                    result+=pairs;

                    j-=1;
                }
                else
                {
                    i+=1;
                }
            }

            return result;
        }
};