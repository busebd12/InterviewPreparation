#include <deque>
#include <string>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/remove-k-digits/discuss/607570/C%2B%2B-solution-8ms-with-detailed-explanation

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        string removeKdigits(string num, int k)
        {
            string result{};
            
            int n=num.size();
            
            if(k==n)
            {
                return "0";
            }
            
            deque<char> stack;
            
            for(int i=0;i<n;i++)
            {
                if(stack.empty())
                {
                    stack.emplace_back(num[i]);
                }
                else
                {
                    //If the current digit is less than the digit at the top of the stack
                    while(!stack.empty() && stack.back() - '0' > num[i] - '0' && k > 0)
                    {
                        stack.pop_back();
                        
                        k-=1;
                    }
                    
                    stack.emplace_back(num[i]);
                }
            }
            
            //If we didn't finsish removing all k digits or the string is all increasing digits
            while(!stack.empty() && k > 0)
            {
                stack.pop_back();
                
                k-=1;
            }
            
            //If there are leading zeros, let's remove them
            while(stack.size() > 1 && stack.front()=='0')
            {
                stack.pop_front();
            }
            
            //Create the result string
            while(!stack.empty())
            {
                result.push_back(stack.front());
                
                stack.pop_front();
            }
            
            return result;
        }
};