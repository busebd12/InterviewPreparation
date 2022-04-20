#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution 1: Brute force.

Time complexity: O(u * L) [where u is the number of updates and L is the average length of an update interval]
Space complexity: O(1)
*/

class Solution
{
    public:
        vector<int> getModifiedArray(int length, vector<vector<int>> & updates)
        {
            vector<int> result(length, 0);
            
            for(auto & update : updates)
            {
                int start=update[0];
                
                int end=update[1];
                
                int increment=update[2];
                
                for(int index=start;index<=end;index++)
                {
                    result[index]+=increment;
                }
            }
            
            return result;
        }
};


/*
Solution 2: see comments.

Time complexity: O(n + u) [where n is the number of updates and u is the number of unique update intervals]
Space complexity: O(u)
*/

class Solution
{
    public:
        vector<int> getModifiedArray(int length, vector<vector<int>> & updates)
        {
            vector<int> result(length, 0);
            
            //<key, value> map where the key is a string composed of the start and end values for each update interval separated by a -
            //and the value is the total increment value. Since unordered_map doesn't allow duplicate keys, all update intervals that
            //are the same will be represented by one key
            unordered_map<string, int> intervalToIncrement;
            
            //Iterate through the intervals
            for(auto & update : updates)
            {
                int intervalStart=update[0];
                
                int intervalEnd=update[1];
                
                int increment=update[2];
                
                //Create the key
                string key=to_string(intervalStart) + "-" + to_string(intervalEnd);
                
                //If the hashtable doesn't have the key yet, map the key to the increment value
                if(intervalToIncrement.find(key)==end(intervalToIncrement))
                {
                    intervalToIncrement[key]=increment;
                }
                //Else, the hashtable does have the key so just add to the already existing increment value
                else
                {
                    intervalToIncrement[key]+=increment;
                }
            }
            
            //Iterate through the hashtable
            for(auto & [key, increment] : intervalToIncrement)
            {
                auto dashIndex=key.find('-');
                
                //Parse out the start index of the intervl
                int start=stoi(key.substr(0, dashIndex));
                
                //Prase out the end index of the interval
                int end=stoi(key.substr(dashIndex + 1, string::npos));
                
                //Loop over the interval and apply the increment to the indices
                for(int index=start;index<=end;index++)
                {
                    result[index]+=increment;
                }
            }
            
            return result;
        }
};