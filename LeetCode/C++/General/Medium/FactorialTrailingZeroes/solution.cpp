/*
Solution: inspired by this post --> https://leetcode.com/problems/factorial-trailing-zeroes/solutions/1151659/c-from-worst-to-best-all-solutions-with-expalanation-comments/

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
        int trailingZeroes(int n)
        {
            int result=0;

            for(int number=1;number<=n;number++)
            {
                bool multipleOf5=((number % 5)==0);

                if(multipleOf5==true)
                {
                    int powerOf5=number;

                    while((powerOf5 % 5)==0)
                    {
                        powerOf5/=5;

                        result+=1;
                    }
                }
            }

            return result;
        }
};