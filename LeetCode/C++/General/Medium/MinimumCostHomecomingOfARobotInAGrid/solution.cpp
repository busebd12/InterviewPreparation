#include <array>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

/*
Solution 1: Find the minimum cost path using a priority_queue as we traverse the grid. Note, this solution receives Time Limit Exceeded when executed.

Time complexity: O(rows * columns * log(4 * rows * columns))
Space complexity: O(rows * columns)
*/

class Solution
{
    public:
        int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts)
        {
            int result=0;

            int rows=rowCosts.size();

            int columns=colCosts.size();

            const int INF=numeric_limits<int>::max();

            vector<vector<int>> costs(rows, vector<int>(columns, INF));

            costs[startPos[0]][startPos[1]]=0;

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            auto customComparator=[] (tuple<int, int, int> & lhs, tuple<int, int, int> & rhs)
            {
                return get<2>(lhs) > get<2>(rhs);
            };

            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(customComparator)> minHeap(customComparator);

            minHeap.emplace(startPos[0], startPos[1], 0);

            while(!minHeap.empty())
            {
                auto [row, column, cost]=minHeap.top();

                minHeap.pop();

                if(row==homePos[0] and column==homePos[1])
                {
                    result=cost;

                    break;
                }

                for(auto & [rowOffset, columnOffset] : directions)
                {
                    int nextRow=row + rowOffset;

                    int nextColumn=column + columnOffset;

                    bool isValid=((nextRow >= 0 and nextRow < rows) and (nextColumn >= 0 and nextColumn < columns));

                    if(isValid==true)
                    {
                        int nextCost=cost;

                        if(nextRow!=row)
                        {
                            nextCost+=rowCosts[nextRow];
                        }

                        if(nextColumn!=column)
                        {
                            nextCost+=colCosts[nextColumn];
                        }

                        if(nextCost < costs[nextRow][nextColumn])
                        {
                            costs[nextRow][nextColumn]=nextCost;
                            
                            minHeap.emplace(nextRow, nextColumn, nextCost);
                        }
                    }
                }
            }

            return result;
        }
};

/*
Solution 2: Breadth-first search/traversal. Note, this solution receives Time Limit Exceeded when executed.

Time complexity: O(rows * columns)
Space complexity: O(rows * columns)
*/

class Solution
{
    public:
        int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts)
        {
            int result=0;

            int rows=rowCosts.size();

            int columns=colCosts.size();

            const int INF=numeric_limits<int>::max();

            vector<vector<int>> costs(rows, vector<int>(columns, INF));

            costs[startPos[0]][startPos[1]]=0;

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            deque<tuple<int, int, int>> queue;

            queue.emplace_back(startPos[0], startPos[1], 0);

            while(!queue.empty())
            {   
                auto [row, column, cost]=queue.front();

                queue.pop_front();

                for(auto & [rowOffset, columnOffset] : directions)
                {
                    int nextRow=row + rowOffset;

                    int nextColumn=column + columnOffset;

                    bool isValid=((nextRow >= 0 and nextRow < rows) and (nextColumn >= 0 and nextColumn < columns));

                    if(isValid==true)
                    {
                        int nextCost=cost;

                        if(nextRow!=row)
                        {
                            nextCost+=rowCosts[nextRow];
                        }

                        if(nextColumn!=column)
                        {
                            nextCost+=colCosts[nextColumn];
                        }

                        if(nextCost < costs[nextRow][nextColumn])
                        {
                            costs[nextRow][nextColumn]=nextCost;
                            
                            queue.emplace_back(nextRow, nextColumn, nextCost);
                        }
                    }
                }
            }

            result=costs[homePos[0]][homePos[1]];

            return result;
        }
};

/*
Solution 3: Since all shortest paths have the minimum cost, just add up the cost of all the rows and columns
starting from the startPos and ending at homePos. Then, subtract the cost of startPos.

Time complexity: O(rows * columns)
Space complexity: O(1)
*/

class Solution
{
    public:
        int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts)
        {
            int result=0;

            int rows=rowCosts.size();

            int columns=colCosts.size();

            for(int row=min(startPos[0], homePos[0]);row<=max(startPos[0], homePos[0]);row++)
            {
                result+=rowCosts[row];
            }

            for(int column=min(startPos[1], homePos[1]);column<=max(startPos[1], homePos[1]);column++)
            {
                result+=colCosts[column];
            }

            result-=rowCosts[startPos[0]];

            result-=colCosts[startPos[1]];

            return result;
        }
};