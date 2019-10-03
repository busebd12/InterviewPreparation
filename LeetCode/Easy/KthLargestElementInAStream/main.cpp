#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;

/*
 * Approaches:
 *
 * 1) Using a multiset. Add we add numbers, whenever the size of our multiset reaches K (or larger)
 * just return the Kth element.
 *
 * Time complexity: O(n log n) [where n is the number of elements in our stream]
 * Space complexity: O(n)
 *
 *
 * 2) Also, using a multiset. However, instead of returning the kth largest element as the stream goes along,
 * we fill the multiset with the entire stream and then remove elements until we only have k numbers left in the stream.
 * Then, we just maintain a stream size of k elements and return kth element whenever we need to.
 *
 * Time complexity: O(n log n) [where n is the number of elements in our stream]
 * Space complexity: O(n)
 *
 * 3) Using a max heap (priority_queue) to maintain a stream size of k elements and return the kth largest
 * number when we need to.
 *
 * Time complexity: O(n log n) [where n is the number of total elements in our stream]
 * Space complexity: O(log(k))
 *
 * 4) Use a min heap (priority_queue<int>) instead of a max heap to maintain our stream size of k elements and return the kth largest
 * element when we need to.
 *
 * Time complexity: O(n log n) [where n is the total number of elements in our stream]
 * Space complexity: O(log(k))
 *
 * 5) Same idea as solution number four but with a vector<int> in combination with the make_heap function
 * instead of a priority_queue.
 *
 * Time complexity: O(n log n) [where n is the total number of numbers in our stream]
 * Space complexity: O(log(k))
 *
 *
 */

class KthLargest
{
    public:
        multiset<int> stream;

        int K;

        KthLargest(int k, vector<int>& nums)
        {
            K=k;

            for(const int & number : nums)
            {
                stream.insert(number);
            }
        }

        int add(int val)
        {
            stream.insert(val);

            auto itr=stream.end();

            int result=-1;

            if(stream.size() >= K)
            {
                auto kthLargest=prev(itr, K);

                result=*kthLargest;
            }

            return result;
        }
};

class KthLargest
{
    public:
        multiset<int> stream;

        int K;

        KthLargest(int k, vector<int>& nums)
        {
            K=k;

            for(const int & number : nums)
            {
                stream.insert(number);
            }

            while(stream.size() > k)
            {
                auto itr=stream.begin();

                stream.erase(itr);
            }
        }

        int add(int val)
        {
            if(val > *(stream.begin()))
            {
                auto firstElement=stream.begin();

                stream.erase(firstElement);
            }

            stream.insert(val);

            auto itr=stream.end();

            int result=-1;

            if(stream.size() >= K)
            {
                auto kthLargest=prev(itr, K);

                result=*kthLargest;
            }

            return result;
        }
};


class KthLargest
{
    public:
        priority_queue<int> stream;

        queue<int> extra;

        int kthLargest;

        int K;

        KthLargest(int k, vector<int> & nums)
        {
            if(!nums.empty())
            {
                sort(nums.begin(), nums.end());

                int n=int(nums.size());

                if(n < k)
                {
                    for(const int & number : nums)
                    {
                        stream.push(number);
                    }
                }
                else
                {
                    for(int i=n-1,j=k-1;j>=0;--i,--j)
                    {
                        stream.push(nums[i]);
                    }

                    if(!stream.empty())
                    {
                        while(stream.size() > 1)
                        {
                            int current=stream.top();

                            extra.push(current);

                            stream.pop();
                        }

                        kthLargest=stream.top();

                        while(!extra.empty())
                        {
                            int value=extra.front();

                            extra.pop();

                            stream.push(value);
                        }
                    }
                }
            }

            K=k;
        }

        int add(int val)
        {
            if(stream.empty())
            {
                stream.push(val);

                kthLargest=val;
            }
            else
            {
                if(stream.size() < K)
                {
                    stream.push(val);

                    while(stream.size() > 1)
                    {
                        int current=stream.top();

                        stream.pop();

                        extra.push(current);
                    }

                    kthLargest=stream.top();

                    while(!extra.empty())
                    {
                        stream.push(extra.front());

                        extra.pop();
                    }
                }
                else if(stream.size()==K)
                {
                    if(val > kthLargest)
                    {
                        while(stream.size() > 1)
                        {
                            int current=stream.top();

                            stream.pop();

                            extra.push(current);
                        }

                        stream.pop();

                        stream.push(val);

                        while(!extra.empty())
                        {
                            stream.push(extra.front());

                            extra.pop();
                        }

                        while(stream.size() > 1)
                        {
                            int current=stream.top();

                            stream.pop();

                            extra.push(current);
                        }

                        kthLargest=stream.top();

                        while(!extra.empty())
                        {
                            stream.push(extra.front());

                            extra.pop();
                        }
                    }
                }
            }

            return kthLargest;
        }
};

class KthLargest
{
    public:
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int streamSize;

        KthLargest(int k, vector<int> nums)
        {
            streamSize=k;

            int n=int(nums.size());

            for(int i=0;i<n;i++)
            {
                minHeap.push(nums[i]);

                if(minHeap.size() > k)
                {
                    minHeap.pop();
                }
            }
        }

        int add(int val)
        {
            minHeap.push(val);

            if(minHeap.size() > streamSize)
            {
                minHeap.pop();
            }

            return minHeap.top();
        }
};

class KthLargest
{
    public:
        vector<int> minHeap;

        int streamSize;

        KthLargest(int k, vector<int> & nums) : minHeap(nums), streamSize(k)
        {
            make_heap(minHeap.begin(), minHeap.end(), greater<int>());

            while(minHeap.size() > k)
            {
                pop_heap(minHeap.begin(), minHeap.end(), greater<int>());

                minHeap.pop_back();
            }
        }

        int add(int val)
        {
            minHeap.push_back(val);

            push_heap(minHeap.begin(), minHeap.end(), greater<int>());

            if(minHeap.size() > streamSize)
            {
                pop_heap(minHeap.begin(), minHeap.end(), greater<int>());

                minHeap.pop_back();
            }

            return minHeap[0];
        }
};