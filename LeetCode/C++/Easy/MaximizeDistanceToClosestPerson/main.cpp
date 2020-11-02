#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
 * Approaches:
 *
 * 1) Brute-force. Store each index of a 1 in the input vector in a vector<int> takenSeatIndices.
 * Then, for each zero in the input vector, calculate the minimum distance between that index and all
 * indices of 1s in the vector. Take the maximum value out of all indices for zeroes.
 *
 * Time complexity: O(n * m) [where n is the length of the input vector and m is the number of indices of 1's in our input vector]
 * Space complexity: O(m)
 *
 * 2) Let left[i] be the distance from seat i to the closest person sitting to the left of i.
 * Similarly, let right[i] be the distance to the closest person sitting to the right of i.
 * This is motivated by the idea that the closest person in seat i sits a distance min(left[i], right[i]) away.
 * Then, for each seat[i], the answer for that seat is the minimum of left[i] and right[i]. Take the maximum
 * of those values.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(n)
 */

int maxDistToClosest(vector<int>& seats)
{
    vector<int> takenSeatIndices;

    int n=int(seats.size());

    for(int i=0;i<n;++i)
    {
        if(seats[i]==1)
        {
            takenSeatIndices.push_back(i);
        }
    }

    int result=numeric_limits<int>::min();

    for(int i=0;i<n;++i)
    {
        int candidate=numeric_limits<int>::max();

        if(seats[i]==0)
        {
            for(const int & index : takenSeatIndices)
            {
                candidate=min(candidate, abs(index - i));
            }

            result=max(candidate, result);
        }
    }

    return result;
}

int maxDistToClosest(vector<int>& seats)
{
    vector<int> takenSeatIndices;

    int n=int(seats.size());

    for(int i=0;i<n;++i)
    {
        if(seats[i]==1)
        {
            takenSeatIndices.push_back(i);
        }
    }

    int result=numeric_limits<int>::min();

    for(int i=0;i<n;++i)
    {
        int candidate=numeric_limits<int>::max();

        if(seats[i]==0)
        {
            for(const int & index : takenSeatIndices)
            {
                candidate=min(candidate, abs(index - i));
            }

            result=max(candidate, result);
        }
    }

    return result;
}