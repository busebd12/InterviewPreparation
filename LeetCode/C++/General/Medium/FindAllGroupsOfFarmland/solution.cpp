#include <array>
#include <deque>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> findFarmland(vector<vector<int>> & land)
        {
            vector<vector<int>> result;

            int rows=land.size();

            int columns=land[0].size();

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            for(int row=0;row<rows;row+=1)
            {
                for(int column=0;column<columns;column+=1)
                {
                    if(land[row][column]==1)
                    {
                        vector<int> coordinates={row, column, row, column};
                        
                        dfs(land, directions, coordinates, rows, columns, row, column);

                        result.push_back(coordinates);
                    }
                }
            }

            return result;
        }

        void dfs(vector<vector<int>> & land, array<pair<int, int>, 4> & directions, vector<int> & coordinates, int rows, int columns, int row, int column)
        {
            land[row][column]=2;

            for(auto [row_offset, column_offset] : directions)
            {
                int next_row=row + row_offset;

                int next_column=column + column_offset;

                bool is_valid=((next_row >= 0 and next_row < rows) and (next_column >= 0 and next_column < columns));

                if(is_valid==true and land[next_row][next_column]==1)
                {
                    coordinates[2]=max(coordinates[2], next_row);

                    coordinates[3]=max(coordinates[3], next_column);
                    
                    dfs(land, directions, coordinates, rows, columns, next_row, next_column);
                }
            }
        }
};

class Solution
{
    public:
        vector<vector<int>> findFarmland(vector<vector<int>> & land)
        {
            vector<vector<int>> result;

            int rows=land.size();

            int columns=land[0].size();

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            for(int row=0;row<rows;row+=1)
            {
                for(int column=0;column<columns;column+=1)
                {
                    if(land[row][column]==1)
                    {
                        vector<int> coordinates={row, column, row, column};
                        
                        dfs(land, directions, coordinates, rows, columns, row, column);

                        result.push_back(coordinates);
                    }
                }
            }

            return result;
        }

        void dfs(vector<vector<int>> & land, array<pair<int, int>, 4> & directions, vector<int> & coordinates, int rows, int columns, int row, int column)
        {
            vector<pair<int, int>> stack;
            
            land[row][column]=2;

            stack.push_back(make_pair(row, column));

            while(!stack.empty())
            {
                pair<int, int> p=stack.back();

                stack.pop_back();

                int current_row=p.first;

                int current_column=p.second;
                
                for(auto [row_offset, column_offset] : directions)
                {
                    int next_row=current_row + row_offset;

                    int next_column=current_column + column_offset;

                    bool is_valid=((next_row >= 0 and next_row < rows) and (next_column >= 0 and next_column < columns));

                    if(is_valid==true and land[next_row][next_column]==1)
                    {
                        coordinates[2]=max(coordinates[2], next_row);

                        coordinates[3]=max(coordinates[3], next_column);

                        land[next_row][next_column]=2;

                        stack.push_back(make_pair(next_row, next_column));
                    }
                }
            }
        }
};

class Solution
{
    public:
        vector<vector<int>> findFarmland(vector<vector<int>> & land)
        {
            vector<vector<int>> result;

            int rows=land.size();

            int columns=land[0].size();

            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            for(int row=0;row<rows;row+=1)
            {
                for(int column=0;column<columns;column+=1)
                {
                    if(land[row][column]==1)
                    {
                        vector<int> coordinates={row, column, row, column};
                        
                        bfs(land, directions, coordinates, rows, columns, row, column);

                        result.push_back(coordinates);
                    }
                }
            }

            return result;
        }

        void bfs(vector<vector<int>> & land, array<pair<int, int>, 4> & directions, vector<int> & coordinates, int rows, int columns, int row, int column)
        {
            deque<pair<int, int>> queue;
            
            land[row][column]=2;

            queue.push_back(make_pair(row, column));

            while(!queue.empty())
            {
                int q_size=queue.size();

                for(int iteration=0;iteration<q_size;iteration+=1)
                {
                    pair<int, int> p=queue.back();

                    queue.pop_back();

                    int current_row=p.first;

                    int current_column=p.second;
                    
                    for(auto [row_offset, column_offset] : directions)
                    {
                        int next_row=current_row + row_offset;

                        int next_column=current_column + column_offset;

                        bool is_valid=((next_row >= 0 and next_row < rows) and (next_column >= 0 and next_column < columns));

                        if(is_valid==true and land[next_row][next_column]==1)
                        {
                            coordinates[2]=max(coordinates[2], next_row);

                            coordinates[3]=max(coordinates[3], next_column);

                            land[next_row][next_column]=2;

                            queue.push_back(make_pair(next_row, next_column));
                        }
                    }
                }
            }
        }
};