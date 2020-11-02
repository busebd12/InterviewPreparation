#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <unordered_map>
#include <vector>

/*
 * Solutions:
 *
 * 1. We use a hashtable to map each number in nums to its frequency.
 * Then, we use a minimum heap, along with a custom comparator, to keep the only top K elements
 * in our minimum heap at any given time. Finally, after iterating through all the unique numbers
 * in our hashtable, we place the top k numbers in our result vector at the correct indices.
 *
 * Time complexity: O(n + d * log(k) + k) [where n is the length of nums and d is the number of distinct numbers in nums]
 * Space complexity: O(d + log(k)) [where d is number of distinct numbers in nums]
 *
 * 2. We use a hashtable to map each number in nums to its frequency.
 * Next, we store each number and its frequency as a pair in a maximum heap (sorted using a custom comparator).
 * Then, we simply put the top K numbers from our heap into the correct position in our result vector.
 *
 * Time complexity: O(n + d * log(k) + k) [where n is the length of nums and d is the number of distinct numbers in nums]
 * Space complexity: O(d + log(d)) [where d is number of distinct numbers in nums]
 *
 * 3. We use a hashtable to map each number in nums to its frequency. Next, we place each number and its frequency,
 * as a pair, into a vector of pairs. Then, we use the std::partial_sort algorithm along with a custom comparator
 * to place the top K elements in the first K spots of the vector. Then, we simply take the first K numbers and place
 * them at the correct indices in the result vector.
 *
 * Time complexity: O(n + n * log(k)) [where n is the length of the nums vector]
 * Space complexity: O(d) [where d is the number of distinct elements in nums]
 */

std::vector<int> topKFrequent(std::vector<int> & nums, int k)
{
    std::vector<int> result;

    if(nums.empty() || k <= 0)
    {
        return result;
    }

    std::unordered_map<int, int> hashtable;

    for(const auto & number : nums)
    {
        hashtable[number]++;
    }

    auto comparator=[] (const auto & e1, const auto & e2) -> bool {return e1.second >= e2.second;};

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comparator)> minHeap(comparator);

    for(const auto & [key, value] : hashtable)
    {
        minHeap.emplace(std::make_pair(key, value));

        if(minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    result.resize(k);

    for(auto index=k-1;index>=0;--index)
    {
        result[index]=minHeap.top().first;

        minHeap.pop();
    }

    return result;
}

std::vector<int> topKFrequent(std::vector<int> & nums, int k)
{
    std::vector<int> result;

    if(nums.empty() || k <= 0)
    {
        return result;
    }

    std::unordered_map<int, int> hashtable;

    for(const auto & number : nums)
    {
        hashtable[number]++;
    }

    auto comparator=[] (const auto & e1, const auto & e2) -> bool {return e1.second <= e2.second;};

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comparator)> maxHeap(comparator);

    for(const auto & [key, value] : hashtable)
    {
        maxHeap.emplace(std::make_pair(key, value));
    }

    result.resize(k);

    for(auto index=0;index<k;++index)
    {
        result[index]=maxHeap.top().first;

        maxHeap.pop();
    }

    return result;
}

std::vector<int> topKFrequent(std::vector<int> & nums, int k)
{
    std::vector<int> result;

    if(nums.empty() || k <= 0)
    {
        return result;
    }

    std::unordered_map<int, int> hashtable;

    for(const auto & number : nums)
    {
        hashtable[number]++;
    }

    std::vector<std::pair<int, int>> pairs;

    for(const auto & [key, value] : hashtable)
    {
        pairs.emplace_back(std::make_pair(key, value));
    }

    std::partial_sort(pairs.begin(), pairs.begin() + k, pairs.end(), [] (const auto & e1, const auto & e2) -> bool {return e1.second >= e2.second;});

    result.resize(k);

    for(auto index=0;index<k;++index)
    {
        result[index]=pairs[index].first;
    }

    return result;
}