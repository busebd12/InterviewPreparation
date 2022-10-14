#include <string>
#include <vector>
using namespace std;

/*
Time complexity: O(columns * n) [where n is the length of strs and columns is the length of a word in strs]
Space complexity: O(c) [where c is the total number of characters in strs]
*/

class Solution
{
    public:
        int minDeletionSize(vector<string> & strs)
        {
            int result=0;

            int n=strs.size();

            int columns=strs[0].size();

            vector<string> words(n, "");

            for(int column=0;column<columns;column++)
            {
                for(int i=0;i<n;i++)
                {
                    words[i].push_back(strs[i][column]);
                }

                bool isSorted=true;

                for(int i=1;i<n;i++)
                {
                    if(words[i - 1] > words[i])
                    {
                        isSorted=false;
                    }
                }

                if(isSorted==false)
                {
                    for(int i=0;i<n;i++)
                    {
                        words[i].pop_back();
                    }
                }
            }

            result=columns - words[0].size();

            return result;
        }
};