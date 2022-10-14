#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: sliding window + hashtable

Time complexity: O(n) [where n is the length of s]
Space complexity: O(u) [where u is the total number of unique DNA sequences of length 10]
*/

class Solution
{
    public:
        vector<string> findRepeatedDnaSequences(string s)
        {
            vector<string> result;
            
            int n=s.size();
            
            if(n <= 10)
            {
                return result;
            }
            
            //Map each unique DNA sequence to how many times it appears in the string
            unordered_map<string, int> hashtable;
            
            int back=0;
            
            int front=9;
            
            while(front < n)
            {
                int length=(front - back) + 1;
                
                string sequence=s.substr(back, length);
                
                //If the DNA sequence is not in the hashtable
                if(hashtable.find(sequence)==end(hashtable))
                {
                    hashtable.emplace(sequence, 0);
                }
                
                hashtable[sequence]+=1;
                
                back+=1;
                
                front+=1;
            }
            
            for(auto & [dnaSequence, frequency] : hashtable)
            {
                //If the frequency of the DNA sequence is more than one
                if(frequency > 1)
                {
                    result.push_back(dnaSequence);
                }
            }
            
            return result;
        }
};