#include <iostream>
#include <queue>

/*
 * Solution: the first time our function is called, we read all the characters from the file into a std::queue<char>.
 * Then, we read the desired amount of characters from the queue into the buffer and return the number of characters read.
 * For all subsequent calls, we just read the required amount of characters in the buffer from the queue and return the number of characters read.
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

            while(!Q.empty() && totalCharactersRead < n)
            {
                buf[totalCharactersRead]=Q.front();

                Q.pop();

                totalCharactersRead++;
            }

            while(true)
            {
                char nextCharacters[4];

                int charactersReadFromFile=read4(nextCharacters);

                if(charactersReadFromFile==0)
                {
                    break;
                }

                for(int index=0;index<charactersReadFromFile;index++)
                {
                    Q.emplace(nextCharacters[index]);
                }
            }

            while(!Q.empty() && totalCharactersRead < n)
            {
                buf[totalCharactersRead]=Q.front();

                Q.pop();

                totalCharactersRead++;
            }

            return totalCharactersRead;
        }
};