#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>
using namespace std;

int fourSumCountBruteForce(vector<int> & A, vector<int> & B, vector<int> & C, vector<int> & D)
{
    int tuples=0;

    if(A.empty() || B.empty() || C.empty() || D.empty())
    {
        return tuples;
    }

    int n=int(A.size());

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int k=0;k<n;++k)
            {
                for(int l=0;l<n;++l)
                {
                    int sum=A[i] + B[j] + C[k] + D[l];

                    if(sum==0)
                    {
                        ++tuples;
                    }
                }
            }
        }
    }

    return tuples;
}

int fourSumCount(vector<int> & A, vector<int> & B, vector<int> & C, vector<int> & D)
{
    int tuples=0;

    unordered_map<int, int> sums;

    int n=int(A.size());

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            int sum=A[i] + B[j];

            sums[sum]++;
        }
    }

    for(int x=0;x<n;++x)
    {
        for(int y=0;y<n;++y)
        {
            int sum=-(C[x] + D[y]);

            if(sums.count(sum))
            {
                tuples+=sums[sum];
            }
        }
    }

    return tuples;
}
