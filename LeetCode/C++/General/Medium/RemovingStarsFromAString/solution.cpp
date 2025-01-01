#include <deque>
#include <string>
using namespace std;

class Solution
{
    public:
        string removeStars(string s)
        {
            string result="";

            int n=s.size();

            deque<char> stack;

            for(char character : s)
            {
                if(stack.empty())
                {
                    if(character!='*')
                    {
                        stack.push_back(character);
                    }
                }
                else
                {
                    if(character=='*')
                    {
                        stack.pop_back();
                    }
                    else
                    {
                        stack.push_back(character);
                    }
                }
            }

            while(!stack.empty())
            {
                char character=stack.front();

                stack.pop_front();

                result.push_back(character);
            }

            return result;
        }
};