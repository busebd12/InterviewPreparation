#include <deque>
#include <vector>
using namespace std;

/*
Solution 1: brute force. Note, this solution gets Time Limit Exceeded when run.

Time complexity: O(n^2) [where n is the length of heights]
Space complexity: O(1)
*/

class Solution
{
    public:
        vector<int> findBuildings(vector<int> & heights)
        {
            vector<int> result;
            
            int n=heights.size();
            
            //Iterate through all buildings
            for(int i=0;i<n;i++)
            {
                int height=heights[i];
                
                bool flag=true;
                
                //Check all buildings to the right of each building
                for(int j=i+1;j<n;j++)
                {
                    //If a building to the right is taller, then the current building can't have an ocean view
                    if(height <= heights[j])
                    {
                        flag=false;
                        
                        break;
                    }
                }
                
                //If all the buildings to the right of the current one are shorter
                if(flag)
                {
                    result.emplace_back(i);
                }
            }
            
            return result;
        }
};

/*
Solution 2: monotonic increasing stack

Time complexity: O(n)
Space complexity: O(n)

*/

class Solution
{
    public:
        vector<int> findBuildings(vector<int> & heights)
        {
            vector<int> result;
            
            int n=heights.size();
            
            deque<int> stack;
            
            //Iterate through the buildings
            for(int i=0;i<n;i++)
            {
                //While the stack is not empty and the height of the building on the top of the stack is the same or shorter than the current building
                while(!stack.empty() && heights[stack.back()] <= heights[i])
                {
                    //Pop from the stack
                    stack.pop_back();
                }
                
                //Add the current index to the stack
                stack.emplace_back(i);
            }
            
            //Create the result vector from the indices left on the stack
            for(const auto & index : stack)
            {
                result.emplace_back(index);
            }
            
            return result;
        }
};