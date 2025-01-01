#include <algorithm>
#include <vector>
using namespace std;

/*
Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
    public:
        int minimumSwaps(vector<int> & nums)
        {
            int result=0;

            int n=nums.size();

            int minValue=*(min_element(nums.begin(), nums.end()));

            int maxValue=*(max_element(nums.begin(), nums.end()));

            if(nums[0]==minValue and nums[n - 1]==maxValue)
            {
                return result;
            }

            int maxValueIndex=-1;

            for(int i=n-1;i>=0;i--)
            {
                if(nums[i]==maxValue)
                {
                    maxValueIndex=i;

                    break;
                }
            }

            for(int i=maxValueIndex;i<n;i++)
            {
                if(i + 1 < n)
                {
                    swap(nums[i], nums[i + 1]);

                    result+=1;
                }
            }

            int minValueIndex=-1;

            for(int i=0;i<n;i++)
            {
                if(nums[i]==minValue)
                {
                    minValueIndex=i;

                    break;
                }
            }

            for(int i=minValueIndex;i>=0;i--)
            {
                if(i - 1 >= 0)
                {
                    swap(nums[i], nums[i - 1]);

                    result+=1;
                }
            }

            return result;
        }
};