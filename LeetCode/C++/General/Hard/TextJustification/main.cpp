#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

class Solution
{
    public:
        vector<string> fullJustify(vector<string> & words, int maxWidth)
        {
            vector<string> result;

            deque<string> queue;

            for(string word : words)
            {
                queue.push_back(word);
            }

            while(!queue.empty())
            {
                deque<string> wordsInSentence;

                int lineLength=0;

                int totalLetters=0;

                while(!queue.empty() and lineLength <= maxWidth)
                {
                    if(lineLength + queue.front().size() + 1 <= maxWidth)
                    {
                        wordsInSentence.push_back(queue.front());

                        lineLength+=queue.front().size() + 1;

                        totalLetters+=queue.front().size();

                        queue.pop_front();
                    }
                    else if(lineLength + queue.front().size() <= maxWidth)
                    {
                        wordsInSentence.push_back(queue.front());

                        lineLength+=queue.front().size();

                        totalLetters+=queue.front().size();

                        queue.pop_front();
                    }
                    else
                    {
                        break;
                    }
                }

                string line="";

                if(queue.empty())
                {
                    line=createLastLine(wordsInSentence, maxWidth, totalLetters);
                }
                else
                {
                    line=createLine(wordsInSentence, maxWidth, totalLetters);
                }

                result.push_back(line);
            }

            return result;
        }

        string createLine(deque<string> & wordsInSentence, int maxWidth, int totalLetters)
        {
            string line="";

            int spaces=maxWidth - totalLetters;

            int spotsForSpaces=wordsInSentence.size() - 1;

            if(spotsForSpaces==0)
            {
                spotsForSpaces=1;
            }

            int minimumSpaces=spaces / spotsForSpaces;

            int leftover=spaces % spotsForSpaces;

            vector<int> buckets(spotsForSpaces, minimumSpaces);

            while(leftover > 0)
            {
                for(int i=0;i<spotsForSpaces and leftover>0;i++)
                {
                    buckets[i]+=1;

                    leftover-=1;
                }
            }

            int bucketsIndex=0;

            while(!wordsInSentence.empty())
            {
                line.append(wordsInSentence.front());

                wordsInSentence.pop_front();

                if(bucketsIndex < spotsForSpaces)
                {
                    for(int count=0;count<buckets[bucketsIndex];count++)
                    {
                        line.push_back(' ');
                    }

                    bucketsIndex+=1;
                }
            }

            return line;
        }

        string createLastLine(deque<string> & wordsInSentence, int maxWidth, int totalLetters)
        {
            string line="";

            int spaces=maxWidth - totalLetters;

            while(!wordsInSentence.empty())
            {
                line.append(wordsInSentence.front());

                wordsInSentence.pop_front();

                if(spaces > 0)
                {
                    line.push_back(' ');

                    spaces-=1;
                }
            }

            while(spaces > 0)
            {
                line.push_back(' ');

                spaces-=1;
            }

            return line;
        }
};