#include <iostream>
#include <string>
#include <unordered_set>
#include <cmath>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    if(s.empty())
    {
        return 0;
    }

    const size_t stringSize=s.size();

    int maxLength=0;

    unordered_set<char> cache;

    for(int current=0, ahead=0;ahead<stringSize;)
    {
        if(cache.find(s[ahead])==end(cache))
        {
            cache.insert(s[ahead++]);

            maxLength=max(maxLength, (int)cache.size());
        }
        else
        {   
            cache.erase(s[current++]);
        }
    }

    return maxLength;
}