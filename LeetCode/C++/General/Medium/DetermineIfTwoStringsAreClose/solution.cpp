#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Time complexity: O(n + m) [where n is the length of word1 and m is the length of word2]
Space complexity: O(26 + u + v) [where u is the unique character frequencies from word1 and v is the unique character frequencies from word2]
*/

class Solution
{
    public:
        bool closeStrings(string word1, string word2)
        {
            int n=word1.size();

            int m=word2.size();

            if(n!=m)
            {
                return false;
            }

            vector<int> word1Frequencies(26, 0);

            for(char letter : word1)
            {
                int index=letter - 'a';

                word1Frequencies[index]+=1;
            }

            vector<int> word2Frequencies(26, 0);

            for(char letter : word2)
            {
                int index=letter - 'a';

                word2Frequencies[index]+=1;
            }

            for(int asciiValue=0;asciiValue<26;asciiValue++)
            {
                bool characterExistsInWord1Only=word1Frequencies[asciiValue] > 0 and word2Frequencies[asciiValue]==0;

                bool characterExistsInWord2Only=word1Frequencies[asciiValue]==0 and word2Frequencies[asciiValue] > 0;

                if(characterExistsInWord1Only or characterExistsInWord2Only)
                {
                    return false;
                }
            }

            unordered_map<int, int> hashmap;

            for(int frequency : word1Frequencies)
            {
                hashmap[frequency]+=frequency;
            }

            for(int frequency : word2Frequencies)
            {
                hashmap[frequency]-=frequency;
            }

            for(auto & [frequency, amount] : hashmap)
            {
                if(amount!=0)
                {
                    return false;
                }
            }

            return true;
        }
};