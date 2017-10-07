#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s)
{
    if(s.empty())
    {
        return -1;
    }

    const size_t stringSize=s.size();

    unordered_map<char, pair<int, int>> letterMap;

    for(int index=0;index<stringSize;++index)
    {
        char letter=s[index];

        if(letterMap.find(letter)==end(letterMap))
        {
            letterMap.insert(make_pair(letter, make_pair(1, index)));
        }
        else
        {
            letterMap[letter].first++;
        }
    }

    int answer=-1;

    for(const auto & element : letterMap)
    {
        int appearances=element.second.first;

        if(appearances==1)
        {
            int index=element.second.second;

            if(answer==-1)
            {
                answer=index;
            }
            else
            {
                if(index < answer)
                {
                    answer=index;
                }
            }
        }
    }

    return answer;
}