#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * 1. For each number in the range [0, num], count the number of one bits and add the result to our std::vector<int> result.
 * Then, return the result vector.
 *
 * Time complexity: O(n * size of a number) [where n is the total number of numbers in the range [0, num]]
 * Space complexity: O(1)
 *
 * 2. Inspire from this post: https://leetcode.com/problems/counting-bits/discuss/270693/Intermediate-processsolution-for-the-most-voted-solution-i.e.-no-simplificationtrick-hidden
 *
 * Time complexity: O(n) [where n is the number of numbers in the range [0, num]]
 * Space complexity: O(n)
 */

int countOnes(int number)
{
    int count=0;

    while(number)
    {
        int digit=(number & 1);

        if(digit==1)
        {
            count++;
        }

        number=number >> 1;
    }

    return count;
}

std::vector<int> countBits(int num)
{
    std::vector<int> result;

    for(int number=0;number<=num;number++)
    {
        int ones=countOnes(number);

        result.push_back(ones);
    }

    return result;
}

std::vector<int> countBits(int num)
{
    std::vector<int> result(num + 1, 0);

    for(int number=1;number<=num;number++)
    {
        if((number & 1)==0)
        {
            result[number]=result[number >> 1];
        }
        else
        {
            result[number]=result[number-1] + 1;
        }
    }

    return result;
}