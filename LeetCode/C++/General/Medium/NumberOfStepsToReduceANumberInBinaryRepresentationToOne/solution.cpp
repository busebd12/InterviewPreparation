#include <algorithm>
#include <string>
using namespace std;

/*
Time complexity: O(n) [where n is the length of s]
Space complexity: O(1)
*/

class Solution
{
    public:
        int numSteps(string s)
        {
            int result=0;
            
            while(s.size() > 1)
            {
                int lastDigit=s.back() - '0';
                
                //If the binary string represents an odd number
                if((lastDigit & 1)==1)
                {
                    s=doBinaryAddition(s);
                }
                //If the binary string represents an even number
                else
                {
                    //Do a right shift - remove a character from end of the string
                    s.pop_back();
                }
                
                result+=1;
            }
            
            return result;
        }
    
        string doBinaryAddition(string s)
        {
            string binary{};
            
            string one="1";
            
            int m=one.size();
            
            int n=s.size();
            
            int i=n-1;
            
            int j=m-1;
            
            int carry=0;
            
            while(i >= 0 || j >= 0 || carry > 0)
            {
                int sum=0;
                
                if(i >= 0)
                {
                    sum+=(s[i] - '0');
                }
                
                if(j >= 0)
                {
                    sum+=(one[j] - '0');
                }
                
                sum+=carry;
                
                int digit=sum % 2;
                
                carry=sum / 2;
                
                binary.push_back(digit + '0');
                
                i-=1;
                
                j-=1;
            }
            
            reverse(begin(binary), end(binary));
            
            return binary;
        }
};