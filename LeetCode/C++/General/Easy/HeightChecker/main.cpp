#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1. Create an extra copy of the vector<int> heights and sort it.
 * Then, count the differences in heights between the unsorted input and the sorted copy.
 * The difference is our answer.
 *
 * Time complexity: O(n log n) [where n is the length of the input vector]
 * Space complexity: O(n)
 *
 * 2. Bucket sort. Use a hashtable (unordered_map<int, int>) to count the frequency for each height.
 * Then, create a vector of buckets to represent each height. Loop from the smallest height up to, and including, the
 * largest height and increment each bucket accordingly. Finally, compare the differences between the heights in
 * our buckets vector with the original input. The number of differences is our answer.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

int heightChecker(vector<int> & heights)
{
    if(heights.empty())
    {
        return 0;
    }

    auto n=heights.size();

    if(n==1)
    {
        return 0;
    }

    vector<int> copy=heights;

    sort(copy.begin(), copy.end());

    int count=0;

    for(auto i=0;i<n;++i)
    {
        if(copy[i]!=heights[i])
        {
            count++;
        }
    }

    return count;
}

int heightChecker(vector<int>& heights)
{
    if(heights.empty())
    {
        return 0;
    }

    auto n=heights.size();

    if(n==1)
    {
        return 0;
    }

    unordered_map<int, int> hashtable;

    for(const auto & height : heights)
    {
        hashtable[height]++;
    }

    vector<int> buckets(n, 0);

    int minValue=*(min_element(heights.begin(), heights.end()));

    int maxValue=*(max_element(heights.begin(), heights.end()));

    int index=0;

    for(auto number=minValue;number<=maxValue;++number)
    {
        if(hashtable.count(number))
        {
            for(auto i=0;i<hashtable[number];++i)
            {
                buckets[index]=number;

                index++;
            }
        }
    }

    int count=0;

    for(auto i=0;i<n;++i)
    {
        if(buckets[i]!=heights[i])
        {
            count++;
        }
    }

    return count;
}