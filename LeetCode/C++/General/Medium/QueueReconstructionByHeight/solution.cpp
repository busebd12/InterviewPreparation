#include <algorithm>
#include <list>
#include <queue>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/queue-reconstruction-by-height/discuss/2214066/C%2B%2B-faster-than-99.73-with-linkedlist
*/

class Solution
{
    public:
        vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
        {
            vector<vector<int>> result;
            
            int p=people.size();
            
            auto compareLikeThis=[] (vector<int> & lhs, vector<int> & rhs)
            {
                //If two people have the same height
                if(lhs[0]==rhs[0])
                {
                    //Whoever has the least amount of people in front of them goes first
                    return lhs[1] < rhs[1];
                }
                //Else, both people are different heights
                else
                {
                    //Put the taller person before the shorter person
                    return lhs[0] > rhs[0];
                }
            };
            
            //Sort based on our custom comparator
            sort(begin(people), end(people), compareLikeThis);
            
            
            list<vector<int>> queue;
            
            //Iterate through the sorted list of people
            for(vector<int> & person : people)
            {
                auto itr=begin(queue);
                
                //Starting from the front of the queue, iterate backwards by how many people are supposed to be in front of the current person in the queue
                for(int place=0;place<person[1];place++)
                {
                    itr++;
                }
                
                //Insert the person at the correct spot in the queue
                queue.insert(itr, person);
            }
            
            //Populate the result vector
            for(vector<int> & person : queue)
            {
                result.push_back(person);
            }
            
            return result;
        }
};