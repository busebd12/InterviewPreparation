#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * Solutions:
 *
 * 1. We use a hashtable to map each string to the string it's an anagram of.
 * For each string, we compare it to all the current keys in our hashtable to
 * see if any of the keys are a valid anagram. If a key is a valid anagram,
 * we add the current string to the vector<string> the anagram hashes to.
 * If none of the keys in the hashtable are valid anagrams, we add the
 * current string as a new key. It should be noted that this solution
 * gets "Time Limit Exceeded" when executed.
 *
 * Time complexity: O(n * (L + K)) [where n is the total number of strings in the input vector,
 * L is the average length of a string, and K is the average length of a key from our hashtable]
 *
 * Space complexity: O(n) [where n is the length of our input vector]
 *
 * 2. Use an unordered_map to group the strings by their sorted counterparts. Use the sorted string as the key and all anagram strings as the value.
 *
 * Time complexity: O(n log n * L) [where L is the average length of a string from our input vector]
 * Space complexity: O(n) [where n is the length of our input vector]
 *
 * 3. Use an unordered_map to group the strings by a hash formed by compressing the each string into a string
 * made up of the counts of how many time each letter appears and that letter. So, for example,
 * the string eat would have a hash of a1e1t1. All anagrams will share the same hash value since
 * anagrams have the same number of letters just in a different order.
 *
 * Time complexity: O(n * L) [where n is the length of our input vector and L is the average length of a string from our input vector]
 * Space complexity: O(n) [where n is the length of our input vector]
 */

bool isAnagram(const std::string & key, std::string & str)
{
    std::unordered_map<char, int> cache;

    for(const auto & letter : key)
    {
        cache[letter]++;
    }

    for(const auto & letter : str)
    {
        if(!cache.count(letter))
        {
            return false;
        }
        else
        {
            cache[letter]--;

            if(cache[letter]==0)
            {
                cache.erase(letter);
            }
        }
    }

    if(!cache.empty())
    {
        return false;
    }

    return true;
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    std::vector<std::vector<std::string>> result;

    if(strs.empty())
    {
        return result;
    }

    std::unordered_map<std::string, std::vector<std::string>> hashtable;

    for(auto & s : strs)
    {
        bool found=false;

        std::string anagram{};

        for(const auto & [key, value] : hashtable)
        {
            if(isAnagram(key, s))
            {
                found=true;

                anagram=key;

                break;
            }
        }

        if(!found)
        {
            hashtable.insert(std::make_pair(s, std::vector<std::string>{s}));
        }
        else
        {
            hashtable[anagram].push_back(s);
        }
    }

    for(const auto & [key, value] : hashtable)
    {
        result.push_back(value);
    }

    return result;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> & strs)
{
    std::vector<std::vector<std::string>> result;

    if(strs.empty())
    {
        return result;
    }

    std::unordered_map<std::string, std::vector<std::string>> hashtable;

    for(auto & s : strs)
    {
        std::string sorted=s;

        std::sort(sorted.begin(), sorted.end());

        hashtable[sorted].push_back(s);
    }

    for(const auto & [key, value] : hashtable)
    {
        result.push_back(value);
    }

    return result;
}

std::string getHash(std::string & s)
{
    std::string compressed{};

    std::vector<int> values(26, 0);

    for(auto & letter : s)
    {
        values[letter - 'a']++;
    }

    for(int index=0;index<26;++index)
    {
        if(values[index] > 0)
        {
            compressed+=std::to_string(values[index]);

            compressed+=(index + 'a');
        }
    }

    return compressed;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> & strs)
{
    std::vector<std::vector<std::string>> result;

    if(strs.empty())
    {
        return result;
    }

    std::unordered_map<std::string, std::vector<std::string>> hashtable;

    for(auto & s : strs)
    {
        std::string hash=getHash(s);

        hashtable[hash].push_back(s);
    }

    for(const auto & [key, value] : hashtable)
    {
        result.push_back(value);
    }

    return result;
}