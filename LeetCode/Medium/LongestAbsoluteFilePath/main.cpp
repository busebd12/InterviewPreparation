#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

int lengthLongestPath(string & input)
{
    int maxLength=0;

    int count=0;

    int level=1;

    bool isFile=false;

    unordered_map<int, int> levels;

    levels.insert(make_pair(0, 0));

    int i=0;

    int length=int(input.size());

    while(i < length)
    {
        while(input[i]=='\t')
        {
            ++level;

            ++i;
        }

        while(i < length && input[i]!='\n')
        {
            if(input[i]=='.')
            {
                isFile=true;
            }

            ++count;

            ++i;
        }

        if(isFile)
        {
            maxLength=max(maxLength, levels[level-1] + count);
        }
        else
        {
            levels.insert(make_pair(level, levels[level-1] + count + 1));
        }

        count=0;

        level=1;

        isFile=false;

        ++i;
    }

    return maxLength;
}