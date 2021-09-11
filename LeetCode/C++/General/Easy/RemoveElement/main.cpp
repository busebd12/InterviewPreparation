#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Approach:
 * Use the remove_if algorithm from the STL to move all occurrences of the target number to the end of the vector.
 * Then, utilize the erase method from the vector class to actually remove the desired elements.
 *
 * Time Complexity: O(n) [where n is the size of the input vector]
 *
 * Space Complexity: O(1)
 */

int removeElement(vector<int>& nums, int val)
{
    auto itr=remove_if(nums.begin(), nums.end(), [val] (auto & number) {return number==val;});

    nums.erase(itr, nums.end());

    return int(nums.size());
}