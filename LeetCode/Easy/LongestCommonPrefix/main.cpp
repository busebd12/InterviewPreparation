#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Approach:
 * Find the shortest length string.
 * Then, loop over the shortest string, adding characters to the common prefix as we go,
 * until we find a character that is not shared by the other strings.
 *
 * Time Complexity: O(m * n) [where m is the length of the shortest string and n is the number of input strings]
 *
 * Space Complexity: O(1) [if we don't count the length of the resulting longest common prefix]
 */

bool isCommon(vector<string> & strs, char current, int index)
{
    for(string & str : strs)
    {
        if(str[index]!=current)
        {
            return false;
        }
    }

    return true;
}

string longestCommonPrefix(vector<string> & strs)
{
    if(strs.empty())
    {
        return "";
    }

    if(strs.size()==1)
    {
        return strs[0];
    }

    string result="";

    string prefix="";

    int shortestLength=numeric_limits<int>::max();

    for(string & s : strs)
    {
        if(int(s.size()) <= shortestLength)
        {
            shortestLength=int(s.size());
        }
    }

    string shortest="";

    for(string & s : strs)
    {
        if(int(s.size())==shortestLength)
        {
            shortest=s;

            break;
        }
    }

    for(int i=0;i<shortestLength;++i)
    {
        char current=shortest[i];

        if(isCommon(strs, current, i))
        {
            prefix+=current;
        }
        else
        {
            result=prefix;

            prefix.clear();

            break;
        }
    }

    if(result.empty() && prefix.size() > 0)
    {
        result=prefix;
    }

    return result;
}