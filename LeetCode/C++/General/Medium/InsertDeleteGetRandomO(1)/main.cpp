#include <iostream>
#include <unordered_map>
#include <vector>

/*
 * Solution: we use an std::unordered_map<int, int> to achieve O(1) insertion and deletion. We use an std::vector<int>
 * to achieve O(1) random access. The std::unordered_map<int, int> maps each number to its index in the vector.
 * So, when we want to delete a number from the vector in O(1) time we override the index of the number we want
 * to delete with the last value in the vector (since order doesn't matter) and then we delete the last element
 * from the vector.
 *
 * Time complexity: O(1)
 * Space complexity: O(n) [where n is the number of numbers provided as input]
 */

class RandomizedSet
{
    public:

        std::unordered_map<int, int> hashtable;

        std::vector<int> numbers;

        /** Initialize your data structure here. */
        RandomizedSet()
        {
            srand(time(NULL));
        }

        /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
        bool insert(int val)
        {
            bool insertResult=false;

            if(!hashtable.count(val))
            {
                numbers.emplace_back(val);

                hashtable[val]=numbers.size()-1;

                insertResult=true;
            }

            return insertResult;
        }

        /** Removes a value from the set. Returns true if the set contained the specified element. */
        bool remove(int val)
        {
            bool removeResult=false;

            if(hashtable.count(val))
            {
                int last=numbers.back();

                hashtable[last]=hashtable[val];

                int index=hashtable[val];

                numbers[index]=last;

                numbers.pop_back();

                hashtable.erase(val);

                removeResult=true;
            }

            return removeResult;
        }

        /** Get a random element from the set. */
        int getRandom()
        {
            return numbers[rand() % numbers.size()];
        }
};