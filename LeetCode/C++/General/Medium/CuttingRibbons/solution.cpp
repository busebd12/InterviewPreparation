#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n + n * log(r)) [where n is the length of ribbons and r is the range of 1 to the max ribbon length]
Space complexity: O(1)
*/

class Solution
{
    public:
        bool canCut(vector<int> & ribbons, int k, int length)
        {
            //Keep track of the total number of pieces that can be formed when we divided each ribbon by the length
            int pieces=0;
            
            //Calculate the total number of pieces
            for(auto & ribbon : ribbons)
            {
                pieces+=(ribbon / length);
            }
            
            //If the total number of pieces is at least k, then this length allows to obtain the k desired ribbons
            return pieces >= k;
        }
    
        int maxLength(vector<int> & ribbons, int k)
        {
            int result=0;
            
            //Find the ribbon with maximum length
            //This ribbon length will serve as the upper bound for our binary search
            int maxLength=*max_element(begin(ribbons), end(ribbons));
            
            //Lower bound for our binary search
            int low=1;
            
            //Upper bound for our binary search
            int high=maxLength;
            
            //Do the binary search
            while(low <= high)
            {
                int length=(low + (high - low)/2);
                
                //If we can cut the ribbons such that we form k ribbons with length "length"
                if(canCut(ribbons, k, length))
                {
                    result=length;
                    
                    //If we can form the desired k ribbons, let's check if we can form the desired k ribbons with a longer length
                    low=length + 1;
                }
                else
                {
                    //We can't form the desired k ribbons using this length, so let's try a smaller length
                    high=length - 1;
                }
            }
            
            return result;
        }
};