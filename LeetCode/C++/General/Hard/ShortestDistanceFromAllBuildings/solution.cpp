class Solution
{
    public:
        int shortestDistance(vector<vector<int>> & grid)
        {
            const int INF=numeric_limits<int>::max();
            
            int result=INF;

            int rows=grid.size();

            int columns=grid[0].size();

            bool noZeros=true;

            bool noOnes=true;

            int ones=0;

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(grid[row][column]==0)
                    {
                        noZeros=false;
                    }
                    else if(grid[row][column]==1)
                    {
                        noOnes=false;

                        ones+=1;
                    }
                }
            }

            //If there are no 0s or 1s in the grid
            if(noZeros==true or noOnes==true)
            {
                return -1;
            }

            //For each (row, column), use a pair of the form {distance from each 1 in the grid,
            //number of 1s that are able to reach this spot in the grid} to keep track of necessary information
            vector<vector<pair<int, int>>> distances(rows, vector<pair<int, int>>(columns, make_pair(INF, 0)));

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(grid[row][column]==0)
                    {
                        distances[row][column].first=0;
                    }
                }
            }

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    //Do breadth-first search from each 1 in the grid
                    if(grid[row][column]==1)
                    {
                        bfs(grid, distances, rows, columns, row, column);
                    }
                }
            }

            bool foundValidHouse=false;

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    int dist=distances[row][column].first;

                    int visited=distances[row][column].second;
                    
                    //If distance to this (row, column) in grid is not zero and not INF,
                    //and all ones were able to reach this zero, then this is a valid spot for a house to be built
                    if(dist!=0 and dist!=INF and visited==ones)
                    {
                        //Minimize our result
                        result=min(result, dist);
                        
                        foundValidHouse=true;
                    }
                }
            }

            //If we weren't able to find a valid zero where we can build a house
            if(foundValidHouse==false)
            {
                return -1;
            }

            return result;
        }

        void bfs(vector<vector<int>> grid, vector<vector<pair<int, int>>> & distances, int rows, int columns, int row, int column)
        {
            //Up, down, left, and right directions for breadth-first search
            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

            //Queue used for breadth-first search
            deque<pair<int, int>> queue;

            queue.emplace_back(row, column);

            //Keep track of the distance from the starting 1 (row, column) to all zeros that can be reached
            int steps=1;

            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    auto [currentRow, currentColumn]=queue.front();

                    queue.pop_front();

                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        int nextRow=currentRow + rowOffset;

                        int nextColumn=currentColumn + columnOffset;

                        bool isValid=((0 <= nextRow and nextRow < rows) and (0 <= nextColumn and nextColumn < columns));

                        //If the next spot is on the grid and is zero
                        if(isValid==true and grid[nextRow][nextColumn]==0)
                        {
                            //Increment the distance needed to reach this (row, column) spot in the grid
                            distances[nextRow][nextColumn].first+=steps;

                            //Increment the number of 1s that are able to reach this (row, column) spot in the grid
                            distances[nextRow][nextColumn].second+=1;

                            //Mark this spot in the grid as a 2 so we don't visit it again
                            grid[nextRow][nextColumn]=2;

                            queue.emplace_back(nextRow, nextColumn);
                        }
                    }
                }

                steps+=1;
            }
        }
};