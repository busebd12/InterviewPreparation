#include <string>
using namespace std;

class Solution
{
    public:
        string mergeAlternately(string word1, string word2)
        {
            string result="";

            int n=word1.size();

            int m=word2.size();

            int i=0;

            int j=0;

            while(i < n or j < m)
            {
                if(i < n)
                {
                    result.push_back(word1[i]);

                    i+=1;
                }

                if(j < m)
                {
                    result.push_back(word2[j]);

                    j+=1;
                }
            }

            return result;
        }
};