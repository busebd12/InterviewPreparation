#include <string>
using namespace std;

/*
Time complexity: O(d * (min(n, w)))) [where d is the size of dictionary, n is length of s, and w is the average length of a word in the dictionary]
Space complexity: O(1)
*/

class Solution
{
    public:
        string findLongestWord(string s, vector<string> & dictionary)
        {
            string result="";

            for(string word : dictionary) //O(d)
            {
                if(canBeFormedByDeletion(s, word)==true) //O(min(n, w))
                {
                    if(word.size() > result.size())
                    {
                        result=word;
                    }
                    else if(word.size()==result.size())
                    {
                        if(word < result)
                        {
                            result=word;
                        }
                    }
                }
            }

            return result;
        }

        bool canBeFormedByDeletion(string & s, string & word)
        {
            int n=s.size();

            int w=word.size();

            int sIndex=0;

            int wordIndex=0;

            while(sIndex < n and wordIndex < w)
            {
                if(s[sIndex]==word[wordIndex])
                {
                    wordIndex+=1;
                }

                sIndex+=1;
            }

            return wordIndex==w;
        }
};