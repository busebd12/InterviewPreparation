#include <string>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of colors]
Space complexity: O(n)
*/

class Solution
{
    public:
        int minCost(string colors, vector<int> & neededTime)
        {
            int result=0;
            
            int n=colors.size();
            
            vector<int> indices;
            
            for(int i=0;i<n;i++)
            {
                if(indices.empty())
                {
                    indices.push_back(i);
                }
                else
                {
                    if(colors[indices.back()]==colors[i])
                    {
                        if(neededTime[indices.back()] < neededTime[i])
                        {
                            result+=neededTime[indices.back()];
                            
                            indices.pop_back();
                            
                            indices.push_back(i);
                        }
                        else if(neededTime[i] <= neededTime[indices.back()])
                        {   
                            result+=neededTime[i];
                        }
                    }
                    else
                    {   
                        indices.push_back(i);
                    }
                }
            }
            
            return result;
        }
};