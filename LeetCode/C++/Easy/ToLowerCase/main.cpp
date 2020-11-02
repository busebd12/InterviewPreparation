#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
 * Approaches:
 *
 * 1) Loop over the string and make each letter lower-case.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(1)
 *
 * 2) Same idea as the first solution, just using the for_each STL algorithm.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(1)
 *
 * 3) Same idea as the first two solutions, just using the transform STL algorithm
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(1)
 */

string toLowerCase(string str)
{
    if(str.empty())
    {
        return str;
    }

    int n=int(str.size());

    for(int i=0;i<n;++i)
    {
        if(isalpha(str[i]))
        {
            str[i]=tolower(str[i]);
        }
    }

    return str;
}

string toLowerCase(string str)
{
    for_each(str.begin(), str.end(), [] (char & c) {if(isalpha(c)){c=tolower(c);}});

    return str;
}

string toLowerCase(string str)
{
    transform(str.begin(), str.end(), str.begin(), [] (char & c) {return tolower(c);});

    return str;
}