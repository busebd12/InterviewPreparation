#include <algorithm>
#include <iostream>
#include <vector>

/*
 * Solution: Combination of two explinations taken from https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
 * and https://www.nayuki.io/page/next-lexicographical-permutation-algorithm.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

void nextPermutation(std::vector<int> & nums)
{
    if(nums.empty())
    {
        return;
    }

    int n=int(nums.size());

    int i=0;

    bool sortedInDescendingOrder=true;

    for(int index=0;index<n;++index)
    {
        if(index+1 < n)
        {
            if(nums[index] < nums[index+1])
            {
                i=index;

                sortedInDescendingOrder=false;
            }
        }
    }

    if(i==0 && sortedInDescendingOrder)
    {
        std::reverse(nums.begin(), nums.end());

        return;
    }

    int k=0;

    for(int j=0;j<n;++j)
    {
        if(nums[j] > nums[i] && j > i)
        {
            k=j;
        }
    }

    std::swap(nums[i], nums[k]);

    std::reverse(nums.begin()+(i+1), nums.end());
}


int main()
{
    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}