#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

string frequencySort(string s)
{
    if(s.empty())
    {
        return s;
    }

    unordered_map<char, int> frequencies;

    for(auto & letter : s)
    {
        frequencies[letter]++;
    }

    multimap<int, char> sortedFrequencies;

    for(auto & element : frequencies)
    {
        sortedFrequencies.insert(make_pair(element.second, element.first));
    }

    s.clear();

    for(auto itr=sortedFrequencies.rbegin();itr!=sortedFrequencies.rend();++itr)
    {
        int frequency=itr->first;

        for(int count=0;count<frequency;++count)
        {
            s+=itr->second;
        }
    }

    return s;
}