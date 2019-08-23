#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Generate and store all valid perfect squares that are less than or equal to num.
 * Then, use binary search to see if the input number is among them. This solution results in memory limit exceeded result.
 *
 * Time complexity: O(number of perfect squares less than or equal to the input number log n)
 * Space complexity: O(number of perfect squares less than or equal to the input number)
 *
 * 2) While generating perfect squares less than or equal to the input number,
 * check if the input number is one of them.
 *
 * Time complexity: O(number of perfect squares less than or equal to the input number)
 * Space complexity: O(1)
 *
 * 3) Use the mathematical property that adding the first n odd numbers is always a perfect square
 *
 * Time complexity: O(num)
 * Space complexity: O(1)
 */

bool binarySearch(vector<int> & perfectSquares, int num)
{
    int low=0;

    int high=int(perfectSquares.size())-1;

    while(low <= high)
    {
        int middle=(low + ((high - low))/2);

        if(perfectSquares[middle]==num)
        {
            return true;
        }
        else if(perfectSquares[middle] > num)
        {
            high=middle-1;
        }
        else
        {
            low=middle+1;
        }
    }

    return false;
}

bool isPerfectSquare(int num)
{
    if(num <= 0)
    {
        return false;
    }

    if(num==1)
    {
        return true;
    }

    vector<int> perfectSquares;

    long int base=2;

    int power=2;

    while(true)
    {
        int perfectSquare=int(pow(base, power));

        if(perfectSquare==num)
        {
            return true;
        }

        if(perfectSquare > num)
        {
            break;
        }

        perfectSquares.push_back(perfectSquare);

        base++;
    }

    return binarySearch(perfectSquares, num);
}

bool isPerfectSquare(int num)
{
    if(num <= 0)
    {
        return false;
    }

    if(num==1)
    {
        return true;
    }

    long int base=2;

    while(true)
    {
        int perfectSquare=int(base * base);

        if(perfectSquare==num)
        {
            return true;
        }

        if(perfectSquare > num)
        {
            break;
        }

        base++;
    }

    return false;
}

bool isPerfectSquare(int num)
{
    if(num <= 0)
    {
        return false;
    }

    if(num==1)
    {
        return true;
    }

    for(long int sum=0,number=1;sum<=num;number+=2)
    {
        sum+=number;

        if(sum==num)
        {
            return true;
        }
    }

    return false;
}