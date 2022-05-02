#include <deque>
#include <string>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n) [where n is the length of s]
Space complexity: O(n)
*/

class Solution
{
    public:
        bool checkValidString(string s)
        {   
            int n=s.size();
            
            deque<int> openParenIndicesStack;
            
            deque<int> asteriskIndicesStack;
            
            for(int i=0;i<n;i++)
            {
                char c=s[i];
                
                if(c=='(')
                {
                    //Push index onto the stack
                    openParenIndicesStack.emplace_back(i);
                }
                else if(c=='*')
                {
                    //Push index onto the stack
                    asteriskIndicesStack.emplace_back(i);
                }
                //Else, this character is a )
                else
                {
                    //If a ( character appeared before
                    if(!openParenIndicesStack.empty())
                    {
                        openParenIndicesStack.pop_back();
                    }
                    //If there isn't a ( available, check if a * character appeared before
                    else if(!asteriskIndicesStack.empty())
                    {
                        asteriskIndicesStack.pop_back();
                    }
                    //Else, there isn't a ( or * that appeared before, so return false
                    else
                    {
                        return false;
                    }
                }
            }
            
            //Now, we check to make sure any left over ( characters have corresponding * characters that can act as )
            //The only catch is that every * character has to appear after the ( character in the string
            while(!openParenIndicesStack.empty() && !asteriskIndicesStack.empty() && asteriskIndicesStack.back() > openParenIndicesStack.back())
            {
                asteriskIndicesStack.pop_back();
                    
                openParenIndicesStack.pop_back();
            }
            
            //If we weren't able to find a matching * for all left over ( characters
            if(!openParenIndicesStack.empty())
            {
                return false;
            }
            
            return true;
        }
};