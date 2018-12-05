#include <iostream>
#include <vector>
using namespace std;

int countOnes(vector<int> & counts, int number)
{
    int r=0;

    int ones=0;

    while(number > 0)
    {
        r=number%2;

        if(r==1)
        {
            ++ones;
        }

        number/=2;
    }

    return ones;
}

vector<int> countBits(int num)
{
    vector<int> counts(num+1);

    for(int i=0;i<=num;++i)
    {
        int ones=countOnes(counts, i);

        counts[i]=ones;
    }

    return counts;
}