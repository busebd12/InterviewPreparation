#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

/*
 * Approaches:
 *
 * 1) While we loop over the string, keep track of the starting and ending positions of groups of repeating characters.
 * After we reach the end of the repeating group of characters, if the length is greater than or equal to the length
 * which qualifies as a large group, then add the starting and ending indices to our result list (vector<vector<int>> result).
 * Return our result list.
 *
 * Time complexity: O(n) [where n is the length of the input string, S]
 * Space complexity: O(1)
 *
 * 2) Same logic as the first solution just using more explicit vector initialization when we are inserting our
 * vectors containing the starting and ending indices of large group of repeating characters.
 *
 * Time complexity: O(n) [where n is the length of the input string, S]
 * Space complexity: O(1)
 */

vector<vector<int>> largeGroupPositions(string S)
{
    vector<vector<int>> result;

    if(S.empty())
    {
        return result;
    }

    int n=int(S.size());

    int groupSize=3;

    for(int index=0;index<n;)
    {
        char current=S[index];

        pair<int, int> startAndEnd(index, -1);

        while(S[index]==current)
        {
            startAndEnd.second=index;

            index++;
        }

        if((startAndEnd.second - startAndEnd.first) + 1 >= groupSize)
        {
            result.push_back({{startAndEnd.first, startAndEnd.second}});
        }
    }

    return result;
}

vector<vector<int>> largeGroupPositions(string S)
{
    vector<vector<int>> result;

    if(S.empty())
    {
        return result;
    }

    int n=int(S.size());

    int groupSize=3;

    for(int index=0;index<n;)
    {
        char current=S[index];

        pair<int, int> startAndEnd(index, -1);

        while(S[index]==current)
        {
            startAndEnd.second=index;

            index++;
        }

        if((startAndEnd.second - startAndEnd.first) + 1 >= groupSize)
        {
            vector<int> v(2, 0);

            v[0]=startAndEnd.first;

            v[1]=startAndEnd.second;

            result.push_back(v);
        }
    }

    return result;
}