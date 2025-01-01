#include <deque>
#include <string>
#include <vector>
using namespace std;

/*
Time complexity: O(n) [where n is the length of s]
Space complexity: O(n)
*/

class Solution
{
    public:
        string robotWithString(string s)
        {
            string result="";

            vector<int> frequencies(26, 0);

            for(char letter : s)
            {
                int index=letter - 'a';

                frequencies[index]+=1;
            }

            deque<char> stack;

            for(char letter : s)
            {
                stack.push_back(letter);

                int index=letter - 'a';

                //IMPORTANT: make sure we decrement the frequency since we use to frequency to find the smallest letter to the right in the while loop coming up
                frequencies[index]-=1;

                //while the stack and is not empty and the top letter is less than or equal to the smallest letter to the right of it in s
                //IMPORTANT: this smallest letter could be a singleton or have more than one occurrance in the string
                while(!stack.empty() and stack.back() <= getSmallestLetterToTheRight(frequencies))
                {
                    result.push_back(stack.back());

                    stack.pop_back();
                }
            }

            return result;
        }

        char getSmallestLetterToTheRight(vector<int> & frequencies)
        {
            char smallest='z';

            for(int ascii=0;ascii<26;ascii++)
            {
                if(frequencies[ascii] > 0)
                {
                    smallest=ascii + 'a';

                    break;
                }
            }

            return smallest;
        }
};