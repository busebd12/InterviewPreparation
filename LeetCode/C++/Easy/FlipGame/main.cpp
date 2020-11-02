#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Approach: Loop over the string, s, and if we find two consecutive '+'s,
 * flip them to '-'s and add the resulting string to the vector of strings.
 *
 * Time complexity: O(n)
 * Space complexity: O(number of pairs of +)
 */

vector<string> generatePossibleNextMoves(string s)
{
    vector<string> states;

    if(s.empty())
    {
        return states;
    }

    int n=int(s.size());

    for(int i=0;i<n;++i)
    {
        if(i < n-1)
        {
            if(s[i]=='+' && s[i+1]=='+')
            {
                s[i]='-';

                s[i+1]='-';

                states.push_back(s);

                s[i]='+';

                s[i+1]='+';
            }
        }
    }

    return states;
}