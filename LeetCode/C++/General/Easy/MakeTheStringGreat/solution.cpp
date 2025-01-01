#include <deque>
#include <string>
using namespace std;

/*
Solution 1: using stack

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        string makeGood(string s)
        {
            string result="";

            int n=s.size();

            deque<char> stack;

            for(char letter : s)
            {
                if(stack.empty())
                {
                    stack.push_back(letter);
                }
                else
                {
                    if(isupper(letter) or isupper(stack.back()))
                    {
                        if(tolower(letter)==stack.back() or tolower(stack.back())==letter)
                        {
                            stack.pop_back();
                        }
                        else
                        {
                            stack.push_back(letter);
                        }
                    }
                    else
                    {
                        stack.push_back(letter);
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

/*
Solution 2: using stack and ascii value trick/hack

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        string makeGood(string s)
        {
            string result="";

            int n=s.size();

            deque<char> stack;

            for(char letter : s)
            {
                if(stack.empty())
                {
                    stack.push_back(letter);
                }
                else
                {
                    //The ascii difference between the lowercase and uppercase version of the same letter is 32
                    int asciiDifference=abs(letter - stack.back());

                    if(asciiDifference==32)
                    {
                        stack.pop_back();
                    }
                    else
                    {
                        stack.push_back(letter);
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