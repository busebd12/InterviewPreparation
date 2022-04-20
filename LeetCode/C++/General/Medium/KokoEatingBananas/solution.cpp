#include <algorithm>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/koko-eating-bananas/discuss/1703687/JavaC%2B%2B-A-very-very-well-detailed-explanation

Time complexity: O(p * log(m)) [where p is the number of piles and m is the range of k]
Space complexity: O(1)
*/

class Solution
{
    public:
        bool canEat(vector<int> & piles, int h, int k)
        {
            int p=piles.size();
            
            int hours=0;
            
            for(int index=0;index<p;index++)
            {
                int dividend=piles[index] / k;
                
                hours+=dividend;
                
                if((piles[index] % k)!=0)
                {
                    hours+=1;
                }
            }
            
            return hours <= h;
        }
    
        int minEatingSpeed(vector<int> & piles, int h)
        {
            int result=0;
            
            int largestPile=*(max_element(begin(piles), end(piles)));
            
            int left=1;
            
            int right=largestPile;
            
            while(left <= right)
            {
                int k=(left + (right - left)/2);
                
                if(canEat(piles, h, k))
                {   
                    result=k;
                    
                    right=k - 1;
                }
                else
                {
                    left=k + 1;
                }
            }
            
            return result;
        }
};