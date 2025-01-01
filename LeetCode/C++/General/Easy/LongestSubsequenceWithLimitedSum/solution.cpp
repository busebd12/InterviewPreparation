#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n log n) [where n is the length of nums]
Space complexity: O(n + m) [where m is the length of queries]
*/

class Solution
{   
    public:
        vector<int> answerQueries(vector<int> & nums, vector<int> & queries)
        {
            vector<int> result;

            int n=nums.size();

            int m=queries.size();

            result.resize(m, 0); //O(m)

            //Sort nums in increasing order
            sort(nums.begin(), nums.end()); //O(n log n)

            vector<int> prefixSums(n, 0); //O(n)

            //Calculate prefix sums
            //Note: since we sorted nums in increasing order, each prefix sum represents the sum of the maximum amount of numbers from nums
            //Put another way, the numbers from num that sum to the prefix sum represent the longest subsequence
            prefixSums[0]=nums[0];

            for(int i=1;i<n;i++) //O(n)
            {
                prefixSums[i]=prefixSums[i - 1] + nums[i];
            }

            //Iterate through the queries
            for(int i=0;i<m;i++) //O(m)
            {
                int query=queries[i];

                //std::upper_bound returns an iterator pointing to the first prefix sum that is larger than query
                auto itr=upper_bound(prefixSums.begin(), prefixSums.end(), query); //O(n log n)

                //If itr is not equal to prefixSums.begin(), that means there is at least one prefix sum that is less than or equal to query
                //This is the prefixSum we are looking for
                if(itr!=prefixSums.begin())
                {
                    //Move the iterator backwards in prefixSums by one to point to the prefix sum that is less than or equal to query
                    itr=prev(itr);

                    //Calculate the distance between itr and prefixSums.begin()
                    int dist=distance(prefixSums.begin(), itr);

                    //We need to add one to dist since each index in prefixSums is the sum of index + 1 number of values
                    //prefixSums[2]=nums[0] + nums[i] + nums[2] --> three values but index only equals two; 2+1=3
                    result[i]=dist + 1;
                }
            }

            return result;
        }
};