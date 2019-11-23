#include <iostream>
using namespace std;

/*
 * Approach: first, count the number of digits in the number. Then, for each digit in the input number,
 * cube it and add the result to the sum integer variable. Finally, return whether or not the sum of each
 * digit cubed is equal to the original number.
 *
 * Time complexity: O(d) [where d is the number of digits in the input number]
 * Space complexity: O(d) [if you count the extra copies of the input number. If not, O(1)]
 */

bool isArmstrong(int N)
{
    if(N <= 0)
    {
        return false;
    }

    int copy=N;

    int digits=0;

    while(copy)
    {
        digits++;

        copy/=10;
    }

    copy=N;

    int sum=0;

    while(copy)
    {
        int digit=copy % 10;

        int value=1;

        for(int count=0;count<digits;++count)
        {
            value*=digit;
        }

        sum+=value;

        copy/=10;
    }

    return sum==N;
}