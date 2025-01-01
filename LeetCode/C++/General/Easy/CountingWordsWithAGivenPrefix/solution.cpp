#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
        int prefixCount(vector<string> & words, string pref)
        {
            int result=0;

            for(string & word : words)
            {
                if(startsWith(word, pref)==true)
                {
                    result+=1;
                }
            }

            return result;
        }

        bool startsWith(string & word, string & prefix)
        {
            int w=word.size();

            int p=prefix.size();

            if(w < p)
            {
                return false;
            }

            int i=0;

            for(;i<min(w, p);i++)
            {
                if(word[i]!=prefix[i])
                {
                    return false;
                }
            }

            return i==p;
        }
};