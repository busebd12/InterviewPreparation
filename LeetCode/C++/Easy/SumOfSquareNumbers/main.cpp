#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

/*
 * Approaches:
 *
 * 1) Loop from [1, c], square each number and add it to our unordered_set<int>.
 * Then, check if c is in the unordered_set. If it is, return true. Then,
 * for each number in the unordered_set<int>, check if c-that number is in
 * the unordered_map. If it is, return true. After the for loop, return false.
 *
 * Time complexity: O(n) [where n is equal to c]
 * Space complexity: O(n)
 *
 * 2) Pretty much the same approach as the first solution, except that we check if the squared number
 * is equal to c every time we square the number from [1, c].
 *
 * Time complexity: O(n) [where n is equal to c]
 * Space complexity: O(n)
 *
 * 3) Use binary search.
 *
 * Time complexity: O(sqrt(c))
 * Space complexity: O(1)
 */

bool judgeSquareSum(int c)
{
    if(c < 0)
    {
        return false;
    }

    if(c==0)
    {
        return true;
    }

    unordered_set<long int> squares;

    for(long int number=1;number*number<=c;++number)
    {
        long int squared=number * number;

        squares.insert(squared);
    }

    if(squares.count(c))
    {
        return true;
    }

    for(long int number : squares)
    {
        long int target=c-number;

        if(squares.count(target))
        {
            return true;
        }
    }

    return false;
}

bool judgeSquareSum(int c)
{
    if(c < 0)
    {
        return false;
    }

    if(c==0)
    {
        return true;
    }

    unordered_set<long int> squares;

    for(long int number=1;number*number<=c;++number)
    {
        long int squared=number * number;

        if(squared==c)
        {
            return true;
        }

        squares.insert(squared);
    }

    for(long int number : squares)
    {
        long int target=c-number;

        if(squares.count(target))
        {
            return true;
        }
    }

    return false;
}

bool judgeSquareSum(int c)
{
    if(c < 0)
    {
        return false;
    }

    long int left=0;

    long int right=static_cast<int>(sqrt(c));

    while(left <= right)
    {
        long int middle=(left * left) + (right * right);

        if(middle==c)
        {
            return true;
        }
        else if(middle > c)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    return false;
}