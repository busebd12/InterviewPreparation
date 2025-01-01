#include <deque>
#include <vector>
using namespace std;

/*
Solution 1:

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        int minimumOperations(vector<int> & nums)
        {
            int result=0;

            deque<long long> queue(nums.begin(), nums.end());

            while(queue.size() > 2)
            {
                if(queue.front() > queue.back())
                {
                    long long sum=queue[queue.size() - 1] + queue[queue.size() - 2];

                    if(sum==queue.front())
                    {
                        queue.pop_front();

                        queue.pop_back();

                        queue.pop_back();
                    }
                    else
                    {
                        queue.pop_back();

                        queue.pop_back();

                        queue.push_back(sum);
                    }

                    result+=1;
                }
                else if(queue.back() > queue.front())
                {   
                    long long sum=queue[0] + queue[1];

                    if(sum==queue.back())
                    {
                        queue.pop_front();

                        queue.pop_front();

                        queue.pop_back();
                    }
                    else
                    {
                        queue.pop_front();

                        queue.pop_front();

                        queue.push_front(sum);
                    }

                    result+=1;
                }
                else
                {   
                    queue.pop_front();

                    queue.pop_back();
                }
            }

            if(queue.size()==2 and queue[0]!=queue[1])
            {
                result+=1;
            }

            return result;
        }
};

/*
Solution 2:

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(n)
*/

class Solution
{
    public:
        int minimumOperations(vector<int> & nums)
        {
            int result=0;

            deque<long long> queue(nums.begin(), nums.end());

            while(queue.size() > 1)
            {
                int front=queue.front();

                int back=queue.back();

                if(front > back)
                {
                    queue.pop_back();

                    queue.back()+=back;

                    result+=1;
                }
                else if(back > front)
                {
                    queue.pop_front();

                    queue.front()+=front;

                    result+=1;
                }
                else
                {
                    queue.pop_front();

                    queue.pop_back();
                }
            }

            return result;
        }
};

/*
Solution 3:

Time complexity: O(n) [where n is the length of nums]
Space complexity: O(1)
*/

class Solution
{
    public:
        int minimumOperations(vector<int> & nums)
        {
            int result=0;

            int n=nums.size();

            int low=0;

            int high=n - 1;

            long long left=nums[low];

            long long right=nums[high];

            while(low < high)
            {
                if(left < right)
                {
                    low+=1;

                    left+=nums[low];

                    result+=1;
                }
                else if(right < left)
                {
                    high-=1;

                    right+=nums[high];

                    result+=1;
                }
                else
                {
                    low+=1;

                    left=nums[low];

                    high-=1;

                    right=nums[high];
                }
            }
            
            return result;
        }
};