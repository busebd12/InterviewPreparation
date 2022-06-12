#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(n + (u log u) + k)
[where n=number of logs; u=unique log ids]

Space complexity: O(u + t) [where t is number of UAM]
*/

class Solution
{
    public:
        vector<int> findingUsersActiveMinutes(vector<vector<int>> & logs, int k)
        {
            vector<int> result(k, 0);
            
            unordered_map<int, unordered_set<int>> idToTimes;
            
            //Map each user id to a list of unique minutes
            for(vector<int> & log : logs) //O(n) [where n is the number of logs]
            {
                int id=log[0];
                
                int time=log[1];
                
                if(idToTimes.find(id)==end(idToTimes))
                {
                    idToTimes[id]=unordered_set<int>();
                }
                
                if(idToTimes[id].find(time)==end(idToTimes[id]))
                {
                    idToTimes[id].insert(time);
                }
            }
            
            map<int, vector<int>> hashtable;
            
            //Group user ids by total unique active minutes
            //So, Number of UAM --> {id1, id2, id3, etc}
            for(auto & [id, times] : idToTimes) //O(u) [where u is the number of unique ids]
            {
                if(hashtable.find(times.size())==end(hashtable))
                {
                    hashtable[times.size()]=vector<int>();
                }
                
                hashtable[times.size()].emplace_back(id); //O(log(u))
            }
            
            //Populate output vector
            for(int j=1;j<=k;j++) //O(k)
            {
                if(hashtable.find(j)!=end(hashtable))
                {   
                    result[j - 1]=hashtable[j].size();
                }
            }
            
            return result;
        }
};