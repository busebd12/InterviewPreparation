#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Approaches:
 *
 * 1) Two passes through the input vector. On the first pass, we put all even numbers into our vector<int> result.
 * On the second pass, we put all the odd numbers into our vector<int> result. Return our result vector.
 *
 * Time complexity: O(n) [where n is the length of our input vector]
 * Space complexity: O(n)
 *
 *
 * 2) First, we sort the array. Then, for each pair of odd and even numbers in the vector, we keep swapping the
 * place of odd and even numbers until all the even numbers come first followed by all the odd numbers.
 *
 * Time complexity: O(n log n) [where n is the length of our input vector]
 * Space complexity: O(1)
 *
 * 3) Using the STL partition function to parition the input vector such that all even numbers come before all odd numbers.
 *
 * Time complexity: O(n log n)
 * Space complexity: O(1)
 */

vector<int> sortArrayByParity(vector<int> & A)
{
    if(A.empty())
    {
        return A;
    }

    vector<int> result;

    for(const int & number : A)
    {
        if(number%2==0)
        {
            result.push_back(number);
        }
    }

    for(const int & number : A)
    {
        if(number%2==1)
        {
            result.push_back(number);
        }
    }

    return result;
}

vector<int> sortArrayByParity(vector<int> & A)
{
    if(A.empty())
    {
        return A;
    }

    int n=int(A.size());

    sort(A.begin(), A.end());

    for(int i=1;i<n;++i)
    {
        if(A[i]%2==0 && A[i-1]%2==1)
        {
            int j=i;

            while(j > 0 && A[j-1]%2==1)
            {
                swap(A[j], A[j-1]);

                j--;
            }
        }
    }

    return A;
}

vector<int> sortArrayByParity(vector<int> & A)
{
    if(A.empty())
    {
        return A;
    }

    partition(A.begin(), A.end(), [] (const int & number) {return number%2==0;});

    return A;
}