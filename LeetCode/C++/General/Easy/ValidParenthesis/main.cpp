#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
 * Approach:
 * Looping over the string, if we find an opening (, [, or {, push it onto the stack.
 * If we find a ')', ']', or '}', check to see if the stack is not empty and if the
 * top of the stack is the corresponding '(', '[', or '{'.
 * If this is the case, pop the top of the stack.
 * If not, return false.
 *
 * Time Complexity: O(n) [where n is the length of the input string]
 *
 * Space Complexity: O(n) [where n is the length of the input string]
 */

bool isValid(string & s)
{
    stack<char> stk;

    int n=int(s.size());

    for(int i=0;i<n;++i)
    {
        char current=s[i];

        if(current=='(' || current=='[' || current=='{')
        {
            stk.push(current);
        }
        else if(current==')' && !stk.empty() && stk.top()=='(')
        {
            stk.pop();
        }
        else if(current==']' && !stk.empty() && stk.top()=='[')
        {
            stk.pop();
        }
        else if(current=='}' && !stk.empty() && stk.top()=='{')
        {
            stk.pop();
        }
        else
        {
            return false;
        }
    }

    return stk.empty();
}