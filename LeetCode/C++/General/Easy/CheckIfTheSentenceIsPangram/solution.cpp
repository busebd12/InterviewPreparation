#include <string>
#include <vector>
using namespace std;

/*
Time complexity: O(n)
Space complexity: O(26) --> O(1)
*/

class Solution
{
    public:
        bool checkIfPangram(string sentence)
        {
            vector<int> frequencies(26, 0);

            for(char & letter : sentence)
            {
                int index=letter - 'a';

                frequencies[index]+=1;
            }

            for(int i=0;i<26;i++)
            {
                if(frequencies[i]==0)
                {
                    return false;
                }
            }

            return true;
        }
};