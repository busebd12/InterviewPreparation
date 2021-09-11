#include <deque>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
 * Approach: we generate all prefixes for str1 and str2 and find the largest prefix that divides both strings.
 *
 * Time complexity: O(min(n, m) * (n + m)) [where n is the length of str1 and m is the length of str2]
 * Space complexity: O(m + n)
 */

bool prefixDividesStrings(const string & str1, const string & str2, const string & prefix)
{
    string s{};

    bool dividesStr1=false;

    while(s.size() <= str1.size())
    {
        if(s==str1)
        {
            dividesStr1=true;

            break;
        }

        s+=prefix;
    }

    bool dividesStr2=false;

    s.clear();

    while(s.size() <= str2.size())
    {
        if(s==str2)
        {
            dividesStr2=true;

            break;
        }

        s+=prefix;
    }

    return dividesStr1 && dividesStr2;
}

string gcdOfStrings(string str1, string str2)
{
    string result{};

    if(str1.empty() && str2.empty())
    {
        return result;
    }

    if(str1.empty())
    {
        return str2;
    }

    if(str2.empty())
    {
        return str1;
    }

    auto n=str1.size();

    auto m=str2.size();

    for(auto i=1;i<=min(n, m);++i)
    {
        string str1Prefix{};

        string str2Prefix{};

        for(auto j=0;j<i;++j)
        {
            str1Prefix+=str1[j];

            str2Prefix+=str2[j];
        }

        bool str1PrefixValid=prefixDividesStrings(str1, str2, str1Prefix);

        bool str2PrefixValid=prefixDividesStrings(str1, str2, str2Prefix);

        if(str1PrefixValid && str2PrefixValid)
        {
            if(result.empty() || str1Prefix.size() > result.size())
            {
                result=str1Prefix;
            }
        }
    }

    return result;
}