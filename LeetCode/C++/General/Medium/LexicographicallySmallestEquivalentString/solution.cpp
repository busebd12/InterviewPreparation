#include <algorithm>
#include <deque>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    public:
        string smallestEquivalentString(string s1, string s2, string baseStr)
        {
            string result="";

            int n=s1.size();

            int m=baseStr.size();

            unordered_map<char, vector<char>> hashmap;

            for(int i=0;i<n;i++)
            {
                char s1Letter=s1[i];

                char s2Letter=s2[i];

                hashmap[s1Letter].push_back(s2Letter);

                hashmap[s2Letter].push_back(s1Letter);
            }

            unordered_map<char, char> cache;

            for(int j=0;j<m;j++)
            {
                char baseLetter=baseStr[j];

                if(cache.find(baseLetter)!=cache.end())
                {
                    result.push_back(cache[baseLetter]);
                }
                else
                {
                    char resultLetter='~';

                    unordered_set<char> visited;

                    helper(hashmap, visited, resultLetter, baseLetter);

                    result.push_back(resultLetter);

                    cache[baseLetter]=resultLetter;
                }
            }

            return result;
        }

        void helper(unordered_map<char, vector<char>> & hashmap, unordered_set<char> & visited, char & resultLetter, char baseLetter)
        {
            visited.insert(baseLetter);

            resultLetter=min(resultLetter, baseLetter);

            for(char next : hashmap[baseLetter])
            {
                if(visited.find(next)==visited.end())
                {
                    helper(hashmap, visited, resultLetter, next);
                }
            }
        }
};

class Solution
{
    public:
        string smallestEquivalentString(string s1, string s2, string baseStr)
        {
            string result="";

            int n=s1.size();

            int m=baseStr.size();

            vector<vector<int>> graph(26, vector<int>());

            for(int i=0;i<n;i++)
            {
                char s1Letter=s1[i];

                char s2Letter=s2[i];

                graph[s1Letter - 'a'].push_back(s2Letter - 'a');

                graph[s2Letter - 'a'].push_back(s1Letter - 'a');
            }

            vector<int> cache(26, -1);

            for(int j=0;j<m;j++)
            {
                char baseLetter=baseStr[j];

                int baseLetterIndex=baseLetter - 'a';

                char resultLetter='$';

                if(cache[baseLetterIndex]!=-1)
                {
                    resultLetter=cache[baseLetterIndex] + 'a';
                }
                else
                {
                    int resultLetterIndex=27;

                    vector<int> visited(26, 0);

                    helper(graph, visited, resultLetterIndex, baseLetterIndex);

                    cache[baseLetterIndex]=resultLetterIndex;

                    resultLetter=resultLetterIndex + 'a';
                }

                result.push_back(resultLetter);
            }

            return result;
        }

        void helper(vector<vector<int>> & graph, vector<int> & visited, int & resultLetterIndex, int baseLetterIndex)
        {
            visited[baseLetterIndex]=1;

            resultLetterIndex=min(resultLetterIndex, baseLetterIndex);

            for(int next : graph[baseLetterIndex])
            {
                if(visited[next]==0)
                {
                    helper(graph, visited, resultLetterIndex, next);
                }
            }
        }
};

class Solution
{
    public:
        string smallestEquivalentString(string s1, string s2, string baseStr)
        {
            string result="";

            int n=s1.size();

            int m=baseStr.size();

            vector<vector<int>> graph(26, vector<int>());

            for(int i=0;i<n;i++)
            {
                char s1Letter=s1[i];

                char s2Letter=s2[i];

                graph[s1Letter - 'a'].push_back(s2Letter - 'a');

                graph[s2Letter - 'a'].push_back(s1Letter - 'a');
            }

            vector<int> cache(26, -1);

            for(int j=0;j<m;j++)
            {
                char baseLetter=baseStr[j];

                int baseLetterIndex=baseLetter - 'a';

                char resultLetter='$';

                if(cache[baseLetterIndex]!=-1)
                {
                    resultLetter=cache[baseLetterIndex] + 'a';
                }
                else
                {
                    int resultLetterIndex=27;

                    vector<int> visited(26, 0);

                    helper(graph, visited, resultLetterIndex, baseLetterIndex);

                    cache[baseLetterIndex]=resultLetterIndex;

                    resultLetter=resultLetterIndex + 'a';
                }

                result.push_back(resultLetter);
            }

            return result;
        }

        void helper(vector<vector<int>> & graph, vector<int> & visited, int & resultLetterIndex, int baseLetterIndex)
        {
            deque<int> stack;

            stack.push_back(baseLetterIndex);

            while(!stack.empty())
            {
                int current=stack.back();

                stack.pop_back();

                resultLetterIndex=min(resultLetterIndex, current);

                if(visited[current]==1)
                {
                    continue;
                }

                visited[current]=1;

                for(int next : graph[current])
                {
                    stack.push_back(next);
                }
            }
        }
};

class Solution
{
    public:
        string smallestEquivalentString(string s1, string s2, string baseStr)
        {
            string result="";

            int n=s1.size();

            int m=baseStr.size();

            vector<vector<int>> graph(26, vector<int>());

            for(int i=0;i<n;i++)
            {
                char s1Letter=s1[i];

                char s2Letter=s2[i];

                graph[s1Letter - 'a'].push_back(s2Letter - 'a');

                graph[s2Letter - 'a'].push_back(s1Letter - 'a');
            }

            vector<int> cache(26, -1);

            for(int j=0;j<m;j++)
            {
                char baseLetter=baseStr[j];

                int baseLetterIndex=baseLetter - 'a';

                char resultLetter='$';

                if(cache[baseLetterIndex]!=-1)
                {
                    resultLetter=cache[baseLetterIndex] + 'a';
                }
                else
                {
                    int resultLetterIndex=27;

                    vector<int> visited(26, 0);

                    helper(graph, visited, resultLetterIndex, baseLetterIndex);

                    cache[baseLetterIndex]=resultLetterIndex;

                    resultLetter=resultLetterIndex + 'a';
                }

                result.push_back(resultLetter);
            }

            return result;
        }

        void helper(vector<vector<int>> & graph, vector<int> & visited, int & resultLetterIndex, int baseLetterIndex)
        {
            deque<int> queue;

            queue.push_back(baseLetterIndex);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    int current=queue.front();

                    queue.pop_front();

                    resultLetterIndex=min(resultLetterIndex, current);

                    if(visited[current]==1)
                    {
                        continue;
                    }

                    visited[current]=1;

                    for(int next : graph[current])
                    {
                        queue.push_back(next);
                    }
                }
            }
        }
};