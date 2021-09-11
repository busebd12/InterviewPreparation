#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>
#include <utility>

/*
 * Solutions:
 *
 * Both of the solutions are based on this article: https://www.interviewcake.com/concept/java/lru-cache
 *
 * 1. We use a std::list (doubly-linked list) to hold our keys and a std::unordered_map<int, int> (hashtable) to map
 * our keys to their values for constant time retrieval of the values. However, since our moveToFront function
 * performs an O(n) time search of the cache, the overall complexities of the get and put functions are O(n).
 *
 * Time complexity: O(n) [where n is the size of the cache]
 * Space complexity: O(n)
 *
 * 2. Still using the same data structures, but we make use of std::list's splice member function to achieve constant
 * time for both the get and set functions.
 *
 * Time complexity: O(1)
 * Space complexity: O(n)
 */

class LRUCache
{
    public:
        std::unordered_map<int, int> lookupTable;

        std::list<int> cache;

        int maxSize=0;

        LRUCache(int capacity)
        {
            maxSize=capacity;
        }

        int get(int key)
        {
            if(lookupTable.count(key))
            {
                moveToFront(key);

                return lookupTable[key];
            }

            return -1;
        }

        void put(int key, int value)
        {
            if(lookupTable.count(key))
            {
                lookupTable[key]=value;

                moveToFront(key);
            }
            else
            {
                if(lookupTable.size()==maxSize)
                {
                    lookupTable.erase(cache.front());

                    cache.pop_front();
                }

                cache.push_back(key);

                lookupTable[key]=value;
            }
        }

        void moveToFront(int key)
        {
            auto itr=std::find(cache.begin(), cache.end(), key);

            if(itr!=cache.end())
            {
                cache.erase(itr);

                cache.push_back(key);
            }
        }
};

class LRUCache
{
    public:
        std::unordered_map<int, std::pair<int, std::list<int>::iterator>> hashtable;

        std::list<int> cache;

        int maxSize=0;

        LRUCache(int capacity)
        {
            maxSize=capacity;
        }

        int get(int key)
        {
            if(hashtable.count(key))
            {
                cache.splice(cache.end(), cache, hashtable[key].second);

                return hashtable[key].first;
            }

            return -1;
        }

        void put(int key, int value)
        {
            if(hashtable.count(key))
            {
                hashtable[key].first=value;

                cache.splice(cache.end(), cache, hashtable[key].second);
            }
            else
            {
                if(hashtable.size()==maxSize)
                {
                    hashtable.erase(cache.front());

                    cache.pop_front();
                }

                auto itr=cache.insert(cache.end(), key);

                hashtable[key]=std::make_pair(value, itr);
            }
        }
};