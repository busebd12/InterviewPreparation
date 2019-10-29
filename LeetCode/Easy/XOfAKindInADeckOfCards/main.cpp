#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
 * Approach:
 *
 * 1) Using a hashtable (unordered_map<int, int>) we map each number in our input vector to its frequency in the input vector.
 * 2) Then, since each frequency can be a potential group size, we check to make sure that all frequencies are greater than or equal to two.
 * 3) Next, we find the largest frequency from our hashtable. This will server as the upper bound for our group sizes.
 * 4) Then, we check each group size starting from two up to and including our largest group size to see if we can group the cards into groups of that size.
 * If we can, then we increment viableGroupSizes.
 * 5) At the end of our function, we return whether or not we found any groups we can divide our cards into.
 * Aka, whether or not viableGroupSizes is greater than zero.
 *
 * Time complexity: O(n) [where n is the length of our input vector]
 * Space complexity: O(d) [where d is the number of distinct numbers in our input vector]
 */

bool hasGroupsSizeX(vector<int> & deck)
{
    if(deck.empty())
    {
        return false;
    }

    int minimumGroupSize=2;

    unordered_map<int, int> hashtable;

    for(const int & number : deck)
    {
        hashtable[number]++;
    }

    for(const auto & element : hashtable)
    {
        if(element.second < minimumGroupSize)
        {
            return false;
        }
    }

    auto maxElement=max_element(hashtable.begin(), hashtable.end(), [] (const auto & e1, const auto & e2) {return e1.second < e2.second;});

    int largestGroupSize=maxElement->second;

    int viableGroupSizes=0;

    for(int groupSize=minimumGroupSize;groupSize<=largestGroupSize;++groupSize)
    {
        bool viableGroupSize=true;

        for(auto & element : hashtable)
        {
            if((element.second % groupSize) > 0)
            {
                viableGroupSize=false;

                break;
            }
        }

        if(viableGroupSize)
        {
            viableGroupSizes++;
        }
    }

    return viableGroupSizes > 0;
}