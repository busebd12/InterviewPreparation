#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * Approach: there are two cases to consider
 *
 * a) If all the letters are greater than our target (ascii value wise) or there is a mix of larger and smaller letters.
 * In this case, we take the smallest letter larger than our target letter.
 *
 * b) All the letters are smaller than our target. In this case, we choose the first possible letter
 *
 * Time complexity: O(n) [where n is the length of the letters vector]
 * Space complexity: O(1)
 */

char nextGreatestLetter(vector<char> & letters, char target)
{
    if(letters.empty())
    {
        return target;
    }

    bool allLarger=all_of(letters.begin(), letters.end(), [target] (char & c) {return c > target;});

    bool allSmaller=all_of(letters.begin(), letters.end(), [target] (char & c) {return c < target;});

    char result{};

    if(allLarger || (!allLarger && !allSmaller))
    {
        result=*min_element(letters.begin(), letters.end(), [] (char & c1, char & c2) {return c1 < c2;});

        if(result==target || result < target)
        {
            char candidate{};

            for(char & letter : letters)
            {
                if(letter > target)
                {
                    candidate=letter;

                    break;
                }
            }

            for(char & letter : letters)
            {
                if(letter <= candidate && letter > target)
                {
                    result=letter;
                }
            }
        }
    }
    else
    {
        result=*min_element(letters.begin(), letters.end(), [target] (char & c1, char & c2) {return c1 < c2;});
    }

    return result;
}