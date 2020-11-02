#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * Approach: for each string in the input vector<string> A, we keep track of the frequency of each character
 * by using a vector of integers and incrementing the ascii value of the letter each time we see it in the string.
 * Then, for each letter in the alphabet, store how many times the letter appears in each string in a vector<int> frequencies.
 * In order for a character to be common, it has to appear in each string at least once. In other words, all the frequencies
 * have to be greater than zero. However, according to the problem definition, we want the common minimum amount of times
 * it appears in each string. So, we want the smallest non-zero frequency. Finally, we add the current character in the alphabet
 * we are looking at minimum frequency number of times to the commonCharacters vector.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(n)
 */

vector<string> commonChars(vector<string>& A)
{
    vector<string> commonCharacters;

    if(A.empty())
    {
        return commonCharacters;
    }

    int n=int(A.size());

    vector<vector<int>> alphabets(n, vector<int>(26, 0));

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<A[i].size();++j)
        {
            alphabets[i][A[i][j] - 'a']++;
        }
    }

    for(char c='a';c<='z';++c)
    {
        vector<int> frequencies(n, 0);

        for(int i=0;i<n;++i)
        {
            frequencies[i]=alphabets[i][c - 'a'];
        }

        int minimumFrequency=*(min_element(frequencies.begin(), frequencies.end()));

        if(minimumFrequency > 0)
        {
            for(int count=0;count<minimumFrequency;++count)
            {
                string s(1, c);

                commonCharacters.push_back(s);
            }
        }
    }

    return commonCharacters;
}