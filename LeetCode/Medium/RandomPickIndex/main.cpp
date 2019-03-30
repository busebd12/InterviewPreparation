#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
    private:
        unordered_map<int, vector<int>> map;

    public:
        Solution(vector<int> nums)
        {
            for(int i=0;i<nums.size();++i)
            {
                map[nums[i]].push_back(i);
            }
        }

        int pick(int target)
        {
            vector<int> v=map[target];

            int index=rand() % v.size();

            return v[index];
        }
};























