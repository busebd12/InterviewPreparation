#include <deque>
#include <string>
using namespace std;

/*
Submission result: accepted.

Time complexity: O(n + (w * (L + spacesBetweenWords)) + spaces)
[where n=length of text; w=number of words; L=average length of a word; spaces=total spaces in text]

Space complexity: O(w)
*/

class Solution
{
    public:
        string reorderSpaces(string text)
        {
            string result="";

            int spaces=countSpaces(text); //O(n)

            deque<string> words=getWords(text); //O(n)

            int numWords=words.size();

            int spotsForSpaces=numWords - 1;

            int spacesBetweenWords=0;

            if(spotsForSpaces > 0)
            {
                spacesBetweenWords=spaces / spotsForSpaces;
            }

            while(!words.empty()) //O(w)
            {
                string word=words.front();

                words.pop_front();

                result.append(word); //O(L)

                if(!words.empty())
                {
                    for(int count=0;count<spacesBetweenWords;count++) //O(spacesBetweenWords)
                    {
                        result.push_back(' ');

                        spaces-=1;
                    }
                }
            }

            while(spaces > 0) //O(spaces)
            {
                result.push_back(' ');

                spaces-=1;
            }

            return result;
        }

        int countSpaces(string & text)
        {
            int spaces=0;

            int n=text.size();

            for(int i=0;i<n;i++)
            {
                if(isspace(text[i]))
                {
                    spaces+=1;
                }
            }

            return spaces;
        }

        deque<string> getWords(string & text)
        {
            deque<string> words;

            int n=text.size();

            for(int i=0;i<n;)
            {
                int j=i;

                while(j < n and isspace(text[j]))
                {
                    j+=1;
                }

                string word="";

                while(j < n and isalpha(text[j]))
                {
                    word.push_back(text[j]);

                    j+=1;
                }

                if(!word.empty())
                {
                    words.push_back(word);
                }

                i=j;
            }

            return words;
        }
};