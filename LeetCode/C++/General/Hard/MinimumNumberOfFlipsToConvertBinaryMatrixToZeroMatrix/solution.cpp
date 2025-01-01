#include <algorithm>
#include <array>
#include <deque>
#include <set>
#include <vector>
using namespace std;

/*
Solution 1: breadth-first search + visited set

Time complexity: O((rows * columns) * 2^(rows * columns))
Space complexity: O(2^(rows * columns))
*/

class Solution
{
    public:
        int minFlips(vector<vector<int>> & mat)
        {
            int result=0;

            int rows=mat.size();

            int columns=mat[0].size();

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            set<vector<vector<int>>> visited;

            deque<vector<vector<int>>> queue;

            queue.push_back(mat);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    auto current=queue.front();

                    queue.pop_front();

                    if(isZeroMatrix(current)==true)
                    {
                        return result;
                    }

                    if(visited.find(current)!=visited.end())
                    {
                        continue;
                    }

                    visited.insert(current);

                    for(int row=0;row<rows;row++)
                    {
                        for(int column=0;column<columns;column++)
                        {
                            vector<vector<int>> copy=current;

                            if(copy[row][column]==1)
                            {
                                copy[row][column]=0;
                            }
                            else
                            {
                                copy[row][column]=1;
                            }

                            for(auto & [rowOffset, columnOffset] : directions)
                            {
                                int nextRow=row + rowOffset;

                                int nextColumn=column + columnOffset;

                                bool valid=((0 <= nextRow and nextRow < rows) and (0 <= nextColumn and nextColumn < columns));

                                if(valid==true)
                                {
                                    if(copy[nextRow][nextColumn]==1)
                                    {
                                        copy[nextRow][nextColumn]=0;
                                    }
                                    else
                                    {
                                        copy[nextRow][nextColumn]=1;
                                    }
                                }
                            }

                            queue.push_back(copy);
                        }
                    }
                }

                result+=1;
            }

            return -1;
        }

        bool isZeroMatrix(vector<vector<int>> & matrix)
        {
            for(vector<int> & row : matrix)
            {
                if(all_of(row.begin(), row.end(), [] (int & value) {return value==0;})==false)
                {
                    return false;
                }
            }

            return true;
        }
};

/*
Solution 2: breath-first search + bit manipulation.

Based on this post --> https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/solutions/446342/java-python-3-convert-matrix-to-int-bfs-and-dfs-codes-w-explanation-comments-and-analysis/

Time complexity: O(2^(rows * columns))
Space complexity: O(2^(rows * columns))
*/

class Solution
{
    public:
        int minFlips(vector<vector<int>> & mat)
        {
            int result=0;

            int rows=mat.size();

            int columns=mat[0].size();

            array<pair<int, int>, 5> directions={{{0, 0},{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            int start=0;

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    int k=(row * columns) + column;
                    
                    start=start | (mat[row][column] << k);
                }
            }

            unordered_set<int> visited;

            deque<int> queue;

            queue.push_back(start);

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    int current=queue.front();

                    queue.pop_front();

                    if(current==0)
                    {
                        return result;
                    }

                    if(visited.find(current)!=visited.end())
                    {
                        continue;
                    }

                    visited.insert(current);

                    for(int row=0;row<rows;row++)
                    {
                        for(int column=0;column<columns;column++)
                        {
                            int next=current;

                            for(auto & [rowOffset, columnOffset] : directions)
                            {
                                int nextRow=row + rowOffset;

                                int nextColumn=column + columnOffset;

                                bool valid=((0 <= nextRow and nextRow < rows) and (0 <= nextColumn and nextColumn < columns));

                                if(valid==true)
                                {
                                    int k=(nextRow * columns) + nextColumn;

                                    next=next ^ (1 << k);
                                }
                            }

                            queue.push_back(next);
                        }
                    }
                }

                result+=1;
            }

            return -1;
        }
};