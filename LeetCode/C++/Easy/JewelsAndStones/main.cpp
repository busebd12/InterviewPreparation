#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * Approaches:
 *
 * 1) Use a hashtable (unordered_map<char, int>) and count how many of each type of stone we have.
 * Then, for each jewel, if the jewel is in our collection of stones (aka in our hashtable), then
 * just add how many of that jewel we have to our result and return our result after we have looked
 * at all the jewels.
 *
 * Time complexity: O(n + m) [where n is the length of the string J and m is the length of the string S)
 * Space complexity: O(m)
 *
 *
 * 2) Same logic has the first solution just using a vector<int> instead of unordered_map<char, int> as our hashtable
 * becuase we will be hashing using the ascii (integer) values for the letters.
 *
 * Time complexity: O(n + m) [where n is the length of the string J and m is the length of the string S]
 * Space complexity: O(1) [since we only need 123 spots in our vector (the ascii value for Z is 122) and 123 is a constant]
 *
 *
 * 3) For each jewel in the string J, each time we see it in the string S, increment our result integer.
 * At the end, return our result.
 *
 * Time complexity: O(n * m) [where n is the length of the string J and m is the length of the string S]
 * Space complexity: O(1)
 */

int numJewelsInStones(string J, string S)
{
    unordered_map<char, int> hashtable;

    for(const char & stone : S)
    {
        hashtable[stone]++;
    }

    int result=0;

    for(const char & jewel : J)
    {
        if(hashtable.count(jewel))
        {
            result+=hashtable[jewel];
        }
    }

    return result;
}

int numJewelsInStones(string J, string S)
{
    vector<int> hashtable(123, 0);

    for(const char & stone : S)
    {
        hashtable[int(stone)]++;
    }

    int result=0;

    for(const char & jewel : J)
    {
        result+=hashtable[int(jewel)];
    }

    return result;
}

int numJewelsInStones(string J, string S)
{
    int result=0;

    size_t n=J.size();

    size_t m=S.size();

    for(size_t i=0;i<n;++i)
    {
        char jewel=J[i];

        for(size_t j=0;j<m;++j)
        {
            char stone=S[j];

            if(stone==jewel)
            {
                result++;
            }
        }
    }

    return result;
}