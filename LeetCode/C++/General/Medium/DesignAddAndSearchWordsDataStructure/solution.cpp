#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class WordDictionary
{
    private:
        //Use word length to index the vector
        //So, all words of length 3 will be stored in an unordered_set<string at index 3 in the vector
        vector<unordered_set<string>> wordSets;
        
        //Map strings to search result (true or false)
        unordered_map<string, bool> cache;
    
    public:
        WordDictionary()
        {
            //Since the maximum word length will be 25
            wordSets.resize(26);
        }

        void addWord(string word) //Time complexity: O(1) Space complexity: O(n) [where n is the total number of words]
        {
            //Clear the cache just so that previously cached search results don't mess things up
            cache.clear();
            
            wordSets[word.size()].insert(word);
        }

        bool search(string word) //O(w) [where w is the length of the word]
        {
            bool result=false;
            
            if(cache.count(word)==true)
            {
                return cache[word];
            }
            
            int length=word.length();
            
            if(word.find('.')==string::npos)
            {
                if(wordSets[length].count(word)==true)
                {
                    result=true;
                }
            }
            else
            {
                for(string w : wordSets[length])
                {
                    bool found=true;
                    
                    for(int i=0;i<length;i++)
                    {
                        char c=word[i];
                        
                        if(c=='.')
                        {
                            continue;
                        }
                        else
                        {
                            if(w[i]!=c)
                            {
                                found=false;
                                
                                break;
                            }
                        }
                    }
                    
                    if(found==true)
                    {
                        result=true;
                        
                        break;
                    }
                }
            }
            
            cache[word]=result;
            
            return result;
        }
};