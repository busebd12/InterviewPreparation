#include <deque>
using namespace std;

/*
Solution 1: Brute-force bread-first search. Note, this solution gets Time Limit Exceeded when run.

Time complexity: O(2^n)
Space complexity: O(2^n)
*/

class Solution
{
    public:
        int brokenCalc(int startValue, int target)
        {
            int result=0;
            
            deque<long> queue;
            
            queue.emplace_back(static_cast<long>(startValue));
            
            bool done=false;
            
            //Perform breadth-first search
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto current=queue.front();
                
                    queue.pop_front();
                
                    //We've reached the target
                    if(current==target)
                    {
                        done=true;
                        
                        break;
                    }
                    
                    //Double the current value
                    long doubled=current * 2;
                    
                    //Decrement the current value
                    long decremented=current - 1;
                    
                    //Add both options to the queue
                    queue.emplace_back(doubled);
                        
                    queue.emplace_back(decremented);
                }
                
                if(done)
                {
                    break;
                }
                
                result++;
            }
            
            return result;
        }
};

/*
Solution 2: inspired by this post --> https://leetcode.com/problems/broken-calculator/discuss/1874839/C%2B%2B-oror-2-Approaches-oror-Easy-oror-Simple-and-Short-oror-Algorithm
*/

class Solution
{
    public:
        int brokenCalc(int startValue, int target)
        {
            int result=0;
            
            while(target > startValue)
            {
                if((target%2)==0)
                {
                    target/=2;
                }
                else
                {
                    target+=1;
                }
                
                result++;
            }
            
            //At this point, target is less than start value, but we may not have reached the point where startVaue is equal to target
            //So, to account for the missing operations need to make startValue equal to target, add the difference between the two to the result
            result+=(startValue - target);
            
            return result;
        }
};