import heapq

class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        result=0

        meetings.sort(key=lambda meeting: meeting[0])

        meetings_held_per_room=[0 for _ in range(0, n)]

        available_meeting_rooms=list()

        rooms_in_use=list()

        for meeting_room in range(0, n):
            heapq.heappush(available_meeting_rooms, meeting_room)

        most_meetings_held=0

        for meeting in meetings:
            current_meeting_start=meeting[0]

            current_meeting_end=meeting[1]

            while rooms_in_use and rooms_in_use[0][0] <= current_meeting_start:
                (ending_time, room)=heapq.heappop(rooms_in_use)

                heapq.heappush(available_meeting_rooms, room)

            if available_meeting_rooms:
                room=heapq.heappop(available_meeting_rooms)

                meetings_held_per_room[room]+=1

                heapq.heappush(rooms_in_use, (current_meeting_end, room))

                most_meetings_held=max(most_meetings_held, meetings_held_per_room[room])
            else:
                (ending_time, room)=heapq.heappop(rooms_in_use)

                meetings_held_per_room[room]+=1

                current_meeting_duration=current_meeting_end - current_meeting_start

                delayed_meeting_ending_time=ending_time + current_meeting_duration

                heapq.heappush(rooms_in_use, (delayed_meeting_ending_time, room))

                most_meetings_held=max(most_meetings_held, meetings_held_per_room[room])

        for room in range(0, n):
            if meetings_held_per_room[room]==most_meetings_held:
                result=room

                break

        return result