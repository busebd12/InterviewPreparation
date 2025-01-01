#include <algorithm>
#include <vecotr>

/*
Solution: brute-force.

Time complexity: O(n^2) [where n is the length of nums]
Space complexity: O(1)
*/

class Solution
{
    public:
        int minOperations(vector<int> & nums)
        {
            int result=0;

            int n=nums.size();

            bool allZeros=all_of(nums.begin(), nums.end(), [] (int & number) {return number==0;});

            while(allZeros==false)
            {
                bool allEven=all_of(nums.begin(), nums.end(), [] (int & number) {return (number % 2)==0;});

                int operations=0;
                
                if(allEven==true)
                {
                    operations=divideByTwo(nums, n);
                }
                else
                {
                    operations=decrement(nums, n);
                }

                result+=operations;

                allZeros=all_of(nums.begin(), nums.end(), [] (int & number) {return number==0;});
            }

            return result;
        }

        int decrement(vector<int> & nums, int n)
        {
            int operations=0;

            for(int i=0;i<n;i++)
            {
                if((nums[i] % 2)==1)
                {
                    nums[i]-=1;

                    operations+=1;
                }
            }

            return operations;
        }

        int divideByTwo(vector<int> & nums, int n)
        {
            int operations=0;

            for(int i=0;i<n;i++)
            {
                nums[i]=nums[i] / 2;
            }

            return operations + 1;
        }
};