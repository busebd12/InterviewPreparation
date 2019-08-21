#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
 * Approaches:
 *
 * 1) Looping over the secret and guess, use a hashtable (unordered_map) to map each character to its index.
 * Then, for each character in guess, check to see if it's in the secret hashtable. If it is, increment bulls by
 * the number of matching indices between guess and secret. If there are still occurrences of the character left,
 * loop over the indices and increment cows by the number of indices that don't match.
 *
 * Time complexity: O(n * number of indices for characters that are in both guess and secret)
 * Space complexity: O(n)
 *
 * 2) Same logic just written differently/optimized so that we only use one hashtable (unordered_map) instead of two.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 * 3) Same logic as number two, just optimized even more. We use a vector of integers instead of unordered_map<char, int>
 * to increase performance.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

string getHint(string secret, string guess)
{
    if(secret.empty() || guess.empty())
    {
        return "0A0B";
    }

    if(secret.size()!=guess.size())
    {
        return "0A0B";
    }

    unordered_map<char, unordered_set<int>> secretMap;

    unordered_map<char, unordered_set<int>> guessMap;

    int n=int(secret.size());

    for(int i=0;i<n;++i)
    {
        char secretDigit=secret[i];

        char guessDigit=guess[i];

        if(!secretMap.count(secretDigit))
        {
            secretMap.insert(make_pair(secretDigit, unordered_set<int>()));

            secretMap[secretDigit].insert(i);
        }
        else
        {
            secretMap[secretDigit].insert(i);
        }

        if(!guessMap.count(guessDigit))
        {
            guessMap.insert(make_pair(guessDigit, unordered_set<int>()));

            guessMap[guessDigit].insert(i);
        }
        else
        {
            guessMap[guessDigit].insert(i);
        }
    }

    int bulls=0;

    int cows=0;

    for(const auto & element : guessMap)
    {
        if(secretMap.count(element.first))
        {
            int frequency=int(secretMap[element.first].size());

            for(const int & index : element.second)
            {
                if(secretMap[element.first].count(index))
                {
                    bulls++;

                    frequency--;
                }
            }

            if(frequency > 0)
            {
                for(const int & index : element.second)
                {
                    if(!secretMap[element.first].count(index))
                    {
                        if(frequency > 0)
                        {
                            cows++;

                            frequency--;
                        }
                    }
                }
            }
        }
    }

    string hint{};

    hint+=to_string(bulls);

    hint+='A';

    hint+=to_string(cows);

    hint+='B';

    return hint;

}

string getHint(string secret, string guess)
{
    if(secret.empty() || guess.empty())
    {
        return "0A0B";
    }

    if(secret.size()!=guess.size())
    {
        return "0A0B";
    }

    unordered_map<char, int> hashtable;

    int n=int(secret.size());

    int bulls=0;

    int cows=0;

    for(int i=0;i<n;++i)
    {
        if(guess[i]==secret[i])
        {
            bulls++;
        }
        else
        {
            hashtable[secret[i]]++;
        }
    }

    for(int i=0;i<n;++i)
    {
        if(guess[i]!=secret[i] && hashtable[guess[i]] > 0)
        {
            cows++;

            hashtable[guess[i]]--;
        }
    }

    string hint{};

    hint+=(to_string(bulls) + "A" + to_string(cows) + "B");

    return hint;
}

string getHint(string secret, string guess)
{
    if(secret.empty() || guess.empty())
    {
        return "0A0B";
    }

    if(secret.size()!=guess.size())
    {
        return "0A0B";
    }

    vector<int> hashtable(10, 0);

    int n=int(secret.size());

    int bulls=0;

    int cows=0;

    for(int i=0;i<n;++i)
    {
        if(guess[i]==secret[i])
        {
            bulls++;
        }
        else
        {
            hashtable[secret[i] - '0']++;
        }
    }

    for(int i=0;i<n;++i)
    {
        if(guess[i]!=secret[i] && hashtable[guess[i] - '0'] > 0)
        {
            hashtable[guess[i] - '0']--;

            cows++;
        }
    }

    string hint{};

    hint+=(to_string(bulls) + "A" + to_string(cows) + "B");

    return hint;
}