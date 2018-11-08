#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <limits>
using namespace std;

int nthSuperUglyNumber(int n, vector<int> & primes)
{
    int superUglyNumber=1;

    set<int> sorted(primes.begin(), primes.end());

    for(int i=1;i<n;++i)
    {
        auto smallestNumber=sorted.begin();

        superUglyNumber=*smallestNumber;

        sorted.erase(smallestNumber);

        for(auto & prime : primes)
        {
            if((long long)prime * superUglyNumber > numeric_limits<int>::max())
            {
                continue;
            }

            sorted.insert(prime * superUglyNumber);
        }
    }

    return superUglyNumber;
}