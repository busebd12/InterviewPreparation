#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

/*
 * Approaches:
 *
 * 1) Using a hashtable, map each number in the input vector to its frequency in the vector.
 * Then, we choose each number as the minimum and check if the appropriate maximum (minimum + 1)
 * exists in the vector. If it does, we map the minimum to the maximum in another hashtable.
 * Finally, for each minimum in the hashtable that has corresponding maximum, we loop over
 * the input vector and if the current number is greater than or equal to the minimum and
 * less than or equal to the maximum, we increment the current length. After looping over
 * the input vector, if the current length is greater than our result length, we make
 * our result length equal to the current length.
 *
 * Time complexity: O(n) [where n is the number of elements in the input vector]
 * Space complexity: O(n + m) [where n is the number of elements in the input vector and m is the number of pairs of valid minimums and maximums]
 *
 * 2) Using a hashtable, we map each element in the input vector to its frequency within the input vector.
 * Then, for each number, we see if there exists a corresponding maximum in the hashtable. If there does,
 * then the length of this current subsequence is the frequency of the minimum plus the frequency of the maximum.
 * Update our result length accordingly if the current length is greater.
 *
 * Time complexity: O(n) [where n is the number of elements in the input vector]
 * Space complexity: O(n)
 */

int findLHS(vector<int>& nums)
{
    int result=0;

    if(nums.empty())
    {
        return result;
    }

    unordered_map<int, int> frequencies;

    for(const int & number : nums)
    {
        frequencies[number]++;
    }

    unordered_map<int, int> minMaxPairs;

    for(int number : nums)
    {
        if(frequencies.count(number+1))
        {
            if(!minMaxPairs.count(number))
            {
                minMaxPairs.insert(make_pair(number, number+1));
            }
        }
    }

    for(const auto & element : minMaxPairs)
    {
        int length=0;

        int minimum=element.first;

        int maximum=element.second;

        for(const int & number : nums)
        {
            if(number >= minimum && number <= maximum)
            {
                length++;
            }
        }

        result=max(result, length);
    }

    return result;
}

int findLHS(vector<int>& nums)
{
    int result=0;

    if(nums.empty())
    {
        return result;
    }

    unordered_map<int, int> frequencies;

    for(const int & number : nums)
    {
        frequencies[number]++;
    }

    for(const auto & element : frequencies)
    {
        int length=0;

        int minimum=element.first;

        int maximum=minimum+1;

        if(frequencies.count(maximum))
        {
            length=frequencies[minimum] + frequencies[maximum];
        }

        result=max(result, length);
    }

    return result;
}