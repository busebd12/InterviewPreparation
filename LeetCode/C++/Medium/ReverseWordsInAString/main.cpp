#include <algorithm>
#include <cctype>
#include <deque>
#include <iostream>
#include <string>

/*
 * Solution: the algorithm works as follows
 *
 * 1. Handle edge cases --> if the string is empty, return s. If the string has only spaces, return the empty string.
 *
 * 2. Loop over all the spaces in the front of the string.
 *
 * 3. Iterate through the rest of the string and parse out the individual words and put them in a std::deque<std::string>
 * front-first. This way, the words will be reversed when we remove them from the std::deque front-first.
 *
 * 4. While the std::deque is not empty, remove each word from the front of the std::deque and add it to s. If the
 * word is not the last word in the std::deque, add a space after it.
 *
 * 5. Return the input string.
 *
 * Time complexity: O(n) [where n is the length of the input string]
 * Space complexity: O(m) [where m is the number of non-space characters]
 */

class Solution
{
    public:

        std::string reverseWords(std::string s)
        {
            if(s.empty())
            {
                return s;
            }

            if(std::all_of(s.begin(), s.end(), [] (const auto & character) {return std::isspace(character);}))
            {
                return "";
            }

            std::deque<std::string> words;

            int n=int(s.size());

            int index=0;

            while(index < n && std::isspace(s[index]))
            {
                index++;
            }

            std::string word{};

            while(index < n)
            {
                while(index < n && !std::isspace(s[index]))
                {
                    word+=s[index];

                    index++;
                }

                words.emplace_front(word);

                word.clear();

                while(index < n && std::isspace(s[index]))
                {
                    index++;
                }
            }

            s.clear();

            while(!words.empty())
            {
                s+=words.front();

                if(words.size() > 1)
                {
                    s+=" ";
                }

                words.pop_front();
            }

            return s;
        }
};