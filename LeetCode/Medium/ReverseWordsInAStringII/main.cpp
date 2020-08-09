#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

/*
 * Solutions:
 *
 * 1. The idea is to create individual words in the string and add each of them to the front of a std::deque<std::string>.
 * By doing this, we achieve the desired reversal. Then, we simply remove each word from the std::deque<std::string> and
 * add each character back into the input std::vector<char> and add the spaces at the appropriate spots.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(c) [where c is the number of non-space characters]
 *
 * 2. Almost the same as the first solution except that we override the contents of the input vector with the reversed
 * characters instead of clearing the contents of the input vector before adding the reversed characters.
 *
 * Time complexity: O(n) [where n is the length of the input vector]
 * Space complexity: O(c) [where c is the number of non-space characters]
 */

class Solution
{
    public:
        void reverseWords(std::vector<char> & s)
        {
            if(s.empty())
            {
                return;
            }

            std::deque<std::string> dq;

            int n=int(s.size());

            std::string word{};

            for(int i=0;i<n;i++)
            {
                if(!std::isspace(s[i]))
                {
                    word+=s[i];
                }
                else
                {
                    dq.emplace_front(word);

                    word.clear();
                }
            }

            dq.emplace_front(word);

            s.clear();

            while(!dq.empty())
            {
                auto w=dq.front().size();

                for(auto i=0;i<w;i++)
                {
                    s.emplace_back(dq.front()[i]);
                }

                if(dq.size() > 1)
                {
                    s.emplace_back(' ');
                }

                dq.pop_front();
            }
        }
};

class Solution
{
    public:
        void reverseWords(std::vector<char> & s)
        {
            if(s.empty())
            {
                return;
            }

            std::deque<std::string> dq;

            int n=int(s.size());

            std::string word{};

            for(int i=0;i<n;i++)
            {
                if(!std::isspace(s[i]))
                {
                    word+=s[i];
                }
                else
                {
                    dq.emplace_front(word);

                    word.clear();
                }
            }

            dq.emplace_front(word);

            int index=0;

            while(!dq.empty())
            {
                auto w=dq.front().size();

                for(auto i=0;i<w;i++)
                {
                    s[index]=(dq.front()[i]);

                    index++;
                }

                if(dq.size() > 1)
                {
                    s[index]=' ';

                    index++;
                }

                dq.pop_front();
            }
        }
};