#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1. Add up all pairs of numbers in the input vector and find the maximum sum of the numbers that add up to less than K.
 *
 * Time complexity: O(n-squared) [where n is the length of the input vector]
 * Space complexity: O(1)
 *
 * 2. Using a hashtable (unordered_multimap<int, int>) map each number in the input vector to its index.
 * Then, for each number in the input number, calculate the difference between that number and K. Then,
 * loop from 1 up to the difference and if any number, x, in that range is in the hashtable and the number's index is
 * greater than i, add those two numbers together and if the sum is greater than our sum so far, set our result equal to
 * the current sum. Return our int result.
 *
 * Time complexity: O(n * d * k) [where n is the length of the input vector, d is the difference between the current element in the array and K,
 * and k is the number of keys in the hashtable matching the current number in the range of [1, (K-A[i]))]
 * Space complexity: O(n)
 *
 * 3. Sorting. We sort the input vector and then move towards the middle of the vector from both ends, adding number pairs of numbers as we go.
 * Along the way, we handle two cases:
 *
 * a) the sum is less than K --> we update our result variable if the current sum is greater than result.
 * Then, we increment our left variable by one to get a larger sum on the next iteration of the while loop.
 *
 * b) the sum is greater than K --> decrement our right integer since A[right] is too big.
 *
 * Time complexity: O(n log n)
 * Space complexity: O(1)
 */

int twoSumLessThanK(vector<int> & A, int K)
{
    int sum=-1;

    if(A.empty() || K==0)
    {
        return sum;
    }

    auto n=A.size();

    for(auto i=0;i<n;++i)
    {
        for(auto j=i+1;j<n;++j)
        {
            if(j!=i)
            {
                int currentSum=A[i] + A[j];

                if(currentSum < K)
                {
                    if(sum==-1 || currentSum > sum)
                    {
                        sum=currentSum;
                    }
                }
            }
        }
    }

    return sum;
}

int twoSumLessThanK(vector<int> & A, int K)
{
    int result=-1;

    unordered_multimap<int, int> hashtable;

    auto n=A.size();

    for(auto i=0;i<n;++i)
    {
        int number=A[i];

        hashtable.insert(make_pair(number, i));
    }

    for(auto i=0;i<n;++i)
    {
        int difference=K - A[i];

        for(auto number=1;number<difference;++number)
        {
            if(hashtable.count(number))
            {
                auto range=hashtable.equal_range(number);

                for(auto itr=range.first;itr!=range.second;++itr)
                {
                    if(itr->second > i)
                    {
                        int currentSum=A[i] + itr->first;

                        if(result==-1 || currentSum > result)
                        {
                            result=currentSum;
                        }
                    }
                }
            }
        }
    }

    return result;
}

int twoSumLessThanK(vector<int> & A, int K)
{
    int result=-1;

    sort(A.begin(), A.end());

    auto n=A.size();

    auto left=0;

    auto right=n-1;

    while(left < right)
    {
        int sum=A[left] + A[right];

        if(sum < K)
        {
            result=max(result, sum);

            left++;
        }
        else
        {
            right--;
        }
    }

    return result;
}