#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of flips]
Space complexity: O(1)
*/

class Solution
{
    public:
        int numTimesAllBlue(vector<int> & flips)
        {
            int result=0;
            
            int n=flips.size();
            
            int minValue=-1;
            
            int maxValue=-1;
            
            //As we iterate through the flips vector, we will use minValue and maxValue to represent
            //the inclusive range of indices that have been flipped from zeros to ones [minValue, maxValue]
            for(int i=0;i<n;i++)
            {
                int flip=flips[i];
                
                if(minValue==-1 and maxValue==-1)
                {
                    minValue=flip;
                    
                    maxValue=flip;
                }
                else
                {
                    minValue=min(minValue, flip);
                    
                    maxValue=max(maxValue, flip);
                }
                
                //If the range [minValue, maxValue] equals [1, i], then we know that the bits in the range [1, i] are prefix-aligned
                if(minValue==1 and maxValue==i+1)
                {
                    result+=1;
                }
            }
            
            return result;
        }
};