#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <unordered_map>

/*
 * Solution: we use a std::unordered_map<char, int> to count the frequency of each character. Next, we insert
 * all the <key, value> pairs from the hashtable into a max heap, this way the most frequent character will
 * always be at the top of the heap. Then, while the result string length is less than the input string length,
 * we remove the top element from the max heap and add it to the result string. After removing the top element,
 * if the heap size is greater than or equal to one, then we can a different letter after the one we just added.
 * Then, we add the first element we popped from the heap back into the heap, followed by the second element
 * (if we were able to remove a second element). Repeat this process until either we can't add another letter
 * to the end of the result string because of duplication or the size of the result string equals the size of the
 * input string.
 *
 * Time complexity: O(n + k log k) [where n is the length of the input string and k is the number of unique keys in the hashtable]
 * Space complexity: O(k) [where k is the number of unique keys in the hashtable]
 */

std::string reorganizeString(std::string S)
{
    std::string result{};

    if(S.empty())
    {
        return result;
    }

    std::unordered_map<char, int> hashtable;

    for(const auto & letter : S)
    {
        hashtable[letter]++;
    }

    auto comparator=[] (const auto & p1, const auto & p2) {return p1.second < p2.second;};

    std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, decltype(comparator)> maxHeap(comparator);

    for(const auto & [key, value] : hashtable)
    {
        maxHeap.push(std::make_pair(key, value));
    }

    while(result.size() < S.length())
    {
        auto firstTop=maxHeap.top();

        maxHeap.pop();

        if(!result.empty())
        {
            if(firstTop.first==result.back())
            {
                return "";
            }
        }

        result+=firstTop.first;

        firstTop.second--;

        if(maxHeap.size() >= 1)
        {
            auto secondTop=maxHeap.top();

            maxHeap.pop();

            result+=secondTop.first;

            secondTop.second--;

            if(firstTop.second > 0)
            {
                maxHeap.emplace(firstTop);
            }

            if(secondTop.second > 0)
            {
                maxHeap.emplace(secondTop);
            }
        }
        else
        {
            if(firstTop.second > 0)
            {
                maxHeap.emplace(firstTop);
            }
        }
    }

    return result;
}