#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

/*
 * Solutions:
 *
 * 1. Use a hashtable (std::unordered_map<std::string, int>) to map each string to its frequency.
 * Then, use a min heap to store the top k most frequent words. Finally, remove each element from
 * the min heap and add the word to our result vector.
 *
 * Time complexity: O((n + k) * (n log k)) [where n is the size of the input vector]
 * Space complexity: O(u + log(k)) [where u is the number of unique words from the input vector]
 *
 * 2. Use a hashtable (std::unordered_map<std::string, int>) to map each string to its frequency.
 * Then, place each pair into a vector of pairs (std::vector<std::pair<std::string, int>>).
 * Next, utilize the std::partial_sort algorithm to sort the input vector so that the top k frequent
 * words are at the beginning of the vector of pairs. Then, add the first k words from the vector of pairs
 * to our result vector.
 *
 * Time complexity: O(n + u + k + (k * log(u)) [where n is the size of the input vector and u is the number of unique strings in the input vector]
 * Space complexity: O(u + log(k))
 */

std::vector<std::string> topKFrequent(std::vector<std::string> & words, int k)
{
    std::vector<std::string> result;

    if(words.empty() || k <= 0)
    {
        return result;
    }

    std::unordered_map<std::string, int> hashtable;

    for(auto & word : words)
    {
        hashtable[word]++;
    }

    auto comparator=[&] (const auto & e1, const auto & e2) {return (e1.second > e2.second || (e1.second==e2.second && e1.first < e2.first));};

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, decltype(comparator)> minHeap(comparator);

    for(const auto & element : hashtable)
    {
        minHeap.emplace(element);

        if(minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    result.resize(minHeap.size());

    for(auto index=k-1;index>=0;--index)
    {
        result[index]=minHeap.top().first;

        minHeap.pop();
    }

    return result;
}

std::vector<std::string> topKFrequent(std::vector<std::string> & words, int k)
{
    std::vector<std::string> result;

    if(words.empty() || k <= 0)
    {
        return result;
    }

    std::unordered_map<std::string, int> hashtable;

    for(auto & word : words)
    {
        hashtable[word]++;
    }

    std::vector<std::pair<std::string, int>> pairs;

    for(const auto & element : hashtable)
    {
        pairs.emplace_back(element);
    }

    std::partial_sort(pairs.begin(), pairs.begin() + k, pairs.end(), [&] (const auto & e1, const auto & e2) {return (e1.second>e2.second || (e1.second==e2.second && e1.first<e2.first));});

    result.resize(k);

    int index=0;

    for(const auto & element : pairs)
    {
        if(index==k)
        {
            break;
        }

        result[index]=element.first;

        index++;
    }

    return result;
}