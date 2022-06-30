#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(c * log(c)) + O(c * log(c)) [where c is the total number of courses]
Space complexity: O(c)
*/

class Solution
{
    public:
        int scheduleCourse(vector<vector<int>> & courses)
        {
            int result=0;
            
            int c=courses.size();
            
            //Custom sort comparator to sort the courses based on last day
            auto sortComparator=[] (vector<int> & lhs, vector<int> & rhs)
            {
                return lhs[1] < rhs[1];
            };
            
            //Sort the courses in increasing order of last day
            sort(begin(courses), end(courses), sortComparator); //O(c * log(c)) [where c is the total number of courses]
            
            //Maximum heap used to store the largest duration on top
            priority_queue<int, vector<int>, less<int>> maxHeap;
            
            int totalDuration=0;
            
            //Iterate through the courses
            for(int i=0;i<c;i++) //O(c)
            {
                int duration=courses[i][0];
                
                int lastDay=courses[i][1];
                
                //If we can take the course
                if(totalDuration + duration <= lastDay)
                {
                    totalDuration+=duration;
                    
                    maxHeap.emplace(duration); //O(log(c))
                }
                //Else, we can't take the course, so let's see if we can replace the course with the longest duration with this one
                else
                {
                    if(!maxHeap.empty() && maxHeap.top() > duration)
                    {
                        totalDuration-=maxHeap.top();

                        maxHeap.pop();

                        totalDuration+=duration;

                        maxHeap.emplace(duration); //(log(c))
                    }
                }
            }
            
            result=maxHeap.size();
            
            return result;
        }
};