#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>

/*
 * Solutions: two variations of breadth-first search. We also use a std::set<std::pair<int, int>> to keep track of which
 * places in the matrix we've visited so we don't keep visiting the same ones over and over again.
 *
 * Time complexity: O((rows * columns) * (number of 1s in the matrix * (rows * columns)))
 * Space complexity: O(rows * columns)
 */

class Solution
{
    public:
        bool onMatrix(int rows, int columns, int row, int column)
        {
            return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
        }

        void bfs(std::vector<std::vector<int>> & matrix, std::vector<std::vector<int>> & result, int rows, int columns, int startingRow, int startingColumn)
        {
            std::queue<std::pair<std::pair<int, int>, int>> Q;

            std::set<std::pair<int, int>> visited;

            Q.emplace(std::make_pair(std::make_pair(startingRow, startingColumn), 0));

            while(!Q.empty())
            {
                auto current=Q.front();

                Q.pop();

                int row=current.first.first;

                int column=current.first.second;

                int dist=current.second;

                if(matrix[row][column]==0)
                {
                    result[startingRow][startingColumn]=dist;

                    break;
                }

                if(visited.count(std::make_pair(row, column)))
                {
                    continue;
                }

                visited.insert(std::make_pair(row, column));

                std::array<std::pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

                for(auto & direction : directions)
                {
                    int nextRow=row + direction.first;

                    int nextColumn=column + direction.second;

                    std::pair<int, int> nextDirectionPair=std::make_pair(nextRow, nextColumn);

                    int nextDistance=dist + 1;

                    if(onMatrix(rows, columns, nextRow, nextColumn))
                    {
                        Q.emplace(std::make_pair(nextDirectionPair, nextDistance));
                    }
                }
            }
        }

        std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> & matrix)
        {
            std::vector<std::vector<int>> result;

            if(matrix.empty())
            {
                return result;
            }

            int rows=int(matrix.size());

            int columns=int(matrix[0].size());

            result.resize(rows, std::vector<int>(columns, -1));

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(matrix[row][column]==1)
                    {
                        bfs(matrix, result, rows, columns, row, column);
                    }
                    else
                    {
                        result[row][column]=0;
                    }
                }
            }

            return result;
        }
};


class Solution
{
    public:
        bool onMatrix(int rows, int columns, int row, int column)
        {
            return ((row >= 0 && row < rows) && (column >= 0 && column < columns));
        }

        void bfs(std::vector<std::vector<int>> & matrix, std::vector<std::vector<int>> & result, int rows, int columns, int startingRow, int startingColumn)
        {
            std::queue<std::pair<int, int>> Q;

            std::set<std::pair<int, int>> visited;

            Q.emplace(std::make_pair(startingRow, startingColumn));

            int dist=0;

            while(!Q.empty())
            {
                auto qSize=Q.size();

                for(auto count=0;count<qSize;count++)
                {
                    auto current=Q.front();

                    Q.pop();

                    int row=current.first;

                    int column=current.second;

                    if(matrix[row][column]==0)
                    {
                        result[startingRow][startingColumn]=dist;

                        return;
                    }

                    if(visited.count(std::make_pair(row, column)))
                    {
                        continue;
                    }

                    visited.insert(std::make_pair(row, column));

                    std::array<std::pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

                    for(auto & direction : directions)
                    {
                        int nextRow=row + direction.first;

                        int nextColumn=column + direction.second;

                        auto nextDirectionPair=std::make_pair(nextRow, nextColumn);

                        if(onMatrix(rows, columns, nextRow, nextColumn))
                        {
                            Q.emplace(nextDirectionPair);
                        }
                    }
                }

                dist++;
            }
        }

        std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> & matrix)
        {
            std::vector<std::vector<int>> result;

            if(matrix.empty())
            {
                return result;
            }

            int rows=int(matrix.size());

            int columns=int(matrix[0].size());

            result.resize(rows, std::vector<int>(columns, -1));

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(matrix[row][column]==1)
                    {
                        bfs(matrix, result, rows, columns, row, column);
                    }
                    else
                    {
                        result[row][column]=0;
                    }
                }
            }

            return result;
        }
};