#include <bitset>
#include <string>
using namespace std;

/*
Solution: see comments.

Time complexity: O(32) --> O(1)
Space complexity: O(32) --> O(1)
*/

class Solution
{
    public:
        string encode(int num)
        {
            string result="";
            
            //Create a bitset representing the value num + 1
            bitset<32> b(num + 1);
            
            //Convert bitset to string
            string binaryString=b.to_string();
            
            int n=binaryString.size();
            
            int i=0;
            
            //Skip all leading zeros
            while(i < n and binaryString[i]=='0')
            {
                i+=1;
            }
            
            //Skip the most significant bit set (if there is one)
            if(i > 0 and i < n and binaryString[i]=='1')
            {
                i+=1;
            }
            
            //Append the rest of the binary string to the result string
            while(i < n)
            {
                result.push_back(binaryString[i]);
                
                i+=1;
            }
            
            return result;
        }
};