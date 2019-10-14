#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
 * Approach: Starting rotating the string A with the first letter and while we haven't started rotations
 * with each letter in the string, check if A equals B. If, after make n rotations (where n is the length of
 * the string A), A is not equal to B, then it will never be.
 *
 * Time complexity: O(n-squared) [where n is the length of string A]
 * Space complexity: O(1)
 */

bool rotateString(string A, string B)
{
    if(A.empty() && B.empty())
    {
        return true;
    }

    if(A.empty() || B.empty())
    {
        return false;
    }

    size_t n=A.size();

    size_t rotations=0;

    while(rotations < n)
    {
        rotate(A.rbegin(), A.rbegin() + 1, A.rend());

        if(A==B)
        {
            return true;
        }

        rotations++;
    }

    return false;
}