#include <iostream>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Use an auxiliary vector and copy all non-zero elements into it and then copy the zero elements
 *
 * Time complexity: O(n) [where n is the size of the input vector]
 * Space complexity: O(n)
 *
 *
 * 2) Move all non-zero elements to the left as far as possible in the vector.
 * Then, fill the rest of the spots with zeroes.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

void moveZeroes(vector<int>& nums)
{
    if(nums.empty())
    {
        return;
    }

    int n=int(nums.size());

    vector<int> extra;

    for(const auto & number : nums)
    {
        if(number!=0)
        {
            extra.push_back(number);
        }
    }

    for(const auto & number : nums)
    {
        if(number==0)
        {
            extra.push_back(number);
        }
    }

    nums=extra;
}

void moveZeroes(vector<int> & nums)
{
    if(nums.empty())
    {
        return;
    }

    int insertPosition=0;

    for(int number : nums)
    {
        if(number!=0)
        {
            nums[insertPosition]=number;

            insertPosition++;
        }
    }

    int n=int(nums.size());

    while(insertPosition < n)
    {
        nums[insertPosition]=0;

        insertPosition++;
    }
}