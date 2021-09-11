#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
 * Approaches:
 *
 * 1) Using std::list (linked list)
 *
 * add() time complexity: O(1)
 * add() space complexity: O(1)
 *
 * remove() time complexity: O(n) [where n is the number of elements in our hashset]
 * remove() space complexity: O(1)
 *
 * contains() time complexity: O(n) [where n is the number of elements in our hashset]
 * contains() space complexity: O(1)
 *
 *
 * 2) Using std::vector (without using the numbers as keys)
 *
 * add() time complexity: O(1)
 * add() space complexity: O(1)
 *
 * remove() time complexity: O(n) [where n is the number of elements in our hashset]
 * remove() space complexity: O(n)
 *
 * contains() time complexity: O(n) [where n is the number of elements in our hashset]
 * contains() space complexity: O(1)
 *
 *
 * 3) Using std::vector (utilizing the key values to hash)
 *
 * add() time complexity: O(1)
 * add() space complexity: O(1)
 *
 * remove() time complexity: O(1)
 * remove() space complexity: O(1)
 *
 * contains() time complexity: O(1)
 * contains() space complexity: O(1)
 */

class MyHashSet
{
public:

    list<int> hashset;

    MyHashSet()
    {

    }

    void add(int key)
    {
        hashset.push_back(key);
    }

    void remove(int key)
    {
        if(contains(key))
        {
            hashset.remove(key);
        }
    }


    bool contains(int key)
    {
        auto itr=find(hashset.begin(), hashset.end(), key);

        return itr!=hashset.end();
    }
};

class MyHashSet
{
    public:

        vector<int> hashset;

        MyHashSet()
        {

        }

        void add(int key)
        {
            hashset.push_back(key);
        }

        void remove(int key)
        {
            if(contains(key))
            {
                auto itr=remove_if(hashset.begin(), hashset.end(), [key] (const auto & element) {return element==key;});

                hashset.erase(itr, hashset.end());
            }
        }

        bool contains(int key)
        {
            auto itr=find(hashset.begin(), hashset.end(), key);

            return itr!=hashset.end();
        }
};

class MyHashSet
{
    public:

        vector<int> hashset;

        const size_t capacity=1000000;

        MyHashSet()
        {
            hashset=vector<int>(capacity, 0);
        }

        void add(int key)
        {
            hashset[key]++;
        }

        void remove(int key)
        {
            hashset[key]=0;
        }

        bool contains(int key)
        {
            return hashset[key]!=0;
        }
};