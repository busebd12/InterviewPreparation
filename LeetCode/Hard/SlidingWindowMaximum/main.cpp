#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

/*
 * Solutions:
 *
 * 1. Brute force. Loop through all size k sliding windows and take the maximum number from each.
 *
 * Time complexity: O((n-k) * k) => O(nk-k^2) [where n is the length of the input vector and k is the sliding window size]
 * Space complexity: O(1)
 *
 * 2. For each index in the input vector, maintain a window of k indices starting from that index.
 * Take the maximum number from each of those sliding windows.
 *
 * Time complexity: O(n * k) [where n is the length of the input vector and k is the sliding window size]
 * Space complexity: O(k)
 *
 * 3. Maintain a monotonically increasing queue of possible maximum values for each sliding window.
 * The current maximum will always be at the front of the queue.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(n)
 */

std::vector<int> maxSlidingWindow(std::vector<int> & nums, int k)
{
    std::vector<int> result;

    if(nums.empty() || k <= 0)
    {
        return result;
    }

    auto n=int(nums.size());

    int sum=0;

    int back=0;

    int front=0;

    for(auto start=0;start<=n-k;++start)
    {
        int windowMaximum=std::numeric_limits<int>::min();

        for(auto current=start,count=0;count<k;++count,++current)
        {
            windowMaximum=std::max(windowMaximum, nums[current]);
        }

        result.emplace_back(windowMaximum);
    }

    return result;
}

std::vector<int> maxSlidingWindow(std::vector<int> & nums, int k)
{
    std::vector<int> result;

    if(nums.empty())
    {
        return result;
    }

    auto n=int(nums.size());

    std::deque<int> window;

    int back=0;

    int front=0;

    for(;front<k;++front)
    {
        if(result.empty())
        {
            result.emplace_back(nums[front]);
        }
        else
        {
            if(nums[front] > result.back())
            {
                result.pop_back();

                result.emplace_back(nums[front]);
            }
        }

        window.emplace_back(front);
    }

    while(front > k-1)
    {
        front--;
    }

    for(;front<n-1;)
    {
        int windowMax=std::numeric_limits<int>::min();

        if(!window.empty())
        {
            window.pop_front();
        }

        front++;

        window.emplace_back(front);

        for(auto & index : window)
        {
            windowMax=std::max(windowMax, nums[index]);
        }

        result.emplace_back(windowMax);
    }

    return result;
}

std::vector<int> maxSlidingWindow(std::vector<int> & nums, int k)
{
    std::vector<int> result;

    if(nums.empty())
    {
        return result;
    }

    auto n=int(nums.size());

    std::deque<int> monotonicallyIncreasingQueue;

    for(auto i=0;i<n;++i)
    {
        int slidingWindowStartIndex=i-(k-1);

        while(!monotonicallyIncreasingQueue.empty() && nums[monotonicallyIncreasingQueue.back()] <= nums[i])
        {
            monotonicallyIncreasingQueue.pop_back();
        }

        monotonicallyIncreasingQueue.emplace_back(i);

        if(monotonicallyIncreasingQueue.front() < slidingWindowStartIndex)
        {
            monotonicallyIncreasingQueue.pop_front();
        }

        if(i >= k-1)
        {
            result.emplace_back(nums[monotonicallyIncreasingQueue.front()]);
        }
    }

    return result;
}