#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: Using a vector<int>, utilize the number's value as the hash value in our hashtable.
 *
 * put() time complexity: O(1)
 * put() space complexity: O(1)
 *
 * get() time complexity: O(1)
 * get() space complexity: O(1)
 *
 * remove() time complexity: O(1)
 * remove() space complexity: O(1)
 */

class MyHashMap
{
    public:

        vector<int> hashmap;

        const size_t size=1000000;

        MyHashMap()
        {
            hashmap=vector<int>(size, -1);
        }

        void put(int key, int value)
        {
            hashmap[key]=value;
        }

        int get(int key)
        {
            return hashmap[key];
        }

        void remove(int key)
        {
            if(hashmap[key]!=-1)
            {
                hashmap[key]=-1;
            }
        }
};