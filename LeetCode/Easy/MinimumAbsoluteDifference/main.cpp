#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: we sort the input vector and then make two passes over the input vector.
 * In the first pass, we find the minimum absolute difference between any two numbers.
 * In the second pass, we find all pairs of numbers that have a difference equal to the
 * absolute minimum difference and add them to the vector<vector<int>> result. Finally,
 * we return our vector<vector<int>> result.
 *
 * Time complexity: O(n log n)
 * Space complexity: O(1)
 */

vector<vector<int>> minimumAbsDifference(vector<int> & arr)
{
    vector<vector<int>> result;

    if(arr.empty())
    {
        return result;
    }

    sort(arr.begin(), arr.end());

    int difference=numeric_limits<int>::max();

    auto n=arr.size();

    for(auto i=1;i<n;++i)
    {
        int currentDifference=arr[i] - arr[i-1];

        difference=min(difference, currentDifference);
    }

    for(auto i=1;i<n;++i)
    {
        int currentDifference=arr[i] - arr[i-1];

        if(currentDifference==difference)
        {
            result.push_back({{arr[i-1], arr[i]}});
        }
    }

    return result;
}