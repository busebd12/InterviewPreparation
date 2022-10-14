#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/removing-minimum-number-of-magic-beans/discuss/1767106/C%2B%2B-oror-Easy-Solution-oror-Explained-oror

Time complexity: O(n) [where n is the length of beans]
Space complexity: O(n)
*/

class Solution
{
    public:
        long long minimumRemoval(vector<int> & beans)
        {
            long long result=numeric_limits<long long>::max();
            
            int n=beans.size();
            
            sort(begin(beans), end(beans));
            
            vector<long long> prefixSums(n, 0);
            
            prefixSums[0]=beans[0];
            
            for(int i=1;i<n;i++)
            {
                prefixSums[i]=prefixSums[i - 1] + beans[i];
            }
            
            for(int i=0;i<n;i++)
            {
                long long sumOfSmaller=(i==0) ? 0 : prefixSums[i - 1];
                
                long long sumOfLarger=prefixSums[n - 1] - prefixSums[i];
                
                long long numberOfLargerValues=n - i - 1;
                
                long long removalsFromLargerValues=numberOfLargerValues * static_cast<long long>(beans[i]);
                
                long long beansToRemove=sumOfLarger - removalsFromLargerValues + sumOfSmaller;
                
                result=min(result, beansToRemove);
            }
            
            return result;
        }
};