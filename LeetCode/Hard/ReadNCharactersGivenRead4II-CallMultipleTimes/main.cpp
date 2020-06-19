#include <iostream>
#include <queue>

/*
 * Solution: inspired from this post --> https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/discuss/613198/Simple-and-short-c%2B%2B-with-queue-beats-100-memory-%2B-runtime
 *
 * Time complexity: O(c) [where c is the number of times the read function is called]
 * Space complexity: O(m) [where m is the number of characters in the file being read from]
 */

class Solution
{
    public:
        std::queue<char> Q;

        /**
         * @param buf Destination buffer
         * @param n   Number of characters to read
         * @return    The number of actual characters read
         */
        int read(char *buf, int n)
        {
            int totalCharactersRead=0;

            while(totalCharactersRead < n && !Q.empty())
            {
                buf[totalCharactersRead]=Q.front();

                Q.pop();

                totalCharactersRead++;
            }

            while(totalCharactersRead < n)
            {
                char nextCharacters[4];

                int charactersReadFromFile=read4(nextCharacters);

                int i=0;

                for(;i<charactersReadFromFile;i++)
                {
                    if(totalCharactersRead==n)
                    {
                        Q.push(nextCharacters[i]);
                    }
                    else
                    {
                        buf[totalCharactersRead]=nextCharacters[i];

                        totalCharactersRead++;
                    }
                }

                if(i==charactersReadFromFile && charactersReadFromFile < 4)
                {
                    break;
                }
            }

            return totalCharactersRead;
        }
};