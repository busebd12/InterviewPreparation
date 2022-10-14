#include <algorithm>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
    public:
        string longestWord(vector<string> & words)
        {
            string result="";
            
            int maxLength=0;
            
            sort(begin(words), end(words));
            
            unordered_set<string_view> dictionary;
            
            for(const string & word : words)
            {
                string_view view=word;
                
                dictionary.insert(view);
            }
            
            for(string & word : words)
            {
                string_view wordView=word;
                
                if(canBeFormed(dictionary, wordView)==true)
                {
                    if(maxLength==0 or maxLength < word.size())
                    {
                        maxLength=word.size();
                        
                        result=word;
                    }
                }
            }
            
            return result;
        }
    
        bool canBeFormed(unordered_set<string_view> & dictionary, string_view & wordView)
        {
            int w=wordView.size();
            
            for(int prefixLength=1;prefixLength<=w;prefixLength++)
            {
                string_view prefix=wordView.substr(0, prefixLength);
                
                if(dictionary.find(prefix)==end(dictionary))
                {
                    return false;
                }
            }
            
            return true;
        }
};