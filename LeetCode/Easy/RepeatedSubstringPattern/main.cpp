#include <iostream>
#include <string>
using namespace std;

/*
Approaches:

1) Brute force. Generate all possible substrings for the string
and then, for each substring that smaller than the length of the string,
try creating the matching string.

Time complexity: O(n-cubed) [where n is the length of the string]
Space complexity: O(n-squared)

2) If the string is indeed made up of repeated subtrings, then the length of one of the subtrings must be at most n/2
(where n is the length of the string). So, for each divisor, substringLength, of the string length, starting at n/2,
we generate the substring that spans from 0 to substringLength. Then, we build a string by repeatedly adding the substring
to it the number of times the substring length even divides the string length. If the resulting string is the same as s, return true.

Time complexity: O(n/2) [where n is the length of the input string]
Space complexity: O(k * (l + m)) [where k is the number of times the length of the string % the length of
a substring is 0; l is the length of said substring and m is the number of times that substring fits into
the input string]
*/

bool repeatedSubstringPattern(string s)
{
    if(s.empty())
    {
        return true;
    }

    int n=int(s.size());

    if(n==1)
    {
        return false;
    }

    for(int start=0;start<=n;++start)
    {
        for(int length=1;length<=n-start;++length)
        {
            string substring=s.substr(start, length);

            if(substring.size() < n)
            {
                string candidate{};

                while(candidate.size() <= n)
                {
                    if(candidate==s)
                    {
                        return true;
                    }

                    candidate+=substring;
                }
            }
        }
    }

    return false;
}

bool repeatedSubstringPattern(string s)
{
    if(s.empty())
    {
        return true;
    }

    int n=int(s.size());

    if(n==1)
    {
        return false;
    }

    for(int substringLength=n/2;substringLength>=1;--substringLength)
    {
        if(n%substringLength==0)
        {
            int numberOfSubstrings=n/substringLength;

            string substring=s.substr(0, substringLength);

            string candidate{};

            for(int count=0;count<numberOfSubstrings;++count)
            {
                candidate+=substring;
            }

            if(candidate==s)
            {
                return true;
            }
        }
    }

    return false;
}