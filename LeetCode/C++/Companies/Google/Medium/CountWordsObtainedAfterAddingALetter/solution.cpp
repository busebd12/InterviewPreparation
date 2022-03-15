#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution 1: see comments. Note, this solution gets Time Limit Exceeded when run.

Time complexity: O((n * l^2) + (m * l)) [where l is the average length of a word; n is the length of startWords; m is the length of targetWords]
Space complexity: O(n * 26)
*/

class Solution
{
    public:
        string getHash(string & word)
        {
            //Track the frequencies for each letter
            vector<int> frequencies(26, 0);

            //Calculate the frequencies for each letter
            for(auto c : word)
            {
                frequencies[c - 'a']++;
            }

            string hash{};

            for(int i=0;i<26;i++)
            {
                if(frequencies[i] > 0)
                {
                    char c=('a' + i);

                    //Count representing the number of times the letter appears in the string
                    char count=(frequencies[i] + '0');

                    hash.push_back(count);

                    hash.push_back(c);
                }
            }

            return hash;
        }

        int wordCount(vector<string> & startWords, vector<string> & targetWords)
        {
            int result=0;

            int n=startWords.size();

            int m=targetWords.size();

            //Set of hashes for each word in startWords
            //Example: for the word "ant" the hashes would be {1a1n1t1b, 1a1n1t1c, 1a1n1t1d, etc}
            unordered_set<string> hashset;

            for(auto word : startWords) //O(n)
            {
                vector<bool> offLimits(26, false);

                //Mark the letters from the word that we aren't allowed to use
                for(auto letter : word)
                {
                    offLimits[letter - 'a']=true;
                }

                string copy=word; //O(l)

                for(char letter='a';letter<='z';letter++)
                {
                    //If we are allowed to use the letter
                    if(offLimits[letter - 'a']==false)
                    {
                        //Add the letter to the end of the word
                        copy.push_back(letter);

                        //Create a hash for the copy string
                        //Example: for the word "tack", the hash would be "1t1a1c1k"
                        string hash=getHash(copy); //O(l)

                        //Add the hash to the unordered_set for the startWord
                        hashset.insert(hash);

                        //Remove the letter from the end of the string
                        copy.pop_back();
                    }
                }
            }

            for(auto word : targetWords) //O(m)
            {
                //Create a hash for the target word
                string hash=getHash(word); //O(l)

                //If the hash is in the hashset, then we know the targetWord can be created from a startWord
                if(hashset.count(hash))
                {
                    result++;
                }
            }

            return result;
        }
};

/*
Solution 2: see comments.

Time complexity: O(n * l * (l log l) + m * (l log l)) where l is the average length of a word; n is the length of startWords; m is the length of targetWords]
Space complexity: O(26 * n)
*/

class Solution
{
    public:
        int wordCount(vector<string> & startWords, vector<string> & targetWords)
        {
            int result=0;

            int n=startWords.size();

            int m=targetWords.size();

            //Set of hashes for each word in startWords
            //Example: for the word "ant" the hashes would be {1a1n1t1b, 1a1n1t1c, 1a1n1t1d, etc}
            unordered_set<string> hashset;

            for(auto word : startWords) //O(n)
            {
                vector<bool> offLimits(26, false);

                //Mark the letters from the word that we aren't allowed to use
                for(auto letter : word)
                {
                    offLimits[letter - 'a']=true;
                }

                for(char letter='a';letter<='z';letter++)
                {
                    //If we are allowed to use the letter
                    if(offLimits[letter - 'a']==false)
                    {
                        string copy=word; //O(l)
                        
                        //Add the letter to the end of the word
                        copy.push_back(letter);
                        
                        //Sort the letters within the word
                        sort(begin(copy), end(copy)); //O(l log l)

                        //Add copy to the hashset
                        hashset.insert(copy);

                        //Remove the letter from the end of the string
                        copy.pop_back();
                    }
                }
            }

            for(auto word : targetWords) //O(m)
            {
                sort(begin(word), end(word)); //O(l log l)

                //If the sorted word is in the hashset, then we know the targetWord can be created from a startWord
                if(hashset.count(word))
                {
                    result++;
                }
            }

            return result;
        }
};