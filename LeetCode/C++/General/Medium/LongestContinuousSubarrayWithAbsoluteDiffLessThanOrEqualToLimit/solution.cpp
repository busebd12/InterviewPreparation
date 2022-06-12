#include <numeric>
#include <set>
#include <vector>
using namespace std;

/*
Time complexity: O(n log n) [where n is the length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        int longestSubarray(vector<int> & nums, int limit)
        {
            int result=0;
            
            int n=nums.size();
            
            multiset<int> window;
            
            int left=0;
            
            int right=0;
            
            int maxValue=-1;
            
            int minValue=-1;
            
            while(right < n)
            {
                window.insert(nums[right]);
                
                minValue=*(begin(window));
                
                maxValue=*(rbegin(window));
                
                if(abs(maxValue - minValue) <= limit)
                {
                    result=max(result, int(window.size()));
                    
                    right+=1;
                }
                else
                {
                    while(left < right && abs(maxValue - minValue) > limit)
                    {
                        window.erase(window.find(nums[left]));
                        
                        left+=1;
                        
                        minValue=*(begin(window));
                        
                        maxValue=*(rbegin(window));
                    }
                    
                    right+=1;
                }
            }
            
            return result;
        }
};