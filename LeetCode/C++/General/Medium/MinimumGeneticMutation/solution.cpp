#include <deque>
#include <string>
#include <unordered_set>
#include <vector>

/*
Solution 1: breadth-first search + visited set.

Time complexity: O(n) [where n is the number of strings in the path from start to end]
Space complexity: O(n)
*/

class Solution
{
    public:
        int minMutation(string start, string end, vector<string> & bank)
        {
            int result=0;

            unordered_set<string> hashset(bank.begin(), bank.end());

            unordered_set<string> visited;

            visited.insert(start);

            vector<char> replacements={'A', 'C', 'G', 'T'};

            deque<string> queue;

            queue.push_back(start);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    string geneString=queue.front();

                    queue.pop_front();

                    if(geneString==end)
                    {
                        return result;
                    }

                    for(int i=0;i<geneString.size();i++)
                    {
                        char current=geneString[i];

                        for(int j=0;j<replacements.size();j++)
                        {
                            if(current!=replacements[j])
                            {
                                geneString[i]=replacements[j];

                                if(hashset.find(geneString)!=hashset.end() and visited.find(geneString)==visited.end())
                                {
                                    visited.insert(geneString);
                                    
                                    queue.push_back(geneString);
                                }
                            }
                        }

                        geneString[i]=current;
                    }
                }

                result+=1;
            }

            return -1;
        }
};

/*
Solution 1: breadth-first search without a visited set.

Time complexity: O(n) [where n is the number of strings in the path from start to end]
Space complexity: O(n)
*/

class Solution
{
    public:
        int minMutation(string start, string end, vector<string> & bank)
        {
            int result=0;

            unordered_set<string> hashset(bank.begin(), bank.end());

            if(hashset.find(start)!=hashset.end())
            {
                hashset.erase(start);
            }

            vector<char> replacements={'A', 'C', 'G', 'T'};

            deque<string> queue;

            queue.push_back(start);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    string geneString=queue.front();

                    queue.pop_front();

                    if(geneString==end)
                    {
                        return result;
                    }

                    for(int i=0;i<geneString.size();i++)
                    {
                        char current=geneString[i];

                        for(int j=0;j<replacements.size();j++)
                        {
                            if(current!=replacements[j])
                            {
                                geneString[i]=replacements[j];

                                if(hashset.find(geneString)!=hashset.end())
                                {
                                    hashset.erase(geneString);
                                    
                                    queue.push_back(geneString);
                                }
                            }
                        }

                        geneString[i]=current;
                    }
                }

                result+=1;
            }

            return -1;
        }
};