#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isSubsequence(string s, string t)
{
    int sLength=s.length();

    int tLength=t.length();

    int sIndex=0;

    for(int i=0;i<tLength && sIndex<sLength;++i)
    {
        if(t[i]==s[sIndex])
        {
            ++sLength;
        }
    }

    return sIndex==sLength;
}