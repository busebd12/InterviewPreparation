#include <queue>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: minimum heap + breadth-first search.

Time complexity: O(m + n log n) [where m=length of meetings]
Space complexity: O(n)
*/

class Solution
{
    public:
        vector<int> findAllPeople(int n, vector<vector<int>> & meetings, int firstPerson)
        {
            vector<int> result;

            vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());

            //Build graph based on meetings
            for(vector<int> & meeting : meetings) //O(m)
            {
                int personX=meeting[0];

                int personY=meeting[1];

                int meetingTime=meeting[2];

                graph[personX].emplace_back(personY, meetingTime);

                graph[personY].emplace_back(personX, meetingTime);
            }

            //Add the extra relationship to person 0 to first person in the graph
            graph[0].emplace_back(firstPerson, 0);

            //Minimum heap used during breadth-first search
            //Elements of minimum heap is a pair of the form {meeting time, person}
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

            int startPerson=0;

            int startMeetingTime=0;

            minHeap.emplace(startMeetingTime, startPerson);

            vector<bool> sharedSecretWith(n, false);

            while(!minHeap.empty()) //O(n log n)
            {
                auto [meetingTime, person]=minHeap.top();

                minHeap.pop();

                if(sharedSecretWith[person]==true)
                {
                    continue;
                }

                result.push_back(person);

                sharedSecretWith[person]=true;

                for(auto & [neighbour, nextMeetingTime] : graph[person])
                {
                    //Make sure we only include meetings that start at the same time of or after the current meeting
                    if(nextMeetingTime >= meetingTime)
                    {
                        minHeap.emplace(nextMeetingTime, neighbour);
                    }
                }
            }

            return result;
        }
};