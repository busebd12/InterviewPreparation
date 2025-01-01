#include <deque>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

/*
All solutions based on these resources:

1) https://www.youtube.com/watch?v=ZyB_gQ8vqGA
2) https://www.youtube.com/watch?v=8MpoO2zA2l4
3) https://www.youtube.com/watch?v=xR4sGgwtR2I
4) https://leetcode.com/problems/reconstruct-itinerary/solutions/78846/very-short-iterative-java-solution/
*/

class Solution
{
    public:
        vector<string> findItinerary(vector<vector<string>> & tickets)
        {
            vector<string> result;

            unordered_map<string, priority_queue<string, vector<string>, greater<string>>> hashmap;

            for(vector<string> ticket : tickets)
            {
                string departing=ticket[0];

                string arriving=ticket[1];

                if(hashmap.find(departing)==hashmap.end())
                {
                    hashmap.emplace(departing, priority_queue<string, vector<string>, greater<string>>());
                }
                
                hashmap[departing].push(arriving);
            }

            deque<string> eulerPath;

            deque<string> stack;

            stack.emplace_back("JFK");

            while(!stack.empty())
            {
                string departing=stack.back();

                if(hashmap.find(departing)!=hashmap.end() and !hashmap[departing].empty())
                {
                    string arriving=hashmap[departing].top();

                    hashmap[departing].pop();

                    stack.push_back(arriving);
                }
                else
                {
                    eulerPath.push_front(departing);

                    stack.pop_back();
                }
            }

            while(!eulerPath.empty())
            {
                result.push_back(eulerPath.front());

                eulerPath.pop_front();
            }

            return result;
        }
};

class Solution
{
    public:
        vector<string> findItinerary(vector<vector<string>> & tickets)
        {
            vector<string> result;

            auto compareLikeThis=[] (const vector<string> & lhs, const vector<string> & rhs)
            {
                if(lhs[0]!=rhs[0])
                {
                    return lhs[0] < rhs[0];
                }
                else
                {
                    return lhs[1] < rhs[1];
                }
            };

            sort(tickets.begin(), tickets.end(), compareLikeThis);

            unordered_map<string, deque<string>> hashmap;

            for(vector<string> & ticket : tickets)
            {
                string departing=ticket[0];

                string arriving=ticket[1];

                if(hashmap.find(departing)==hashmap.end())
                {
                    hashmap.emplace(departing, deque<string>());
                }

                hashmap[departing].push_back(arriving);
            }

            deque<string> eulerPath;

            deque<string> stack;

            stack.emplace_back("JFK");

            while(!stack.empty())
            {
                string departing=stack.back();

                if(hashmap.find(departing)!=hashmap.end() and !hashmap[departing].empty())
                {
                    string arriving=hashmap[departing].front();

                    hashmap[departing].pop_front();

                    stack.push_back(arriving);
                }
                else
                {
                    eulerPath.push_front(departing);

                    stack.pop_back();
                }
            }

            while(!eulerPath.empty())
            {
                result.push_back(eulerPath.front());

                eulerPath.pop_front();
            }

            return result;
        }
};