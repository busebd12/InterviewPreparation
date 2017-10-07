#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> & nums)
{
    int answer=0;

    int current=0;

    const size_t numsSize=nums.size();

    for(int index=0;index<numsSize;++index)
    {   
        if(index==numsSize-1)
        {
            if(nums[index]==1)
            {
                ++current;
            }
            
            if(current > 0)
            {
                if(current > answer)
                {
                    answer=current;
                }
            }
        }
        else
        {
            if(nums[index]==0)
            {
                if(current > answer)
                {
                    answer=current;
                }
                
                current=0;
            }
            else
            {
                ++current;
            }
        }
        
    }

    return answer;
}