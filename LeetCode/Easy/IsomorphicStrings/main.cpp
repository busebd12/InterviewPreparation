#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;

/*
 * Approach:
 * Use to hash tables that keep track of the frequency and indices where each letter appears
 * in the strings s and t. Then, for each letter in s, check if there exists a letter in t
 * that appears the same number of times and has the same indices.
 *
 * Time complexity: O(n + m) [where n is the length of s and m is the length of t]
 * Space complexity: O(n + m)
 */

bool canFindReplacement(unordered_map<char, pair<int, vector<int>>> & m, int & frequency, vector<int> & indices)
{
    for(const auto & element : m)
    {
        if(element.second.first==frequency && element.second.second==indices)
        {
            return true;
        }
    }

    return false;
}

void populateMap(unordered_map<char, pair<int, vector<int>>> & m, string str, int size)
{
    for(int index=0;index<size;++index)
    {
        char c=str[index];

        if(m.count(c))
        {
            m[c].second.push_back(index);
        }
        else
        {
            pair<int, vector<int>> innerPair(0, vector<int>());

            m.insert(make_pair(c, innerPair));

            m[c].second.push_back(index);
        }
    }
}

bool isIsomorphic(string s, string t)
{
    if(s.empty() && t.empty())
    {
        return true;
    }

    if(s.empty() && !t.empty())
    {
        return false;
    }

    if(!s.empty() && t.empty())
    {
        return false;
    }

    if(s.size()!=t.size())
    {
        return false;
    }

    unordered_map<char, pair<int, vector<int>>> sMap;

    int n=int(s.size());

    unordered_map<char, pair<int, vector<int>>> tMap;

    int m=int(t.size());

    populateMap(sMap, s, n);

    populateMap(tMap, t, m);

    for(char c : s)
    {
        if(!canFindReplacement(tMap, sMap[c].first, sMap[c].second))
        {
            return false;
        }
    }

    return true;
}