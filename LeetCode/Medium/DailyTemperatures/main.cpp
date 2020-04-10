#include <iostream>
#include <stack>
#include <vector>

/*
 * Solutions:
 *
 * 1. Brute force.
 *
 * Time complexity: O(n^2) [where n is the length of the input vector]
 * Space complexity: O(1) [not counting space required for output] O(n) [if we count the space required for the output]
 *
 * 2. Keeping a monotone stack; inspired from this video --> https://www.youtube.com/watch?v=uFso48YRRao
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(n)
 */

std::vector<int> dailyTemperatures(std:: vector<int> & T)
{
    std::vector<int> result;

    if(T.empty())
    {
        return result;
    }

    result.resize(T.size(), 0);

    auto n=T.size();

    for(auto i=0;i<n;++i)
    {
        auto currentTemperature=T[i];

        for(auto j=i+1;j<n;++j)
        {
            auto nextTemperature=T[j];

            if(nextTemperature > currentTemperature)
            {
                result[i]=j-i;

                break;
            }
        }
    }

    return result;
}

std::vector<int> dailyTemperatures(std:: vector<int> & T)
{
    std::vector<int> result;

    if(T.empty())
    {
        return result;
    }

    result.resize(T.size(), 0);

    auto n=int(T.size());

    std::stack<int> stk;

    for(auto index=0;index<n;++index)
    {
        int currentTemperature=T[index];

        while(!stk.empty() && T[stk.top()] < currentTemperature)
        {
            auto i=stk.top();

            stk.pop();

            result[i]=index - i;
        }

        stk.push(index);
    }

    return result;
}