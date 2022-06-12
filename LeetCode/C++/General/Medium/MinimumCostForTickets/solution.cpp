#include <algorithm>
#include <deque>
#include <priority_queue>
#include <utility>
#include <vector>

/*
Solution 1: graph + breadth-first search
*/

class Solution
{
    public:
        int mincostTickets(vector<int> & days, vector<int> & costs)
        {
            int result=0;
            
            vector<vector<pair<int, int>>> graph(400);
            
            vector<int> consecutiveDays={1, 7, 30};
            
            days.emplace_back(399);
            
            for(int day : days)
            {   
                for(int index=0;index<3;index++)
                {
                    auto itr=upper_bound(begin(days), end(days), day + (consecutiveDays[index] - 1));
                    
                    if(itr!=end(days))
                    {
                        int nextDay=*itr;
                    
                        graph[day].emplace_back(nextDay, costs[index]);
                    }
                }
            }
            
            vector<int> travelled(400, numeric_limits<int>::max());
            
            int startDay=days[0];
            
            int endDay=days.back();
            
            deque<pair<int, int>> queue;
            
            queue.emplace_back(startDay, 0);
            
            while(!queue.empty())
            {
                int qSize=queue.size();
                
                for(int count=0;count<qSize;count++)
                {
                    auto [currentDay, currentCost]=queue.front();
                
                    queue.pop_front();

                    for(auto & [day, cost] : graph[currentDay])
                    {
                        int nextCost=currentCost + cost;

                        if(nextCost < travelled[day])
                        {
                            travelled[day]=nextCost;

                            queue.emplace_back(day, nextCost);
                        }
                    }
                }
            }
            
            result=travelled[endDay];
            
            return result;
        }
};

/*
Solution 2: graph + a variation of Dijkstra's algorithm
*/

class Solution
{
    public:
        int mincostTickets(vector<int> & days, vector<int> & costs)
        {
            int result=0;
            
            vector<vector<pair<int, int>>> graph(400);
            
            vector<int> consecutiveDays={1, 7, 30};
            
            days.emplace_back(399);
            
            for(int day : days)
            {
                for(int index=0;index<3;index++)
                {
                    auto itr=upper_bound(begin(days), end(days), day + (consecutiveDays[index] - 1));
                    
                    if(itr!=end(days))
                    {
                        int nextDay=*itr;
                        
                        graph[day].emplace_back(costs[index], nextDay);
                    }
                }
            }
            
            vector<int> travelled(400, numeric_limits<int>::max());
            
            int startDay=days[0];
            
            int endDay=days.back();
            
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
            
            minHeap.emplace(0, startDay);
            
            while(!minHeap.empty())
            {
                auto [currentCost, currentDay]=minHeap.top();
                
                minHeap.pop();
                
                for(auto & [cost, day] : graph[currentDay])
                {
                    int nextCost=currentCost + cost;

                    if(nextCost < travelled[day])
                    {
                        travelled[day]=nextCost;

                        minHeap.emplace(nextCost, day);
                    }
                }
            }
            
            result=travelled[endDay];
            
            return result;
        }
};