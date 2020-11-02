#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

/*
 * Solution: the idea is to evaluate the string using the order of operations: PEMDAS.
 * Since the input string will only contain the characters '(', ')', '+', and/or, '-',
 * we first evaluate all expressions enclosed in parentheses first. We evaluate the parentheses
 * enclosed expressions by extracting each part of the string that is surrounded by parentheses,
 * erase that substring from the string, erase that substring from the original string, and then
 * pass the expression to the helper function. This helper function evaluates string expressions
 * with only '+', '-', and/or digits in it. Once we have finished evaluating all the parenthetical
 * expressions, we evaluate the remaining expression, if it is not a valid number.
 *
 * Time complexity: O(n^2) [where n is the length of the input string]
 * Space complexity: O(n)
 */

int helper(std::string & substring)
{
    std::stack<int> digitsStack;

    std::stack<char> operatorsStack;

    auto n=int(substring.size());

    for(auto i=0;i<n;)
    {
        char c=substring[i];

        if(std::isspace(c))
        {
            i++;
        }

        else if(c=='+' || c=='-')
        {
            operatorsStack.push(c);

            i++;
        }
        else
        {
            int num2=0;

            while(std::isdigit(substring[i]))
            {
                num2=(num2 * 10 ) + (substring[i] - '0');

                i++;
            }

            if(!operatorsStack.empty())
            {
                int num1=digitsStack.top();

                digitsStack.pop();

                char op=operatorsStack.top();

                operatorsStack.pop();

                int num3=0;

                if(op=='+')
                {
                    num3=num1 + num2;
                }
                else
                {
                    num3=num1 - num2;
                }

                digitsStack.push(num3);
            }
            else
            {
                digitsStack.push(num2);
            }
        }
    }

    return digitsStack.top();
}

int calculate(std::string & s)
{
    int result=0;

    if(s.empty())
    {
        return result;
    }

    while(s.find('(')!=std::string::npos)
    {
        auto openingParenthesisIndex=s.find_last_of('(');

        std::size_t closingParenthesisIndex=0;

        for(auto i=openingParenthesisIndex;i<s.size();++i)
        {
            if(s[i]==')')
            {
                closingParenthesisIndex=i;

                break;
            }
        }

        std::size_t substringLength=(closingParenthesisIndex - openingParenthesisIndex) - 1;

        std::string substring=s.substr(openingParenthesisIndex+1, substringLength);

        std::size_t eraseLength=(closingParenthesisIndex - openingParenthesisIndex) + 1;

        s.erase(openingParenthesisIndex, eraseLength);

        int subproblemResult=helper(substring);

        if(!s.empty())
        {
            if(openingParenthesisIndex-1 > 0 && openingParenthesisIndex-1 < s.size())
            {
                if(subproblemResult < 0)
                {
                    if(s[openingParenthesisIndex-1]=='-')
                    {
                        subproblemResult*=-1;

                        s[openingParenthesisIndex-1]='+';
                    }
                    else if(s[openingParenthesisIndex-1]=='+')
                    {
                        subproblemResult*=-1;

                        s[openingParenthesisIndex-1]='-';
                    }
                }
            }
        }

        substring=std::to_string(subproblemResult);

        if(s.empty())
        {
            s=substring;
        }
        else if(openingParenthesisIndex >= s.size())
        {
            s+=substring;
        }
        else
        {
            if(openingParenthesisIndex >= 0 && openingParenthesisIndex < s.size())
            {
                s.insert(openingParenthesisIndex, substring);
            }
        }
    }

    auto numberOfMinusSigns=std::count(s.begin(), s.end(), '-');

    auto numberOfPlusSigns=std::count(s.begin(), s.end(), '+');

    if((numberOfMinusSigns > 1 || (numberOfMinusSigns==1 && s[0]!='-') || numberOfPlusSigns >= 1))
    {
        result=helper(s);
    }
    else
    {
        result=std::stoi(s);
    }

    return result;
}