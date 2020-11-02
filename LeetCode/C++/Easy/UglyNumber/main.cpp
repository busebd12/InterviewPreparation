#include <iostream>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Brute force, TLE (time limit exceeded): generate all prime factors of the input number.
 * Then, check if a prime that is not 2, 3, or 5 is in the vector.
 *
 * 2) While the number is divisible by two, repeatedly divide it by two.
 * While the number is divisible by three, repeatedly divide it by three.
 * While the number is divisible by five, repeatedly divide it by five.
 * Check whether the number is one, or not, at the end.
 */

bool isUgly(int num)
{
    if(num <= 0)
    {
        return false;
    }

    if(num==1)
    {
        return true;
    }

    vector<int> primeFactors;

    for(int number=2;number<num;++number)
    {
        while((num % number)==0)
        {
            primeFactors.push_back(number);

            num/=number;
        }
    }

    if(num > 2)
    {
        primeFactors.push_back(num);
    }

    for(const auto & factor : primeFactors)
    {
        if(factor!=2 && factor!=3 && factor!=5)
        {
            return false;
        }
    }

    return true;
}

bool isUgly(int num)
{
    if(num <= 0)
    {
        return false;
    }

    while((num % 2)==0)
    {
        num/=2;
    }

    while((num % 3)==0)
    {
        num/=3;
    }

    while((num % 5)==0)
    {
        num/=5;
    }

    return num==1;
}