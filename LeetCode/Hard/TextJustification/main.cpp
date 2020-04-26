#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

/*
 * Solutions:
 *
 * 1. We put all the words into a queue. Then, while the queue is not empty, we place all the words that can fit
 * on the next line we want to build into a deque. Next, we use the buildLine function to build the correct
 * space separated line. We then place the built string into the result vector.
 *
 * Time complexity: O(w^2) [where w is the number of words in the input vector]
 * Space complexity: O(w)
 *
 * 2. Similar approach as the first solution except that we don't use the queue to store all the words.
 * We just iterate through the vector of the words.
 *
 * Time complexity: O(w^2)
 * Space complexity: O(w)
 */

std::string buildLine(std::deque<std::string> & dq, int & maxWidth, int & nonSpaceCharacters, bool & lastLine)
{
    std::string line{};

    int spaces=maxWidth - nonSpaceCharacters;

    int spotsForSpaces=static_cast<int>(dq.size()) - 1;

    std::vector<int> buckets;

    if(lastLine)
    {
        buckets.resize(spotsForSpaces, 1);
    }
    else
    {
        if(spotsForSpaces==0)
        {
            buckets.resize(1, spaces);
        }
        else
        {
            buckets.resize(spotsForSpaces, 0);

            int count=0;

            while(count < spaces)
            {
                for(auto i=0;i<spotsForSpaces;++i)
                {
                    if(count < spaces)
                    {
                        buckets[i]++;

                        count++;
                    }
                }
            }
        }
    }

    int bucketsSize=static_cast<int>(buckets.size());

    int index=0;

    while(!dq.empty())
    {
        auto str=dq.front();

        dq.pop_front();

        line+=str;

        if(index < bucketsSize)
        {
            std::string extraSpaces(buckets[index], ' ');

            line+=extraSpaces;

            spaces-=buckets[index];
        }

        index++;
    }

    if(lastLine)
    {
        while(spaces > 0)
        {
            line+=' ';

            spaces--;
        }
    }

    return line;
}

std::vector<std::string> fullJustify(std::vector<std::string> & words, int maxWidth)
{
    std::vector<std::string> result{};

    if(words.empty() || maxWidth <= 0)
    {
        return result;
    }

    std::queue<std::string> Q;

    for(const auto & word : words)
    {
        Q.emplace(word);
    }

    while(!Q.empty())
    {
        std::deque<std::string> dq;

        int count=0;

        int nonSpaceCharacters=0;

        bool lastLine=false;

        while(!Q.empty())
        {
            int length=static_cast<int>(Q.front().size());

            if(length + count <= maxWidth)
            {
                dq.emplace_back(Q.front());

                Q.pop();

                nonSpaceCharacters+=length;

                count+=length;

                if(count + 1 <= maxWidth)
                {
                    count+=1;
                }
            }
            else
            {
                break;
            }
        }

        if(Q.empty())
        {
            lastLine=true;
        }

        std::string subproblem=buildLine(dq, maxWidth, nonSpaceCharacters, lastLine); //O(w)

        result.emplace_back(subproblem);

        dq.clear();
    }

    return result;
}

std::vector<std::string> fullJustify(std::vector<std::string> & words, int maxWidth)
{
    std::vector<std::string> result{};

    if(words.empty() || maxWidth <= 0)
    {
        return result;
    }

    int count=0;

    int nonSpaceCharacters=0;

    bool lastLine=false;

    std::deque<std::string> dq;

    auto n=int(words.size());

    for(auto index=0;index<n;)
    {
        std::string word=words[index];

        int length=static_cast<int>(word.size());

        if(length + count <= maxWidth)
        {
            dq.emplace_back(word);

            nonSpaceCharacters+=length;

            count+=length;

            if(count + 1 <= maxWidth)
            {
                count+=1;
            }

            index++;
        }
        else
        {
            std::string subproblem=buildLine(dq, maxWidth, nonSpaceCharacters, lastLine);

            result.emplace_back(subproblem);

            dq.clear();

            count=0;

            nonSpaceCharacters=0;
        }
    }

    if(!dq.empty())
    {
        lastLine=true;

        std::string last=buildLine(dq, maxWidth, nonSpaceCharacters, lastLine);

        result.emplace_back(last);
    }

    return result;
}