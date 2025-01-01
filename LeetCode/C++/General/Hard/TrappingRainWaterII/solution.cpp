#include <array>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O((rows * columns) * log(rows * columns))
Space complexity: O(rows * columns)
*/

class Solution
{
    public:
        int trapRainWater(vector<vector<int>> & heightMap)
        {
            int result=0;

            int rows=heightMap.size();

            int columns=heightMap[0].size();

            vector<vector<bool>> visited(rows, vector<bool>(columns, false));

            //Custom heap comparator
            auto compareLikeThis=[] (const tuple<int, int, int> & lhs, const tuple<int, int, int> & rhs)
            {
                return get<0>(lhs) > get<0>(rhs);
            };

            //Minimum heap sorted by the height (smallest on top) where each element is a tuple of the form {height, row, column}
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(compareLikeThis)> minHeap(compareLikeThis);

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    //Add the boundary heights to the min heap
                    if(row==0 or row==rows-1 or column==0 or column==columns-1)
                    {
                        int height=heightMap[row][column];
                        
                        minHeap.emplace(height, row, column);

                        //Mark the boundary cells as visited
                        visited[row][column]=true;
                    }
                }
            }

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            /*Keep track of the largest neighbour height
            //The volume of water that can be trapped is not only bounded by the maximum values in each direction,
            //it's also bounded by other heights along paths leading to any of the grid edges.
            //In other words, the volume that can be trapped at any given cell can be bounded by (potentially) any other
            //cell in the grid, not just its immediate four-direction neighbour cells
            //Hence, we need a "global" variable to keep track of the largest neighbour height*/
            int largestNeighbourHeightSoFar=numeric_limits<int>::min();

            while(!minHeap.empty())
            {
                auto [height, row, column]=minHeap.top();

                minHeap.pop();

                //As we are using a minimum heap, the value for largestNeighbourHeightSoFar will slowly get larger as more elements are removed from the heap (smaller heights will be removed earlier)
                largestNeighbourHeightSoFar=max(largestNeighbourHeightSoFar, height);

                //Iterate through all four directions from the current cell (up, down, left, and right)
                for(auto & [rowOffset, columnOffset] : directions)
                {
                    int nextRow=row + rowOffset;

                    int nextColumn=column + columnOffset;

                    bool isValid=((0 <= nextRow and nextRow < rows) and (0 <= nextColumn and nextColumn < columns));

                    //If the next cell is in a valid position and it hasn't been visited yet
                    if(isValid==true and visited[nextRow][nextColumn]==false)
                    {
                        //If the neighbouring cells is shorter than the largest neighbouring height we've seen so far, then we can trap some amount of water
                        if(largestNeighbourHeightSoFar > heightMap[nextRow][nextColumn])
                        {
                            int waterTrapped=largestNeighbourHeightSoFar - heightMap[nextRow][nextColumn];

                            result+=waterTrapped;
                        }

                        //Add neighbouring cells to the heap
                        minHeap.emplace(heightMap[nextRow][nextColumn], nextRow, nextColumn);

                        //Mark the neighbouring cells as visited
                        visited[nextRow][nextColumn]=true;
                    }
                }
            }

            return result;
        }
};