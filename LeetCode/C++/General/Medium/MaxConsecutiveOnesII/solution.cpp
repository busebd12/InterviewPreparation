#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
    public:
        int findMaxConsecutiveOnes(vector<int> & nums)
        {
            int result=0;

            int n=nums.size();

            int zeros=count(nums.begin(), nums.end(), 0);

            if(zeros==0)
            {
                result=n;

                return result;
            }

            if(zeros==n)
            {
                result=1;

                return result;
            }

            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    int onesToTheLeft=countOnesToTheLeft(nums, n, i);

                    int onesToTheRight=countOnesToTheRight(nums, n, i);

                    int totalOnes=onesToTheLeft + onesToTheRight + 1;

                    result=max(result, totalOnes);
                }
            }

            return result;
        }

        int countOnesToTheLeft(vector<int> & nums, int n, int i)
        {
            int ones=0;

            for(int index=i-1;index>=0;index--)
            {
                if(nums[index]==1)
                {
                    ones+=1;
                }
                else
                {
                    break;
                }
            }

            return ones;
        }

        int countOnesToTheRight(vector<int> & nums, int n, int i)
        {
            int ones=0;

            for(int index=i+1;index<n;index++)
            {
                if(nums[index]==1)
                {
                    ones+=1;
                }
                else
                {
                    break;
                }
            }

            return ones;
        }
};

class Solution
{
    public:
        int findMaxConsecutiveOnes(vector<int> & nums)
        {
            int result=0;

            int n=nums.size();

            int zeros=count(nums.begin(), nums.end(), 0);

            if(zeros==0)
            {
                result=n;

                return result;
            }

            if(zeros==n)
            {
                result=1;

                return result;
            }

            vector<int> onesToTheLeft(n, 0);

            int ones=0;

            for(int i=0;i<n;i++)
            {
                if(nums[i]==1)
                {
                    ones+=1;
                }
                else
                {
                    onesToTheLeft[i]=ones;
                    
                    ones=0;
                }
            }

            ones=0;

            vector<int> onesToTheRight(n, 0);

            for(int i=n-1;i>=0;i--)
            {
                if(nums[i]==1)
                {
                    ones+=1;
                }
                else
                {
                    onesToTheRight[i]=ones;
                    
                    ones=0;
                }
            }

            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    int totalOnes=onesToTheLeft[i] + onesToTheRight[i] + 1;

                    result=max(result, totalOnes);
                }
            }

            return result;
        }
};