#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Approach: we use the find method of the string class to find all occurrences of each word in our vector<string> words.
 * Then, we calculate the starting and ending indices for each occurrence and add both indices to a vector<int> indices
 * which we then add to our vector<vector<int>> result. Sort our vector<vector<int>> result and return it.
 *
 * Time complexity: O(w * L * n) + O(p log p) [where w is the length of the vector<string> words, L is the average length of a word,
 * n is the length of the input string text, and p is the number of resulting index pairs]
 *
 * Space complexity: O(p) [where p is the number of resulting index pairs]
 */

vector<vector<int>> indexPairs(string text, vector<string> & words)
{
    vector<vector<int>> result;

    if(text.empty() || words.empty())
    {
        return result;
    }

    for(const auto & word : words)
    {
        auto position=text.find(word);

        while(position!=string::npos)
        {
            vector<int> indices(2, 0);

            indices[0]=position;

            indices[1]=int(position + word.size() - 1);

            result.push_back(indices);

            position=text.find(word, position + 1);
        }
    }

    sort(result.begin(), result.end(), [] (const auto & e1, const auto & e2)
    {
        if(e1[0]==e2[0])
        {
            return e1[1] < e2[1];
        }
        else
        {
            return e1[0] < e2[0];
        }
    });

    return result;
}