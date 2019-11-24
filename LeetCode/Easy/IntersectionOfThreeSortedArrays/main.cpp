#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: we use a hashtable (vector<int>) to count the frequencies of all numbers
 * from arr1, arr2, and arr3. Any number in the hashtable that has a frequency of three
 * or more appears in all three of the input vectors and we add that number to our result vector.
 *
 * Time complexity: O(a + b + c) [where a is the length of arr1; b is the length of arr2; c is the length of arr3]
 * Space complexity: O(2001)
 */

vector<int> arraysIntersection(vector<int> & arr1, vector<int> & arr2, vector<int> & arr3)
{
    vector<int> result;

    if(arr1.empty() || arr2.empty() || arr3.empty())
    {
        return result;
    }

    vector<int> hashtable(2001);

    for(const auto & number : arr1)
    {
        hashtable[number]++;
    }

    for(const auto & number : arr2)
    {
        hashtable[number]++;
    }

    for(const auto & number : arr3)
    {
        hashtable[number]++;
    }

    auto h=hashtable.size();

    for(auto index=0;index<h;++index)
    {
        if(hashtable[index] >= 3)
        {
            result.push_back(index);
        }
    }

    return result;
}