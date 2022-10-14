#include <set>
using namespace std;

/*
Time complexity: O(n * log(k))
Space complexity: O(k)
*/

class Solution
{
    public:
        bool containsNearbyAlmostDuplicate(vector<int> & nums, int k, int t)
        {
            int n=nums.size();
            
            if(k < 1)
            {
                return false;
            }
            
            multiset<long long> window;
            
            for(int i=0;i<n;i++)
            {
                long long maxValue=static_cast<long long>(nums[i]) + t;
                
                long long minValue=static_cast<long long>(nums[i]) - t;
                
                //Check if the window contains a number in the range nums[i] - t to nums[i] + t
                //See this post: https://stackoverflow.com/questions/8997232/how-to-check-whether-a-set-has-elements-in-certain-range-in-c
                if(window.lower_bound(minValue)!=window.upper_bound(maxValue))
                {
                    return true;
                }
                
                //Insert the current number into the sliding window (window slides to the right)
                window.insert(nums[i]);
                
                //If the window size exceeds k, then we want to remove the first element in the window to ensure that all indices are within distance k of each other
                //Removing this number slides the window to the right
                if(window.size() > k)
                {
                    window.erase(window.find(nums[i - k]));
                }
            }
            
            return false;
        }
};