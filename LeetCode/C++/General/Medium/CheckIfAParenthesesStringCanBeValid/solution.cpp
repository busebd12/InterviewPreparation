#include <deque>
#include <string>
using namespace std;

/*
Time complexity: O(n) [where n is the length of s]
Space complexity: O(n)
*/

class Solution
{
    public:
        bool canBeValid(string s, string locked)
        {
            int n=s.size();
            
            if((n % 2)==1)
            {
                return false;
            }
            
            deque<int> openParenIndices;
            
            deque<int> unlockedIndices;
            
            for(int i=0;i<n;i++)
            {
                char c=s[i];
                
                if(locked[i]=='0')
                {
                    unlockedIndices.push_back(i);
                }
                else if(c=='(')
                {
                    openParenIndices.push_back(i);
                }
                else if(c==')' and !openParenIndices.empty())
                {
                    openParenIndices.pop_back();
                }
                else if(c==')' and !unlockedIndices.empty())
                {
                    unlockedIndices.pop_back();
                }
                else
                {
                    return false;
                }
            }
            
            while(!openParenIndices.empty() and !unlockedIndices.empty())
            {
                int openParenIndex=openParenIndices.back();
                
                openParenIndices.pop_back();
                
                int unlockedIndex=unlockedIndices.back();
                
                unlockedIndices.pop_back();
                
                if(unlockedIndex < openParenIndex)
                {
                    return false;
                }
            }
            
            if(!openParenIndices.empty())
            {
                return false;
            }
            
            if((unlockedIndices.size() % 2)!=0)
            {
                return false;
            }
            
            return true;
        }
};