#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> nthUglyNumberHelper(int n)
{
    vector<int> cache{1};

    int multiplyBy2=0;

    int multiplyBy3=0;

    int multiplyBy5=0;

    while(cache.size() < 1691)
    {
        int value=min(cache[multiplyBy2] * 2, min(cache[multiplyBy3] * 3, cache[multiplyBy5] * 5));

        cache.emplace_back(value);

        if(value==cache[multiplyBy2] * 2)
        {
            ++multiplyBy2;
        }

        if(value==cache[multiplyBy3] * 3)
        {
            ++multiplyBy3;
        }

        if(value==cache[multiplyBy5] * 5)
        {
            ++multiplyBy5;
        }
    }

    return cache;
}

int nthUglyNumber(int n)
{
    auto result=nthUglyNumberHelper(n);

    return result[n-1];
}