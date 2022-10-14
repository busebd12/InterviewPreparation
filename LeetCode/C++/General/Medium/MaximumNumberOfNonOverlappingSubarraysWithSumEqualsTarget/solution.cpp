#include <unordered_map>
#include <vector>
using namespace std;


class Solution
{
    private:
        unordered_map<int, int> hashtable;
    
    public:
        int maxNonOverlapping(vector<int> & nums, int target)
        {
            int result=0;
            
            int n=nums.size();
            
            int prefixSum=0;
            
            for(int i=0;i<n;i++)
            {
                //Calculate the running prefix sum as we go
                prefixSum+=nums[i];
                
                //If we found a subarray ending at index i that has sum equal to the target
                if(prefixSum==target)
                {
                    result+=1;
                    
                    //Clear the hashtable since we don't want any other subarray overlapping with this one
                    hashtable.clear();
                    
                    //Clear prefixSum since we don't want any other subarray overlapping with this one
                    prefixSum=0;
                }
                //Else if there is another subarray in the array that has sum equal to prefixSum - target, then we know that there is a subarray
                //starting from the index after this subarray and extending to the current index that has sum equal to target
                else if(hashtable.find(prefixSum - target)!=end(hashtable))
                {
                    result+=1;
                    
                    //Clear the hashtable since we don't want any other subarray overlapping with this one
                    hashtable.clear();
                    
                    //Clear prefixSum since we don't want any other subarray overlapping with this one
                    prefixSum=0;
                }
                //Else, just increment the frequency of the prefixSum in the hashtable, so we can reference it later
                else
                {
                    hashtable[prefixSum]+=1;
                }
            }
            
            return result;
        }
};