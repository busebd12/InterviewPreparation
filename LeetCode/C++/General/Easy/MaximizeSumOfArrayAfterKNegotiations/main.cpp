#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
using namespace std;

/*
 * Approaches:
 *
 * 1. Sorting. The algorithm is as follows
 *
 * Step 1: sort the input vector
 * Step 2: count the number of negative numbers
 * Step 3: If there are no negative numbers, then we count the number of zeroes.
 * If there are any zeroes, then we will do all our negations on one of the zeroes.
 * Thus, the maximum sum is the sum of all the numbers in the vector
 * Step 4: If there are no zeroes, then all our negations will be done on the smallest positive value in the vector.
 * Each time we negate the smallest positive value, we recalculate the sum of the vector.
 * Step 6: If there are negative numbers in the vector, we negate all the negative numbers we can until we run out of negative
 * values of K becomes zero.
 * Step 7: We then re-sort the vector so that all the newly positive values will be ordered correctly.
 * Step 8: If K is still greater than zero, we than perform the remaining negations on the smallest remaining value in
 * the input vector and re-calculate the sum as we do each negation.
 *
 * Our final answer is the sum of the vector.
 *
 * Time complexity: O(n log n)
 * Space complexity: O(1)
 *
 *
 * 2. Minimum priority queue. We add all the numbers to a minimum priority queue so that the numbers are sorted from
 * least to greatest. Then, we remove the first K elements from the priority queue. Because of the ordering, these
 * numbers will be the K smallest numbers. As we remove each number, we perform the negation. After we have negated
 * the number, we add it back into the priority queue. Finally, we add up all the numbers in the priority queue
 * and that is our answer.
 *
 * Time complexity: O(n log n)
 * Space complexity: O(n)
 */

int largestSumAfterKNegations(vector<int> & A, int K)
{
    int sum=0;

    if(A.empty())
    {
        return sum;
    }

    int n=int(A.size());

    if(K==0)
    {
        sum=accumulate(A.begin(), A.end(), 0);

        return sum;
    }

    sort(A.begin(), A.end());

    int negativeNumbers=count_if(A.begin(), A.end(), [] (const int & number) {return number < 0;});

    if(negativeNumbers==0)
    {
        int zeroes=count_if(A.begin(), A.end(), [] (const int & number) {return number==0;});

        if(zeroes >= 1)
        {
            sum=accumulate(A.begin(), A.end(), 0);
        }
        else
        {
            while(K > 0)
            {
                A[0]=-A[0];

                sum=accumulate(A.begin(), A.end(), 0);

                K--;
            }
        }
    }
    else
    {
        int i=0;

        while(A[i] < 0)
        {
            if(K==0)
            {
                break;
            }

            A[i]=-A[i];

            K--;

            i++;
        }

        sort(A.begin(), A.end());

        while(K > 0)
        {
            A[0]=-A[0];

            sum=accumulate(A.begin(), A.end(), 0);

            K--;
        }

        sum=accumulate(A.begin(), A.end(), 0);
    }

    return sum;
}

int largestSumAfterKNegations(vector<int> & A, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for(auto & element : A)
    {
        pq.push(element);
    }

    while(K > 0)
    {
        int current=pq.top();

        pq.pop();

        current=-current;

        pq.push(current);

        K--;
    }

    int sum=0;

    while(!pq.empty())
    {
        sum+=pq.top();

        pq.pop();
    }

    return sum;
}