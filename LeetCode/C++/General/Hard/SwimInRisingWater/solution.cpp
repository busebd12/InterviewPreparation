#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

class Solution
{
    public:
        int swimInWater(vector<vector<int>> & grid)
        {
            int result=0;

            int rows=grid.size();

            int columns=grid[0].size();

            auto compareLikeThis=[] (tuple<int, int, int> & lhs, tuple<int, int, int> & rhs)
            {
                return get<0>(lhs) > get<0>(rhs);
            };

            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(compareLikeThis)> minHeap(compareLikeThis);

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            int startRow=0;

            int startColumn=0;
            
            int startTime=grid[startRow][startColumn];

            minHeap.emplace(startTime, startRow, startColumn);

            grid[startRow][startColumn]=-1;

            while(!minHeap.empty())
            {
                auto [currentTime, currentRow, currentColumn]=minHeap.top();
                
                minHeap.pop();

                result=max(result, currentTime);

                if(currentRow==rows - 1 and currentColumn==columns - 1)
                {
                    break;
                }

                for(auto & [rowOffset, columnOffset] : directions)
                {
                    int nextRow=currentRow + rowOffset;

                    int nextColumn=currentColumn + columnOffset;

                    bool isValid=((0 <= nextRow and nextRow < rows) and (0 <= nextColumn and nextColumn < columns));

                    if(isValid==true and grid[nextRow][nextColumn] >= 0)
                    {   
                        int nextTime=grid[nextRow][nextColumn];
                        
                        minHeap.emplace(nextTime, nextRow, nextColumn);

                        grid[nextRow][nextColumn]=-1;
                    }
                }
            }

            return result;
        }
};