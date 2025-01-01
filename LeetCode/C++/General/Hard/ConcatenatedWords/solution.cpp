#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<string> findAllConcatenatedWordsInADict(vector<string> & words)
        {
            vector<string> result;

            int w=words.size();

            unordered_set<string> dictionary;

            for(string & word : words)
            {
                dictionary.insert(word);
            }

            for(string & word : words)
            {
                int count=0;
                
                if(helper(dictionary, word, count)==true)
                {
                    result.push_back(word);
                }
            }

            return result;
        }

        bool helper(unordered_set<string> & dictionary, string & word, int count)
        {
            if(word.empty() and count > 1)
            {
                return true;
            }

            bool subproblemSolution=false;

            for(int i=1;i<=word.size();i++)
            {
                string prefix=word.substr(0, i);

                string suffix=word.substr(i, string::npos);

                if(dictionary.find(prefix)!=dictionary.end())
                {
                    count+=1;
                    
                    if(helper(dictionary, suffix, count)==true)
                    {
                        subproblemSolution=true;

                        return subproblemSolution;
                    }

                    count-=1;
                }
            }

            return subproblemSolution;
        }
};