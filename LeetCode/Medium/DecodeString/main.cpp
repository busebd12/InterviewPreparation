#include <cctype>
#include <iostream>
#include <stack>
#include <string>

/*
 * Solution: as we loop through the string, we handle the following cases:
 *
 * 1. the current character is a digit --> this number will tell us how many times this part of the string will be repeated
 *
 * 2. the current character is a [ --> since this character always comes after a number, we can push the current digit
 * onto the numbersStack and reset count to zero. Then, we make a copy of the result string and push the copy onto the
 * stringStack so as to not loose the current value of result.
 *
 * 3. the current character is a letter --> just add the letter to the result string
 *
 * 4. the current character is a ] --> we pop off the previous count value and string from their respective stacks and
 * build the current repeated string using the previous value of result and the current string within the [].
 * Then, we update the value of result with the just created string to save our progress.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(n)
 */

std::string decodeString(std::string s)
{
    std::string result{};

    if(s.empty())
    {
        return result;
    }

    std::stack<std::string> stringStack;

    std::stack<int> numberStack;

    int count=0;

    for(auto & c : s)
    {
        if(std::isdigit(c))
        {
            count=count * 10 + (c - '0');
        }
        else if(c=='[')
        {
            numberStack.push(count);

            count=0;

            std::string copy=result;

            stringStack.push(copy);

            result.clear();
        }
        else if(std::isalpha(c))
        {
            result+=c;
        }
        else if(c==']')
        {
            auto previousCount=numberStack.top();

            numberStack.pop();

            auto previousString=stringStack.top();

            stringStack.pop();

            for(auto i=0;i<previousCount;++i)
            {
                previousString+=result;
            }

            result=previousString;
        }
    }

    return result;
}