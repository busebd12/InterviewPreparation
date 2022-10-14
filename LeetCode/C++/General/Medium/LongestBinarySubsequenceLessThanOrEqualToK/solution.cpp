#include <algorithm>
#include <string>
using namespace std;

/*
Time complexity: O(n + k) [where n is the length of s]
Space complexity: O(1)
*/

class Solution
{
    public:
        int longestSubsequence(string s, int k)
        {
            int result=0;
            
            int n=s.size();
            
            int placeValue=1;
            
            int total=0;
            
            for(int i=n-1;i>=0 and total + placeValue <= k;i--)
            {
                if(s[i]=='1')
                {
                    result+=1;
                    
                    total+=placeValue;
                }
                
                placeValue=placeValue << 1;
            }
            
            int zeros=count(begin(s), end(s), '0');
            
            result+=zeros;
            
            return result;
        }
};