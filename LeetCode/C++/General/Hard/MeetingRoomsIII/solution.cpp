#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O((m log m) + (n log n))
Space complexity: O(n + m)
*/

class Solution
{
    public:
        int mostBooked(int n, vector<vector<int>> & meetings)
        {
            int result=0;

            int m=meetings.size();

            int mostMeetingsHeld=0;

            int lastMeetingEndingTime=0;

            //Sort the meetings by start time
            sort(meetings.begin(), meetings.end()); //O(m log m) [where m is the length of meetings]

            //Hashmap used to map each meeting room to the number of meetings held in that room
            vector<int> hashmap(n, 0);

            //Minimum heap used to store pairs of the form {ending time of a meeting, the meeting room number}
            priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> meetingRoomsInUse;

            //Minimum heap used to store pairs of the form {meeting room number, ending time of a meeting held in that room}
            priority_queue<pair<int, long>, vector<pair<int, long>>, greater<pair<int, long>>> freeMeetingRooms;

            //Add each meeting room and a dummy meeting ending time to the freeMeetingRooms minimum heap
            for(int meetingRoom=0;meetingRoom<n;meetingRoom++) //O(n log n)
            {
                freeMeetingRooms.emplace(meetingRoom, -1);
            }

            //Iterate through each meeting
            for(vector<int> meeting : meetings) //O(m)
            {
                //Remove all meetings that ended before or just as the current meeting is about to begin from the meetingRoomsInUse minimum heap  
                while(!meetingRoomsInUse.empty() and meetingRoomsInUse.top().first <= meeting[0])
                {   
                    auto [previousMeetingEndingTime, meetingRoom]=meetingRoomsInUse.top();

                    meetingRoomsInUse.pop(); //O(log(m))

                    freeMeetingRooms.emplace(meetingRoom, previousMeetingEndingTime); //O(log(m))
                }

                //If there is an available meeting room for the current meeting
                if(!freeMeetingRooms.empty())
                {
                    //Remove the free meeting from the min heap
                    auto [meetingRoom, previousMeetingEndingTime]=freeMeetingRooms.top();

                    freeMeetingRooms.pop(); //O(log(m))

                    //Increment the number of meetings held in that room
                    hashmap[meetingRoom]+=1;

                    //Update the value of mostMeetingsHeld
                    mostMeetingsHeld=max(mostMeetingsHeld, hashmap[meetingRoom]);

                    //Add the meeting room to the min heap of in-use meeting rooms
                    meetingRoomsInUse.emplace(meeting[1], meetingRoom); //O(log(m))
                }
                //Else, there isn't a free room for the meeting
                else
                {
                    long delayedMeetingEndingTime=0;

                    //Choose the room that has the meeting which will end the soonest
                    auto [previousMeetingEndingTime, meetingRoom]=meetingRoomsInUse.top();

                    meetingRoomsInUse.pop(); //O(log(m))

                    long currentMeetingLength=(long)meeting[1] - (long)meeting[0];

                    //Calculate the new ending time for the delayed meeting
                    delayedMeetingEndingTime=previousMeetingEndingTime + currentMeetingLength;

                    //Increment the number of meetings held in this meeting room
                    hashmap[meetingRoom]+=1;

                    //Update the mostMeetingsHeld value
                    mostMeetingsHeld=max(mostMeetingsHeld, hashmap[meetingRoom]);

                    //Add the chosen meeting room to the meetingRoomsInUse min heap
                    meetingRoomsInUse.emplace(delayedMeetingEndingTime, meetingRoom); //O(log(m))
                }
            }

            for(int meetingRoom=0;meetingRoom<n;meetingRoom++) //O(n)
            {
                if(hashmap[meetingRoom]==mostMeetingsHeld)
                {
                    result=meetingRoom;

                    break;
                }
            }

            return result;
        }
};