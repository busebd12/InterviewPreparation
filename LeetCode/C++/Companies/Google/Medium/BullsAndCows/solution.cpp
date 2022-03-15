#include <string>
#include <vector>

/*
Solution: see comments for details

Time complexity: O(n) [where n is the length of secret and guess]
Space complexity: O(10) => O(1)
*/

class Solution
{
    public:
        string getHint(string secret, string guess)
        {
            vector<int> hashtable(10, 0);

            int n=int(secret.size());

            int bulls=0;

            int cows=0;

            //Calculate the number of bulls
            for(int i=0;i<n;++i)
            {
                //Guess character matches secret character
                if(guess[i]==secret[i])
                {
                    bulls++;
                }
                //Guess character does not match secret character, so this is a potential cow
                else
                {
                    hashtable[secret[i] - '0']++;
                }
            }

            //Calculate the number of cows
            for(int i=0;i<n;++i)
            {
                //If the guess character does not match the secret character and there are still more than zero of this character, then it can be a cow
                if(guess[i]!=secret[i] && hashtable[guess[i] - '0'] > 0)
                {
                    hashtable[guess[i] - '0']--;

                    cows++;
                }
            }

            //Create the hint
            string hint{};

            hint+=(to_string(bulls) + "A" + to_string(cows) + "B");

            return hint;
        }
};