#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
 * Approach: we count the frequency of each number in arr using a hashtable (unordered_map<int, int>).
 * Then, for each frequency, if it is not already in our unordered_set<int> cache, we insert it.
 * If the frequency is already in cache, then we know the frequencies are not all unique and return false.
 * After looping over all the frequencies, we know that they are all unique and we return true.
 *
 * Time complexity: O(n) [where n is the number of integers in the input vector]
 * Space complexity: O(u) [where u is the number of unique elements in the input vector]
 */

bool uniqueOccurrences(vector<int>& arr)
{
    unordered_map<int, int> hashtable;

    for(const auto & number : arr)
    {
        hashtable[number]++;
    }

    unordered_set<int> cache;

    for(const auto & [key, value] : hashtable)
    {
        if(cache.count(value))
        {
            return false;
        }
        else
        {
            cache.insert(value);
        }
    }

    return true;
}