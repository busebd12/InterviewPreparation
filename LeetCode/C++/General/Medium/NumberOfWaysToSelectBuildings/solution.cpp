#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by this explanation --> https://leetcode.com/problems/number-of-ways-to-select-buildings/discuss/2391922/Easy-to-follow-C%2B%2B-code

Time complexity: O(n) [where n is the length of s]
Space complexity: O(n)
*/

class Solution
{
    public:
        long long numberOfWays(string s)
        {
            long long result=0;
            
            int n=s.size();
            
            vector<long long> onesToTheLeft(n, 0);
            
            int ones=0;
            
            for(int i=0;i<n;i++)
            {
                if(s[i]=='0')
                {
                    onesToTheLeft[i]=ones;
                }
                else
                {
                    ones+=1;
                }
            }
            
            vector<long long> onesToTheRight(n, 0);
            
            ones=0;
            
            for(int i=n-1;i>=0;i--)
            {
                if(s[i]=='0')
                {
                    onesToTheRight[i]=ones;
                }
                else
                {
                    ones+=1;
                }
            }
            
            int zeros=0;
            
            vector<long long> zerosToTheLeft(n, 0);
            
            for(int i=0;i<n;i++)
            {
                if(s[i]=='1')
                {
                    zerosToTheLeft[i]=zeros;
                }
                else
                {
                    zeros+=1;
                }
            }
            
            zeros=0;
            
            vector<long long> zerosToTheRight(n, 0);
            
            for(int i=n-1;i>=0;i--)
            {
                if(s[i]=='1')
                {
                    zerosToTheRight[i]=zeros;
                }
                else
                {
                    zeros+=1;
                }
            }
            
            for(int i=0;i<n;i++)
            {
                long long ways=0;
                
                if(s[i]=='1')
                {
                    ways=zerosToTheRight[i] * zerosToTheLeft[i];
                }
                else
                {
                    ways=onesToTheRight[i] * onesToTheLeft[i];
                }
                
                result+=ways;
            }
            
            return result;
        }
};