#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
 * Approaches:
 *
 * 1) We convert the input number into a binary string. Then, we count the longest length between two ones
 * in the string.
 *
 * Time complexity: O(b) [where b is the number of bits in our input number]
 * Space complexity: O(b)
 *
 * 2) Same logic as the first solution. However, we don't store the bits in a separate string, we count the
 * longest length between two ones as we are shifting the input number by one to the right each time.
 *
 * Time complexity: O(b) [where b is the number of bits in the input number]
 * Space complexity: O(1)
 */

int binaryGap(int N)
{
    string number{};

    int ones=0;

    while(N)
    {
        int digit=N & 1;

        N >>= 1;

        number+=(digit + '0');
    }

    reverse(number.begin(), number.end());

    int result=0;

    int length=0;

    int n=int(number.size());

    for(int i=n-1;i>=0;--i)
    {
        if(number[i]=='0')
        {
            if(ones==0)
            {
                continue;
            }
            else
            {
                length++;
            }
        }
        else
        {
            if(ones==0)
            {
                length++;

                ones++;
            }
            else if(ones==1)
            {
                result=max(result, length);

                length=1;

                ones=1;
            }
        }
    }

    return result;
}

int binaryGap(int N)
{
    int ones=0;

    int result=0;

    int length=0;

    while(N)
    {
        int digit=N & 1;

        if(digit==0)
        {
            if(ones > 0)
            {
                length++;
            }
        }
        else
        {
            if(ones==0)
            {
                length++;

                ones++;
            }
            else if(ones==1)
            {
                result=max(result, length);

                length=1;

                ones=1;
            }
        }

        N >>= 1;
    }

    return result;
}