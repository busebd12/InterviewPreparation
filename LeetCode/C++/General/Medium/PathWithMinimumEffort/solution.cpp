#include <array>
#include <cmath>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

/*
Solution: inspired by this post --> https://leetcode.com/problems/path-with-minimum-effort/discuss/1988458/Java-oror-BFS-%2B-PriorityQueue-oror-Easy-to-Understand

Time complexity: O(rows * columns * log(rows * columns))
Space complexity: O(row * columns)
*/

class Solution
{
    public:
        int minimumEffortPath(vector<vector<int>>& heights)
        {
            int rows=heights.size();
            
            int columns=heights[0].size();
            
            vector<vector<int>> efforts(rows, vector<int>(columns, numeric_limits<int>::max()));
            
            efforts[0][0]=0;
            
            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
            
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
            
            vector<int> start{0, 0, 0};
            
            minHeap.push(start);
            
            while(!minHeap.empty())
            {
                vector<int> current=minHeap.top();
                
                minHeap.pop();
                
                int currentRow=current[0];
                
                int currentColumn=current[1];
                
                int currentEffort=current[2];
                
                for(auto & [rowOffset, columnOffset] : directions)
                {
                    int nextRow=currentRow + rowOffset;

                    int nextColumn=currentColumn + columnOffset;

                    bool isValid=((nextRow >= 0 && nextRow < rows) && (nextColumn >= 0 && nextColumn < columns));

                    if(isValid==true)
                    {
                        int nextEffort=max(currentEffort, abs(heights[currentRow][currentColumn] - heights[nextRow][nextColumn]));

                        if(nextEffort < efforts[nextRow][nextColumn])
                        {
                            efforts[nextRow][nextColumn]=nextEffort;
                            
                            vector<int> next{nextRow, nextColumn, nextEffort};
                            
                            minHeap.push(next);
                        }
                    }
                }
            }
            
            return efforts[rows - 1][columns - 1];
        }
};