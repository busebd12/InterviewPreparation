#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(w + (w * l) + (q * l)) [where w is the length of wordlist, q is the length of queries, and l is the average length of word]
Space complexity: O(w)
*/

class Solution
{
    public:
        vector<string> spellchecker(vector<string> & wordlist, vector<string> & queries)
        {
            vector<string> result;

            int q=queries.size();

            result.resize(q, "");

            //Store words from wordlist in an unordered_set<string> to get O(1) lookup for each word
            unordered_set<string> words;

            //Add all the words from wordlist into the unordered_set<string>
            for(string word : wordlist) //O(w) [where w is the length of the wordlist]
            {
                if(words.find(word)==end(words))
                {
                    words.insert(word);
                }
            }

            //Hashmap to map the lowercase version each word in wordlist to the original word
            unordered_map<string, string> lowercaseMap;

            //Add all the words from wordlist into the hashmap
            for(string word : wordlist) //O(w) [where w is the length of wordlist]
            {
                string allLowercase=toLowerCase(word);

                if(lowercaseMap.find(allLowercase)==end(lowercaseMap))
                {
                    lowercaseMap.emplace(allLowercase, word);
                }
            }

            //Hashmap to map the lowercase version of each word in wordlist with all vowels replaced with '*' to the original version of the word
            unordered_map<string, string> vowelMatchMap;

            //Add each word from wordlist to vowelMatchMap
            for(string word : wordlist) //O(w) [where w is the length of wordlist]
            {
                string allLowercase=toLowerCase(word);

                replaceVowels(allLowercase);

                if(vowelMatchMap.find(allLowercase)==end(vowelMatchMap))
                {
                    vowelMatchMap.emplace(allLowercase, word);
                }
            }

            //For each query
            for(int i=0;i<q;i++) //O(q) [where q is the length of queries]
            {
                string query=queries[i];
                
                //Check first precedence rule: the original query word is in wordlist
                if(words.find(query)!=end(words))
                {
                    result[i]=query;
                }
                //Else, check the second and third precedence rules
                else
                {
                    //Convert the query word to lowercase since matches are case-insensitive
                    string allLowercase=toLowerCase(query); //O(l) [where l is the average length of a query word]

                    //Check the second precedence rule: the query word matches a word ignoring capitalization
                    if(lowercaseMap.find(allLowercase)!=end(lowercaseMap))
                    {
                        result[i]=lowercaseMap[allLowercase];
                    }
                    //Check the third precendence rule: the query word matches a word, ignoring vowel mismatches (a.k.a all consonants match)
                    else
                    {
                        replaceVowels(allLowercase);

                        if(vowelMatchMap.find(allLowercase)!=end(vowelMatchMap))
                        {
                            result[i]=vowelMatchMap[allLowercase];
                        }
                    }
                }
            }

            return result;
        }

        string toLowerCase(string & word)
        {
            string lowercase=word;

            for(char & letter : lowercase)
            {
                letter=tolower(letter);
            }

            return lowercase;
        }

        void replaceVowels(string & word)
        {
            for(char & letter : word)
            {
                bool isVowel=((letter=='a') || (letter=='e') || (letter=='i') || (letter=='o') || (letter=='u'));

                if(isVowel==true)
                {
                    letter='*';
                }
            }
        }
};