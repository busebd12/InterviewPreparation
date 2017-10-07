#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    if(nums1.empty() || nums2.empty())
    {
        return vector<int>();
    }
    
    unordered_set<int> us;
    
    vector<int> result;
    
    for(const auto & element : nums1)
    {
        if(us.find(element)==end(us))
        {
            us.insert(element);
        }
    }
    
    for(const auto & element : nums2)
    {
        if(us.find(element)!=end(us))
        {
            if(find(begin(result), end(result), element)==end(result))
            {
                result.emplace_back(element);
            }
        }
    }
    
    return result;
}