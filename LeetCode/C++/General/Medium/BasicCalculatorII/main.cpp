#include <algorithm>
#include <deque>
#include <iostream>
#include <string>

/*
 * Solution: we evalute the expressions according to the rules of PEMDAS.
 * When evaluating the multiplication and division expressions, we replace
 * the expression with the result of the expression. Then, we maintain a rolling
 * sum when evaluting the addition and subtraction expressions.
 *
 * Time complexity: O(n^2) [where n is the length of the input string]
 * Space complexity: O(d) [where d is the total number of digits involved in all multiplication and division expressions]
 */

int calculate(std::string s)
{
    int result=0;

    if(s.empty())
    {
        return result;
    }

    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

    std::deque<char> rightDQ;

    std::deque<char> leftDQ;

    for(auto index=0;index<s.size();++index)
    {
        if(s[index]=='/' || s[index]=='*')
        {
            int rightIndex=index+1;

            while(rightIndex < static_cast<int>(s.size()) && std::isdigit(s[rightIndex]))
            {
                rightDQ.emplace_back(s[rightIndex]);

                rightIndex++;
            }

            int leftIndex=index-1;

            while(leftIndex >= 0 && std::isdigit(s[leftIndex]))
            {
                leftDQ.emplace_front(s[leftIndex]);

                leftIndex--;
            }

            int left=0;

            for(auto & element : leftDQ)
            {
                left=((left * 10) + (element - '0'));
            }

            int right=0;

            for(auto & element : rightDQ)
            {
                right=((right * 10) + (element - '0'));
            }

            int subproblem=0;

            if(s[index]=='*')
            {
                subproblem=left * right;
            }
            else
            {
                subproblem=left / right;
            }

            int leftBound=index - static_cast<int>(leftDQ.size());

            int length=1 + static_cast<int>(rightDQ.size()) + static_cast<int>(leftDQ.size());

            std::string substring=s.substr(leftBound, length);

            s.erase(leftBound, length);

            if(s.empty())
            {
                s.insert(0, std::to_string(subproblem));

                index=0;
            }
            else
            {
                s.insert(leftIndex+1, std::to_string(subproblem));

                index=leftIndex+1;
            }

            leftDQ.clear();

            rightDQ.clear();
        }
    }

    int index=0;

    while(index < static_cast<int>(s.length()) && std::isdigit(s[index]))
    {
        result=((result * 10) + (s[index] - '0'));

        index++;
    }

    char op{};

    while(index < static_cast<int>(s.length()))
    {
        if(s[index]=='+' || s[index]=='-')
        {
            op=s[index];
        }

        index++;

        int number=0;

        while(std::isdigit(s[index]))
        {
            number=((number * 10) + (s[index] - '0'));

            index++;
        }

        if(op=='+')
        {
            result+=number;
        }
        else
        {
            result-=number;
        }
    }

    return result;
}