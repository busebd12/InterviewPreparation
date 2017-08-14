#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
    if(nums1.empty() || nums2.empty())
    {
        return vector<int>();
    }

    vector<int> result;

    unordered_map<int, int> nums1Map;

    unordered_map<int, int> nums2Map;

    for(const auto & element : nums1)
    {
        nums1Map[element]++;
    }

    for(const auto & element : nums2)
    {
        nums2Map[element]++;
    }

    for(const auto & element : nums1Map)
    {
        int value=element.first;

        if(nums2Map.find(value)!=end(nums2Map))
        {
            int nums1Appearances=nums1Map[value];

            int nums2Appearances=nums2Map[value];

            if(nums1Appearances==nums2Appearances)
            {
                for(int count=0;count<nums1Appearances;++count)
                {
                    result.emplace_back(value);
                }
            }
            else
            {
                int appearances=min(nums1Appearances, nums2Appearances);

                for(int count=0;count<appearances;++count)
                {
                    result.emplace_back(value);
                }
            }
        }
    }

    return result;
}