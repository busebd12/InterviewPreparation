#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1. As we generate each substring for the input string S, we check to see if
 * that substring is made up of just one type of letter. If it is, we increment
 * our integer result variable. After we are done looping over the string and
 * generating substrings, we return our integer result variable.
 *
 * Time complexity: O(n * (n - length)) => O(n^2 - (n * length)) => O(n^2)
 * [where n is the length of the input string and length is the length of substring of the input string]
 * Space complexity: O(1)
 *
 * 2. We pre-compute the total amount of substrings based on a strings length from [0, length of the input string]
 * and store the values in the substrings vector. Then, we find the length(s) of the longest substrings that are
 * made up of one type of character and add the number of substrings that each of those strings contain to our
 * integer result variable. After we finishing looping over the input string, return the result variable.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(n)
 */

int countLetters(string S)
{
    int result=0;

    if(S.empty())
    {
        return result;
    }

    auto n=S.size();

    for(auto length=1;length<=n;++length)
    {
        for(auto start=0;start+length<=n;++start)
        {
            unordered_set<char> cache;

            int count=0;

            bool oneDistinctLetter=true;

            for(const char & letter : S.substr(start, length))
            {
                if(!cache.count(letter))
                {
                    if(count==0)
                    {
                        cache.insert(letter);

                        count++;
                    }
                    else
                    {
                        oneDistinctLetter=false;

                        break;
                    }
                }
            }

            if(oneDistinctLetter)
            {
                result++;
            }
        }
    }

    return result;
}

int countLetters(string S)
{
    int result=0;

    if(S.empty())
    {
        return result;
    }

    auto n=S.size();

    vector<int> substrings(n+1, 0);

    substrings[0]=0;

    substrings[1]=1;

    for(auto i=2;i<=n;++i)
    {
        substrings[i]=i + substrings[i-1];
    }

    int length=0;

    for(auto index=0;index<n;)
    {
        char current=S[index];

        while(index < n && S[index]==current)
        {
            length++;

            index++;
        }

        result+=substrings[length];

        length=0;
    }

    return result;
}