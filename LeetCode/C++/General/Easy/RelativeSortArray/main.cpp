#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

/*
 * Approach: We use bucket sort to sort the elements in arr1 and keep track of each number's frequency.
 * Then, we loop through arr2 and create the relative ordering in our vector<int> result. Finally,
 * we loop over our buckets vector and any buckets that have value greater than zero are numbers
 * that were in arr1 but not in arr2. Since the buckets vector is sorted, we just add the numbers
 * to the end of the result vector as we go along.
 *
 * Time complexity: O(n + m + 1001) [where n is the length of arr1, m is the length of arr2, and 1001 is the length of our buckets vector]
 * Space complexity: O(r + 1001) [where r is the length of our results vector and 1001 is the length of our buckets vector]
 */

vector<int> relativeSortArray(vector<int> & arr1, vector<int> & arr2)
{
    if(arr2.empty())
    {
        return arr1;
    }

    vector<int> result;

    if(arr1.empty())
    {
        return result;
    }

    vector<int> buckets(1001, 0);

    for(const auto & number : arr1)
    {
        buckets[number]++;
    }

    for(const auto & number : arr2)
    {
        for(auto count=0;count<buckets[number];++count)
        {
            result.push_back(number);
        }

        buckets[number]=0;
    }

    for(auto i=0;i<buckets.size();++i)
    {
        if(buckets[i] > 0)
        {
            for(auto count=0;count<buckets[i];++count)
            {
                result.push_back(i);
            }
        }
    }

    return result;
}