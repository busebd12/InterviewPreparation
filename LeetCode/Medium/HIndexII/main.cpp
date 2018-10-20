#include <iostream>
#include <vector>
using namespace std;

int hIndex(vector<int>& citations)
{
    int hIndex=0;

    if(citations.empty())
    {
        return hIndex;
    }

    int N=static_cast<int>(citations.size());

    for(int i=0;i<N;++i)
    {
        if(N-i <= citations[i])
        {
            return N-i;
        }
    }

    return hIndex;
}