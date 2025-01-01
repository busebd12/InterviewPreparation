#include <unordered_map>
#include <vector>
using namespace std;

/*
Time complexity: O(n + m)
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<int> arrayChange(vector<int> & nums, vector<vector<int>> & operations)
        {
            int n=nums.size();

            unordered_map<int, int> hashmap;

            for(int i=0;i<n;i++) //O(n)
            {
                int number=nums[i];

                hashmap.emplace(number, i);
            }

            for(vector<int> operation : operations) //O(m)
            {
                int old=operation[0];

                int replacement=operation[1];

                int index=hashmap[old];

                nums[index]=replacement;

                hashmap.erase(old);

                hashmap.emplace(replacement, index);
            }

            return nums;
        }
};