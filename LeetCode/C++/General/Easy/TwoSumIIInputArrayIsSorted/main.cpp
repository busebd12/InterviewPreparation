#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Loop over the input vector and subtract the current number from our target.
 * Then, use binary search to see if the remaining value is in the input vector.
 *
 * Time complexity: O(n log n)
 * Space complexity: O(1)
 *
 * 2) Looping over the input vector, check to see if the current element is in the hash table.
 * If it is, that means we have found the other number that we add to the current one to make our target sum.
 * So, return its index along with the index of the current number. Else, add the difference between the target
 * sum and the current number, and its index, to the hash table.
 *
 * Time complexity: O(n) [where n is the size of the input vector]
 * Space complexity: O(n) [where n is the size of the input vector]
 */

int binarySearch(vector<int> & numbers, int low, int high, int target)
{
    while(low <= high)
    {
        int middle=low + ((high-low)/2);

        if(numbers[middle]==target)
        {
            return middle+1;
        }
        else if(numbers[middle] < target)
        {
            low=middle+1;
        }
        else
        {
            high=middle-1;
        }
    }

    return -1;
}

vector<int> twoSum(vector<int>& numbers, int target)
{
    vector<int> result;

    if(numbers.empty())
    {
        return result;
    }

    int n=int(numbers.size());

    for(int i=0;i<n;++i)
    {
        int current=numbers[i];

        int remaining=target-current;

        int low=0;

        int high=n-1;

        int index=binarySearch(numbers, low, high, remaining);

        if(index!=-1)
        {
            if(index!=i+1)
            {
                if(index > i+1)
                {
                    result.emplace_back(i+1);

                    result.push_back(index);
                }
                else
                {
                    result.push_back(index);

                    result.emplace_back(i+1);
                }

                break;
            }
        }

    }

    return result;
}

vector<int> twoSum(vector<int> & numbers, int target)
{
    vector<int> result;

    if(numbers.empty())
    {
        return result;
    }

    unordered_map<int, int> table;

    int n=int(numbers.size());

    for(int index=0;index<n;++index)
    {
        int current=numbers[index];

        int remaining=target-current;

        if(table.count(current))
        {
            result.emplace_back(table[current]+1);

            result.emplace_back(index+1);

            break;
        }
        else
        {
            table[remaining]=index;
        }
    }

    return result;
}