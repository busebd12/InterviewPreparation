#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cmath>
using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
    const size_t numsSize=nums.size();
    
    int minimum=numeric_limits<int>::max();
    
    int answer=0;
    
    sort(begin(nums), end(nums));
    
    for(int index=0;index<numsSize;++index)
    {
        int left=index+1;
        
        int right=numsSize-1;
        
        while(left < right)
        {
            int sum=nums[index] + nums[left] + nums[right];
            
            int difference=abs(target-sum);
            
            if(difference==0)
            {
                return sum;
            }
            
            if(difference < minimum)
            {
                minimum=difference;
                
                answer=sum;
            }
            
            if(sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }
    
    return answer;
}