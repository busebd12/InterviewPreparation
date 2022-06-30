#include <cctype>
#include <deque>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Solution: inspired by the following posts

1. https://leetcode.com/problems/synonymous-sentences/discuss/1787368/Javascript-using-queue-and-set

2. https://leetcode.com/problems/synonymous-sentences/discuss/1198968/Simple-10-lines-BFS-or-JAVA
*/

class Solution
{
    public:
        vector<string> generateSentences(vector<vector<string>> & synonyms, string text)
        {
            vector<string> result;
            
            unordered_map<string, vector<string>> graph=createGraph(synonyms);

            set<string> sentences;

            deque<string> queue;

            queue.push_back(text);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    string sentence=queue.front();

                    sentences.insert(sentence);

                    queue.pop_front();
                    
                    vector<string> words=splitSentence(sentence);
                    
                    int w=words.size();
                    
                    for(int index=0;index<w;index++)
                    {
                        if(graph.find(words[index])!=end(graph))
                        {
                            for(string & synonym : graph[words[index]])
                            {
                                words[index]=synonym;
                                
                                string next=joinWords(words);
                                
                                if(sentences.find(next)==end(sentences))
                                {
                                    queue.push_back(next);
                                }
                            }
                        }
                    }
                }
            }

            for(string sentence : sentences)
            {
                result.push_back(sentence);
            }
            
            return result;
        }
    
        unordered_map<string, vector<string>> createGraph(vector<vector<string>> & synonyms)
        {
            unordered_map<string, vector<string>> graph;
            
            for(vector<string> synonym : synonyms)
            {
                string s=synonym[0];
                
                string t=synonym[1];
                
                if(graph.find(s)==end(graph))
                {
                    graph.emplace(s, vector<string>());
                }
                
                if(graph.find(t)==end(graph))
                {
                    graph.emplace(t, vector<string>());
                }
                
                graph[s].push_back(t);
                
                graph[t].push_back(s);
            }
            
            return graph;
        }
    
        vector<string> splitSentence(string & sentence)
        {
            vector<string> words;
            
            int s=sentence.size();
            
            string word{};
            
            int i=0;
            
            while(i < s)
            {
                while(i < s && isalpha(sentence[i]))
                {
                    word.push_back(sentence[i]);
                    
                    i+=1;
                }
                
                words.push_back(word);
                
                word.clear();
                
                while(i < s && isspace(sentence[i]))
                {
                    i+=1;
                }
            }
            
            return words;
        }
    
        string joinWords(vector<string> & words)
        {
            string next="";
            
            int w=words.size();
            
            for(int i=0;i<w;i++)
            {
                next.append(words[i]);
                
                if(i < w - 1)
                {
                    next.append(" ");
                }
            }
            
            return next;
        }
};