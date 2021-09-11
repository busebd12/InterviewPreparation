#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1. Hashtable via unordered_map. We count the frequency of each number in the input vector and return the one that appears N/2 times.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(u) [where u is the number of unique elements in the input vector]
 *
 * 2. Using an unordered_set. For each number in the input vector, we check to see if the number has already
 * been seen before (aka if the number is in the unordered_set or not). If it hasn't we add it to the unordered_set.
 * If it has, then we know that that number is our answer.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(u) [where u is the number of unique numbers in the input vector]
 */

int repeatedNTimes(vector<int>& A)
{
    unordered_map<int, int> hashtable;

    int twoN=int(A.size());

    int N=twoN/2;

    int result=-1;

    for(const int & number : A)
    {
        hashtable[number]++;

        if(hashtable[number]==N)
        {
            result=number;

            break;
        }
    }

    return result;
}

int repeatedNTimes(vector<int>& A)
{
    int result=-1;

    if(A.empty())
    {
        return result;
    }

    unordered_set<int> us;

    for(const int & number : A)
    {
        if(!us.count(number))
        {
            us.insert(number);
        }
        else
        {
            result=number;

            break;
        }
    }

    return result;
}