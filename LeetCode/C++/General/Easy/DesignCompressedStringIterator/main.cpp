#include <iostream>
#include <deque>
#include <string>
using namespace std;

/*
 * Approach: Separate the contents of the compressed string into two deques, one for the numbers and one for the letters.
 * Then, set the frequency for the first letter. Each time we call the next function, we check to see if either
 * of the deques are empty. If they are, then we know there are no more characters, and we can return the ' ' character.
 * If the hasNext() function returns true, then we return the character at the front of the deque holding the characters
 * and decrement its frequency. Once the frequency of the current letter reaches zero, we remove the first element
 * from each of the deques and use the new front of each deque and the new current character and current frequency.
 *
 * Time complexity for the populate function: O(n) [where n is the length of the compressed string]
 * Space complexity for the populate function: O(n)
 *
 * Time complexity for the next() function: O(n)
 * Space complexity for the next() function: O(1)
 *
 * Time complexity for the hasNext() function: O(1)
 * Space complexity for the hasNext() function: O(1)
 */

class StringIterator
{
    public:
        deque<int> frequencies;

        deque<char> letters;

        int frequency;

        StringIterator(string compressedString)
        {
            populate(compressedString);

            frequency=frequencies.front();
        }

        char next()
        {
            char c{};

            if(hasNext())
            {
                if(frequency > 0)
                {
                    c=letters.front();

                    frequency--;

                    if(frequency==0)
                    {
                        letters.pop_front();

                        frequencies.pop_front();

                        frequency=frequencies.front();
                    }
                }
            }
            else
            {
                c=' ';
            }

            return c;
        }

        bool hasNext()
        {
            if(letters.empty() || frequencies.empty())
            {
                return false;
            }

            return true;
        }

        void populate(string compressedString)
        {
            if(compressedString.empty())
            {
                return;
            }

            int n=int(compressedString.size());

            for(int i=0;i<n;)
            {
                if(isdigit(compressedString[i]))
                {
                    string str{};

                    while(isdigit(compressedString[i]))
                    {
                        str+=compressedString[i];

                        i++;
                    }

                    frequencies.push_back(stoi(str));
                }
                else
                {
                    letters.emplace_back(compressedString[i]);

                    i++;
                }
            }
        }
};