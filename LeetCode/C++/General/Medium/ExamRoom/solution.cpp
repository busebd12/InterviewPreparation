#include <iterator>
#include <set>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/exam-room/discuss/177949/C%2B%2B-set-solution-with-detailed-comments
*/

class ExamRoom
{
    private:
        set<int> seats;
    
        int students;
    
    public:

        ExamRoom(int N)
        {
            students=N;
        }

        int seat()
        {
            int studentToSit=0;
            
            int dist=0;
            
            if(!seats.empty())
            {
                auto previousSeat=begin(seats);
                
                if(*(previousSeat)!=0)
                {
                    dist=*(previousSeat);
                    
                    studentToSit=0;
                }
                
                for(auto currentSeat=next(previousSeat);currentSeat!=end(seats);currentSeat=next(currentSeat))
                {
                    int currentDist=(*(currentSeat) - *(previousSeat)) / 2;
                    
                    if(currentDist > dist)
                    {
                        studentToSit=*(previousSeat) + currentDist;
                        
                        dist=currentDist;
                    }
                    
                    previousSeat=currentSeat;
                }
                
                previousSeat=prev(end(seats));
                
                if(students - *(previousSeat) - 1 > dist)
                {
                    studentToSit=students - 1;
                }
            }
            
            seats.insert(studentToSit);
            
            return studentToSit;
        }

        void leave(int p)
        {
            seats.erase(p);
        }
};