#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n) [where n is the length of arr]
Space complexity: O(n)
*/

class Solution
{
    public:
        int numOfSubarrays(vector<int> & arr)
        {
            int result=0;
            
            int n=arr.size();
            
            const int MOD=1000000007;
            
            int evenPrefixSums=0;
            
            int oddPrefixSums=0;
            
            vector<int> prefixSums(n, 0);
            
            prefixSums[0]=arr[0];
            
            if((prefixSums[0] % 2)==0)
            {
                evenPrefixSums+=1;
            }
            else
            {
                oddPrefixSums+=1;
            }
            
            for(int i=1;i<n;i++)
            {
                prefixSums[i]=prefixSums[i - 1] + arr[i];
                
                //If a prefix sum is even, then the only way to get odd prefix sums is to subtract
                //all odd prefix sums we've seen up to this point from the current prefix sum.
                //However, we don't actually need to perform the subtraction, just increment our result by the number of oddPrefixSums we've seen up to this point
                if((prefixSums[i] % 2)==0)
                {
                    result+=oddPrefixSums;
                    
                    result=result % MOD;
                    
                    evenPrefixSums+=1;
                }
                ////If a prefix sum is odd, then the only way to get odd prefix sums is to subtract all even prefix sums we've seen up to this point from the current prefix sum
                //However, we don't actually need to perform the subtraction, just increment our result by the number of evenPrefixSums we've seen up to this point
                else
                {
                    result+=evenPrefixSums;
                    
                    result=result % MOD;
                    
                    oddPrefixSums+=1;
                }
            }
            
            int p=prefixSums.size();
            
            //Loop through prefixSums a second time to ensure we don't miss any singular odd prefix sums
            for(int prefixSum : prefixSums)
            {
                if((prefixSum % 2)==1)
                {
                    result+=1;
                }
            }
            
            return result;
        }
};