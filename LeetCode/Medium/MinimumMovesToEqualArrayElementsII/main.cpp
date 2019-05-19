#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

int minMoves2BruteForce(vector<int> & nums)
{
    int minMoves=0;

    if(nums.empty())
    {
        return minMoves;
    }

    unordered_map<int, int> cache;

    int n=int(nums.size());

    for(int i=0;i<n;++i)
    {
        int target=nums[i];

        int total=0;

        for(int j=0;j<n;++j)
        {
            if(i!=j)
            {
                total+=abs(target-nums[j]);
            }
        }

        cache.insert(make_pair(total, target));
    }

    auto itr=*(min_element(cache.begin(), cache.end(), [] (auto & x, auto & y) {return x.first < y.first;}));

    minMoves=itr.first;

    return minMoves;
}

int minMoves2(vector<int> & nums)
{
    sort(nums.begin(), nums.end());

    int i=0;

    int j=int(nums.size()-1);

    int count=0;

    while(i < j)
    {
        count+=(nums[j]-nums[i]);

        i++;

        j++;
    }

    return count;
}