#include <string>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/swap-adjacent-in-lr-string/discuss/2047353/Python-O(n)-with-comments-and-reasonings

Time complexity: O(n) [where n is the length of start and end]
Space complexity: O(n)
*/

class Solution
{
    public:
        bool canTransform(string start, string end)
        {
            int n=start.size();
            
            string startWithoutX{};
            
            for(char c : start)
            {
                if(c!='X')
                {
                    startWithoutX.push_back(c);
                }
            }
            
            string endWithoutX{};
            
            for(char c : end)
            {
                if(c!='X')
                {
                    endWithoutX.push_back(c);
                }
            }
            
            if(startWithoutX!=endWithoutX)
            {
                return false;
            }
            
            vector<int> startLIndices;
            
            vector<int> startRIndices;
            
            for(int i=0;i<n;i++)
            {
                char c=start[i];
                
                if(c=='L')
                {
                    startLIndices.push_back(i);
                }
                else if(c=='R')
                {
                    startRIndices.push_back(i);
                }
            }
            
            vector<int> endLIndices;
            
            vector<int> endRIndices;
            
            for(int i=0;i<n;i++)
            {
                char c=end[i];
                
                if(c=='L')
                {
                    endLIndices.push_back(i);
                }
                else if(c=='R')
                {
                    endRIndices.push_back(i);
                }
            }
            
            for(int i=0;i<startLIndices.size();i++)
            {
                if(endLIndices[i] > startLIndices[i])
                {
                    return false;
                }
            }
            
            for(int i=0;i<startRIndices.size();i++)
            {
                if(endRIndices[i] < startRIndices[i])
                {
                    return false;
                }
            }
            
            return true;
        }
};