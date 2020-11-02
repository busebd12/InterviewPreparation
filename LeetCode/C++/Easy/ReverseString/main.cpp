#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) While moving in towards the center of the character vector from the left and right, swap the left and right characters.
 *
 * Time complexity: O(n/2) [where n is the number of characters in the input vector]
 * Space complexity: O(1)
 *
 * 2) Using the STL function, reverse
 *
 * Time complexity: O(n/2)
 * Space complexity: O(1)
 */

void reverseString(vector<char> & s)
{
    if(s.empty())
    {
        return;
    }

    int n=int(s.size());

    if(n==1)
    {
        return;
    }

    for(int i=0;i<n/2;++i)
    {
        swap(s[i], s[n-1-i]);
    }
}

void reverseString(vector<char> & s)
{
    reverse(s.begin(), s.end());
}