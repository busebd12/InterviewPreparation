#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Approach: use a stringstream object to parse the string by spaces and then store every three words in a deque and
 * if the first two words in the deque are equal to first and second, respectively, add the third word to our vector<string> result.
 * Return the vector<string> result.
 *
 * Time complexity: O(n) [where n is the length of the input string text]
 * Space complexity: O(n)
 */

vector<string> findOcurrences(string text, string first, string second)
{
    vector<string> result;

    if(text.empty())
    {
        return result;
    }

    if(first.empty() || second.empty())
    {
        return result;
    }

    stringstream ss(text);

    string buffer{};

    deque<string> cache;

    while(ss >> buffer)
    {
        cache.push_back(buffer);

        if(cache.size()==3)
        {
            if(cache[0]==first && cache[1]==second)
            {
                result.push_back(cache[2]);
            }

            cache.pop_front();
        }
    }

    return result;
}