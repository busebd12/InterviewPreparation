#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Calculate the minimum and maximum values of the vector.
 * Then, loop through the vector and if we find a duplicate value, make it equal to INT_MAX.
 * Next, sort the vector and then, remove all maximum int values (duplicates) from the vector.
 * If the minimum and maximum values are missing, add them back to the vector.
 *
 * Time complexity: O(n log n) [where n is the size of the input vector]
 * Space complexity: O(1)
 *
 * 2) Use the unique function from the STL to move all duplicates to the end of the vector.
 * Then, remove all the duplicate values.
 *
 * Time complexity: O(n) [where n is the size of the input vector]
 * Space complexity: O(1)
 *
 * 3) Loop over the vector and if we find a duplicate update the count of duplicates.
 * When two numbers are not the same, set nums[i-count] equal to nums[i] (pushing all duplicate values to the end of the vector).
 *
 * Time complexity: O(n) [where n is the size of the input vector]
 * Space complexity: O(1)
 */

int removeDuplicates(vector<int> & nums)
{
    if(nums.empty())
    {
        return 0;
    }

    if(nums.size()==1)
    {
        return 1;
    }

    int n=int(nums.size());

    int maxNumber=*(max_element(nums.begin(), nums.end()));

    int minNumber=*(min_element(nums.begin(), nums.end()));

    for(int i=0;i<n;++i)
    {
        if(i < n-1)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]=numeric_limits<int>::max();
            }
        }
    }

    sort(nums.begin(), nums.end());

    while(nums.back()==numeric_limits<int>::max())
    {
        nums.pop_back();
    }

    auto maxItr=find(nums.begin(), nums.end(), maxNumber);

    if(maxItr==nums.end())
    {
        nums.push_back(maxNumber);
    }

    auto minItr=find(nums.begin(), nums.end(), minNumber);

    if(minItr==nums.end())
    {
        nums.insert(nums.begin(), minNumber);
    }

    return int(nums.size());
}

int removeDuplicates(vector<int> & nums)
{
    auto last=unique(nums.begin(), nums.end());

    nums.erase(last, nums.end());

    return int(nums.size());
}

int removeDuplicates(vector<int> & nums)
{
    int n=int(nums.size());

    int count=0;

    for(int i=1;i<n;i++)
    {
        if(nums[i]==nums[i-1])
        {
            count++;
        }
        else
        {
            nums[i-count]=nums[i];
        }
    }

    return n-count;
}
int main()
{
    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}