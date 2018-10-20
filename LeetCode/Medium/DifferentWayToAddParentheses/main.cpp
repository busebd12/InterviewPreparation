#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> diffWaysToCompute(string input, unordered_map<string, vector<int>> & memoization)
{
    vector<int> result;

    int size=static_cast<int>(input.size());

    for(int i=0;i<size;++i)
    {
        char current=input[i];

        if(current=='+' || current=='-' || current=='*')
        {
            string substring{};

            vector<int> leftResult;

            substring=input.substr(0, i);

            if(memoization.find(substring)!=memoization.end())
            {
                leftResult=memoization[substring];
            }
            else
            {
                leftResult=diffWaysToCompute(substring, memoization);
            }

            vector<int> rightResult;

            substring=input.substr(i+1);

            if(memoization.find(substring)!=memoization.end())
            {
                rightResult=memoization[substring];
            }
            else
            {
                rightResult=diffWaysToCompute(substring, memoization);
            }

            for(auto & firstNumber: leftResult)
            {
                for(auto & secondNumber : rightResult)
                {
                    if(current=='+')
                    {
                        result.push_back(firstNumber + secondNumber);
                    }
                    else if(current=='-')
                    {
                        result.push_back(firstNumber - secondNumber);
                    }
                    else
                    {
                        result.push_back(firstNumber * secondNumber);
                    }
                }
            }
        }
    }

    if(result.empty())
    {
        result.push_back(stoi(input));
    }

    memoization[input]=result;

    return result;
}

vector<int> diffWaysToCompute(string input)
{
    unordered_map<string, vector<int>> memoization;

    return diffWaysToCompute(input, memoization);
}