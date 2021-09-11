#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Fill an unordered_set with all the numbers in the range of [0, n].
 * Then, loop over the input vector and remove each number from the unordered_set.
 * The missing number will be the only number left in the unordered_set.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 * 2) Sum up all the numbers in the range [0, n].
 * Then, loop through the input vector and subtract each number from the sum.
 * The value of the sum will be the missing number.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 * 3) Use bit manipulation, specifically, XOR, to single out the missing number.
 * How? First, we need to understand the properties of XOR: firstly, XOR'ing a number by itself results in 0.
 * So if we have 1 ^ 1, this will equal 0.
 * Secondly, XOR is commutative and associative - what this means is we can re-order our
 * XOR operations in any way we want and it will result in the same value we would have if we didn't.
 * Finally, a number XOR'd by 0 will result in the same number unchanged.
 * So, essentially, by XOR'ing all the numbers from 0 to n, and all the numbers in the array,
 * we will end up XOR'ing 2 of every number except for the missing one.
 * As we know, it doesn't matter which order we XOR these numbers in - as long as we XOR 2 of the same number,
 * it will result in 0. So eventually we will get 0 ^ the missing number, which, due to the third property I mentioned, will simply equal the missing number.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

int missingNumber(vector<int>& nums)
{
    if(nums.empty())
    {
        return 0;
    }

    unordered_set<int> numbers;

    int n=int(nums.size());

    for(int number=0;number<=n;++number)
    {
        numbers.insert(number);
    }

    for(int number : nums)
    {
        numbers.erase(number);
    }

    return *numbers.begin();
}

int missingNumber(vector<int> & nums)
{
    if(nums.empty())
    {
        return 0;
    }

    int n=int(nums.size());

    int sum=0;

    for(int number=0;number<=n;++number)
    {
        sum+=number;
    }

    for(int number : nums)
    {
        sum-=number;
    }

    return sum;
}

int missingNumber(vector<int> & nums)
{
    if(nums.empty())
    {
        return true;
    }

    int n=int(nums.size());

    int result=n;

    int i=0;

    for(int number : nums)
    {
        result^=number;

        result^=i;

        i++;
    }

    return result;
}