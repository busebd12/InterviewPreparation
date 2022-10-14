/*
Solution: inspired by this post --> https://leetcode.com/problems/elimination-game/solutions/355060/c-simple-explanation-with-pictures/

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
        int lastRemaining(int n)
        {
            int result=0;

            int head=1;

            int distanceBetweenValues=1;

            bool leftToRight=true;

            while(n > 1)
            {
                if(leftToRight==true)
                {
                    head+=distanceBetweenValues;
                }
                else
                {
                    if((n % 2)==1)
                    {
                        head+=distanceBetweenValues;
                    }
                }

                distanceBetweenValues*=2;

                n=n / 2;

                leftToRight=!leftToRight;
            }

            result=head;

            return result;
        }
};