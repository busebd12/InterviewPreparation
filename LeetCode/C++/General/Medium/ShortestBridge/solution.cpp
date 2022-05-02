#include <array>
#include <deque>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
    public:
        void dfs(vector<vector<int>> & grid, vector<vector<bool>> & visited, deque<pair<int, int>> & queue, int rows, int columns, int row, int column)
        {
            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            queue.emplace_back(row, column);

            visited[row][column]=true;

            deque<pair<int, int>> stack;

            stack.emplace_back(row, column);

            while(!stack.empty())
            {
                auto [currentRow, currentColumn]=stack.back();

                stack.pop_back();

                for(auto & [rowOffset, columnOffset] : directions)
                {
                    int nextRow=currentRow + rowOffset;

                    int nextColumn=currentColumn + columnOffset;

                    bool onGrid=((nextRow >= 0 && nextRow < rows) && (nextColumn >= 0 && nextColumn < columns));

                    if(onGrid==true && grid[nextRow][nextColumn]==1 && visited[nextRow][nextColumn]==false)
                    {
                        stack.emplace_back(nextRow, nextColumn);

                        visited[nextRow][nextColumn]=true;

                        queue.emplace_back(nextRow, nextColumn);
                    }
                }
            }
        }

        int shortestBridge(vector<vector<int>> & grid)
        {
            int result=0;

            int rows=grid.size();

            int columns=grid[0].size();

            vector<vector<bool>> visited(rows, vector<bool>(columns, false));

            deque<pair<int, int>> queue;

            bool firstIslandFound=false;

            for(int row=0;row<rows;row++)
            {
                //Once we find all the ones in the first island, we want to break since we will use breadth-first search to find the second island
                if(firstIslandFound==true)
                {
                    break;
                }

                for(int column=0;column<columns;column++)
                {
                    if(grid[row][column]==1)
                    {
                        //Use depth-first search to mark all 1's in the first island we come across as found
                        dfs(grid, visited, queue, rows, columns, row, column);

                        firstIslandFound=true;

                        break;
                    }
                }
            }

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            //At this point, one island has been "discovered" and now we execute breadth-first search from every 1 in the discovered island to search for a 1 in the second island
            while(!queue.empty())
            {
                auto qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    auto [currentRow, currentColumn]=queue.front();

                    queue.pop_front();

                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        int nextRow=currentRow + rowOffset;

                        int nextColumn=currentColumn + columnOffset;

                        bool onGrid=((nextRow >= 0 && nextRow < rows) && (nextColumn >= 0 && nextColumn < columns));

                        if(onGrid==true && visited[nextRow][nextColumn]==false)
                        {
                            //Found a 1 from the second island
                            //The result variable now holds the minimum number of zeros we need to flip in order to build the bridge
                            if(grid[nextRow][nextColumn]==1)
                            {
                                return result;
                            }

                            queue.emplace_back(nextRow, nextColumn);

                            visited[nextRow][nextColumn]=true;
                        }
                    }
                }

                result+=1;
            }

            return -1;
        }
};