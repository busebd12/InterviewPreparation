#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

bool isAnagram(string first, string second)
{
    if(first.size()!=second.size())
    {
        return false;
    }

    unordered_map<char, int> counts;

    const int firstSize=int(first.size());

    for(int index=0;index<firstSize;++index)
    {
        counts[first[index]]++;

        counts[second[index]]--;
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

vector<vector<string>> groupAnagramsBruteForce(vector<string> & strs)
{
    vector<vector<string>> result;

    if(strs.empty())
    {
        return result;
    }

    const int strsSize=int(strs.size());

    vector<bool> used(strsSize, false);

    for(int i=0;i<strsSize;++i)
    {
        vector<string> v;

        if(!used[i])
        {
            v.emplace_back(strs[i]);

            used[i]=true;

            for(int j=0;j<strsSize;++j)
            {
                if(j!=i)
                {
                    if(isAnagram(strs[i], strs[j]))
                    {
                        if(!used[j])
                        {
                            v.emplace_back(strs[j]);

                            used[j]=true;
                        }
                    }
                }
            }

            result.emplace_back(v);
        }
    }

    return result;
}

vector<vector<string>> groupAnagrams(vector<string> & strs)
{
    vector<vector<string>> result;

    multimap<int, vector<int>> stringMap;

    if(strs.empty())
    {
        return result;
    }

    const int strsSize=int(strs.size());

    for(int index=0;index<strsSize;++index)
    {
        int asciiValue=0;

        for(int i=0;i<strs[index].size();++i)
        {
            asciiValue+=static_cast<int>(strs[index][i]);
        }

        if(stringMap.find(asciiValue)!=end(stringMap))
        {
            auto range=stringMap.equal_range(asciiValue);

            bool found=false;

            for(auto itr=range.first;itr!=range.second;++itr)
            {
                int spot=itr->second[0];

                if(isAnagram(strs[index], strs[spot]))
                {
                    found=true;

                    itr->second.emplace_back(index);

                    break;
                }
            }

            if(!found)
            {
                vector<int> v;

                v.emplace_back(index);

                stringMap.emplace(asciiValue, v);
            }
        }
        else
        {
            vector<int> v;

            v.emplace_back(index);

            stringMap.emplace(asciiValue, v);
        }
    }

    for(const auto & element : stringMap)
    {
        vector<string> v;

        for(const auto & index : element.second)
        {
            v.emplace_back(strs[index]);
        }

        result.emplace_back(v);
    }

    return result;
}