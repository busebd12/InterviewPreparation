#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

/*
 * Solutions:
 *
 * 1. Using recursion + backtracking to generate all possible permutations and then select the one at the kth index.
 *
 * Time complexity: O(n!)
 * Space complexity: O(n!)
 *
 * 2. Generate the next permutation k times and then return the desired permutation.
 *
 * Time complexity: O(k * n)
 * Space complexity: O(n) if we count the space needed for the return value. Else, O(1)
 *
 * 3. Generate the next permutation k times using the std::next_permutation function provided by the STL.
 *
 * Time complexity: O(k * n)
 * Space complexity: O(n) if we count the space needed for the return value. Else, O(1)
 *
 * 4. Based on the following logic: https://www.lintcode.com/problem/permutation-sequence/note/187602
 *
 * Time complexity: O(n-squared)
 * Space complexity: O(n)
 */

void backtracking(std::vector<int> & numbers, std::vector<std::vector<int>> & permutations, std::unordered_set<int> & skipIndices, std::vector<int> & permutation, int n)
{
    if(permutation.size()==n)
    {
        permutations.push_back(permutation);

        return;
    }

    for(int index=0;index<n;++index)
    {
        if(!skipIndices.count(index))
        {
            permutation.push_back(numbers[index]);

            skipIndices.insert(index);

            backtracking(numbers, permutations, skipIndices, permutation, n);

            skipIndices.erase(index);

            permutation.pop_back();
        }
    }
}

std::string getPermutation(int n, int k)
{
    std::string result{};

    if(n <= 0 || k <= 0)
    {
        return result;
    }

    std::vector<int> numbers(n, 0);

    for(int number=1;number<=n;++number)
    {
        numbers[number-1]=number;
    }

    std::vector<std::vector<int>> permutations;

    std::vector<int> permutation;

    std::unordered_set<int> skipIndices;

    backtracking(numbers, permutations, skipIndices, permutation, n);

    for(auto & element : permutations[k-1])
    {
        result+=(element + '0');
    }

    return result;
}

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

std::string getPermutation(int n, int k)
{
    std::string result{};

    if(n <= 0 || k <= 0)
    {
        return result;
    }

    std::vector<int> numbers(n, 0);

    for(int number=1;number<=n;++number)
    {
        numbers[number-1]=number;
    }

    for(int count=0;count<k-1;++count)
    {
        nextPermutation(numbers);
    }

    for(auto & number : numbers)
    {
        result+=(number + '0');
    }

    return result;
}

std::string getPermutation(int n, int k)
{
    std::string result{};

    if(n <= 0 || k <= 0)
    {
        return result;
    }

    for(int number=1;number<=n;++number)
    {
        result+=(number + '0');
    }

    for(int count=0;count<k-1;++count)
    {
        std::next_permutation(result.begin(), result.end());
    }

    return result;
}

std::string getPermutation(int n, int k)
{
    std::string result{};

    if(n <= 0 || k <= 0)
    {
        return result;
    }

    std::string numbers{};

    for(int number=1;number<=n;++number)
    {
        numbers+=(number + '0');
    }

    std::vector<int> factorial(n+1, 0);

    factorial[0]=1;

    for(int i=1;i<=n;++i)
    {
        factorial[i]=i * factorial[i-1];
    }

    k--;

    for(int i=n;i>0;--i)
    {
        int index=k/factorial[i-1];

        result+=numbers[index];

        numbers.erase(numbers.begin() + index);

        k=k % factorial[i-1];
    }

    return result;
}