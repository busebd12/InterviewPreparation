#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
 * Approach: copy the contents of the input vector into an unordered_set<int> (this will eliminate duplicates
 * since duplicates are not allowed in an unordered_set). If the size of the set is less than three,
 * then there were only two distinct numbers to begin with, so return the maximum of the unordered_set.
 * If there are more than three elements, remove the first two maximums and return the third one.
 *
 * Time complexity: O(n) [where n is the number of elements in the input vector]
 * Space complexity: O(n - number of duplicate elements)
 */

int thirdMax(vector<int>& nums)
{
    if(nums.empty())
    {
        return 0;
    }

    int n=int(nums.size());

    if(n < 3)
    {
        return *(max_element(nums.begin(), nums.end()));
    }

    unordered_set<int> distinct(nums.begin(), nums.end());

    if(distinct.size() < 3)
    {
        return *(max_element(distinct.begin(), distinct.end()));
    }

    for(int count=0;count<2;++count)
    {
        int currentMax=*(max_element(distinct.begin(), distinct.end()));

        distinct.erase(currentMax);
    }

    return *(max_element(distinct.begin(), distinct.end()));
}