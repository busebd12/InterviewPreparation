#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * Solutions
 *
 * 1. Use two for loops to create all pairs of phrases. If the last word of one phrase is the same as the
 * starting word of another phrase, then the two phrases form a puzzle. We use a std::set<std::string> to
 * accomplish two things: keep the resulting puzzles distinct and sorted. We then copy the contents our
 * the std::set<std::string> into our std::vector<std::string> and return the vector.
 *
 * Time complexity: O(n^2 * log(n)) [where n is the number of phrases]
 * Space complexity: O(d) [where d is the number of distinct puzzles]
 *
 * 2. For two phrases to form a valid puzzle, then the prefix of one phrase must be the same as the suffix of the other phrase.
 * Based on that observation, we use a hashtable (std::unordered_map<std::string, int>) to map each prefix of every phrase
 * to the phrases that have that prefix. Then, for each phrase, we determine its suffix. If the suffix is in the hashtable,
 * then we know another phrase has this suffix as its prefix and we can combine the two phrases to form a valid puzzle.
 *
 * Time complexity: O(n * p) [where n is the number of phrases and p is the number of shared prefixes]
 * Space complexity: O(n)
 */

std::string getFirstWord(std::string & str)
{
    auto firstSpaceIndex=str.find_first_of(' ');

    return (firstSpaceIndex!=std::string::npos) ? str.substr(0, firstSpaceIndex) : "";
}

std::string getLastWord(std::string & str)
{
    auto lastSpaceIndex=str.find_last_of(' ');

    return (lastSpaceIndex!=std::string::npos) ? str.substr(lastSpaceIndex + 1, std::string::npos) : "";
}

std::string getRest(std::string & str)
{
    auto firstSpaceIndex=str.find_first_of(' ');

    return (firstSpaceIndex!=std::string::npos) ? str.substr(firstSpaceIndex + 1, std::string::npos) : "";
}

std::vector<std::string> beforeAndAfterPuzzles(std::vector<std::string> & phrases)
{
    std::vector<std::string> result;

    if(phrases.empty())
    {
        return result;
    }

    std::set<std::string> uniques;

    int N=int(phrases.size());

    for(auto i=0;i<N;++i)
    {
        for(auto j=0;j<N;++j)
        {
            if(i!=j)
            {
                auto firstPhrase=phrases[i];

                auto secondPhrase=phrases[j];

                auto firstPhraseLastWord=getLastWord(firstPhrase);

                if(firstPhraseLastWord.empty())
                {
                    firstPhraseLastWord=firstPhrase;
                }

                auto secondPhraseFirstWord=getFirstWord(secondPhrase);

                if(secondPhraseFirstWord.empty())
                {
                    secondPhraseFirstWord=secondPhrase;
                }

                if(firstPhraseLastWord==secondPhraseFirstWord)
                {
                    auto restOfSecondPhrase=getRest(secondPhrase);

                    std::string puzzle=firstPhrase;

                    if(!restOfSecondPhrase.empty())
                    {
                        puzzle+=" " + restOfSecondPhrase;
                    }

                    if(!uniques.count(puzzle))
                    {
                        uniques.insert(puzzle);
                    }
                }
            }
        }
    }

    for(const auto & puzzle : uniques)
    {
        result.emplace_back(puzzle);
    }

    return result;
}

std::vector<std::string> beforeAndAfterPuzzles(std::vector<std::string> & phrases)
{
    std::vector<std::string> result;

    if(phrases.empty())
    {
        return result;
    }

    int N=int(phrases.size());

    std::set<std::string> uniques;

    std::unordered_map<std::string, std::vector<int>> hashtable;

    for(int i=0;i<N;++i)
    {
        std::stringstream ss(phrases[i]);

        std::string prefix{};

        ss >> prefix;

        hashtable[prefix].emplace_back(i);
    }

    for(int j=0;j<N;++j)
    {
        auto phrase=phrases[j];

        std::string suffix{};

        std::stringstream ss(phrase);

        while(ss >> suffix);

        if(hashtable.count(suffix))
        {
            while(!phrase.empty() && phrase.back()!=' ')
            {
                phrase.pop_back();
            }

            for(int i : hashtable[suffix])
            {
                if(i!=j)
                {
                    std::string puzzle=phrase + phrases[i];

                    if(!uniques.count(puzzle))
                    {
                        uniques.insert(puzzle);
                    }
                }
            }
        }
    }

    for(const auto & puzzle : uniques)
    {
        result.emplace_back(puzzle);
    }

    return result;
}