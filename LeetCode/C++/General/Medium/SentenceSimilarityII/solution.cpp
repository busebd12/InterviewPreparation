#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution:

Time complexity: O(n * p) [where n=length of sentence1 and sentence2 and p=length of pairs]
Space complexity: O(p)
*/

class Solution
{
    public:
        bool areSentencesSimilarTwo(vector<string> & sentence1, vector<string> & sentence2, vector<vector<string>> & similarPairs)
        {
            int n=sentence1.size();

            int m=sentence2.size();

            if(n!=m)
            {
                return false;
            }

            //Map each word to all words that are similar to it
            unordered_map<string, vector<string>> graph;

            //Iterate through similar pairs
            for(vector<string> pair : similarPairs)
            {
                string u=pair[0];

                string v=pair[1];

                //Both words being similar means that pair[0] is similar to pair[1] and pair[1] is similar to pair[0]
                //In other words, both words being similar means there is a undirected edge between the two words in our graph
                graph[u].push_back(v);

                graph[v].push_back(u);
            }

            for(int i=0;i<n;i++)
            {
                string sentence1Word=sentence1[i];

                string sentence2Word=sentence2[i];

                //If the two words are not already the same, we need to know if we can transform the word from sentence1 into the word from sentence2
                //using the similarity relationships defined by similarPairs
                //In other words, we need to see if there is a path from sentence1Word to sentence2Word in our graph
                if(sentence1Word!=sentence2Word)
                {
                    //Use depth-first search to look for a path
                    //If we can't find a path, then it is not possible to transform sentence1Word into sentence2Word and the two sentence are not similar
                    if(canTransform(graph, sentence1Word, sentence2Word)==false)
                    {
                        return false;
                    }
                }
            }

            return true;
        }

        bool canTransform(unordered_map<string, vector<string>> & graph, string & source, string & destination)
        {
            deque<string> stack;

            unordered_set<string> seen;

            stack.push_back(source);

            while(!stack.empty())
            {
                string word=stack.back();

                stack.pop_back();

                if(word==destination)
                {
                    return true;
                }

                auto [insertionIterator, success]=seen.insert(word);

                if(success==false)
                {
                    continue;
                }

                for(string & neighbour : graph[word])
                {
                    stack.push_back(neighbour);
                }
            }

            return false;
        }
};