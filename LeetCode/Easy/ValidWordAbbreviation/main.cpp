#include <iostream>
#include <vector>
using namespace std;

/*
 * Approach: Loop over the abbreviation and see if the number of characters plus the sum of the integer characters
 * equals the length of the original word. Some edge cases to check are if either word or abbr are empty;
 * if the abbreviation size is greater than the original word; if there is a '0' in the abbreviation;
 * if there is a character in the abbreviation that is not in the original word.
 *
 * Time complexity: O(n) [where n is the length of the abbreviation]
 * Space complexity: O(m) [where m is the length of the original word]
 */

bool validWordAbbreviation(string word, string abbr)
{
    if(word.empty() && abbr.empty())
    {
        return true;
    }

    if(word.empty() || abbr.empty())
    {
        return false;
    }

    if(abbr.size() > word.size())
    {
        return false;
    }

    vector<int> hashtable(26, 0);

    int m=int(word.size());

    int n=int(abbr.size());

    for(int i=0;i<m;++i)
    {
        hashtable[word[i] - 'a']++;
    }

    int characters=0;

    int digits=0;

    int sum=0;

    bool leadingZero=false;

    bool mismatchCharacter=false;

    for(int i=0;i<n;)
    {
        if(isalpha(abbr[i]))
        {
            if(hashtable[abbr[i] - 'a']==0)
            {
                mismatchCharacter=true;

                break;
            }

            characters++;

            i++;
        }

        if(isdigit(abbr[i]))
        {
            if(abbr[i]=='0')
            {
                leadingZero=true;

                break;
            }

            string current{};

            while(isdigit(abbr[i]))
            {
                current+=abbr[i];

                digits++;

                i++;
            }

            sum+=stoi(current);
        }
    }

    if(leadingZero)
    {
        return false;
    }

    if(mismatchCharacter)
    {
        return false;
    }

    int total=sum + characters;

    return (total==word.size());
}