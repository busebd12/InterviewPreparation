#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int singleNonDuplicate(vector<int>& nums)
{
    if(nums.empty())
    {
        return 0;
    }

    if(nums.size()==1)
    {
        return nums[0];
    }

    int n=int(nums.size());

    int minimum=nums[0];

    int maximum=nums[n-1];

    int result=0;

    for(int number=minimum;number<=maximum;++number)
    {
        auto itr=lower_bound(nums.begin(), nums.end(), number);

        if(itr!=nums.end())
        {
            if(*itr==number)
            {
                int foundIndex=(itr - nums.begin());

                if(foundIndex==0)
                {
                    if(nums[foundIndex+1]!=number)
                    {
                        result=number;

                        break;
                    }
                }
                else if(foundIndex==n-1)
                {
                    if(nums[foundIndex-1]!=number)
                    {
                        result=number;

                        break;
                    }
                }
                else
                {
                    if(nums[foundIndex-1]!=number && nums[foundIndex+1]!=number)
                    {
                        //cout << *itr << " found at index " << foundIndex << endl;

                        result=number;

                        break;
                    }
                }
            }
        }
    }

    return result;
}

int singleNonDuplicate(vector<int>& nums)
{
    int result=0;

    for(int number : nums)
    {
        result=result ^ number;
    }

    return result;
}

void doWork(vector<int> & nums, int i, int j, int & result)
{
    if(i < 0 || j > nums.size()-1 || i > j)
    {
        return;
    }

    int mid=(i + ((j-i) >> 1));

    if(mid==0)
    {
        if(nums[mid]!=nums[mid+1])
        {
            result=nums[mid];

            return;
        }
    }
    else
    {
        if(mid==nums.size()-1)
        {
            if(nums[mid]!=nums[mid-1])
            {
                result=nums[mid];

                return;
            }
        }

        if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1])
        {
            result=nums[mid];

            return;
        }
    }

    doWork(nums, i, mid-1, result);

    doWork(nums, mid+1, j, result);
}

int singleNonDuplicate(vector<int>& nums)
{
    if(nums.empty())
    {
        return 0;
    }

    if(nums.size()==1)
    {
        return nums[0];
    }

    int i=0;

    int j=int(nums.size()-1);

    int result=0;

    doWork(nums, i, j, result);

    return result;
}