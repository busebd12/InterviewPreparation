#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: for each number in the range [left, right], check to see if it is divisible by all its digits.
 * If it is, add the number to the vector<int> result. Return the result vector.
 *
 * Time complexity: O(n) [where n is the number of numbers in the range [left, right]
 * Space complexity without counting the vector<int> result: O(1)
 * Space complexity counting the vector<int> result: O(n)
 *
 */

vector<int> selfDividingNumbers(int left, int right)
{
    vector<int> result;

    for(int number=left;number<=right;++number)
    {
        int copy=number;

        bool selfDividing=true;

        while(copy)
        {
            int digit=copy % 10;

            if(digit==0)
            {
                selfDividing=false;

                break;
            }

            if((number % digit)!=0)
            {
                selfDividing=false;

                break;
            }

            copy/=10;
        }

        if(selfDividing)
        {
            result.push_back(number);
        }
    }

    return result;
}