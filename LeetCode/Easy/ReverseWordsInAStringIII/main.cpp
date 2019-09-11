#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

/*
 * Approaches:
 *
 * 1) Use two-pointers, i and j, to loop over the string. We start i and j at zero
 * and increment j till we are at a character right before a space. We then reverse
 * the substring from i up to and including j. Then move i and j to point to the next
 * character after the space, and repeat the process till we reach the end of the string.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 * 2) Use the stringstream class provided by the STL to tokenize the string by spaces and
 * reverse each individual word in the string.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

void reverseHelper(string & s, int start, int end)
{
    while(start <= end)
    {
        swap(s[start], s[end]);

        start++;

        end--;
    }
}

string reverseWords(string s)
{
    if(s.empty())
    {
        return s;
    }

    int n=int(s.size());

    int i=0;

    int j=0;

    while(j < n)
    {
        if(j+1 < n)
        {
            while(!isspace(s[j+1]) && j+1 < n)
            {
                j++;
            }

            reverseHelper(s, i, j);

            j++;

            while(isspace(s[j]))
            {
                j++;
            }

            while(i < j)
            {
                i++;
            }
        }
        else
        {
            break;
        }
    }

    return s;
}

string reverseWords(string s)
{
    if(s.empty())
    {
        return s;
    }

    istringstream iss(s);

    s.clear();

    string line{};

    while(iss >> line)
    {
        reverse(line.begin(), line.end());

        s+=line;

        s+=' ';
    }

    s.pop_back();

    return s;
}