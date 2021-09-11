#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cctype>
using namespace std;

/*
 * Approaches:
 *
 * 1) For each word, we map each letter to the row it appears in using a hashtable (unordered_map<char, int>).
 * Then, we loop over the word and if two letters appear in two different rows, then the current
 * word can't be formed from just the letters from one row. However, if all the letters in the current
 * word are all in the same row, then we add the word to our result vector.
 *
 * Time complexity: O(n * length of each word) [where n is the number of words in the input vector]
 * Space complexity: O(n)
 *
 * 2) Same logic as the first solution, we just using a vector<int> instead of unordered_map<char, int> for our
 * hashtable, and we hash by the ascii value of the uppercase version of each letter in each word.
 *
 * Time complexity: O(n * length of each word) [where n is the total number of words in the input vector]
 * Space complexity: O(n)
 */

vector<string> findWords(vector<string>& words)
{
    vector<string> result;

    if(words.empty())
    {
        return result;
    }

    int alphabetRows=3;

    vector<unordered_set<char>> rows(alphabetRows);

    unordered_set<char> row1={'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};

    unordered_set<char> row2={'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};

    unordered_set<char> row3={'Z', 'X', 'C', 'V', 'B', 'N', 'M'};

    rows[0]=row1;

    rows[1]=row2;

    rows[2]=row3;

    for(string word : words)
    {
        unordered_map<char, int> hashtable;

        for(char letter : word)
        {
            if(!hashtable.count(letter))
            {
                for(int row=0;row<alphabetRows;++row)
                {
                    if(rows[row].count(toupper(letter)))
                    {
                        hashtable[letter]=row;
                    }
                }

                if(!hashtable.count(letter))
                {
                    hashtable[letter]=-1;
                }
            }
        }

        bool valid=true;

        int current=hashtable[word[0]];

        for(char letter : word)
        {
            if(hashtable[letter]!=current)
            {
                valid=false;

                break;
            }
        }

        if(valid)
        {
            result.push_back(word);
        }
    }

    return result;
}

vector<string> findWords(vector<string>& words)
{
    vector<string> result;

    if(words.empty())
    {
        return result;
    }

    int alphabetRows=3;

    vector<unordered_set<char>> rows(alphabetRows);

    unordered_set<char> row1={'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};

    unordered_set<char> row2={'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};

    unordered_set<char> row3={'Z', 'X', 'C', 'V', 'B', 'N', 'M'};

    rows[0]=row1;

    rows[1]=row2;

    rows[2]=row3;

    for(string word : words)
    {
        vector<int> hashtable(26, -1);

        for(char letter : word)
        {
            char upperCaseLetter=toupper(letter);

            if(hashtable[upperCaseLetter - 'A']==-1)
            {
                for(int row=0;row<alphabetRows;++row)
                {
                    if(rows[row].count(upperCaseLetter))
                    {
                        hashtable[upperCaseLetter - 'A']=row;
                    }
                }
            }
        }

        bool valid=true;

        int current=hashtable[toupper(word[0]) - 'A'];

        for(char letter : word)
        {
            if(hashtable[toupper(letter) - 'A']!=current)
            {
                valid=false;

                break;
            }
        }

        if(valid)
        {
            result.push_back(word);
        }
    }

    return result;
}