#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> getSubstrings(string & s)
{
    int n=int(s.length());

    vector<string> substrings;

    for(int i=0;i<n;++i)
    {
        int maxSubstringLength=n-i;

        for(int substringLength=0;substringLength<=maxSubstringLength;++substringLength)
        {
            string substring{};

            for(int j=i,k=0;k<substringLength && j<n;++j,++k)
            {
                substring+=s[j];
            }

            if(!substring.empty())
            {
                substrings.emplace_back(substring);
            }
        }
    }

    return substrings;
}

int longestSubstringBruteForce(string s, int k)
{
    int result=0;

    string resultSubstring{};

    if(s.empty() || k==0)
    {
        return result;
    }

    auto substrings=getSubstrings(s);

    for(auto & substring : substrings)
    {
        unordered_map<char, int> occurrences;

        for(auto & letter : substring)
        {
            occurrences[letter]++;
        }

        bool valid=true;

        for(auto & element : occurrences)
        {
            if(element.second < k)
            {
                valid=false;

                 break;
            }
        }

        if(valid)
        {
            if(substring.length() > result)
            {
                result=int(substring.length());

                resultSubstring=substring;
            }
        }
    }

    return result;
}

int longestSubstring(string & s, int & k)
{
    if(s.length()==0)
    {
        return 0;
    }

    vector<int> counts(26, 0);

    for(auto & letter : s)
    {
        counts[letter-'a']++;
    }

    vector<string> substrings;

    int splitPoint=-1;

    for(int i=0;i<s.length();++i)
    {
        if(counts[s[i]-'a'] < k)
        {
            substrings.push_back(s.substr(splitPoint+1, i-splitPoint-1));

            splitPoint=i;
        }
    }

    if(substrings.size()==0)
    {
        return s.length();
    }

    substrings.emplace_back(s.substr(splitPoint+1, s.length()-splitPoint));

    int answer=0;

    for(auto & substring : substrings)
    {
        answer=max(answer, longestSubstring(substring, k));
    }

    return answer;
}