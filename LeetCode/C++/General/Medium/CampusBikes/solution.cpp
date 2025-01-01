#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O((n * m) + (m * n * log(m * n)) + (n * m))
Space complexity: O(n * m)
*/

class Solution
{
    public:
        vector<int> assignBikes(vector<vector<int>> & workers, vector<vector<int>> & bikes)
        {
            vector<int> result;

            int n=workers.size();

            int m=bikes.size();

            vector<tuple<int, int, int>> tuples;

            //For each worker
            for(int i=0;i<n;i++) //O(n)
            {
                int workerX=workers[i][0];

                int workerY=workers[i][1];
                
                //For each biker
                for(int j=0;j<m;j++) //O(m)
                {
                    int bikeX=bikes[j][0];

                    int bikeY=bikes[j][1];

                    //Calculate the manhattan distance between worker[i] and all bikes
                    int manhattanDistance=getManhattanDistance(workerX, workerY, bikeX, bikeY);

                    //Add tuple of {manhattanDistance, worker index, bike index} to vector of tuples
                    tuples.emplace_back(manhattanDistance, i, j);
                }
            }

            //Custom sort comparator for vector of tuples
            auto compareLikeThis=[] (tuple<int, int, int> & lhs, tuple<int, int, int> & rhs)
            {
                int lhsManhattanDistance=get<0>(lhs);

                int lhsWorkerIndex=get<1>(lhs);

                int lhsBikeIndex=get<2>(lhs);

                int rhsManhattanDistance=get<0>(rhs);

                int rhsWorkerIndex=get<1>(rhs);

                int rhsBikeIndex=get<2>(rhs);

                //Attempt to sort by Manhattan distance
                if(lhsManhattanDistance!=rhsManhattanDistance)
                {
                    return lhsManhattanDistance < rhsManhattanDistance;
                }
                //Attempt to sort by worker index
                else if(lhsWorkerIndex!=rhsWorkerIndex)
                {
                    return lhsWorkerIndex < rhsWorkerIndex;
                }
                //All else fails, sort by bike index
                else
                {
                    return lhsBikeIndex < rhsBikeIndex;
                }
            };

            sort(tuples.begin(), tuples.end(), compareLikeThis); //O(m * n * log(m * n))

            result.resize(n, -1);

            vector<int> assignedBikes(m, -1);

            for(tuple<int, int, int> t : tuples) //O(m * n)
            {
                int workerIndex=get<1>(t);

                int bikeIndex=get<2>(t);

                //If the worker hasn't been assigned a bike, assign them one
                if(result[workerIndex]==-1 and assignedBikes[bikeIndex]==-1)
                {
                    result[workerIndex]=bikeIndex;

                    assignedBikes[bikeIndex]=workerIndex;
                }
            }

            return result;
        }

        int getManhattanDistance(int x1, int y1, int x2, int y2)
        {
            int dx=abs(x1 - x2);

            int dy=abs(y1 - y2);
            
            int manhattanDistance=dx + dy;

            return manhattanDistance;
        }
};