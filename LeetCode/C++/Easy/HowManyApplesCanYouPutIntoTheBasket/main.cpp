#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: sort the input vector and then greedily select apples with increasing weights until our basket capacity is full.
 *
 * Time complexity: O(n log n)
 * Space complexity: O(1)
 */

int maxNumberOfApples(vector<int> & arr)
{
    if(arr.empty())
    {
        return 0;
    }

    sort(arr.begin(), arr.end());

    int capacity=5000;

    int count=0;

    for(auto & weight : arr)
    {
        if(capacity - weight >= 0)
        {
            capacity-=weight;

            count++;
        }
    }

    return count;
}