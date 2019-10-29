#include <iostream>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Brute force. For each odd number in A that is at an even index, we look for a even number at an odd index to swap with.
 *
 * Time complexity: O(n-squared) [where n is the length of our input vector]
 * Space complexity: O(1)
 *
 *
 * 2) Using extra space. We allocate an extra vector that is the same size as our input vector.
 * Then, using two integer variables, oddIndex and evenIndex, we loop through the input vector
 * and place each odd number at the current available odd index and place each even number at
 * the current available even index. We then increment both oddIndex and evenIndex by two after
 * placing each even and odd number.
 *
 * Time complexity: O(n) [where n is the length of our input vector]
 * Space complexity: O(n)
 *
 *
 * 3) Two pointers. We use to integer variables, i and j, to iterate through our input vector,
 * with i starting at 0 and j starting at 1. While the number A[i] is even, we increment i by two.
 * While the number A[j] is odd, we increment j by two. If we reach a point where A[i] is odd and A[j]
 * is even, then we know we can swap the two numbers.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

vector<int> sortArrayByParityII(vector<int> & A)
{
    if(A.empty())
    {
        return A;
    }

    int n=int(A.size());

    if(n < 2)
    {
        return A;
    }

    for(int i=0;i<n;++i)
    {
        if(i%2==0 && A[i]%2==1)
        {
            for(int j=0;j<n;++j)
            {
                if(j!=i)
                {
                    if(j%2==1 && A[j]%2==0)
                    {
                        swap(A[i], A[j]);
                    }
                }
            }
        }
    }

    return A;
}

vector<int> sortArrayByParityII(vector<int> & A)
{
    if(A.empty())
    {
        return A;
    }

    int n=int(A.size());

    vector<int> result(n, 0);

    int oddIndex=1;

    int evenIndex=0;

    for(int i=0;i<n;++i)
    {
        if(A[i]%2==0)
        {
            result[evenIndex]=A[i];

            evenIndex+=2;
        }
        else
        {
            result[oddIndex]=A[i];

            oddIndex+=2;
        }
    }

    return result;
}

vector<int> sortArrayByParityII(vector<int> & A)
{
    if(A.empty())
    {
        return A;
    }

    int n=int(A.size());

    for(int i=0,j=1;i<n&&j<n;)
    {
        if(A[i]%2==0)
        {
            i+=2;
        }
        else if(A[j]%2==1)
        {
            j+=2;
        }
        else
        {
            swap(A[i], A[j]);
        }
    }

    return A;
}