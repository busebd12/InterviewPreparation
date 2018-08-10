#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> wordList)
{
    int length=1;

    if(find(begin(wordList), end(wordList), endWord)==end(wordList))
    {
        return 0;
    }

    if(beginWord.empty() || endWord.empty() || wordList.empty())
    {
        return length;
    }

    queue<string> Q;

    unordered_set<string> seen(begin(wordList), end(wordList));

    Q.emplace(beginWord);

    seen.erase(beginWord);

    while(!Q.empty())
    {
        int qSize=int(Q.size());

        ++length;

        for(int i=0;i<qSize;++i)
        {
            string current=Q.front();

            Q.pop();

            for(int j=0;j<current.length();++j)
            {
                char temp=current[j];

                for(char c='a';c<='z';++c)
                {
                    current[j]=c;

                    if(seen.find(current)!=end(seen))
                    {
                        if(current==endWord)
                        {
                            return length;
                        }

                        Q.push(current);

                        seen.erase(current);
                    }
                }

                current[j]=temp;
            }
        }
    }

    return 0;
}