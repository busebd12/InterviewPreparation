#include <iostream>
using namespace std;

/*
 * Approach: just your basic binary search
 *
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

int guessNumber(int n)
{
    int result=0;

    int high=n;

    int low=0;

    while(low <= high)
    {
        int number=(low + ((high - low))/2);

        int guessResult=guess(number);

        if(guessResult==0)
        {
            result=number;

            break;
        }
        else if(guessResult==1)
        {
            low=number+1;
        }
        else
        {
            high=number-1;
        }
    }

    return result;
}