#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: inspired by this blog post --> https://leetcode.com/problems/exclusive-time-of-functions/discuss/1889699/CPP-O(n)-time-using-stack

Time complexity: O(n) [where n is the length of logs]
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<string> parseLog(string log)
        {
            vector<string> parts;
            
            stringstream ss(log);
            
            char delimiter=':';
            
            string token{};
            
            while(getline(ss, token, delimiter))
            {
                parts.emplace_back(token);
            }
            
            return parts;
        }
        
        vector<int> exclusiveTime(int n, vector<string> & logs)
        {
            vector<int> result(n, 0);
            
            unordered_map<int, int> functionsToExecutionTime;
            
            int currentTime=0;
            
            deque<int> stack;
            
            for(auto log : logs)
            {   
                auto parts=parseLog(log);
                
                int functionId=stoi(parts[0]);
                
                int timestamp=stoi(parts[2]);
                
                if(parts[1]=="start")
                {
                    if(!stack.empty())
                    {
                        functionsToExecutionTime[stack.back()]+=(timestamp - currentTime);
                    }
                    
                    currentTime=timestamp;
                    
                    stack.emplace_back(functionId);
                }
                else
                {
                    functionsToExecutionTime[stack.back()]+=(timestamp - currentTime) + 1;
                    
                    currentTime=timestamp + 1;
                    
                    stack.pop_back();
                }
            }
            
            for(auto & [functionId, executionTime] : functionsToExecutionTime)
            {
                result[functionId]=executionTime;
            }
            
            return result;
        }
};