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
    private:
        char buf4[4]={0};

        int buf4Pointer=0;

        int buf4Size=0;
    
    public:
        /**
        * @param buf Destination buffer
        * @param n   Number of characters to read
        * @return    The number of actual characters read
        */
        int read(char *buf, int n)
        {
            int totalCharactersRead=0;

            while(totalCharactersRead < n)
            {
                //If there is data left in buf4 from a previous call of read, read that data into buf
                if(buf4Pointer < buf4Size)
                {
                    buf[totalCharactersRead]=buf4[buf4Pointer];

                    totalCharactersRead+=1;

                    buf4Pointer+=1;
                }
                //Else, no data remaining from previous call to read
                else
                {
                    //How many characters left to be read
                    int charactersLeft=n - totalCharactersRead;

                    //If characters left is at least 4, then we can read them directly into buf and skip copying them into buf4 and then copying them from buf4 into buf
                    if(charactersLeft >= 4)
                    {
                        int charactersRead=read4(buf + totalCharactersRead);

                        //No more characters to read, return the total amount read from the file
                        if(charactersRead==0)
                        {
                            return totalCharactersRead;
                        }

                        totalCharactersRead+=charactersRead;
                    }
                    //Else, less than four characters left, so we just read them into buf4 and we will copy them into buf later
                    else
                    {
                        //Read characters from the file into buf4
                        buf4Size=read4(buf4);

                        //Reset the buf4Pointer
                        buf4Pointer=0;

                        //If we read zero characters from the file, then there are no more characters to be read
                        if(buf4Size==0)
                        {
                            return totalCharactersRead;
                        }
                    }
                }
            }

            return totalCharactersRead;
        }
    };