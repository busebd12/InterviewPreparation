#include <unordered_set>
#include <vector>
using namespace std;

/*
Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int maximumUniqueSubarray(vector<int> & nums)
        {
            int result=0;
            
            int n=nums.size();
            
            //Sliding window
            unordered_set<int> window;
            
            int back=0;
            
            int front=0;
            
            int sum=0;
            
            while(front < n)
            {
                //If the window does not contain nums[front]
                if(window.find(nums[front])==end(window))
                {
                    //Add nums[front] to the window
                    window.insert(nums[front]);
                    
                    //Add nums[front] to the sum
                    sum+=nums[front];
                    
                    //Update the result
                    result=max(result, sum);
                    
                    //Move the front of the window up by one
                    front+=1;
                }
                //Else, the window contains nums[front]
                else
                {
                    //Remove nums[back] from the window
                    window.erase(nums[back]);
                    
                    //Decrease the sum by nums[back]
                    sum-=nums[back];
                    
                    //Move the back of the window up by one
                    back+=1;
                }
            }
            
            return result;
        }
};