#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double findMaxAverage(vector<int>& nums, int k)
{
    if(nums.empty())
    {
        return 0.0;
    }
    
    const size_t numsSize=nums.size();
    
    if(numsSize < k)
    {
        return 0.0;
    }
    
    double firstAverage=0.0;
    
    int total=0;
    
    for(int index=0;index<k;++index)
    {
        total+=nums[index];
    }
    
    firstAverage=(double)total/k;
    
    double maxAverage=firstAverage;
    
    for(int index=k;index<numsSize;++index)
    {
        int currentTotal=(total-nums[index-k]) + nums[index];
        
        double currentAverage=(double)currentTotal/k;
        
        maxAverage=max(maxAverage, currentAverage);
        
        total=currentTotal;
    }
    
    return maxAverage;
}