#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>

/*
 * Solutions:
 *
 * 1. We use a hashtable to map each string to its frequency. The inc() and dec() functions take O(1) time,
 * but the entire hashtable has to be scanned for the getMinKey() and getMaxKey() functions. So, those two
 * functions take O(u) [where u is the total number of unique strings]. In the worst case, if all the strings
 * are unique then these two functions will have time complexity of O(n) [where n is the total number of strings].
 * Space complexity is O(u) [where u is the total number of unique strings].
 *
 *
 *
 * 2. In order to improve the time complexity of the getMinKey() and getMaxKey() functions, we use another hashtable
 * (std::map<int, unordered_set<std::string>>) to group the strings into buckets based on frequency. Each frequency is
 * mapped to a std::unordered_set<std::string> that holds all strings with said frequency. Since std::map keeps its keys
 * sorted in increasing order, the getMinKey() and getMaxKey() functions now take O(1) time but the inc() and dec() functions
 * take O(log(u)) time [where u is the number of unique keys in the map]. Space complexity is now O(f) + O(n) [where
 * f is the total number of unique frequencies and n is the total number of unique strings]
 *
 *
 *
 * 3. The idea with this solution is to introduce a third data structure: doubly linked-list (std::list).
 * This linked-list will hold pairs of integers and std::unordered_set<std::string>. The integer value is the frequency
 * of the strings stored within the std::unordered_set<std::string>. In order to achieve O(1) time for the inc() and dec()
 * functions, we have to keep the pairs in the linked-list sorted in increasing order by the frequencies. The inc() function
 * has the following logic
 *
 * Two main cases
 *
 * a. We have not seen the string before
 *  i. If the bucket for strings of frequency one does not exist, we create it and then we insert the string in it
 *  ii. If the bucket for strings of frequency one does exit, we simply insert the string into it
 *
 * b. We have seen the string before
 *  i. If we already have a bucket for the increased frequency, just place the string into that bucket
 *
 *  ii. If no bucket for the increased frequency exists, create the bucket after the bucket the string currently resides
 *  in and insert the string into the newly created bucket. This will ensure we keep the ordering property of the linked-list.
 *
 *  iii. Erase the string from its old bucket
 *
 *  iv. Update the frequency of the string
 *
 *
 * The dec() function has the following logic
 *
 * Three main cases
 *
 * a. If the string doesn't exist, just return from the function.
 *
 * b. If the bucket for the decreased frequency already exists, just insert the string into that bucket.
 *
 * c. If the bucket for the decreased frequency does not exist, create it before the bucket that the string currently
 * sits in and insert the string into the newly created bucket. This way, we maintain the ordered property of the linked-list.
 *
 *
 * For the getMinKey() function, we just return the first string in the std::unordered_set<std::string> at the head
 * of the linked-list, an O(1) time operation.
 *
 * For the getMaxKey() function, we just return the first string in the std::unordered_set<std::string> at the tail
 * of the linked-list, an O(1) time operation.
 */

class AllOne
{
    public:
        std::unordered_map<std::string, int> hashtable;

        AllOne()
        {

        }

        void inc(std::string key)
        {
            if(!hashtable.count(key))
            {
                hashtable[key]=1;
            }
            else
            {
                hashtable[key]++;
            }
        }

        void dec(std::string key)
        {
            if(!hashtable.count(key))
            {
                return;
            }

            if(hashtable[key]==1)
            {
                hashtable.erase(key);
            }
            else
            {
                hashtable[key]--;
            }
        }

        std::string getMaxKey()
        {
            int maxFrequency=0;

            std::string maxKey{};

            for(const auto & [key, value] : hashtable)
            {
                if(maxKey.empty() || value > maxFrequency)
                {
                    maxFrequency=value;

                    maxKey=key;
                }
            }

            return maxKey;
        }

        std::string getMinKey()
        {
            int minFrequency=std::numeric_limits<int>::max();

            std::string minKey{};

            for(const auto & [key, value] : hashtable)
            {
                if(minKey.empty() || value < minFrequency)
                {
                    minKey=key;

                    minFrequency=value;
                }
            }

            return minKey;
        }
};

class AllOne
{
    public:
        std::unordered_map<std::string, int> hashtable;

        std::map<int, std::unordered_set<std::string>> buckets;

        AllOne()
        {

        }

        //Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        void inc(std::string key)
        {
            if(!hashtable.count(key))
            {
                hashtable[key]=1;

                if(!buckets.count(1))
                {
                    buckets.insert(std::make_pair(1, std::unordered_set<std::string>()));
                }

                buckets[1].insert(key);
            }
            else
            {
                int oldFrequency=hashtable[key];

                int newFrequency=oldFrequency + 1;

                if(!buckets.count(newFrequency))
                {
                    buckets.insert(std::make_pair(newFrequency, std::unordered_set<std::string>()));
                }

                buckets[newFrequency].insert(key);

                buckets[oldFrequency].erase(key);

                if(buckets[oldFrequency].empty())
                {
                    buckets.erase(oldFrequency);
                }

                hashtable[key]++;
            }
        }

        //Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        void dec(std::string key)
        {
            if(!hashtable.count(key))
            {
                return;
            }

            if(hashtable[key]==1)
            {
                buckets[hashtable[key]].erase(key);

                if(buckets[1].empty())
                {
                    buckets.erase(1);
                }

                hashtable.erase(key);
            }
            else
            {
                int oldFrequency=hashtable[key];

                int newFrequency=oldFrequency - 1;

                if(!buckets.count(newFrequency))
                {
                    buckets.insert(std::make_pair(newFrequency, std::unordered_set<std::string>()));
                }

                buckets[newFrequency].insert(key);

                buckets[oldFrequency].erase(key);

                if(buckets[oldFrequency].empty())
                {
                    buckets.erase(oldFrequency);
                }

                hashtable[key]--;
            }
        }

        //Returns one of the keys with maximal value.
        std::string getMaxKey()
        {
            std::string maxKey{};

            if(!buckets.empty())
            {
                auto itr=buckets.end();

                std::advance(itr, -1);

                if(!itr->second.empty())
                {
                    maxKey=*(itr->second.begin());
                }
            }

            return maxKey;
        }

        //Returns one of the keys with Minimal value.
        std::string getMinKey()
        {
            std::string minKey{};

            if(!buckets.empty())
            {
                auto itr=buckets.begin();

                if(!itr->second.empty())
                {
                    minKey=*(itr->second.begin());
                }
            }

            return minKey;
        }
};

class AllOne
{
    public:
        std::unordered_map<std::string, int> stringToFrequencyMap;

        std::unordered_map<int, std::list<std::pair<int, std::unordered_set<std::string>>>::iterator> frequencyToIteratorMap;

        std::list<std::pair<int, std::unordered_set<std::string>>> buckets;

        AllOne()
        {

        }

        //Inserts a new key <Key> with value 1. Or increments an existing key by 1
        void inc(std::string key)
        {
            if(!stringToFrequencyMap.count(key))
            {
                stringToFrequencyMap[key]=1;

                if(!frequencyToIteratorMap.count(1))
                {
                    auto itr=buckets.insert(buckets.begin(), std::make_pair(1, std::unordered_set<std::string>()));

                    (*itr).second.insert(key);

                    frequencyToIteratorMap.insert(std::make_pair(1, itr));
                }
                else
                {
                    auto bucketIterator=frequencyToIteratorMap[1];

                    (*bucketIterator).second.insert(key);
                }
            }
            else
            {
                int oldFrequency=stringToFrequencyMap[key];

                auto oldBucketIterator=frequencyToIteratorMap[oldFrequency];

                int newFrequency=oldFrequency + 1;

                if(frequencyToIteratorMap.count(newFrequency))
                {
                    (*frequencyToIteratorMap[newFrequency]).second.insert(key);
                }
                else
                {
                    auto nextIterator=oldBucketIterator;

                    std::advance(nextIterator, 1);

                    auto itr=buckets.insert(nextIterator, std::make_pair(newFrequency, std::unordered_set<std::string>()));

                    (*itr).second.insert(key);

                    frequencyToIteratorMap.insert(std::make_pair(newFrequency, itr));
                }

                (*oldBucketIterator).second.erase(key);

                if((*oldBucketIterator).second.empty())
                {
                    buckets.erase(oldBucketIterator);

                    frequencyToIteratorMap.erase(oldFrequency);
                }

                stringToFrequencyMap[key]++;
            }
        }

        //Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        void dec(std::string key)
        {
            if(!stringToFrequencyMap.count(key))
            {
                return;
            }

            if(stringToFrequencyMap[key]==1)
            {
                auto bucketIterator=frequencyToIteratorMap[1];

                (*bucketIterator).second.erase(key);

                if((*bucketIterator).second.empty())
                {
                    buckets.erase(bucketIterator);

                    frequencyToIteratorMap.erase(1);
                }

                stringToFrequencyMap.erase(key);
            }
            else
            {
                int oldFrequency=stringToFrequencyMap[key];

                int newFrequency=oldFrequency - 1;

                auto oldBucketIterator=frequencyToIteratorMap[oldFrequency];

                if(frequencyToIteratorMap.count(newFrequency))
                {
                    auto bucketIterator=frequencyToIteratorMap[newFrequency];

                    (*bucketIterator).second.insert(key);
                }
                else
                {
                    auto itr=buckets.insert(oldBucketIterator, std::make_pair(newFrequency, std::unordered_set<std::string>()));

                    (*itr).second.insert(key);

                    frequencyToIteratorMap.insert(std::make_pair(newFrequency, itr));
                }

                (*oldBucketIterator).second.erase(key);

                if((*oldBucketIterator).second.empty())
                {
                    buckets.erase(oldBucketIterator);

                    frequencyToIteratorMap.erase(oldFrequency);
                }

                stringToFrequencyMap[key]--;
            }
        }

        //Returns one of the keys with maximal value.
        std::string getMaxKey()
        {
            std::string maxKey{};

            if(!buckets.empty())
            {
                if(!buckets.back().second.empty())
                {
                    maxKey=*(buckets.back().second.begin());
                }
            }

            return maxKey;
        }

        //Returns one of the keys with Minimal value.
        std::string getMinKey()
        {
            std::string minKey{};

            if(!buckets.empty())
            {
                if(!buckets.front().second.empty())
                {
                    minKey=*(buckets.front().second.begin());
                }
            }

            return minKey;
        }
};