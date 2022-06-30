#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: inspired from this post --> https://leetcode.com/problems/prefix-and-suffix-search/discuss/1185249/C%2B%2B-No-TRIE-A-HashMap-soln.
*/

class WordFilter
{
    private:
        unordered_map<string, int> hashtable;
    
    public:
        WordFilter(vector<string> & words)
        {
            populateHashtable(words);
        }

        int f(string prefix, string suffix)
        {   
            int result=-1;
            
            string key=prefix + "$" + suffix;
            
            if(hashtable.find(key)!=end(hashtable))
            {
                result=hashtable[key];
            }
            
            return result;
        }
    
        void populateHashtable(vector<string> & words)
        {
            int w=words.size();
            
            for(int i=0;i<w;i++)
            {
                string word=words[i];
                
                int wordLength=word.length();
                
                for(int prefixLength=1;prefixLength<=wordLength;prefixLength++)
                {
                    string prefix=word.substr(0, prefixLength);

                    for(int index=wordLength-1;index>=0;index--)
                    {
                        string suffix=&word[index];

                        string key=prefix + "$" + suffix;

                        hashtable[key]=i;
                    }
                }
            }
        }
};