#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

/*
 * Approach: Check up to which point the input vector is sorted until.
 * If the position is either the last element or the second to last element,
 * then we can fix the array in one move. Else, look at the current element,
 * the previous element, and the next element. If the previous element is
 * greater than the next element, then the current element needs to become
 * the previous element in order to maintain the ascending order property.
 * Else, the current number needs to become the next number in order to maintain
 * the ascending order condition. After making our one change, check to see if the
 * input array is in sorted order. Return false if it is not. Otherwise, return true.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

bool checkPossibility(vector<int> & nums)
{
    if(nums.empty())
    {
        return true;
    }


    const int n=int(nums.size());

    if(n==1)
    {
        return true;
    }

    auto itr=is_sorted_until(nums.begin(), nums.end());

    if(itr==nums.end() || next(itr)==nums.end())
    {
        return true;
    }

    int previous=*(itr - 1);

    int current=*(itr);

    int next=*(itr + 1);

    if(previous > next)
    {
        *(itr - 1)=current;
    }
    else
    {
        *(itr)=next;
    }

    return is_sorted(nums.begin(), nums.end());
}