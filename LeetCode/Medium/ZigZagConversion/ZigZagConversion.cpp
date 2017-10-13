#include <iostream>
#include <vector>
#include <string>
using namespace std;

void fillVector(vector<vector<char>> & letters, string s, size_t stringSize, int numRows)
{
    int i=0;

    int count=0;

    while(i < stringSize)
    {
        if(count==0)
        {
            int start=numRows-numRows;

            int j=0;

            while(j < numRows)
            {
                letters[j].emplace_back(s[i]);

                i++;

                j++;

                start++;
            }
        }
        else if(count > 0)
        {
            if(count%2==1)
            {
                int start=numRows-2;

                bool lessThanNumRowsLettersLeft=(stringSize-i) < numRows;

                if(lessThanNumRowsLettersLeft)
                {
                    int j=0;

                    int lettersLeft=(stringSize-i);

                    while(j < lettersLeft)
                    {
                        letters[start].emplace_back(s[i]);

                        i++;

                        j++;

                        start--;
                    }
                }
                else
                {
                    int j=0;

                    while(j < numRows-1)
                    {
                        letters[start].emplace_back(s[i]);

                        i++;

                        j++;

                        start--;
                    }
                }
            }
            else
            {
                int start=numRows-(numRows-1);

                bool lessThanNumRowsLettersLeft=(stringSize-i) < numRows;

                if(lessThanNumRowsLettersLeft)
                {
                    int j=0;

                    int lettersLeft=(stringSize-i);

                    while(j < lettersLeft)
                    {
                        letters[start].emplace_back(s[i]);

                        i++;

                        j++;

                        start++;
                    }
                }
                else
                {
                    int j=0;

                    while(j < numRows-1)
                    {
                        letters[start].emplace_back(s[i]);

                        i++;

                        j++;

                        start++;
                    }
                }
            }
        }

        count++;
    }
}
    
string convert(string s, int numRows)
{
    const size_t stringSize=s.size();

    if(stringSize==0)
    {
        return s;
    }

    if(numRows <= 1)
    {
        return s;
    }

    vector<vector<char>> letters(numRows, vector<char>());

    fillVector(letters, s, stringSize, numRows);

    string answer="";

    for(const auto & row : letters)
    {
        for(const auto & letter : row)
        {
            answer+=letter;
        }
    }

    return answer;
}