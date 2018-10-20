#include <iostream>
#include <vector>
using namespace std;

int hIndex(vector<int> & citations)
{
    int N=static_cast<int>(citations.size());

    vector<int> buckets(N+1);

    for(int i=0;i<N;++i)
    {
        if(citations[i] <= N)
        {
            buckets[citations[i]]++;
        }
        else
        {
            buckets[N]++;
        }
    }

    int numberOfPapers=0;

    for(int i=N;i>=0;--i)
    {
        numberOfPapers+=buckets[i];

        if(numberOfPapers >= i)
        {
            return i;
        }
    }

    return 0;
}