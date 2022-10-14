#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<string> wordSubsets(vector<string> & words1, vector<string> & words2)
        {
            vector<string> result;
            
            unordered_map<char, int> maxFrequencies;
            
            for(string & word2 : words2)
            {
                unordered_map<char, int> temp;
                
                for(char letter : word2)
                {
                    temp[letter]+=1;
                }
                
                for(auto & [letter, frequency] : temp)
                {
                    if(maxFrequencies.find(letter)==end(maxFrequencies))
                    {
                        maxFrequencies.emplace(letter, frequency);
                    }
                    else
                    {
                        maxFrequencies[letter]=max(maxFrequencies[letter], temp[letter]);
                    }
                }
            }
            
            for(string & word : words1)
            {
                if(isUniversal(maxFrequencies, word)==true)
                {
                    result.push_back(word);
                }
            }
            
            return result;
        }
    
        bool isUniversal(unordered_map<char, int> & maxFrequencies, string & word)
        {
            unordered_map<char, int> frequencies;
            
            for(char letter : word)
            {
                frequencies[letter]+=1;
            }
            
            for(auto & [letter, frequency] : maxFrequencies)
            {
                if(frequencies.find(letter)==end(frequencies))
                {
                    return false;
                }
                else
                {
                    if(frequencies[letter] < maxFrequencies[letter])
                    {
                        return false;
                    }
                }
            }
            
            return true;
        }
};

class Solution
{
    public:
        vector<string> wordSubsets(vector<string> & words1, vector<string> & words2)
        {
            vector<string> result;
            
            vector<int> maxFrequencies(26, 0);
            
            for(string & word2 : words2)
            {
                vector<int> temp(26, 0);
                
                for(char letter : word2)
                {
                    int index=letter - 'a';
                    
                    temp[index]+=1;
                }
                
                for(int index=0;index<26;index++)
                {
                    if(temp[index] > 0)
                    {
                        maxFrequencies[index]=max(maxFrequencies[index], temp[index]);
                    }
                }
            }
            
            for(string & word : words1)
            {
                if(isUniversal(maxFrequencies, word)==true)
                {
                    result.push_back(word);
                }
            }
            
            return result;
        }
    
        bool isUniversal(vector<int> & maxFrequencies, string & word)
        {
            vector<int> frequencies(26, 0);
            
            for(char letter : word)
            {
                int index=letter - 'a';
                
                frequencies[index]+=1;
            }
            
            for(int index=0;index<26;index++)
            {
                if(frequencies[index] < maxFrequencies[index])
                {
                    return false;
                }
            }
            
            return true;
        }
};