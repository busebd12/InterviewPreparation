#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool inDictionary(vector<string> & wordDict, string word)
{
    for(const auto & element : wordDict)
    {
        if(element==word)
        {
            return true;
        }
    }

    return false;
}

bool helper(string s, vector<string> & wordDict)
{
    if(s.empty())
    {
        return true;
    }

    for(int i=0;i<s.size();++i)
    {
        string substring=s.substr(0, i+1);

        if(inDictionary(wordDict, substring))
        {
            if(helper(s.substr(i+1), wordDict))
            {
                return true;
            }
        }
    }

    return false;
}

bool wordBreak(string s, vector<string> & wordDict)
{
    int n=s.length();

    if(wordDict.size()==0)
    {
        return false;
    }

    vector<int> found;

    for(int i=0;i<n;i++)
    {
        string temp=s.substr(0,i+1);

        if(inDictionary(wordDict, temp))
        {
            found.push_back(i);

            continue;
        }

        int sz=found.size();

        for(int j=sz-1;j>=0;j--)
        {
            string temp1=s.substr(found[j]+1,i-found[j]);

            if(inDictionary(wordDict, temp1))
            {
                found.push_back(i);

                break;
            }
        }

    }
    int sz=found.size();

    bool result;

    if(sz!=0 && found[sz-1]==n-1)
    {
        result=true;
    }
    else
    {
        result=false;
    }

    return result;
}