#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*
Approaches:

1) High level steps are as follows. First, add a separator character to the end of the chars vector.
This will mark where the original string ends and the compressed string begins.
Then, create a hashtable that maps character ascii values to frequencies.
Then, while looping over the chars vector, while we see the same character, increment the frequency of its ascii
value in the hashtable. Once we reach a different character, add the previous character and the individual digits from
the number representing its frequency to the end of the chars vector. Reverse the chars vector so that the original
string is at the end. While the last character is not the divider, repeatedly delete the last character.
Then, delete the divider. All we are left with is the compressed string, but backwards. Just reverse the chars vector,
again, to get our answer to face the right direction.

Time complexity: O(n * length of string representing how many times each letter appears)
Space complexity: O(number of ascii digits between 35 and 126, inclusive + length of the compressed string and dividing character at the end of the chars vector)


2) Nearly the same exact logic as the first approach. Except we replace the hashtable with just counting how many
of each character we see before getting to a different character.

Time complexity: O(n)
Space complexity: O(length of the compressed string and dividing character at the end of the chars vector)

*/

int compress(vector<char> & chars)
{
    int result=0;

    if(chars.empty())
    {
        return result;
    }

    int n=int(chars.size());

    vector<int> hashtable(137, 0);

    int dividerInteger=34;

    char divider=char(dividerInteger);

    chars.push_back(divider);

    for(int i=0;i<n;)
    {
        char current=chars[i];

        int ascii=int(current);

        while(chars[i]==current)
        {
            hashtable[ascii]++;

            i++;
        }

        chars.push_back(current);

        int frequency=hashtable[current];

        if(frequency > 1)
        {
            string frequencyString=to_string(frequency);

            for(int i=0;i<frequencyString.size();++i)
            {
                chars.emplace_back(frequencyString[i]);
            }
        }

        hashtable[current]=0;
    }

    reverse(chars.begin(), chars.end());

    while(chars.back()!=divider)
    {
        chars.pop_back();
    }

    chars.pop_back();

    reverse(chars.begin(), chars.end());

    return int(chars.size());
}

int compress(vector<char> & chars)
{
    int result=0;

    if(chars.empty())
    {
        return result;
    }

    int n=int(chars.size());

    int count=0;

    int dividerInteger=34;

    char divider=char(dividerInteger);

    chars.push_back(divider);

    for(int i=0;i<n;)
    {
        char current=chars[i];

        while(chars[i]==current)
        {
            count++;

            i++;
        }

        chars.push_back(current);

        if(count > 1)
        {
            string frequencyString=to_string(count);

            for(int i=0;i<frequencyString.size();++i)
            {
                chars.emplace_back(frequencyString[i]);
            }
        }

        count=0;
    }

    reverse(chars.begin(), chars.end());

    while(chars.back()!=divider)
    {
        chars.pop_back();
    }

    chars.pop_back();

    reverse(chars.begin(), chars.end());

    return int(chars.size());
}