#include <iostream>
#include <string>
#include <vector>

/*
 * Solution: we put each letter in a vector of characters based on the row it will be in the zig zag string (where the rows are zero based).
 * Then, we loop over the vector of vectors and build the result from the characters in each vector.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

std::string convert(std::string s, int numRows)
{
    if(numRows <= 1)
    {
        return s;
    }

    std::vector<std::vector<char>> hashtable(numRows, std::vector<char>());

    auto n=s.size();

    int count=0;

    for(auto i=0;i<n;)
    {
        while(i < n && count < numRows-1)
        {
            hashtable[count].push_back(s[i]);

            count++;

            i++;
        }

        while(i < n && count > 0)
        {
            hashtable[count].push_back(s[i]);

            count--;

            i++;
        }
    }

    std::string result{};

    for(const auto & row : hashtable)
    {
        for(const auto & letter : row)
        {
            result+=letter;
        }
    }

    return result;
}