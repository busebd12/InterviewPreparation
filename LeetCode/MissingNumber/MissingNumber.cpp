#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> & nums)
{
    int limit=nums.size();
    
    int sum=0;
    
    int missingNumberSum=0;
    
    for(int number=0;number<=limit;++number)
    {
        sum+=number;
    }
    
    for(int index=0;index<limit;++index)
    {
        missingNumberSum+=nums[index];
    }
    
    return sum-missingNumberSum;
}