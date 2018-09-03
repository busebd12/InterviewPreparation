#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    vector<string> subsequences;

    if(s.empty())
    {
        return subsequences;
    }

    int subsequenceLength=10;

    size_t stringSize=s.size();

    if(stringSize <= subsequenceLength)
    {
        return subsequences;
    }

    unordered_map<string, int> subsequencesCount;

    string subsequence{};

    for(int i=0;i<stringSize;++i)
    {
        subsequence+=s[i];

        if(i+subsequenceLength-1 <= stringSize-1)
        {
            for(int j=i+1;j<subsequenceLength+i;++j)
            {
                subsequence+=s[j];
            }
        }

        if(subsequence.size()==subsequenceLength)
        {
            subsequencesCount[subsequence]++;
        }

        subsequence.clear();
    }

    for(const auto & element : subsequencesCount)
    {
        if(element.second > 1)
        {
            subsequences.emplace_back(element.first);
        }
    }

    return subsequences;
}