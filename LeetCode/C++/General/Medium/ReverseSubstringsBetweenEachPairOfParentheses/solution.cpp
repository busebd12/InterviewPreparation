#include <deque>
#include <string>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/discuss/382367/Simple-Stack-and-Queue-Solution

Time complexity: O(n * k) [where n is the length of s and k is the number of parenthesis pairs]
Space complexity: O(n)
*/

class Solution
{
    public:
        string reverseParentheses(string s)
        {
            string result="";
            
            int n=s.size();
            
            deque<char> stack;
            
            for(char character : s)
            {
                if(character==')')
                {
                    deque<char> queue;
                    
                    while(!stack.empty() and stack.back()!='(')
                    {
                        queue.emplace_back(stack.back());
                        
                        stack.pop_back();
                    }
                    
                    if(!stack.empty())
                    {
                        stack.pop_back();
                    }
                    
                    while(!queue.empty())
                    {
                        stack.emplace_back(queue.front());
                        
                        queue.pop_front();
                    }
                }
                else
                {
                    stack.push_back(character);
                }
            }
            
            while(!stack.empty())
            {
                result.push_back(stack.front());
                
                stack.pop_front();
            }
            
            return result;
        }
};