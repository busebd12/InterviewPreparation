#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <unordered_map>

/*
 * Solutions:
 *
 * 1. The idea is to use a std::map<int, std::list<int>> to map each frequency to a bucket of all keys with that
 * particular frequency. We use a std::unordered_map<int, std::list<int>::iterator> to map each key to its linked-list
 * iterator. By doing this, we can remove keys from their respective buckets in O(1) time (since, std::list supports
 * deletion-by-iterator in O(1)). We keep another std::unordered_map<int, std::pair<int,int>> which is used to map
 * each key to its frequency and value. This way, for each key, we have O(1) access to its frequency and value when
 * we are removing and adding keys from/to their respective buckets. The get() and put() functions both run in O(log(n))
 * time since insertion and deleting from std::map is O(log(n)). The total space complexity is O(k) [where k is the total number of keys].
 *
 * 2. In order to reduce the time complexity from O(log(n)) to O(1) for the get() and put() functions, we trade the
 * std::map<int, std::list<int>> in for two data structures: std::unordered_map<int, std::list<std::pair<int, std::list<int>>>::iterator> and std::list<std::pair<int, std::list<int>>>
 * We use a std::list (doubly-linked list) of pairs. Each pair contains an integer and another std::list (this time, of integers). The integer represents the frequency
 * and the std::list<int> holds all the keys with that particular frequency. The std::unordered_map maps each key to an iterator that was returned when inserting
 * the key into its particular bucket within the linked-list. In order to achieve O(1) for the get() and put() functions for the cache, we keep the std::list<std::pair<int, std::list<int>>>
 * sorted in ascending order. This way when we are inserting a new key or moving a key from one bucket to another after its frequency has been increased, we can just
 * create the new bucket right after the previous bucket using the iterator to the previous bucket. The other two std::unordered_maps remain the same.
 * The total space complexity is O(k) [where k is the number of keys].
 *
 */

class LFUCache
{
    private:
        std::unordered_map<int, std::pair<int, int>> keyToValueAndFrequencyMap;

        std::unordered_map<int, std::list<int>::iterator> keyToIteratorMap;

        std::map<int, std::list<int>> frequencyToListMap;

        int maxSize;

        int elements;

    public:
        LFUCache(int capacity)
        {
            maxSize=capacity;

            elements=0;
        }

        int get(int key)
        {
            if(!keyToValueAndFrequencyMap.count(key))
            {
                return -1;
            }

            int oldFrequency=keyToValueAndFrequencyMap[key].second;

            int newFrequency=oldFrequency + 1;

            auto itr=frequencyToListMap[newFrequency].insert(frequencyToListMap[newFrequency].begin(), key);

            auto oldIterator=keyToIteratorMap[key];

            frequencyToListMap[oldFrequency].erase(oldIterator);

            if(frequencyToListMap[oldFrequency].empty())
            {
                frequencyToListMap.erase(oldFrequency);
            }

            keyToValueAndFrequencyMap[key].second=newFrequency;

            keyToIteratorMap[key]=itr;

            return keyToValueAndFrequencyMap[key].first;
        }

        void put(int key, int value)
        {
            if(maxSize > 0)
            {
                if(!keyToValueAndFrequencyMap.count(key))
                {
                    if(elements==maxSize)
                    {
                        int keyToRemove=frequencyToListMap.begin()->second.back();

                        frequencyToListMap.begin()->second.pop_back();

                        if(frequencyToListMap.begin()->second.empty())
                        {
                            frequencyToListMap.erase(frequencyToListMap.begin());
                        }

                        keyToValueAndFrequencyMap.erase(keyToRemove);

                        keyToIteratorMap.erase(keyToRemove);

                        elements--;
                    }

                    auto itr=frequencyToListMap[1].insert(frequencyToListMap[1].begin(), key);

                    keyToValueAndFrequencyMap[key]=std::make_pair(value, 1);

                    keyToIteratorMap[key]=itr;

                    elements++;
                }
                else
                {
                    int oldFrequency=keyToValueAndFrequencyMap[key].second;

                    int newFrequency=oldFrequency + 1;

                    auto itr=frequencyToListMap[newFrequency].insert(frequencyToListMap[newFrequency].begin(), key);

                    auto oldIterator=keyToIteratorMap[key];

                    frequencyToListMap[oldFrequency].erase(oldIterator);

                    if(frequencyToListMap[oldFrequency].empty())
                    {
                        frequencyToListMap.erase(oldFrequency);
                    }

                    keyToValueAndFrequencyMap[key].first=value;

                    keyToValueAndFrequencyMap[key].second=newFrequency;

                    keyToIteratorMap[key]=itr;
                }
            }
        }
};

class LFUCache
{
    private:
        std::unordered_map<int, std::pair<int, int>> keyToValueAndFrequencyMap;

        std::unordered_map<int, std::list<int>::iterator> keyToIteratorMap;

        std::unordered_map<int, std::list<std::pair<int, std::list<int>>>::iterator> frequencyToIteratorMap;

        std::list<std::pair<int, std::list<int>>> buckets;

        int maxSize;

        int elements;

    public:
        LFUCache(int capacity)
        {
            maxSize=capacity;

            elements=0;
        }

        int get(int key)
        {
            if(!keyToValueAndFrequencyMap.count(key))
            {
                return -1;
            }

            int oldFrequency=keyToValueAndFrequencyMap[key].second;

            int newFrequency=oldFrequency + 1;

            std::list<int>::iterator newKeyIterator;

            //We already have the bucket for the new frequency. Just insert the key into the new bucket.
            if(frequencyToIteratorMap.count(newFrequency))
            {
                auto bucketIterator=frequencyToIteratorMap[newFrequency];

                newKeyIterator=(*bucketIterator).second.insert((*bucketIterator).second.end(), key);
            }
            //We need to create the bucket for the new frequency and insert the key into the new bucket
            else
            {
                auto iterator=frequencyToIteratorMap[oldFrequency];

                std::advance(iterator, 1);

                auto newBucketIterator=buckets.insert(iterator, std::make_pair(newFrequency, std::list<int>()));

                frequencyToIteratorMap[newFrequency]=newBucketIterator;

                newKeyIterator=(*newBucketIterator).second.insert((*newBucketIterator).second.end(), key);
            }

            //iterator for the key in the old linked-list
            auto oldKeyIterator=keyToIteratorMap[key];

            //iterator for the old bucket
            auto oldFrequencyBucketIterator=frequencyToIteratorMap[oldFrequency];

            //erase key from its old bucket
            (*oldFrequencyBucketIterator).second.erase(oldKeyIterator);

            //if the old bucket we just removed the key from is empty, then we need to remove it from the list
            if((*oldFrequencyBucketIterator).second.empty())
            {
                buckets.erase(oldFrequencyBucketIterator);

                frequencyToIteratorMap.erase(oldFrequency);
            }

            keyToValueAndFrequencyMap[key].second=newFrequency;

            keyToIteratorMap[key]=newKeyIterator;

            return keyToValueAndFrequencyMap[key].first;
        }

        void put(int key, int value)
        {
            if(maxSize > 0)
            {
                //we don't have the key in our hashtable
                if(!keyToValueAndFrequencyMap.count(key))
                {
                    //if the cache is full, we need to remove the lest frequently used element
                    if(elements==maxSize)
                    {
                        int keyToRemove=buckets.front().second.front();

                        buckets.front().second.pop_front();

                        if(buckets.front().second.empty())
                        {
                            frequencyToIteratorMap.erase(buckets.front().first);

                            buckets.erase(buckets.begin());
                        }

                        keyToValueAndFrequencyMap.erase(keyToRemove);

                        keyToIteratorMap.erase(keyToRemove);

                        elements--;
                    }

                    //Okay, now we need to insert the new key into the cache. There are two cases.

                    //case 1: we already have the bucket for the new key and we just need to insert the key into the bucket
                    if(frequencyToIteratorMap.count(1))
                    {
                        auto bucketIterator=frequencyToIteratorMap[1];

                        auto keyItr=(*bucketIterator).second.insert((*bucketIterator).second.end(), key);

                        keyToIteratorMap[key]=keyItr;
                    }
                    //case 2: we need to create the bucket for the key and then insert the key into the new bucket
                    else
                    {
                        auto bucketItr=buckets.insert(buckets.begin(), std::make_pair(1, std::list<int>()));

                        frequencyToIteratorMap[1]=bucketItr;

                        auto keyItr=(*bucketItr).second.insert((*bucketItr).second.end(), key);

                        keyToIteratorMap[key]=keyItr;
                    }

                    keyToValueAndFrequencyMap[key]=std::make_pair(value, 1);

                    elements++;
                }
                //We already have the key in the hashtable and we are just changing the key's value
                else
                {
                    int oldFrequency=keyToValueAndFrequencyMap[key].second;

                    int newFrequency=oldFrequency + 1;

                    std::list<int>::iterator newKeyIterator;

                    //We already have the bucket for the new frequency. Just insert the key into the new bucket.
                    if(frequencyToIteratorMap.count(newFrequency))
                    {
                        auto bucketIterator=frequencyToIteratorMap[newFrequency];

                        newKeyIterator=(*bucketIterator).second.insert((*bucketIterator).second.end(), key);
                    }
                        //We need to create the bucket for the new frequency and insert the key into the new bucket
                    else
                    {
                        auto iterator=frequencyToIteratorMap[oldFrequency];

                        std::advance(iterator, 1);

                        auto newBucketIterator=buckets.insert(iterator, std::make_pair(newFrequency, std::list<int>()));

                        frequencyToIteratorMap[newFrequency]=newBucketIterator;

                        newKeyIterator=(*newBucketIterator).second.insert((*newBucketIterator).second.end(), key);
                    }

                    //iterator for the key in the old linked-list
                    auto oldKeyIterator=keyToIteratorMap[key];

                    //iterator for the old bucket
                    auto oldFrequencyBucketIterator=frequencyToIteratorMap[oldFrequency];

                    //erase key from its old bucket
                    (*oldFrequencyBucketIterator).second.erase(oldKeyIterator);

                    //if the old bucket we just removed the key from is empty, then we need to remove it from the list
                    if((*oldFrequencyBucketIterator).second.empty())
                    {
                        buckets.erase(oldFrequencyBucketIterator);

                        frequencyToIteratorMap.erase(oldFrequency);
                    }

                    keyToValueAndFrequencyMap[key].second=newFrequency;

                    keyToIteratorMap[key]=newKeyIterator;

                    keyToValueAndFrequencyMap[key].first=value;
                }
            }
        }
};
