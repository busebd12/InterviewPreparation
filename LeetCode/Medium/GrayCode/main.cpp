#include <iostream>
#include <string>
#include <vector>

/*
 * Solutions:
 *
 * 1. Recursive implementation of this: https://en.wikipedia.org/wiki/Gray_code#Constructing_an_n-bit_Gray_code
 *
 * Time complexity: O(n * 2^n * b) [where n the input integer and b is the average length of the bit sequences]
 * Space complexity: O(n * 2^n)
 *
 * 2. Iterative version of the first solution: https://en.wikipedia.org/wiki/Gray_code#Constructing_an_n-bit_Gray_code
 *
 * Time complexity: O(n * 2^n * b) [where n the input integer and b is the average length of the bit sequences]
 * Space complexity: O(n * 2^n)
 */

int toDecimal(std::string & bits)
{
    int result=0;

    int power=0;

    int b=int(bits.size());

    for(auto i=b-1;i>=0;--i)
    {
        if(bits[i]=='1')
        {
            int partial=1;

            for(int count=0;count<power;++count)
            {
                partial*=2;
            }

            result+=partial;
        }

        power++;
    }

    return result;
}

std::vector<std::string> helper(int n)
{
    if(n==1)
    {
        return {"0", "1"};
    }
    else
    {
        std::vector<std::string> subproblem=helper(n-1);

        std::vector<std::string> prefixWithZeroes;

        std::vector<std::string> prefixWithOnes;

        int n=int(subproblem.size());

        for(auto i=0;i<n;++i)
        {
            prefixWithZeroes.emplace_back("0" + subproblem[i]);
        }

        for(auto i=n-1;i>=0;--i)
        {
            prefixWithZeroes.emplace_back("1" + subproblem[i]);
        }

        subproblem.clear();

        for(const auto & element : prefixWithZeroes)
        {
            subproblem.push_back(element);
        }

        for(const auto & element : prefixWithOnes)
        {
            subproblem.push_back(element);
        }

        return subproblem;
    }
}

std::vector<int> grayCode(int n)
{
    std::vector<int> result;

    if(n==0)
    {
        result.emplace_back(0);

        return result;
    }

    std::vector<std::string> sequence=helper(n);

    for(auto & bits : sequence)
    {
        int decimal=toDecimal(bits);

        result.push_back(decimal);
    }

    return result;
}

std::vector<int> grayCode(int n)
{
    std::vector<int> result;

    if(n==0)
    {
        result.emplace_back(0);

        return result;
    }

    std::vector<std::vector<std::string>> sequences={{"0", "1"}};

    for(auto count=2;count<=n;++count)
    {
        std::vector<std::string> subproblem;

        int lastIndex=int(sequences.size()-1);

        int m=int(sequences[lastIndex].size());

        for(auto i=0;i<m;++i)
        {
            subproblem.emplace_back("0" + sequences[lastIndex][i]);
        }

        for(auto i=m-1;i>=0;--i)
        {
            subproblem.emplace_back("1" + sequences[lastIndex][i]);
        }

        sequences.push_back(subproblem);
    }

    int last=int(sequences.size()-1);

    for(auto & bits : sequences[last])
    {
        int decimal=toDecimal(bits);

        result.push_back(decimal);
    }

    return result;
}