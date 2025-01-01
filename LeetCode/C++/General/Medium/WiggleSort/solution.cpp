#include <algorithm>
#include <deque>
#include <set>
#include <vector>
using namespace std;

class Solution
{
    public:
        void wiggleSort(vector<int> & nums)
        {
            multiset<int> sorted;

            while(!nums.empty())
            {
                sorted.insert(nums.back());

                nums.pop_back();
            }

            while(sorted.size() >= 2)
            {
                int minValue=*(sorted.begin());

                sorted.erase(sorted.begin());

                int maxValue=*(prev(sorted.end()));

                sorted.erase(prev(sorted.end()));

                nums.push_back(minValue);

                nums.push_back(maxValue);
            }

            if(!sorted.empty())
            {
                nums.push_back(*(sorted.begin()));
            }
        }
};

class Solution
{
    public:
        void wiggleSort(vector<int> & nums)
        {
            deque<int> queue;

            while(!nums.empty())
            {
                queue.push_back(nums.back());

                nums.pop_back();
            }

            sort(queue.begin(), queue.end());

            while(queue.size() >= 2)
            {
                int minValue=queue.front();

                queue.pop_front();

                int maxValue=queue.back();

                queue.pop_back();

                nums.push_back(minValue);

                nums.push_back(maxValue);
            }

            if(!queue.empty())
            {
                nums.push_back(queue.front());
            }
        }
};

class Solution
{
    public:
        void wiggleSort(vector<int> & nums)
        {
            int n=nums.size();

            for(int i=0;i<n;i++)
            {
                if((i % 2)==0)
                {
                    if(i-1 >= 0 and nums[i] > nums[i - 1])
                    {
                        swap(nums[i], nums[i - 1]);
                    }
                }
                else
                {
                    if(nums[i] < nums[i - 1])
                    {
                        swap(nums[i], nums[i - 1]);
                    }
                }
            }
        }
};