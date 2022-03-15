#include <string>
#include <unordered_map>
#include <vector>

/*
Solution: see comments for details
*/

class WordFilter
{
    public:
        //Hashtable used to map prefix + suffix combination to indices
        unordered_map<string, int> hashtable;
    
        //Time complexity: O(n * (L * (L + L^2))) [where n is the number of words and L is the average length of a word]
        //Space complexity: O(p + s) [where p is the total number of prefixes and s is the total number of suffixes]
        WordFilter(vector<string> & words)
        {
            int n=words.size();
            
            //Iterate through the words
            for(int index=0;index<n;index++)
            {
                string word=words[index];
                
                int wordSize=word.size();
                
                //Iterate over the word
                for(int i=0;i<=wordSize;i++)
                {
                    //Generate prefix
                    string prefix=word.substr(0, i);
                    
                    //Iterate through the word
                    for(int j=0;j<wordSize;j++)
                    {
                        //Generate suffix
                        string suffix=word.substr(j, string::npos);
                        
                        //Map the combination of prefix + "#" + suffix to the index of the word
                        hashtable[prefix + "#" + suffix]=index;
                    }
                }
            }
        }

        int f(string prefix, string suffix)
        {
            string str=prefix + "#" + suffix;
            
            //If the string prefix + "#" + suffix is not in the hashtable
            if(!hashtable.count(str))
            {
                return -1;
            }
            
            return hashtable[str];
        }
};
