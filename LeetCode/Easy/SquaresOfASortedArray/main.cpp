#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Approaches:
 *
 * 1. Sorting. Square each number in the input vector, A, and then sort the vector.
 *
 * Time complexity: O(n log n) [where n is the length of the input vector]
 * Space complexity: O(1)
 *
 *
 * 2. Bucket sort/hashtable. First, make all numbers in the input vector positive.
 * Then, allocated a vector<int> bases that has size of the largest number in A plus one.
 * The indices in the vector will correspond to the potential bases that we could square.
 * For each number in the input vector, we count how many times it appears using our bases vector.
 * Finally, we loop through the bases vector and at each index that has value greater than zero
 * we add that many copies of the index squared to our result vector at the appropriate index.
 *
 * Time complexity: O(largest number in the input vector)
 * Space complexity: O(n) [where n is the length of the input vector]
 *
 *
 * 3. Two-pointers. We use two integer variables, i and j, to move from both ends of the input vector towards the middle.
 * As we go, we compare the numbers at A[i] and at A[j]. If the absolute value of A[i] is larger than the absolute value
 * of A[j], then the square of A[i] will be larger than the square of A[j], and we add the square of A[i] to the appropriate
 * index in our result vector. Else, we add the square of A[j] to the appropriate index in our result vector.
 *
 * Time complexity: O(n) [where n is the length of our input vector]
 * Space complexity: O(n)
 *
 */

vector<int> sortedSquares(vector<int> & A)
{
    for(int & number : A)
    {
        number=(number * number);
    }

    sort(A.begin(), A.end());

    return A;
}

vector<int> sortedSquares(vector<int> & A)
{
    int n=int(A.size());

    for(int & number : A)
    {
        if(number < 0)
        {
            number*=-1;
        }
    }

    int maxNumber=*(max_element(A.begin(), A.end()));

    vector<int> bases(maxNumber+1, 0);

    for(const int & number : A)
    {
        bases[number]++;
    }

    vector<int> result(n, 0);

    int index=0;

    for(int i=0;i<int(bases.size());++i)
    {
        for(int count=0;count<bases[i];++count)
        {
            result[index]=i*i;

            index++;
        }
    }

    return result;
}

vector<int> sortedSquares(vector<int> & A)
{
    int n=int(A.size());

    vector<int> result(n, 0);

    int i=0;

    int j=n-1;

    for(int index=n-1;index>=0;--index)
    {
        if(abs(A[i]) > abs(A[j]))
        {
            result[index]=A[i] * A[i];

            i++;
        }
        else
        {
            result[index]=A[j] * A[j];

            j--;
        }
    }

    return result;
}