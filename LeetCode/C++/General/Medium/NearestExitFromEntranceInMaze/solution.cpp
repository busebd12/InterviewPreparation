#include <deque>
#include <vector>
using namespace std;

/*
Solution 1: breadth-first search + keeping track of visited spots using external data structure.

Time complexity: O(rows * columns)
Space complexity: O(rows * column)
*/

class Solution
{
    public:
        int nearestExit(vector<vector<char>> & maze, vector<int> & entrance)
        {
            int result=0;

            int rows=maze.size();

            int columns=maze[0].size();

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            vector<vector<bool>> visited(rows, vector<bool>(columns, false));

            int startRow=entrance[0];

            int startColumn=entrance[1];

            deque<pair<int, int>> queue;

            queue.emplace_back(startRow, startColumn);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    auto [row, column]=queue.front();

                    queue.pop_front();

                    if(row==0 or row==rows-1 or column==0 or column==columns-1)
                    {
                        if(row!=startRow or column!=startColumn)
                        {
                            return result;
                        }
                    }

                    if(visited[row][column]==true)
                    {
                        continue;
                    }

                    visited[row][column]=true;

                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        int nextRow=row + rowOffset;

                        int nextColumn=column + columnOffset;

                        bool isValid=((nextRow >= 0 and nextRow < rows) and (nextColumn >= 0 and nextColumn < columns));

                        if(isValid==true and maze[nextRow][nextColumn]!='+')
                        {
                            queue.emplace_back(nextRow, nextColumn);
                        }
                    }
                }

                result+=1;
            }

            return -1;
        }
};

/*
Solution 2: breadth-first search + keeping track of visited spots without using external data structure.

Time complexity: O(rows * columns)
Space complexity: O(rows * column)
*/

class Solution
{
    public:
        int nearestExit(vector<vector<char>>& maze, vector<int> & entrance)
        {
            int result=0;

            int rows=maze.size();

            int columns=maze[0].size();

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            int startRow=entrance[0];

            int startColumn=entrance[1];

            maze[startRow][startColumn]='+';

            deque<pair<int, int>> queue;

            queue.emplace_back(startRow, startColumn);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    auto [row, column]=queue.front();

                    queue.pop_front();

                    if(row==0 or row==rows-1 or column==0 or column==columns-1)
                    {
                        if(row!=startRow or column!=startColumn)
                        {
                            return result;
                        }
                    }

                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        int nextRow=row + rowOffset;

                        int nextColumn=column + columnOffset;

                        bool isValid=((nextRow >= 0 and nextRow < rows) and (nextColumn >= 0 and nextColumn < columns));

                        if(isValid==true and maze[nextRow][nextColumn]!='+')
                        {
                            maze[nextRow][nextColumn]='+';
                            
                            queue.emplace_back(nextRow, nextColumn);
                        }
                    }
                }

                result+=1;
            }

            return -1;
        }
};