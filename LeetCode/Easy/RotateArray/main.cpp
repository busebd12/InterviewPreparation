#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) For k-times, shift all the elements up one spot and then override the value of the first element with the last element.
 * Result: Time Limit Exceeded (TLE)
 * Time complexity: O(kn) [where n is the number of elements in the input vector and k is the number of rotations]
 * Space complexity: O(1)
 *
 * 2) Very similar to #1 except we remove the last element and then add it to the beginning of the vector. Do this k times.
 * Result: Accepted
 * Time complexity: O(kn)
 * Space complexity: O(1)
 *
 * 3) Make a copy of the input vector and then rotate the elements accordingly. We use the trick (i + k) % n to calculate the index
 * for the rotated element.
 * Result: Accepted
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 * 4) Reverse the first n-k elements. Then, reverse the last k elements. Finally, reverse the entire vector.
 * Result: Accepted
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 * 5) Use the rotate function from the STL.
 * Result: Accepted
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

void rotate(vector<int>& nums, int k)
{
    if(nums.empty())
    {
        return;
    }

    if(k <= 0 || nums.size()==1)
    {
        return;
    }

    int n=int(nums.size());

    for(int count=0;count<k;++count)
    {
        int lastNumber=nums.back();

        for(int i=n-2;i>=0;--i)
        {
            nums[i+1]=nums[i];
        }

        nums[0]=lastNumber;
    }
}

void rotate(vector<int>& nums, int k)
{
    if(nums.empty())
    {
        return;
    }

    if(k<=0||nums.size()==1)
    {
        return;
    }

    for(int count=0; count<k; ++count)
    {
        int number=nums.back();

        nums.pop_back();

        nums.insert(nums.begin(), number);
    }
}

void rotate(vector<int> & nums, int k)
{
    if(nums.empty())
    {
        return;
    }

    if(k <= 0 || nums.size()==1)
    {
        return;
    }

    int n=int(nums.size());

    vector<int> numsCopy(n);

    for(int i=0;i<n;i++)
    {
        numsCopy[i]=nums[i];
    }

    for(int i=0;i<n;i++)
    {
        nums[(i + k) % n]=numsCopy[i];
    }
}

void rotate(vector<int> & nums, int k)
{
    if(nums.empty())
    {
        return;
    }

    if(k <= 0 || nums.size()==1)
    {
        return;
    }

    int n=int(nums.size());

    k=k % n;

    reverse(nums.begin(), nums.begin() + (n-k));

    reverse(nums.begin() + (n-k), nums.end());

    reverse(nums.begin(), nums.end());
}

void rotate(vector<int> & nums, int k)
{
    if(nums.empty())
    {
        return;
    }

    if(k <= 0 || nums.size()==1)
    {
        return;
    }

    int n=int(nums.size());

    k=k % n;

    std::rotate(nums.rbegin(), nums.rbegin() + k, nums.rend());
}