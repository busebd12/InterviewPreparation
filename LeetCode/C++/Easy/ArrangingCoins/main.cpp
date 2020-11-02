#include <iostream>
using namespace std;

/*
 * Approach: Just continue to subtract coins from n while there is enough to form the current row
 * Time complexity: O(number of complete rows)
 * Space complexity: O(1)
*/

int arrangeCoins(int n)
{
    if(n==0)
    {
        return 0;
    }

    int row=0;

    int count=0;

    while(n >= row+1)
    {
        n-=(row+1);

        row++;

        count++;
    }

    return count;
}