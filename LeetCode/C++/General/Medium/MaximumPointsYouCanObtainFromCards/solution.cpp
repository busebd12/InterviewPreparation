#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of cardPoints]
Space complexity: O(n)
*/

class Solution
{
    public:
        int maxScore(vector<int> & cardPoints, int k)
        {
            int result=0;
            
            int n=cardPoints.size();
            
            vector<int> prefixSums(n, 0);
            
            prefixSums[0]=cardPoints[0];
            
            for(int i=1;i<n;i++)
            {
                prefixSums[i]=prefixSums[i - 1] + cardPoints[i];
            }
            
            int totalPoints=prefixSums[n - 1];
            
            if(k==n)
            {
                return totalPoints;
            }
            
            int back=0;
            
            int front=n - k - 1;
            
            int smallestSubarraySum=numeric_limits<int>::max();
            
            //Calculate the smallest subarray sum of all subarrays of length n - k
            //If we remove the smallest n - k cards from the input array, then we will be left with the cards that give us our largest score
            while(front < n)
            {
                int sum=0;
                
                if(back - 1 >= 0)
                {
                    sum=prefixSums[front] - prefixSums[back - 1];
                }
                else
                {
                    sum=prefixSums[front];
                }
                
                smallestSubarraySum=min(smallestSubarraySum, sum);
                
                front+=1;
                
                back+=1;
            }
            
            result=totalPoints - smallestSubarraySum;
            
            return result;
        }
};