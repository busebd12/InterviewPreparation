#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Use a vector<int> to hold the numbers.
 * Then, we use the same logic involved in finding two indices
 * of two numbers that sum up to a given sum, except we only
 * care about finding the two numbers.
 *
 * Time complexity of add: O(1)
 * Time complexity of find: O(n)
 * Space complexity: O(n)
 *
 * 2) Use an unordered_multiset<int> to hold all the numbers.
 * Then, loop through each number in the unordered_multiset
 * and see if we find the following: the unordered_multiset
 * contains the difference between the current number and the
 * target sum and the current number is not equal to difference (avoid using the same number twice)
 * or the unordered_multiset has two difference copies of the current number.
 *
 * Time complexity of add(): O(1)
 * Time complexity of find(): O(n)
 * Space complexity: O(n)
 */

class TwoSum
{
    public:

        vector<int> numbers;

        TwoSum()
        {

        }

        void add(int number)
        {
            numbers.push_back(number);
        }

        bool find(int value)
        {
            unordered_set<int> table;

            for(int & number : numbers)
            {
                int remaining=value-number;

                if(table.count(remaining))
                {
                    return true;
                }

                table.insert(number);
            }

            return false;
        }
};

class TwoSum
{
    public:

        unordered_multiset<int> ums;

        TwoSum()
        {

        }

        void add(int number)
        {
            ums.insert(number);
        }

        bool find(int value)
        {
            for(int number : ums)
            {
                int difference=value-number;

                if(ums.count(difference) && (number!=(difference) || ums.count(number) > 1))
                {
                    return true;
                }
            }

            return false;
        }
};