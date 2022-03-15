#include <string>
#include <vector>
using namespace std;

/*
Solution: see comments for details

Time complexity: O(n) [where n is the length of start and end]
Space complexity: O(n + L + R) [where n is the length of start and end, L is the number of L characters, and R is the number of R characters]
*/
class Solution
{
    public:
        bool canTransform(string start, string end)
        {
            int n=start.size();

            //Copy of the start string with no X's
            string startWithNoX{};

            for(char c : start)
            {
                if(c!='X')
                {
                    startWithNoX.push_back(c);
                }
            }

            //Copy of the end string with no X's
            string endWithNoX{};

            for(char c : end)
            {
                if(c!='X')
                {
                    endWithNoX.push_back(c);
                }
            }
    
            //If the start string and end string with no X's aren't the same, then no transformation is possible
            if(startWithNoX!=endWithNoX)
            {
                return false;
            }

            //Store the indices of L and R characters from the start and end strings
            vector<int> startLIndices;

            vector<int> startRIndices;

            for(int i=0;i<n;i++)
            {
                if(start[i]=='L')
                {
                    startLIndices.emplace_back(i);
                }

                if(start[i]=='R')
                {
                    startRIndices.emplace_back(i);
                }
            }

            //Store the indices of L and R characters from the start and end strings
            vector<int> endLIndices;

            vector<int> endRIndices;

            for(int i=0;i<n;i++)
            {
                if(end[i]=='L')
                {
                    endLIndices.emplace_back(i);
                }

                if(end[i]=='R')
                {
                    endRIndices.emplace_back(i);
                }
            }

            int i=0;

            int j=0;

            //Iterate over the indices of the L characters in the start and end strings
            while(i < startLIndices.size() && j < endLIndices.size())
            {
                //The XL to LX move means L characters can only move to the left
                //I.e. L characters in the end string have to be either in the same position or to the left their original index in the start string
                //So, if the index of a L character in the end string is greater than the index in the start string, then it did not move to the left
                if(endLIndices[j] > startLIndices[i])
                {
                    return false;
                }

                i++;

                j++;
            }

            i=0;

            j=0;

            //Iterate over the indices of the R characters in the start and end strings
            while(i < startRIndices.size() && j < endRIndices.size())
            {
                //The RX to XR move means R characters can only move to the right
                //I.e. R characters in the end string have to be either in the same position or to the right their original index in the start string
                //So, if the index of a R character in the end string is less than the index in the start string, then it did not move to the right
                
                if(endRIndices[i] < startRIndices[j])
                {
                    return false;
                }

                i++;

                j++;
            }

            return true;
        }
};