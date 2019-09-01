#include <iostream>
#include <unordered_set>
using namespace std;

/*
 * Approaches:
 *
 * 1) Brute force. Generate all possible divisors less than num and if they even divide num,
 * add them to the sum. Check if sum equals num.
 *
 * Time complexity: O(num)
 * Space complexity: O(1)
 *
 * 2) Since all proper divisors of a number with never be more than that number divided by two,
 * and all prime factors will never be greater than the square root of that number, just run a for
 * loop from 2 up to the square root of the number. If the divisor divides num evenly, then there
 * are two cases. If the divisor and the result of number/divisor are the same, just add the divisor.
 * Else, add both.
 *
 * Time complexity: O(square root of the input number)
 * Space complexity: O(1)
 *
 * 3) Just store the first five perfect numbers and check if the input number is one of them.
 * First five perfect numbers taken from here: https://en.wikipedia.org/wiki/Perfect_number
 *
 * Time complexity: O(1)
 * Space complexity: O(1)
 */
bool checkPerfectNumber(int num)
{
    if(num <= 0)
    {
        return false;
    }

    long int sum=0;

    for(int divisor=1;divisor<num;++divisor)
    {
        if(num%divisor==0)
        {
            sum+=divisor;
        }
    }

    return sum==num;
}

bool checkPerfectNumber(int num)
{
    if(num <= 0)
    {
        return false;
    }

    if(num==1)
    {
        return false;
    }

    long int sum=1;

    for(int divisor=2;divisor*divisor<=num;++divisor)
    {
        if(num%divisor==0)
        {
            if(divisor==(num/divisor))
            {
                sum+=divisor;
            }
            else
            {
                sum+=(divisor + num/divisor);
            }
        }
    }

    return sum==num;
}

bool checkPerfectNumber(int num)
{
    unordered_set<int> perfectNumbers={6, 28, 496, 8128, 33550336};

    return perfectNumbers.count(num);
}