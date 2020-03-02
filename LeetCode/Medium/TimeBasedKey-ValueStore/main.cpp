#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

/*
 * Solutions
 *
 * 1. Use a hashtable (std::unordered_map<std::string, std::multimap<int, std::string>>) to map each key to all its
 * pairs of values and time stamps. However, this solution gets Time Limited Exceed when run.
 *
 * Time complexity:
 * set function --> O(n) [where n is the number of set operations and m is the number of get operations]
 * get function --> O(m * n)
 *
 * Space complexity: O(n)
 *
 * 2. To avoid the Time Limit Exceed result, we take advantage of the fact that the timestamps will be strictly increasing.
 * Due to this fact, we can use a std::map<int, std::string> instead of a std::multimap<int, std::string> because the
 * timestamps will already be sorted. Also, we can use binary search to drop the get function's complexity from O(n)
 * to O(log n).
 *
 * Time complexity: O(n) [where n is the number of set operations]
 * Space complexity: O(m log n) [where m is the number of get operations]
 */

class TimeMap
{
    public:
        std::unordered_map<std::string, std::multimap<int, std::string>> hashtable;

        TimeMap()
        {

        }

        void set(std::string key, std::string value, int timestamp)
        {
            hashtable[key].insert(std::make_pair(timestamp, value));
        }

        std::string get(std::string key, int timestamp)
        {
            auto keyItr=hashtable.find(key);

            if(keyItr==hashtable.end())
            {
                return "";
            }

            std::string result{};

            for(auto & element : hashtable[key])
            {
                if(element.first <= timestamp)
                {
                    result=element.second;
                }
            }

            return result;
        }
};

class TimeMap
{
    public:
        std::unordered_map<std::string, std::map<int, std::string>> hashtable;

        TimeMap()
        {

        }

        void set(std::string key, std::string value, int timestamp)
        {
            hashtable[key].insert(std::make_pair(timestamp, value));
        }

        std::string get(std::string key, int timestamp)
        {
            auto itr=hashtable[key].upper_bound(timestamp);

            return itr==hashtable[key].begin() ? "" : std::prev(itr)->second;
        }
};