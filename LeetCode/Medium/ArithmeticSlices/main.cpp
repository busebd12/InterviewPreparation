#include <iostream>
#include <vector>
using namespace std;

int numberOfArithmeticSlices(vector<int> & A)
{
    int slices=0;

    int current=0;

    for(int i=2;i<A.size();++i)
    {
        if(A[i]-A[i-1]==A[i-1]-A[i-2])
        {
            ++current;

            slices+=current;
        }
        else
        {
            current=0;
        }
    }

    return slices;
}