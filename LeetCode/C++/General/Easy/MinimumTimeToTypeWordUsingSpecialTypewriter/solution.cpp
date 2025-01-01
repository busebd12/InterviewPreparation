#include <string>
#include <vector>
using namespace std;

/*
Solution 1

Time complexity: O(w + (26^3)) => O(w + (17576)) => O(w) [where w is the length of word]
Space complexity: O(26 * 26) => O(676) => O(1)
*/

class Solution
{
    public:
        int minTimeToType(string word)
        {
            int result=0;

            vector<vector<int>> hashmap;

            hashmap.resize(26, vector<int>(26, 0));

            for(char letter='a';letter<='z';letter++) //O(26)
            {
                for(char target='a';target<='z';target++) //O(26)
                {
                    if(target!=letter)
                    {
                        int clockwise=getClockwiseDistance(letter, target); //O(26)

                        int counterclockwise=getCounterClockwiseDistance(letter, target); //O(26)

                        hashmap[letter - 'a'][target - 'a']=min(clockwise, counterclockwise);
                    }
                }
            }

            char pointer='a';

            for(char letter : word) //O(w)
            {
                int distanceToLetter=hashmap[pointer - 'a'][letter - 'a'];

                result+=distanceToLetter;

                result+=1;

                pointer=letter;
            }

            return result;
        }

        int getClockwiseDistance(char letter, char target)
        {
            int clockwise=0;

            char c=letter;

            for(;c<='z';c++)
            {
                if(c==target)
                {
                    break;
                }

                clockwise+=1;
            }

            if(c!=target)
            {
                c='a';

                while(c!=target)
                {
                    clockwise+=1;
                    
                    c++;
                }
            }

            return clockwise;
        }

        int getCounterClockwiseDistance(char letter, char target)
        {
            int counterclockwise=0;

            char c=letter;

            for(;c>='a';c--)
            {
                if(c==target)
                {
                    break;
                }

                counterclockwise+=1;
            }

            if(c!=target)
            {
                c='z';

                while(c!=target)
                {
                    c--;

                    counterclockwise+=1;
                }
            }

            return counterclockwise;
        }
};

/*
Solution 2

Time complexity: O(w) [where w is the length of word]
Space complexity: O(1)
*/

class Solution
{
    public:
        int minTimeToType(string word)
        {
            int result=0;

            char pointer='a';

            for(char letter : word)
            {
                int clockwise=abs(pointer - letter);

                int counterClockwise=26 - abs(letter - pointer);

                int distanceToLetter=min(clockwise, counterClockwise);

                result+=distanceToLetter;

                result+=1;

                pointer=letter;
            }

            return result;
        }
};