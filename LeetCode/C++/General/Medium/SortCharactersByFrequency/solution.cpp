#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    public:
        string frequencySort(string s)
        {
            string result="";
            
            unordered_map<char, int> frequencies;
            
            for(char letter : s)
            {
                frequencies[letter]+=1;
            }
            
            map<int, vector<char>> hashtable;
            
            for(auto & [letter, frequency] : frequencies)
            {
                hashtable[frequency].push_back(letter);
            }
            
            for(auto itr=rbegin(hashtable);itr!=rend(hashtable);itr++)
            {
                for(char letter : itr->second)
                {
                    for(int count=0;count<itr->first;count++)
                    {
                        result.push_back(letter);
                    }
                }
            }
            
            return result;
        }
};

class Solution
{
    public:
        string frequencySort(string s)
        {
            string result="";
            
            unordered_map<char, int> frequencies;
            
            for(char letter : s)
            {
                frequencies[letter]+=1;
            }
            
            int maxFrequency=0;
            
            for(auto & [letter, frequency] : frequencies)
            {
                if(frequency > maxFrequency)
                {
                    maxFrequency=frequency;
                }
            }
            
            vector<vector<char>> buckets(maxFrequency + 1, vector<char>());
            
            for(auto & [letter, frequency] : frequencies)
            {
                buckets[frequency].push_back(letter);
            }
            
            for(int frequency=buckets.size()-1;frequency>=0;frequency--)
            {
                if(!buckets[frequency].empty())
                {
                    for(char letter : buckets[frequency])
                    {
                        for(int count=0;count<frequency;count++)
                        {
                            result.push_back(letter);
                        }
                    }
                }
            }
            
            return result;
        }
};