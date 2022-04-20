#include <limits>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: see comments
*/

class WordDistance
{
    public:

        //Hashtable used to map each word to all the indices within wordsDict at which it appears
        unordered_map<string, vector<int>> hashtable;
    
        WordDistance(vector<string> & wordsDict)
        {
            int n=wordsDict.size();
            
            //Iterate through wordsDict
            for(int i=0;i<n;i++)
            {
                string word=wordsDict[i];
                
                //Map each word to all the indices at which it appears in wordsDict
                hashtable[word].emplace_back(i);
            }
        }

        int shortest(string word1, string word2)
        {
            int result=numeric_limits<int>::max();
            
            auto word1Indices=hashtable[word1];
            
            auto word2Indices=hashtable[word2];
            
            for(auto i : word2Indices)
            {
                for(auto j : word1Indices)
                {
                    result=min(result, abs(i - j));
                }
            }
            
            return result;
        }
};