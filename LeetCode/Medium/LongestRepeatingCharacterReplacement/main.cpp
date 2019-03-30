#include <iostream>
#include <vector>
#include <string>
using namespace std;

int characterReplacement(string s, int k)
{
    int n=int(s.size());

    int result=0;

    vector<int> frequencies(26, 0);

    int start=0;

    int end=0;

    int localMaxFrequency=0;

    for(;end<n;++end)
    {
        frequencies[s[end]-'A']++;

        localMaxFrequency=max(localMaxFrequency, frequencies[s[end]-'A']);

        if((end-start+1)-localMaxFrequency > k)
        {
            result=max(result, (end-start));

            frequencies[s[start]-'A']--;

            start++;

            localMaxFrequency=*(max_element(frequencies.begin(), frequencies.end()));
        }
    }

    return max(result, (end-start));
}