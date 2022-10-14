#include <utility>
#include <vector>
using namespace std;

/*
Algorithm:

1) Create a list of pairs of indices representing the local inversions.

2) For eaching local inversion index pair, swap the two numbers in nums.

3) After swapping, if nums becomes sorted, return true; else, return false.

Time complexity: O(n + p) [where n is the length of nums and p is the total number of local inversion index pairs]
Space complexity: O(p)
*/

class Solution
{
    public:
        bool isIdealPermutation(vector<int> & nums)
        {
            int n=nums.size();
            
            vector<pair<int, int>> indexPairs=getLocalInversionsIndexPairs(nums, n);
            
            for(pair<int, int> & indexPair : indexPairs)
            {
                int i=indexPair.first;
                
                int j=indexPair.second;
                
                swap(nums[i], nums[j]);
            }
            
            return is_sorted(begin(nums), end(nums));
        }
    
        vector<pair<int, int>> getLocalInversionsIndexPairs(vector<int> & nums, int n)
        {
            vector<pair<int, int>> indexPairs;
            
            int localInversions=0;
            
            for(int i=0;i<n;i++)
            {
                if(i + 1 < n)
                {
                    if(nums[i] > nums[i + 1])
                    {
                        indexPairs.emplace_back(i, i + 1);
                    }
                }
            }
            
            return indexPairs;
        }
};