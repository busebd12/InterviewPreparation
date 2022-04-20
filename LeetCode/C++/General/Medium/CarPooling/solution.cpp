#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

/*
Solution 1: see comments.

Time complexity: O(n log n) [where n is the length of trips]
Space complexity: O(n)
*/

class Solution
{
    public:
        bool carPooling(vector<vector<int>> & trips, int capacity)
        {   
            int n=trips.size();
            
            auto comparator=[] (auto & lhs, auto & rhs)
            {
                //If the starting point for two trips is the same
                if(lhs[1]==rhs[1])
                {
                    //Compare based on the destination point
                    return lhs[2] < rhs[2]; 
                }
                else
                {
                    //Compare based on the starting point
                    return lhs[1] < rhs[1];
                }
            };
            
            //Sort trips based on custom comparator defined above
            sort(begin(trips), end(trips), comparator);
            
            //Custom heap comparator
            //Since priority_queues are, by default, max heaps in C++, we need to use the > operator in our comparator to get a min heap
            auto heapComparator=[] (auto & lhs, auto & rhs){return lhs.first > rhs.first;};
            
            //Min heap storing pairs - where each pair is the trip destination and number of passengers for that trip
            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(heapComparator)> minHeap(heapComparator);
            
            //Keep track of the total number of riders throughout the trips
            int riders=0;
            
            for(auto & trip : trips)
            {
                int people=trip[0];
                
                int startingPoint=trip[1];
                
                int destination=trip[2];
                
                //While the heap is not empty and the destination is <= to the starting point for the current trip
                //All passengers whose trips end at this destination depart
                while(!minHeap.empty() && minHeap.top().first <= startingPoint)
                {
                    auto [destination, passengers]=minHeap.top();
                    
                    minHeap.pop();
                    
                    riders-=passengers;
                }
                
                minHeap.emplace(destination, people);
                
                //Increment the total number of riders
                riders+=people;
                
                //More riders than we have capacity
                if(riders > capacity)
                {
                    return false;
                }
            }
            
            return true;
        }
};

/*
Solution 2: inspired by this post --> https://leetcode.com/problems/car-pooling/discuss/1669928/C%2B%2B-EASY-TO-SOLVE-oror-Beginner-friendly-step-by-step-guide

Time complexity: O(n log n) [where n is the length of trips]
Space complexity: O(n)
*/

class Solution
{
    public:
        bool carPooling(vector<vector<int>> & trips, int capacity)
        {   
            int n=trips.size();
            
            map<int, int> hashtable;
            
            //For each trip
            for(auto trip : trips)
            {
                int passengers=trip[0];
                
                int startingPoint=trip[1];
                
                int destination=trip[2];
                
                //At the pick-up point, take on passengers
                hashtable[startingPoint]+=passengers;
                
                //At the destination, drop passengers off
                hashtable[destination]-=passengers;
            }
            
            for(auto & [key, value] : hashtable)
            {
                //Subtract the passengers
                capacity-=value;
                
                if(capacity < 0)
                {
                    return false;
                }
            }
            
            return true;
        }
};