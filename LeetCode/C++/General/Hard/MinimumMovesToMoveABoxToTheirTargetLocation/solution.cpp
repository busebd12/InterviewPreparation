#include <array>
#include <deque>
#include <functional>
#include <utility>
#include <vector>

/*
Solution: see comments.

Time complexity: O(rows^2 * columns^2)
Space complexity: O(rows * columns)
*/

//Helper position class to encapsulate both the box and player position on the grid
class Position
{
    private:
        int playerRow;

        int playerColumn;

        int boxRow;

        int boxColumn;

    public:
        Position(int pRow, int pColumn, int bRow, int bColumn)
        {
            playerRow=pRow;

            playerColumn=pColumn;

            boxRow=bRow;

            boxColumn=bColumn;
        }

        const int getPlayerRow()
        {
            return playerRow;
        }

        const int getPlayerColumn()
        {
            return playerColumn;
        }

        const int getBoxRow()
        {
            return boxRow;
        }

        const int getBoxColumn()
        {
            return boxColumn;
        }

        //Custom hash function that allows us to store instances of the position classes in an unordered_set<int> as integers
        const long getKey()
        {
            long playerHash=hash<long>{}((playerRow * 23) + playerColumn);
            
            long boxHash=hash<long>{}((boxRow * 24) + boxColumn);
            
            long combinedHash=hash<int>{}(playerHash ^ (boxHash << 25));

            return combinedHash;
        }
};

class Solution
{
    private:
        //Movement directions: up, down, left, and right
        array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    
    public:
        int minPushBox(vector<vector<char>> & grid)
        {
            int result=0;

            int rows=grid.size();

            int columns=grid[0].size();

            int playerRow=-1;

            int playerColumn=-1;

            int boxRow=-1;

            int boxColumn=-1;

            int targetRow=-1;

            int targetColumn=-1;

            //Find the positions of the player, box, and target
            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(grid[row][column]=='S')
                    {
                        playerRow=row;

                        playerColumn=column;
                    }
                    else if(grid[row][column]=='B')
                    {
                        boxRow=row;

                        boxColumn=column;
                    }
                    else if(grid[row][column]=='T')
                    {
                        targetRow=row;

                        targetColumn=column;
                    }
                }
            }

            //Keep track of already visited box and player positions
            //We will store unique hash values for each position generated from the getKey() method of the Position class
            unordered_set<long> visited;

            //Initial position composed of the box and player locations on the grid
            Position start(playerRow, playerColumn, boxRow, boxColumn);

            //Queue used for the box's breadth-first search 
            deque<Position> queue;

            queue.push_back(start);

            //Do the breadth-first search
            while(!queue.empty())
            {
                int qSize=queue.size();

                for(int count=0;count<qSize;count++)
                {
                    Position position=queue.front();

                    queue.pop_front();

                    //If the box has reached the target
                    if(position.getBoxRow()==targetRow and position.getBoxColumn()==targetColumn)
                    {
                        return result;
                    }

                    //If we've already visited this position
                    if(visited.find(position.getKey())!=visited.end())
                    {
                        continue;
                    }

                    //Mark the current position as visited
                    visited.insert(position.getKey());

                    //Iterate through the four different directions we can move the box: up, down, left, and right
                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        //Next box position
                        int nextBoxRow=position.getBoxRow() + rowOffset;

                        int nextBoxColumn=position.getBoxColumn() + columnOffset;

                        /*
                        Here's the big brain part: in order to move the box, the store keeper must be standing
                        in a position that allows him to push the box in in the desired direction
                        Meaning:
                        if the store keeper wants to push the box up, then they need to be standing one spot below the box in the grid.
                        if the store keeper wants to push the box down, then they need to be standing one spot above the box in the grid.
                        if the store keeper wants to push the box to the left, then they need to be standing one spot to the right of the box in the grid.
                        if the store keeper wants to tpush the box to the right, then they need to be standing one spot to the left of the box in the grid.

                        So, we need to use another breadth-first search to check whether or not the store keeper can move to the required spot in the grid so
                        that they have room to push the box in the desired direction/
                        */

                        //(row, column) on the grid the store keeper needs to be standing in order to push the box
                        int requiredPlayerRow=position.getBoxRow() - rowOffset;

                        int requiredPlayerColumn=position.getBoxColumn() - columnOffset;

                        //Make sure the player's position is valid
                        bool validPlayerPosition=((requiredPlayerRow >= 0 and requiredPlayerRow < rows) and (requiredPlayerColumn >= 0 and requiredPlayerColumn < columns) and grid[requiredPlayerRow][requiredPlayerColumn]!='#');

                        //Make sure the next box's position is valid
                        bool validBoxPosition=((nextBoxRow >= 0 and nextBoxRow < rows) and (nextBoxColumn >= 0 and nextBoxColumn < columns) and grid[nextBoxRow][nextBoxColumn]!='#');

                        //If the player's position is valid, the box's position is valid, and the player can move to the required spot in order to push the box in the desired direction.
                        if(validPlayerPosition==true and validBoxPosition==true and playerCanPushBox(grid, position, rows, columns, requiredPlayerRow, requiredPlayerColumn)==true)
                        {
                            //Create the next position
                            Position next(position.getBoxRow(), position.getBoxColumn(), nextBoxRow, nextBoxColumn);

                            //Add the next position to the queue
                            queue.push_back(next);
                        }
                    }
                }

                result+=1;
            }

            return -1;
        }

        //Helper function to check if the player can move the required position on the grid in order to push the box in the desired direction
        //This function also uses the breadth-first search algorithm
        bool playerCanPushBox(vector<vector<char>> & grid, Position & position, int rows, int columns, int requiredPlayerRow, int requiredPlayerColumn)
        {
            vector<vector<bool>> visited(rows, vector<bool>(columns, false));

            int playerStartRow=position.getPlayerRow();

            int playerStartColumn=position.getPlayerColumn();

            int boxStartRow=position.getBoxRow();

            int boxStartColumn=position.getBoxColumn();

            visited[playerStartRow][playerStartColumn]=true;

            visited[boxStartRow][boxStartColumn]=true;

            deque<pair<int, int>> queue;

            queue.emplace_back(playerStartRow, playerStartColumn);

            while(!queue.empty())
            {
                auto [row, column]=queue.front();

                queue.pop_front();

                if(row==requiredPlayerRow and column==requiredPlayerColumn)
                {
                    return true;
                }

                for(auto & [rowOffset, columnOffset] : directions)
                {
                    int nextRow=row + rowOffset;

                    int nextColumn=column + columnOffset;

                    bool isValid=((nextRow >= 0 and nextRow < rows) and (nextColumn >= 0 and nextColumn < columns));

                    if(isValid==true and visited[nextRow][nextColumn]==false and grid[nextRow][nextColumn]!='#')
                    {
                        visited[nextRow][nextColumn]=true;
                        
                        queue.emplace_back(nextRow, nextColumn);
                    }
                }
            }

            return false;
        }
};