#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * Approaches, from top-to-bottom:
 *
 * 1) Use a hash table to keep track of the frequencies for each number.
 * Return the number that has frequency equal to one.
 *
 * Time complexity: O(n) [where n is the size of the input vector]
 * Space complexity: O(n) [where n is the size of the input vector]
 *
 * 2) Bit manipulation. Key realizations:
 * 0 ^ N = N
 * N ^ N = 0
 * So, if N is the single number, then we have the following:
 * N1 ^ N1 ^ N2 ^ N2 ^..............^ Nx ^ Nx ^ N = (N1^N1) ^ (N2^N2) ^..............^ (Nx^Nx) ^ N= 0 ^ 0 ^ ..........^ 0 ^ N= N
 *
 * Time complexity: O(n) [where n is the size of the input vector]
 * Space complexity: O(1)
 */

int singleNumber(vector<int> & nums)
{
    int result=0;

    unordered_map<int, int> table;

    for(const auto & number : nums)
    {
        table[number]++;
    }

    for(const auto & element : table)
    {
        if(element.second==1)
        {
            result=element.first;

            break;
        }
    }

    return result;
}

int singleNumber(vector<int> & nums)
{
    int result=0;

    for(const auto & number : nums)
    {
        result=result ^ number;
    }

    return result;
}