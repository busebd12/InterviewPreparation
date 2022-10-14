#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of nums]
Space complexity: O(u) [where u is the number of unique elements in nums]
*/

class Solution
{
    public:
        vector<int> majorityElement(vector<int> & nums)
        {
            vector<int> result;
            
            int n=nums.size();
            
            int targetFrequency=floor(n / 3);
            
            unordered_map<int, int> frequencies;
            
            for(int number : nums)
            {
                frequencies[number]+=1;
            }
            
            for(auto & [number, frequency] : frequencies)
            {
                if(frequency > targetFrequency)
                {
                    result.push_back(number);
                }
            }
            
            return result;
        }
};