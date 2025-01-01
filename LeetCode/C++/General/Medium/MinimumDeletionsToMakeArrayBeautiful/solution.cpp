#include <deque>
using namespace std;

/*
Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int minDeletion(vector<int> & nums)
        {
            int result=0;

            int n=nums.size();

            deque<int> stack;

            for(int i=0;i<n;i+=1)
            {   
                if((stack.size() % 2)==0)
                {
                    stack.emplace_back(nums[i]);
                }
                else
                {
                    if(stack.back()==nums[i])
                    {
                        result+=1;
                    }
                    else
                    {
                        stack.emplace_back(nums[i]);
                    }
                }
            }

            if((stack.size() % 2)==1)
            {
                result+=1;
            }

            return result;
        }
};