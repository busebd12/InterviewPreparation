#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * Solution: we use a hashtable (std::unordered_map<std::string, std::vector<std::string>>) to map each file contents
 * to the full directory path of all files that have those contents (paths are stored in a std::vector<std::string>).
 * Then, we loop through the hashtable and any vector that has size greater than or equal to two, that vector
 * gets added to our result std::vector<std::vector<std::string>>.
 *
 * Time complexity: O(n) [where n is the number of strings in the input vector]
 * Space complexity: O(n)
 */

std::vector<std::vector<std::string>> findDuplicate(std::vector<std::string> & paths)
{
    std::vector<std::vector<std::string>> result;

    if(paths.empty())
    {
        return result;
    }

    std::unordered_map<std::string, std::vector<std::string>> hashtable;

    for(auto & path : paths)
    {
        std::string part{};

        std::stringstream ss(path);

        std::string filePath{};

        while(ss >> part)
        {
            std::string fileContents{};

            std::string file{};

            if(part.find('.')!=std::string::npos)
            {
                auto openingParenthesisIndex=part.find_first_of('(');

                file=part.substr(0, openingParenthesisIndex);

                fileContents=part.substr(openingParenthesisIndex, std::string::npos);

                std::string value=filePath + "/" + file;

                hashtable[fileContents].push_back(value);
            }
            else
            {
                filePath=part;
            }
        }
    }

    for(const auto & [key, value] : hashtable)
    {
        if(value.size() >= 2)
        {
            result.push_back(value);
        }
    }

    return result;
}