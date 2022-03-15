#include <algorithm>
#include <vector>
#include <unordered_map>

/*
Solution 1: see comments for details. Note, this solution results in TLE.

Time complexity: O(n^2) [where n is the length of arr]
Space complexity: O(n)
*/

class Solution
{
    public:
        int longestSubsequence(vector<int> & arr, int difference)
        {
            int result=0;

            int n=arr.size();

            //DP vector with all values initialized to one
            //Each individual number within arr is a longest arithmetic subsequence of 1
            vector<int> dp(n, 1);

            //Iterate through arr
            for(int i=1;i<n;i++)
            {
                int current=arr[i];

                //Iterate through all elements of arr that come before the current number
                for(int j=0;j<i;j++)
                {
                    //If the current number minus arr[i] results in the required difference,
                    //then the longest arithmetic subsequence for the current element is 1 plus
                    //the longest arithmetic subsequence ending at arr[i] (we add 1 to count the current number)
                    if((current - arr[j])==difference)
                    {
                        dp[i]=1 + dp[j];
                    }
                }
            }

            //Iterate through all the DP vector values and find the largest one (this will be the answer)
            for(int i=0;i<n;i++)
            {
                result=max(result, dp[i]);
            }

            return result;
        }
};

/*
Solution 2: inspired from this post --> https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/discuss/1274490/C%2B%2B-clean-solution-with-Intuition

Time complexity: O(n) [where n is the number of elements in arr]
Space complexity: O(n)
*/
class Solution
{
    public:
        int longestSubsequence(vector<int> & arr, int difference)
        {
            int result=0;

            int n=arr.size();

            unordered_map<int, int> hashtable;
            
            for(int i=0;i<n;i++)
            {
                int target=arr[i] - difference;
                
                if(hashtable.count(target))
                {
                    hashtable[arr[i]]=hashtable[target] + 1;
                }
                else
                {
                    hashtable[arr[i]]=1;
                }
            }
            
            for(const auto & [key, value] : hashtable)
            {
                result=max(result, value);
            }
            
            return result;
        }
};