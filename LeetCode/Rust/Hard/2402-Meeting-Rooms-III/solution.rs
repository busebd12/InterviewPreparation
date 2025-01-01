use std::collections::{BinaryHeap};
use std::cmp;

impl Solution
{
    pub fn most_booked(n: i32, mut meetings: Vec<Vec<i32>>) -> i32
    {
        let mut result: i32=0;

        meetings.sort();

        let mut meetings_held_per_room: Vec<i32>=vec![0; n as usize];

        let mut available_meeting_rooms: BinaryHeap<std::cmp::Reverse<i32>>=BinaryHeap::new();

        let mut rooms_in_use: BinaryHeap<std::cmp::Reverse<(i64, i32)>>=BinaryHeap::new();

        for meeting_room in 0..n
        {
            available_meeting_rooms.push(std::cmp::Reverse(meeting_room));
        }

        let mut most_meetings_held: i32=0;

        for meeting in meetings.iter()
        {
            let current_meeting_start: i64=meeting[0] as i64;

            let current_meeting_end: i64=meeting[1] as i64;

            while let Some(std::cmp::Reverse((ending_time, room)))=rooms_in_use.peek()
            {
                if *ending_time <= current_meeting_start
                {
                    if let Some(std::cmp::Reverse((ending_time, room)))=rooms_in_use.pop()
                    {
                        available_meeting_rooms.push(std::cmp::Reverse(room));
                    }
                }
                else
                {
                    break;
                }
            }

            if let Some(std::cmp::Reverse(room))=available_meeting_rooms.pop()
            {
                meetings_held_per_room[room as usize]+=1;

                rooms_in_use.push(std::cmp::Reverse((current_meeting_end, room)));

                most_meetings_held=std::cmp::max(most_meetings_held, meetings_held_per_room[room as usize]);
            }
            else
            {
                if let Some(std::cmp::Reverse((ending_time, room)))=rooms_in_use.pop()
                {
                    meetings_held_per_room[room as usize]+=1;

                    let current_meeting_duration: i64=current_meeting_end - current_meeting_start;

                    let delayed_meeting_ending_time: i64=ending_time + current_meeting_duration;

                    rooms_in_use.push(std::cmp::Reverse((delayed_meeting_ending_time, room)));

                    most_meetings_held=std::cmp::max(most_meetings_held, meetings_held_per_room[room as usize]);
                }
            }
        }

        for room in 0..n
        {
            if meetings_held_per_room[room as usize]==most_meetings_held
            {
                result=room;

                break;
            }
        }

        result
    }
}