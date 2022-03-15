#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solutions: inspired from this post --> https://leetcode.com/problems/sentence-screen-fitting/discuss/1375893/C%2B%2B-From-unoptimized-to-optimized-version

First solution
Time complexity: O(rows * cols)
Space complexity: O(1)

Second solution
Time complexity: O(rows + cols)
Space complexity: O(i) [where i represents the total number of zero-indexed indices in the sentence vector]
*/

class Solution
{
    public:
        int wordsTyping(vector<string> & sentence, int rows, int cols)
        {
            int result=0;

            int n=sentence.size();

            int i=0;

            while(rows > 0)
            {
                int length=-1;

                while(i < n && length + sentence[i].size() + 1 <= cols)
                {
                    length+=sentence[i].size() + 1;

                    i++;

                    if(i > n-1)
                    {
                        result++;

                        i=0;
                    }
                }

                rows--;
            }

            return result;
        }
};

class Solution
{
    public:
        int wordsTyping(vector<string> & sentence, int rows, int cols)
        {
            int result=0;

            int n=sentence.size();

            int i=0;
            
            unordered_map<int, pair<int, int>> hashtable;

            while(rows > 0)
            {
                if(hashtable.count(i))
                {
                    auto element=hashtable[i];
                    
                    int nextWordIndex=element.first;
                    
                    int repeats=element.second;
                    
                    i=nextWordIndex;
                    
                    result+=repeats;
                }
                else
                {
                    int length=-1;
                    
                    int nextWordStart=i;
                    
                    int repeats=0;
                    
                    while(i < n && length + sentence[i].size() + 1 <= cols)
                    {
                        length+=sentence[i].size() + 1;

                        i++;

                        if(i > n-1)
                        {
                            repeats++;

                            i=0;
                        }
                    }
                    
                    result+=repeats;
                    
                    hashtable[nextWordStart]={i, repeats};
                }

                rows--;
            }

            return result;
        }
};