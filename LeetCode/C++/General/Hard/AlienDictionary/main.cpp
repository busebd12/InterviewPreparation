#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * Solution: Breadth-first search + topological sort. Inspired from this explanation --> https://leetcode.com/problems/alien-dictionary/solution/
 *
 * Time complexity: O((w * l) + (w * min(length of word1, length of word2))) + u + (u * n))
 * Space complexity: O(u)
 *
 * [w=number of words; l=average length of a word;u=number of unique letters;n=number of neighbours]
 */

std::string alienOrder(std::vector<std::string> & words)
{
    std::string result{};

    std::unordered_map<char, std::vector<char>> adjacencyLists;

    std::unordered_map<char, int> indegrees;

    for(const auto & word : words)
    {
        for(const auto & letter : word)
        {
            indegrees[letter]=0;

            adjacencyLists.insert(std::make_pair(letter, std::vector<char>()));
        }
    }

    auto n=int(words.size());

    for(auto index=0;index<n-1;++index)
    {
        auto word1=words[index];

        auto word2=words[index+1];

        auto itrPair=std::mismatch(word1.begin(), word1.end(), word2.begin());

        if(word1.length() > word2.length())
        {
            if(itrPair.second==word2.end())
            {
                return result;
            }
        }

        if(itrPair.first!=word1.end() && itrPair.second!=word2.end())
        {
            char vertex1=*(itrPair.first);

            char vertex2=*(itrPair.second);

            adjacencyLists[vertex1].emplace_back(vertex2);

            indegrees[vertex2]++;
        }
    }

    std::queue<char> Q;

    for(auto & [key, value] : indegrees)
    {
        if(value==0)
        {
            Q.emplace(key);
        }
    }


    while(!Q.empty())
    {
        auto currentLetter=Q.front();

        Q.pop();

        result+=currentLetter;

        for(auto & neighbour : adjacencyLists[currentLetter])
        {
            indegrees[neighbour]--;

            if(indegrees[neighbour]==0)
            {
                Q.emplace(neighbour);
            }
        }
    }

    if(result.size() < indegrees.size())
    {
        return "";
    }

    return result;
}