#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n=length of target]
Space complexity: O(1)
*/

class Solution
{
    public:
        int minNumberOperations(vector<int> & target)
        {
            int result=0;

            int n=target.size();

            //We need to jump target[0] units in height to move from the ground (height=0) to reach the top of the platform which has height target[0]
            result=target[0];

            //Iterate through target
            for(int i=0;i+1<n;i++)
            {
                //Calculate the amount we need to "jump" (like we are jumping from one platform to another) to get from target[i] to target[i + 1]
                int jump=target[i] - target[i + 1];

                //If the jump value is negative, that means the platform at target[i + 1] is at a higher position than the platform at target[i],
                //and we need to decrease the height of target[i - 1] by jump units
                if(jump < 0)
                {
                    //Make jump positive
                    jump*=-1;
                    
                    //Increment the result by jump
                    result+=jump;
                }
            }

            return result;
        }
};