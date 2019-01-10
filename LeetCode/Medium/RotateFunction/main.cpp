#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int calculateSum(vector<int> & A, int & n)
{
    int sum=0;

    for(int i=0;i<n;++i)
    {
        sum+=(i * A[i]);
    }

    return sum;
}

int maxRotateFunction(vector<int> & A)
{
    vector<int> positiveSums;

    vector<int> negativeSums;

    if(A.empty())
    {
        return 0;
    }

    int n=int(A.size());

    for(int k=0; k<n; ++k)
    {
        int sum=0;

        if(k>0)
        {
            rotate(A.rbegin(), A.rbegin()+k, A.rend());

            sum=calculateSum(A, n);

            rotate(A.begin(), A.begin()+k, A.end());
        }
        else
        {
            sum=calculateSum(A, n);
        }

        if(sum<0)
        {
            negativeSums.push_back(sum);
        }
        else
        {
            positiveSums.push_back(sum);
        }
    }

    if(negativeSums.empty())
    {
        return *(max_element(positiveSums.begin(), positiveSums.end()));
    }
    else if(positiveSums.empty())
    {
        return *(min_element(negativeSums.begin(), negativeSums.end()));
    }
    else
    {
        return *(max_element(positiveSums.begin(), positiveSums.end()));
    }
}