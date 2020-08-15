#include <array>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

/*
 * Solution: the idea is put all the gate coordinates in a queue and then perform breadth-first search
 * from each of the gates to calculate the distance to all empty rooms.
 *
 * Time complexity: O((m * n) + (m * n))
 * Space complexity: O(n * m)
 */

class Solution
{
    public:
        bool onGrid(int m, int n, int row, int column)
        {
            return ((row >= 0 && row < m) && (column >= 0 && column < n));
        }

        void wallsAndGates(std::vector<std::vector<int>> & rooms)
        {
            if(rooms.empty())
            {
                return;
            }

            int m=int(rooms.size());

            int n=int(rooms[0].size());

            std::queue<std::pair<int, int>> Q;

            for(int row=0;row<m;row++)
            {
                for(int column=0;column<n;column++)
                {
                    if(rooms[row][column]==0)
                    {
                        Q.emplace(std::make_pair(row, column));
                    }
                }
            }

            int level=1;

            while(!Q.empty())
            {
                int qSize=int(Q.size());

                for(int count=0;count<qSize;count++)
                {
                    auto current=Q.front();

                    Q.pop();

                    int currentRow=current.first;

                    int currentColumn=current.second;

                    std::array<std::pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

                    for(const auto & direction : directions)
                    {
                        int nextRow=currentRow + direction.first;

                        int nextColumn=currentColumn + direction.second;

                        if(onGrid(m, n, nextRow, nextColumn))
                        {
                            if(rooms[nextRow][nextColumn]==std::numeric_limits<int>::max())
                            {
                                rooms[nextRow][nextColumn]=level;

                                Q.emplace(std::make_pair(nextRow, nextColumn));
                            }
                        }
                    }
                }

                level++;
            }
        }
};