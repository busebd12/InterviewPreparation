#include <deque>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;


class Solution
{
    public:
        int ladderLength(string beginWord, string endWord, vector<string> & wordList)
        {
            int result=1;
            
            unordered_set<string> dictionary;
            
            for(string & word : wordList)
            {
                dictionary.insert(word);
            }
            
            unordered_set<string> visited;
            
            visited.insert(beginWord);
            
            deque<string> queue;
            
            queue.push_back(beginWord);
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    string word=queue.front();
                    
                    queue.pop_front();
                    
                    if(word==endWord)
                    {
                        return result;
                    }
                    
                    int w=word.size();
                    
                    for(int i=0;i<w;i++)
                    {
                        char current=word[i];
                        
                        for(char replacement='a';replacement<='z';replacement++)
                        {
                            if(replacement!=current)
                            {
                                word[i]=replacement;
                                
                                if(dictionary.find(word)!=end(dictionary) and visited.find(word)==end(visited))
                                {
                                    visited.insert(word);
                                    
                                    queue.push_back(word);
                                }
                            }
                        }
                        
                        word[i]=current;
                    }
                }
                
                result+=1;
            }
            
            return 0;
        }
};