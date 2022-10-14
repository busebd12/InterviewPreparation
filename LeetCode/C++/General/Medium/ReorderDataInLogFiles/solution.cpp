#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/*
Time complexity: O(n * log(l)) [where n is the total number of logs and l is the number of letter logs]
Space complexity: O(l)
*/

class Solution
{
    public:
        vector<string> reorderLogFiles(vector<string> & logs)
        {
            vector<string> result;
            
            //Custom comparator for the minimum heap
            auto compareLikeThis=[] (pair<string, string> & lhs, pair<string, string> & rhs)
            {
                if(lhs.second==rhs.second)
                {
                    return lhs.first > rhs.first;
                }
                else
                {
                    return lhs.second > rhs.second;
                }
            };
    
            //Minimum heap used to sort the letter logs
            priority_queue<pair<string, string>, vector<pair<string, string>>, decltype(compareLikeThis)> minHeap(compareLikeThis);
            
            //Iterate through the letter logs
            for(string log : logs)
            {
                auto firstSpaceIndex=log.find_first_of(" ");
                
                string identifier=log.substr(0, firstSpaceIndex);
                
                string contents=log.substr(firstSpaceIndex + 1, string::npos);
                
                //Check to make sure the log is a letter log
                if(isalpha(contents[0]))
                {
                    //Add it to the min heap
                    minHeap.emplace(make_pair(identifier, contents));
                }
            }
            
            //Remove the sorted letter logs from the min heap and add them our result
            while(!minHeap.empty())
            {
                auto [identifier, contents]=minHeap.top();
                
                minHeap.pop();
                
                result.emplace_back(identifier + " " + contents);
            }
            
            //Iterate one more time through the logs
            for(string log : logs)
            {
                auto firstSpaceIndex=log.find_first_of(" ");
                
                string identifier=log.substr(0, firstSpaceIndex);
                
                string contents=log.substr(firstSpaceIndex + 1, string::npos);
                
                //If the log is a digit log
                if(isdigit(contents[0]))
                {
                    //Add it to our result
                    result.push_back(log);
                }
            }
            
            return result;
        }
};