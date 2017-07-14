#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> & nums)
{
    if(nums.empty())
    {   
        return vector<int>();
    }
    
    const size_t numsSize=nums.size();
    
    if(numsSize==1)
    {
        if(nums.back()==9)
        {
            nums.back()=1;
            
            nums.emplace_back(0);
        }
        else
        {
            nums[numsSize-1]++;
        }
    }
    else
    {
        int numberOfNines{};
        
        for(int index=numsSize-1;index>=0;--index)
        {
            if(nums[index]==9)
            {
                ++numberOfNines;
            }
            else
            {
                break;
            }
        }
        
        if(numberOfNines==0)
        {
            nums[numsSize-1]++;
        }
        else
        {
            for(int index=numsSize-1, count=0;count<numberOfNines;--index, ++count)
            {
                nums[index]=0;
            }
            
            nums[(numsSize-1)-numberOfNines]++;
        }
    }
    
    return nums;
}