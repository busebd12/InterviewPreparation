#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/discuss/377522/C%2B%2B-forward-and-backward-solution-with-explanation-and-picture

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int maximumSum(vector<int> & arr)
        {
            int result=0;
            
            int n=arr.size();
            
            int maxSumNoDeletions=0;
            
            int maxSumNoDeletionsLeft=arr[0];
            
            int currentMaxSumLeft=arr[0];
            
            vector<int> maxSumEndingHereLeft(n, 0);
            
            maxSumEndingHereLeft[0]=arr[0];
            
            for(int i=1;i<n;i++)
            {
                int includeCurrentNumber=arr[i] + currentMaxSumLeft;
                
                int startOverAtCurrentNumber=arr[i];
                
                currentMaxSumLeft=max(includeCurrentNumber, startOverAtCurrentNumber);
                
                maxSumNoDeletionsLeft=max(maxSumNoDeletionsLeft, currentMaxSumLeft);
                
                maxSumEndingHereLeft[i]=currentMaxSumLeft;
            }
            
            vector<int> maxSumEndingHereRight(n, 0);
            
            int maxSumNoDeletionsRight=arr[n - 1];
            
            int currentMaxSumRight=arr[n - 1];
            
            maxSumEndingHereRight[n - 1]=arr[n - 1];
            
            for(int i=n-2;i>=0;i--)
            {
                int includeCurrentNumber=arr[i] + currentMaxSumRight;
                
                int startOverAtCurrentNumber=arr[i];
                
                currentMaxSumRight=max(includeCurrentNumber, startOverAtCurrentNumber);
                
                maxSumNoDeletionsRight=max(maxSumNoDeletionsRight, currentMaxSumRight);
                
                maxSumEndingHereRight[i]=currentMaxSumRight;
            }
            
            maxSumNoDeletions=max(maxSumNoDeletionsLeft, maxSumNoDeletionsRight);
            
            result=maxSumNoDeletions;
            
            for(int i=1;i<n-1;i++)
            {
                int subarraySumMinusCurrentNumber=maxSumEndingHereLeft[i - 1] + maxSumEndingHereRight[i + 1];
                
                result=max(result, subarraySumMinusCurrentNumber);
            }
            
            return result;
        }
};