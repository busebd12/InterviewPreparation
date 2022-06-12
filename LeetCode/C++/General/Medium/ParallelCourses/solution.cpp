#include <deque>
#include <vector>
using namespace std;

/*
Solution: Breadth-first search and topological sort.

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution
{
    public:
        int minimumSemesters(int n, vector<vector<int>> & relations)
        {
            int result=0;
            
            vector<vector<int>> graph(n + 1);
            
            vector<int> indegree(n + 1);
            
            //Iterate through the relations
            for(vector<int> & relation : relations)
            {
                int prevCourse=relation[0];
                
                int nextCourse=relation[1];
                
                //Build edge in the graph between prevCourse and nextCourse
                graph[prevCourse].push_back(nextCourse);
                
                //Calculate the indegree for each "nextCourse"
                indegree[nextCourse]+=1;
            }
            
            //Queue for topological sort
            deque<int> queue;
            
            //Iterate through all the courses
            for(int course=1;course<=n;course++)
            {
                //If a course has an indegree of zero, then it is a pre-requisite for another course and we should take that course first
                if(indegree[course]==0)
                {
                    queue.emplace_back(course);
                }
            }
            
            //Keep track of how many courses we've finished/taken
            int finished=0;
            
            //Do topological sort
            while(!queue.empty())
            {
                size_t qSize=queue.size();
                
                for(size_t count=0;count<qSize;count++)
                {
                    int course=queue.front();
                    
                    queue.pop_front();

                    finished+=1;
                    
                    //Iterate through all the course for which the current course is a pre-requisite
                    for(int nextCourse : graph[course])
                    {
                        indegree[nextCourse]-=1;
                        
                        //If the indegree for the nextCourse is zero, then we have taken all the necessary pre-requisites for it and we can add it to the queue
                        if(indegree[nextCourse]==0)
                        {
                            queue.push_back(nextCourse);
                        }
                    }
                }
                
                result+=1;
            }
            
            return finished==n ? result : -1;
        }
};