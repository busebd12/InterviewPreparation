#include <deque>
#include <string>
using namespace std;

class Solution
{
    public:
        int minAddToMakeValid(string s)
        {
            int result=0;

            deque<char> stack;

            for(auto & character : s)
            {
                //Push open ( onto the stack
                if(character=='(')
                {
                    stack.emplace_back(character);
                }
                else
                {
                    //If the stack is not empty then we have found a matching ( for the current )
                    if(!stack.empty())
                    {
                        stack.pop_back();
                    }
                    //The stack is empty and we are missing a )
                    else
                    {
                        result+=1;
                    }
                }
            }

            //If the stack is not empty, then the stack contains the number of ( that need a matching )
            if(!stack.empty())
            {
                result+=stack.size();
            }

            return result;
        }
};