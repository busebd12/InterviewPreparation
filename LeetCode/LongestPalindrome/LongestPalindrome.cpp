#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int longestPalindrome(string s)
{
    if(s.empty())
    {
        return 0;
    }

    unordered_map<char, int> letterMap;

    for(const auto & letter : s)
    {   
        letterMap[letter]++;
    }

    int answer=0;

    bool odd=false;

    for(auto itr=begin(letterMap);itr!=end(letterMap);++itr)
    {
        if((itr->second % 2)==0)
        {
            answer+=(itr->second);
        }
        else
        {
            odd=true;

            answer+=(itr->second)-1;
        }
    }

    if(odd)
    {
        ++answer;
    }

    return answer;
}