#include <iostream>
#include <utility>
#include <map>
#include <vector>
using namespace std;

vector<pair<int, int>> kSmallestPairs(vector<int> & nums1, vector<int> & nums2, int k)
{
    vector<pair<int, int>> result;

    if(nums1.empty() || nums2.empty() || k==0)
    {
        return result;
    }

    multimap<int, pair<int, int>> sumToPair;

    for(auto & x : nums1)
    {
        for(auto & y : nums2)
        {
            int sum=x + y;

            auto p=make_pair(x, y);

            sumToPair.insert(make_pair(sum, p));
        }
    }

    int count=k;

    for(auto & element : sumToPair)
    {
        if(count==0)
        {
            break;
        }

        result.emplace_back(element.second);

        --count;
    }

    return result;
}