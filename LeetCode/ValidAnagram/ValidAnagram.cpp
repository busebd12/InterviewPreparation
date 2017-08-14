#include <iostream>
#include <unordered_map>
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