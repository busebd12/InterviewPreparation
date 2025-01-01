#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
Time complexity: O(s + t) [where s is the length of start and t is the length of target]
Space complexity: O(s + t)
*/

class Solution
{
    public:
        bool canChange(string start, string target)
        {
            int n=start.size();
            
            int startL=count(start.begin(), start.end(), 'L');

            int startR=count(start.begin(), start.end(), 'R');

            int targetL=count(target.begin(), target.end(), 'L');

            int targetR=count(target.begin(), target.end(), 'R');

            if(startL!=targetL or startR!=targetR)
            {
                return false;
            }

            string startWithoutUnderscores{};

            for(char character : start)
            {
                if(character!='_')
                {
                    startWithoutUnderscores.push_back(character);
                }
            }

            string targetWithoutUnderscores{};

            for(char character : target)
            {
                if(character!='_')
                {
                    targetWithoutUnderscores.push_back(character);
                }
            }

            if(startWithoutUnderscores!=targetWithoutUnderscores)
            {
                return false;
            }

            vector<int> startLIndices;

            vector<int> targetLIndices;

            for(int i=0;i<n;i++)
            {
                if(start[i]=='L')
                {
                    startLIndices.push_back(i);
                }

                if(target[i]=='L')
                {
                    targetLIndices.push_back(i);
                }
            }

            vector<int> startRIndices;

            vector<int> targetRIndices;

            for(int i=0;i<n;i++)
            {
                if(start[i]=='R')
                {
                    startRIndices.push_back(i);
                }

                if(target[i]=='R')
                {
                    targetRIndices.push_back(i);
                }
            }

            for(int i=0;i<startLIndices.size();i++)
            {
                int startLIndex=startLIndices[i];

                int targetLIndex=targetLIndices[i];

                if(targetLIndex > startLIndex)
                {
                    return false;
                }
            }

            for(int i=0;i<startRIndices.size();i++)
            {
                int startRIndex=startRIndices[i];

                int targetRIndex=targetRIndices[i];

                if(targetRIndex < startRIndex)
                {
                    return false;
                }
            }

            return true;
        }
};