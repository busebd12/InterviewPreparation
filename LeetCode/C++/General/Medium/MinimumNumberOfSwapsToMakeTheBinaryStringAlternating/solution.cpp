#include <algorithm>
#include <string>
using namespace std;

/*
Time complexity: O(n) [where n is the length of s]
Space complexity: O(n)
*/

class Solution
{
    public:
        int minSwaps(string s)
        {
            int result=0;
            
            int n=s.size();
            
            int ones=0;
            
            int zeros=0;
            
            for(int i=0;i<n;i++)
            {
                if(s[i]=='1')
                {
                    ones+=1;
                }
                else
                {
                    zeros+=1;
                }
            }
            
            int difference=abs(ones - zeros);
            
            if(difference > 1)
            {
                return -1;
            }
            
            string startWithOne(n, '$');
            
            for(int i=0;i<n;i++)
            {
                if((i % 2)==0)
                {
                    startWithOne[i]='1';
                }
                else
                {
                    startWithOne[i]='0';
                }
            }
            
            string startWithZero(n, '$');
            
            for(int i=0;i<n;i++)
            {
                if((i % 2)==0)
                {
                    startWithZero[i]='0';
                }
                else
                {
                    startWithZero[i]='1';
                }
            }
            
            if(zeros > ones)
            {
                result=getSwaps(s, startWithZero, n);
            }
            else if(ones > zeros)
            {
                result=getSwaps(s, startWithOne, n);
            }
            else
            {
                result=min(getSwaps(s, startWithOne, n), getSwaps(s, startWithZero, n));
            }
            
            return result;
        }
    
        int getSwaps(string & s, string & alternating, int n)
        {
            int swaps=0;
            
            for(int i=0;i<n;i++)
            {
                if(s[i]!=alternating[i])
                {
                    swaps+=1;
                }
            }
            
            return swaps / 2;
        }
};