#include <iostream>
#include <stack>
#include <string>
#include <vector>

/*
 * Solutions:
 *
 * 1. Brute-force. We generate every possible substring and if the substring is valid, update the result
 * to be the length of the longest one of these substrings.
 *
 * Time complexity: O(n^3) [where n is the length of the input string]
 * Space complexity: O(n^3)
 *
 *
 * 2. We "colour"/label each pair of valid parentheses with 1's and all invalid parentheses with 0's.
 * Then, the problem is reduced to finding the maximum substring sum of all 1's.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(n)
 */

bool isValid(std::string & str)
{
    int count=0;

    for(const auto & character : str)
    {
        if(character=='(')
        {
            count++;
        }
        else
        {
            if(count <= 0)
            {
                return false;
            }

            count--;
        }
    }

    return count==0;
}

int longestValidParentheses(std::string s)
{
    int result=0;

    if(s.empty())
    {
        return result;
    }

    int n=int(s.size());

    for(int start=0;start<=n;++start)
    {
        for(int length=1;length<=n-start;++length)
        {
            std::string substring=s.substr(start, length);

            if(isValid(substring))
            {
                if(result==0 || substring.length() > result)
                {
                    result=substring.length();
                }
            }
        }
    }

    return result;
}

int longestValidParentheses(std::string s)
{
    int result=0;

    if(s.empty())
    {
        return result;
    }

    std::stack<int> stk;

    auto n=s.size();

    std::vector<int> digits(n, 0);

    for(auto i=0;i<n;++i)
    {
        char character=s[i];

        if(character=='(')
        {
            stk.push(i);
        }
        else
        {
            if(!stk.empty())
            {
                if(s[stk.top()]=='(')
                {
                    digits[stk.top()]=1;

                    digits[i]=1;

                    stk.pop();
                }
            }
            else
            {
                stk.push(i);
            }
        }
    }

    int length=0;

    for(const auto & digit : digits)
    {
        if(digit==1)
        {
            length++;
        }
        else
        {
            result=std::max(result, length);

            length=0;
        }
    }

    result=std::max(result, length);

    return result;
}