#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
 * Approaches:
 *
 * 1. While there are adjacent duplicates in the string, use the adjacent_find algorithm from the STL to find
 * the duplicates and then delete them.
 *
 * Time complexity: O(d * n) [where d is the number of adjacent duplicates and n is the length of the input string]
 * Space complexity: O(1)
 *
 * 2. Use a stack. We loop over the input string and handle the following cases.
 *
 * a) the stack is empty --> push character onto the stack
 * b) the current character is the same as the top of the stack (the second letter in an adjacent duplicate): pop from the stack
 * c) the current character is not the same as the top character in the stack --> push character onto the stack
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(n)
 *
 *
 * 3. Use a string as a stack. Exact same logic as the second solution.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(n)
 */

string removeDuplicates(string S)
{
    while(true)
    {
        auto itr=adjacent_find(S.begin(), S.end());

        if(itr==S.end())
        {
            break;
        }

        int index=(itr - S.begin());

        S.erase(S.begin() + index);

        S.erase(S.begin() + index);
    }

    return S;
}

string removeDuplicates(string S)
{
    stack<char> stk;

    for(const auto & letter : S)
    {
        if(stk.empty())
        {
            stk.push(letter);
        }
        else
        {
            if(letter==stk.top())
            {
                stk.pop();
            }
            else
            {
                stk.push(letter);
            }
        }
    }

    S.clear();

    while(!stk.empty())
    {
        S+=stk.top();

        stk.pop();
    }

    reverse(S.begin(), S.end());

    return S;
}

string removeDuplicates(string S)
{
    string result;

    for(const auto & letter : S)
    {
        if(result.empty())
        {
            result+=letter;
        }
        else
        {
            if(letter==result.back())
            {
                result.pop_back();
            }
            else
            {
                result+=letter;
            }
        }
    }

    return result;
}