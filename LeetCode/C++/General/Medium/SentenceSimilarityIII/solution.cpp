#include <deque>
#include <string>
using namespace std;

/*
Time complexity: O(n + m) [where n is the length of sentence1 and m is the length of sentence2]
Space complexity: O(n + m)
*/

class Solution
{
    public:
        bool areSentencesSimilar(string sentence1, string sentence2)
        {
            int n=sentence1.size();

            int m=sentence2.size();

            deque<string> sentence1Words=parseSentence(sentence1, n);

            deque<string> sentence2Words=parseSentence(sentence2, m);

            //Iterate through the words in both sentences starting from the front until we reach two words that differ or we've gone through all the words in one sentence
            while(!sentence1Words.empty() and !sentence2Words.empty())
            {
                if(sentence1Words.front()!=sentence2Words.front())
                {
                    break;
                }

                sentence1Words.pop_front();

                sentence2Words.pop_front();
            }

            //Iterate through the words from both sentences starting from the end until we reach two words that are not the same or we have gone through all the words in one of the sentences
            while(!sentence1Words.empty() and !sentence2Words.empty())
            {
                if(sentence1Words.back()!=sentence2Words.back())
                {
                    break;
                }

                sentence1Words.pop_back();

                sentence2Words.pop_back();
            }

            //If we have gone through all the words in one of the sentences, then the two sentences are similar
            return (sentence1Words.empty() or sentence2Words.empty());
        }

        deque<string> parseSentence(string & sentence, int length)
        {
            deque<string> words;

            for(int i=0;i<length;i++)
            {
                int j=i;

                string word="";

                while(j < length and !isspace(sentence[j]))
                {
                    word.push_back(sentence[j]);
                    
                    j+=1;
                }

                words.push_back(word);

                i=j;
            }

            return words;
        }
};