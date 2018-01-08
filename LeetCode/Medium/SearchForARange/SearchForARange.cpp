#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int> & nums, int left, int right, int target)
{
    int middle=(left + right)/2;

    if(right < left)
    {
        return -1;
    }

    if(nums[middle]==target)
    {
        return middle;
    }
    else if(nums[middle] > target)
    {
        return binarySearch(nums, left, middle-1, target);
    }
    else
    {
        return binarySearch(nums, middle+1, right, target);
    }
}

vector<int> searchRange(vector<int> & nums, int target)
{
    vector<int> result;

    if(nums.empty())
    {
        return {-1, -1};
    }

    if(nums.size()==1)
    {
        if(nums[0]!=target)
        {
            return {-1, -1};
        }
        else
        {
            return {0, 0};
        }
    }

    const size_t numsSize=nums.size();

    if(nums[0]==nums[numsSize-1] && nums[0]==target)
    {
        return {0, (int)numsSize-1};
    }

    int index=binarySearch(nums, 0, (int)numsSize-1, target);

    if(index==-1)
    {
        return {-1, -1};
    }
    else if(index==numsSize-1)
    {
        for(int i=index;i>=0;--i)
        {
            if(nums[i]==target)
            {
                result.emplace_back(i);
            }
            else
            {
                break;
            }
        }
    }
    else if(index==0)
    {
        for(int i=index;i<numsSize;++i)
        {
            if(nums[i]==target)
            {
                result.emplace_back(i);
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        for(int i=index;i>=0;--i)
        {
            if(nums[i]==target)
            {
                result.emplace_back(i);
            }
            else
            {
                break;
            }
        }

        for(int j=index;j<numsSize;++j)
        {
            if(nums[j]==target)
            {
                result.emplace_back(j);
            }
            else
            {
                break;
            }
        }
    }

    int leftEnd=*(min_element(begin(result), end(result)));

    int rightEnd=*(max_element(begin(result), end(result)));

    return {leftEnd, rightEnd};
}