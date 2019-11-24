#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: while the input vector still needs to be transformed, we loop through the vector
 * and store the indices where vector values need to be incremented and decremented.
 * Then, we increment and decrement the appropriate values by their indices. Once there
 * are no more values to be incremented or decremented, we break out of the while loop.
 *
 * Time complexity: O(n-2 + T) [where n-2 is the number of elements in our input vector minus the first and last number
 * and T is the total number of vector values that need to be transformed]
 * Space complexity: O(T)
 */

vector<int> transformArray(vector<int> & arr)
{
    auto n=arr.size();

    while(true)
    {
        vector<int> incrementIndices;

        vector<int> decrementIndices;

        for(auto i=1;i<n-1;++i)
        {
            if(arr[i] < arr[i-1] && arr[i] < arr[i+1])
            {
                incrementIndices.push_back(i);
            }

            if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
            {
                decrementIndices.push_back(i);
            }
        }

        if(incrementIndices.empty() && decrementIndices.empty())
        {
            break;
        }

        for(const auto & index : incrementIndices)
        {
            arr[index]++;
        }

        for(const auto & index : decrementIndices)
        {
            arr[index]--;
        }
    }

    return arr;
}