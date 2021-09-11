#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isAnagram(string s, string t)
{
    if(s.size()!=t.size())
    {
        return false;
    }

    unordered_map<char, int> counts;

    const size_t sSize=s.size();

    for(int index=0;index<sSize;++index)
    {
        counts[s[index]]++;

        counts[t[index]]--;
    }

    for(const auto & count : counts)
    {
        if(count.second!=0)
        {
            return false;
        }
    }

    return true;
}

vector<int> findAnagrams(string s, string p)
{
    vector<int> indices;

    if(s.empty() && p.empty())
    {
        return indices;
    }
    
    if(s.empty() && !p.empty())
    {
        return indices;
    }

    if(!s.empty() && p.empty())
    {
        return indices;
    }

    if(s.size() < p.size())
    {
        return indices;
    }

    const size_t pSize=p.size();

    const size_t sSize=s.size();

    for(int index=0;index<(sSize-pSize)+1;++index)
    {
        string candidate(s.substr(index, pSize));

        if(isAnagram(p, candidate))
        {
            indices.emplace_back(index);
        }
    }

    return indices;
}