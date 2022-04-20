#include <algorithm>
#include <cstdlib>
#include <vector>

/*
Solution: Inspired by this post --> https://leetcode.com/problems/random-pick-with-weight/discuss/671415/C%2B%2B-Binary-Search-Approach(with-explanation)-(edited)

Time complexity: O(n + n log n) [where n is the length of w]
Space complexity: O(n)
*/

class Solution
{
    private:
        vector<int> prefixSums;
    
    public:
        Solution(vector<int> & w)
        {
            for(auto weight : w)
            {
                if(prefixSums.empty())
                {
                    prefixSums.emplace_back(weight);
                }
                else
                {
                    prefixSums.emplace_back(prefixSums.back() + weight);
                }
            }
        }

        int pickIndex()
        {
            int result=-1;
            
            int maxValue=prefixSums.back();
            
            int randomNumber=rand() % maxValue;
            
            auto itr=upper_bound(begin(prefixSums), end(prefixSums), randomNumber);
            
            result=distance(begin(prefixSums), itr);
            
            return result;
        }
};