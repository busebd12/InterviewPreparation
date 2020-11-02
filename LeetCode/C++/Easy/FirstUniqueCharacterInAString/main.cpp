#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <cmath>
using namespace std;

/*
 * Approaches:
 *
 * 1) Using an unordered_map as a hashtable, map each character to the first index at which we discover it and
 * the number of times it appears in the string. Then, loop over the hashtable and determine which index to return
 * based on which letter that only appears once has the earliest index in the string.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 * 2) Same logic as the first solution, just using a vector of pairs to simulate the hashtable.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

int firstUniqChar(string s)
{
    if(s.empty())
    {
        return -1;
    }

    int n=int(s.size());

    unordered_map<char, pair<int, int>> hashtable;

    for(int i=0;i<n;++i)
    {
        if(!hashtable.count(s[i]))
        {
            hashtable.insert(make_pair(s[i], make_pair(1, i)));
        }
        else
        {
            hashtable[s[i]].first++;
        }
    }

    int result=-1;

    for(const auto & element : hashtable)
    {
        if(element.second.first==1)
        {
            if(result==-1)
            {
                result=element.second.second;
            }
            else
            {
                result=min(result, element.second.second);
            }
        }
    }

    return result;
}

int firstUniqChar(string s)
{
    if(s.empty())
    {
        return -1;
    }

    int n=int(s.size());

    vector<pair<int, int>> hashtable(26, pair<int, int>(-1, 0));

    for(int i=0;i<n;++i)
    {
        if(hashtable[s[i] - 'a'].first==-1)
        {
            hashtable[s[i] - 'a'].first=i;

            hashtable[s[i] - 'a'].second=1;
        }
        else
        {
            hashtable[s[i] - 'a'].second++;
        }
    }

    int result=-1;

    for(const pair<int, int> & p : hashtable)
    {
        if(p.second==1)
        {
            if(result==-1)
            {
                result=p.first;
            }
            else
            {
                result=min(result, p.first);
            }
        }
    }

    return result;
}