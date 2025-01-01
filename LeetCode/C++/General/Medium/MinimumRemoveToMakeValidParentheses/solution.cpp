#include <deque>
#include <string>
using namespace std;

class Solution
{
    public:
        string minRemoveToMakeValid(string s)
        {
            string result="";

            int n=s.size();

            deque<int> stack;

            for(int index=0;index<n;index+=1)
            {
                char character=s[index];

                if(character=='(')
                {
                    stack.push_back(index);
                }
                else if(character==')')
                {
                    if(!stack.empty())
                    {
                        stack.pop_back();
                    }
                    else
                    {
                        s[index]='$';
                    }
                }
            }

            while(!stack.empty())
            {
                s[stack.back()]='$';

                stack.pop_back();
            }

            for(int index=0;index<n;index+=1)
            {
                if(s[index]!='$')
                {
                    result.push_back(s[index]);
                }
            }

            return result;
        }
};