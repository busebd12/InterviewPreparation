#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Approaches:
 *
 * 1) Brute force. For each substring, check if it meets both criterion:
 * has an equal amount of ones and zeroes and all ones and zeroes are consecutive.
 * If it does, increment our result variable. Return the result.
 *
 * Time complexity: O(n-squared) [where n is the length of the input string]
 * Space complexity: O(n-squared)
 *
 *
 * 2) Loop over the string and keep track of the consecutive groups of ones and zeroes.
 * Every time we reach the end of the group of consecutive ones or zeroes, add the length
 * of the consecutive group to the vector<int> consecutiveCounts. After looping through the
 * string, loop over the consecutiveCounts vector and take the minimum between each pair of
 * numbers since the minimum gives us equal numbers of zeroes and ones.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(m) [where m is the number of consecutive groups of ones and zeroes]
 */

bool consecutiveOnesAndZeroes(string & str)
{
    auto firstZero=str.find_first_of('0');

    auto lastZero=str.find_last_of('0');

    auto firstOne=str.find_first_of('1');

    auto lastOne=str.find_last_of('1');

    bool zeroesAfterOnes=((firstZero > firstOne && firstZero > lastOne) && (lastZero > firstOne && lastZero > lastOne));

    bool zeroesBeforeOnes=((firstZero < firstOne && firstZero < lastOne) && (lastZero < firstOne && lastZero < lastOne));

    return zeroesBeforeOnes || zeroesAfterOnes;
}

int countBinarySubstrings(string str)
{
    int result=0;

    if(str.empty())
    {
        return result;
    }

    int n=int(str.size());

    for(int length=1;length<=n;++length)
    {
        for(int start=0;((start + length)-1)<n;++start)
        {
            string substring=str.substr(start, length);

            int ones=count(substring.begin(), substring.end(), '1');

            int zeroes=count(substring.begin(), substring.end(), '0');

            if(ones==zeroes)
            {
                if(consecutiveOnesAndZeroes(substring))
                {
                    result++;
                }
            }
        }
    }

    return result;
}

int countBinarySubstrings(string s)
{
    if(s.empty())
    {
        return 0;
    }

    int n=int(s.size());

    if(n < 2)
    {
        return 0;
    }

    vector<int> consecutiveCounts;

    int count=1;

    for(int i=1;i<=n;++i)
    {
        if(s[i]==s[i-1])
        {
            ++count;
        }
        else
        {
            consecutiveCounts.push_back(count);

            count=1;
        }
    }

    int m=int(consecutiveCounts.size());

    int result=0;

    for(int i=1;i<m;++i)
    {
        result+=min(consecutiveCounts[i], consecutiveCounts[i-1]);
    }

    return result;
}
