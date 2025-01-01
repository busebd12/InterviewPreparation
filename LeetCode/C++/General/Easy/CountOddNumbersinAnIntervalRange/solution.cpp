/*
Time complexity: O(1)
Space complexity: O(1)
*/

class Solution
{
    public:
        int countOdds(int low, int high)
        {
            int result=0;

            int length=(high - low) + 1;

            if((length % 2)==0)
            {
                result=(length / 2);
            }
            else
            {
                if((low % 2)==1)
                {
                    result=(length / 2) + 1;
                }
                else
                {
                    result=(length / 2);
                }
            }

            return result;
        }
};