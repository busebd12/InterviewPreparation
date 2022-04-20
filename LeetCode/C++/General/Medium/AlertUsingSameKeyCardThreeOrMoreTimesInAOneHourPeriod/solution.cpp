#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O((n log n) + (u * (n log n)) + (u * t))
[where n is the length of keyName and keyTime, u is the number of unique keyNames, and t is the number of key times associated with each keyName]

Space complexity: O(u)
*/

class Solution
{
    public:
        int getTotalMinutes(string timePoint)
        {
            int colonIndex=timePoint.find(':');
            
            int hours=stoi(timePoint.substr(0, colonIndex));
            
            int minutes=stoi(timePoint.substr(colonIndex + 1, string::npos));
            
            int totalMinutes=(hours * 60) + minutes;
            
            return totalMinutes;
        }
    
        vector<string> alertNames(vector<string> & keyName, vector<string> & keyTime)
        {
            vector<string> result;

            int n=keyName.size();

            //Hashtable that we use to map employee names to times their key-card was used during the day
            map<string, vector<int>> nameToKeyTimesMap;

            //Create name to key time mappings
            for(int i=0;i<n;i++) //O(n log n)
            {
                string name=keyName[i];

                string time=keyTime[i];
                
                //Get the total minutes represented by the 24-hour time point
                int totalMinutes=getTotalMinutes(time);

                nameToKeyTimesMap[name].emplace_back(totalMinutes);
            }

            for(auto & [name, times] : nameToKeyTimesMap) //O(u * (n log n))
            {
                //Sort key-card times for each employee in ascending order based on the total minutes for each 24-hour time point
                sort(begin(times), end(times), [] (auto & lhs, auto & rhs) {return lhs < rhs;});
            }

            for(auto & [name, times] : nameToKeyTimesMap) //O(u * t)
            {
                //Employee used their key card at least three times
                if(times.size() >= 3)
                {
                    int t=times.size();
                    
                    for(int i=2;i<t;i++)
                    {
                        //Check the total minutes difference between the third time point and the first
                        //If the difference is less than or equal to 60, then we've found a group of three times that the employee used their key-card within an hour
                        //Since the times are sorted in ascending order, the second amount of minutes has to fall between the first and third amount of minutes
                        if((times[i] - times[i - 2]) <= 60)
                        {
                            //Add the employee name to the result
                            result.emplace_back(name);
                            
                            break;
                        }
                    }
                }
            }

            return result;
        }
};