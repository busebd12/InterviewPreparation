#include <deque>
#include <string>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of s]
Space complexity: O(n)
*/

class Solution
{
    public:
        string smallestSubsequence(string s)
        {
            string result="";

            int n=s.size();

            vector<int> frequencies(26, 0);

            vector<bool> seen(26, false);

            for(char letter : s)
            {
                int index=letter - 'a';

                frequencies[index]+=1;
            }

            deque<char> stack;

            for(int i=0;i<n;i++)
            {
                char c=s[i];

                if(stack.empty())
                {
                    stack.push_back(c);

                    frequencies[c - 'a']-=1;

                    seen[c - 'a']=true;
                }
                else
                {
                    while(!stack.empty() and c < stack.back() and frequencies[stack.back() - 'a'] > 0 and seen[c - 'a']==false)
                    {
                        seen[stack.back() - 'a']=false;
                        
                        stack.pop_back();
                    }

                    if(seen[c - 'a']==false)
                    {
                        stack.push_back(c);

                        seen[c - 'a']=true;

                        frequencies[c - 'a']-=1;
                    }
                    else
                    {
                        frequencies[c - 'a']-=1;
                    }
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