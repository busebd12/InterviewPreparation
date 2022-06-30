#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/word-abbreviation/discuss/99797/Verbose-Java-Solution-HashMap(s)
*/

class Solution
{
    public:
        vector<string> wordsAbbreviation(vector<string> & words)
        {
            vector<string> result;
            
            int w=words.size();
            
            result.resize(w);
            
            //Map each word to a pair composed of the index in the result vector where its abbreviation will go and the appropriate abbreviation
            unordered_map<string, pair<int, string>> wordToAbbreviation;
            
            //Buckets to place words based on their lengths
            unordered_map<int, vector<string>> buckets;
            
            for(int index=0;index<w;index++)
            {
                int length=words[index].size();
                
                //If length of a word is less than four, no shorter abbreviation can be made, so the only valid abbreviation will be the word itself
                if(length < 4)
                {
                    wordToAbbreviation.emplace(words[index], make_pair(index, words[index]));
                }
                else
                {
                    //If the length is not present in the unordered_map
                    if(buckets.find(length)==end(buckets))
                    {
                        buckets.emplace(length, vector<string>());
                    }

                    //Add the word to the appropriate bucket
                    buckets[length].push_back(words[index]);
                    
                    //Create the word to index && abbreviation pair mapping
                    wordToAbbreviation.emplace(words[index], make_pair(index, ""));
                }
            }
            
            //Iterate through the buckets
            for(auto & [length, wordsOfThatLength] : buckets)
            {
                //Get a mapping of each word to its abbreviation
                unordered_map<string, string> abbreviations=getAbbreviations(wordsOfThatLength);
                
                //Iterate through the abbreviation mappings
                for(auto & [word, abbreviation] : abbreviations)
                {
                    //Update the appropriate abbreviation for the word
                    wordToAbbreviation[word].second=abbreviation;
                }
            }
            
            //Iterate through the word to pair mappings
            for(auto & [word, indexAbbreviationPair] : wordToAbbreviation)
            {
                int index=indexAbbreviationPair.first;
                
                string abbreviation=indexAbbreviationPair.second;
                
                //Update the word's abbreviation in the result vector
                result[index]=abbreviation;
            }
            
            return result;
        }
    
        unordered_map<string, string> getAbbreviations(vector<string> & wordsOfThatLength)
        {
            //Map each word to its abbreviation
            unordered_map<string, string> abbreviations;
            
            //Length of all words in the current bucket
            int wordLength=wordsOfThatLength[0].size();
            
            //Loop through the indices where the abbreviation stops
            for(int stop=1;stop<=wordLength-1;stop++)
            {
                //Map each unique abbreviation to its word (if possible)
                unordered_map<string, string> abbreviationToWord;
                
                //Iterate through each word in the bucket
                for(string & word : wordsOfThatLength)
                {
                    //If we haven't found an abbreviation for the word already
                    if(abbreviations.find(word)==end(abbreviations))
                    {   
                        //Construct the abbreviation
                        string abbreviation=word.substr(0, stop);

                        int digits=(wordLength - 1) - stop;

                        if(digits > 0)
                        {
                            abbreviation+=to_string(digits);
                        }

                        abbreviation.push_back(word[wordLength - 1]);

                        //If we haven't seen this abbreviation before
                        if(abbreviationToWord.find(abbreviation)==end(abbreviationToWord))
                        {
                            //If the abbreviation is smaller than the word itself
                            if(abbreviation.size() < word.size())
                            {
                                //Create the abbreviation-to-word mapping
                                abbreviationToWord.emplace(abbreviation, word);
                            }
                        }
                        //Else, more than one word share this abbreviation, so make it map to just the empty string
                        else
                        {
                            abbreviationToWord[abbreviation]="";
                        }
                    }
                }
                
                //Iterate through the abbreviation-to-word mappings
                for(auto & [abbreviation, word] : abbreviationToWord)
                {
                    //If the word is not empty, then the abbreviation is unique
                    if(!word.empty())
                    {
                        //Create the word-to-abbreviation mapping
                        abbreviations.emplace(word, abbreviation);
                    }
                }
            }
            
            //Iterate through the words in the bucket
            for(string & word : wordsOfThatLength)
            {
                //At this point, if the word does not have a word-to-abbreviation mapping, then the only possible abbreviation is the word itself
                if(abbreviations.find(word)==end(abbreviations))
                {
                    //Create the word-to-itself mapping
                    abbreviations.emplace(word, word);
                }
            }
            
            return abbreviations;
        }
};