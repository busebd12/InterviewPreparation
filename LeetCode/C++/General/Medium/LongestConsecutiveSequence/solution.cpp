#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(u) [where u is the number of unique numbers from nums]
*/

class Solution
{
    public:
        int longestConsecutive(vector<int> & nums)
        {
            int result=0;
            
            unordered_set<int> us(begin(nums), end(nums));
            
            for(int number : us)
            {
                //The main idea is to treat each number as the last number in an increasing sequence and simply iterate backwards
                //through the sequence as far as we can go until we find a number that is not in nums
                if(us.find(number - 1)==end(us))
                {
                    int count=0;
                    
                    int x=number;
                    
                    while(us.find(number)!=end(us))
                    {
                        count+=1;
                        
                        number+=1;
                    }
                    
                    result=max(result, count);
                }
            }
            
            return result;
        }
};