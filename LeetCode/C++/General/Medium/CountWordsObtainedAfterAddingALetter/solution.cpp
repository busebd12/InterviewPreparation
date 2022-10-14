#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
    public:
        int wordCount(vector<string> & startWords, vector<string> & targetWords)
        {
            int result=0;
            
            unordered_set<string> sortedStartWords;
            
            for(string startWord : startWords)
            {
                sort(begin(startWord), end(startWord));
                
                sortedStartWords.insert(startWord);
            }
            
            for(string targetWord : targetWords)
            {
                int w=targetWord.size();
                
                sort(begin(targetWord), end(targetWord));
                
                for(int i=0;i<w;i++)
                {
                    char letter=targetWord[i];
                    
                    targetWord.erase(begin(targetWord) + i);
                    
                    if(sortedStartWords.find(targetWord)!=end(sortedStartWords))
                    {
                        result+=1;
                        
                        break;
                    }
                    
                    targetWord.insert(begin(targetWord) + i, letter);
                }
            }
            
            return result;
        }
};