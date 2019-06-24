#include <iostream>
#include <string>
#include <vector>
using namespace std;

string findLongestWord(string s, vector<string>& d)
{
    string answer{};

    for(string & word : d)
    {
        int n=int(s.size());

        int m=int(word.size());

        int i=0;

        int j=0;

        while(i < n && j < m)
        {
            if(s[i]==word[j])
            {
                j++;
            }

            i++;
        }

        if(j==m && ((answer.size()==m && word < answer) || answer.size() < m))
        {
            answer=word;
        }
    }

    return answer;
}