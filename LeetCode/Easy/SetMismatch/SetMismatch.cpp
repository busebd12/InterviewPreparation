#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findErrorNums(vector<int>& nums)
{
    vector<int> result;
    
    if(nums.empty())
    {
        return result;
    }
    
    const size_t numsSize=nums.size();
    
    unordered_map<int, int> table;
    
    for(int index=0;index<numsSize;++index)
    {
        int number=nums[index];
        
        table[number]++;
    }
    
    int missingNumber=-1;
    
    for(int integer=1;integer<=numsSize;++integer)
    {
        if(table.find(integer)!=end(table))
        {
            table[integer]--;
        }
        else
        {
            missingNumber=integer;
        }
    }
    
    int repeatedNumber=-1;
    
    for(const auto & element : table)
    {
        if(element.second==1)
        {
            repeatedNumber=element.first;
        }
    }
    
    result.emplace_back(repeatedNumber);
    
    result.emplace_back(missingNumber);
    
    return result;
}