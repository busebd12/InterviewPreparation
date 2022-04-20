#include <array>
#include <deque>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(rows * columns) [where rows is the number of rows in the baord and columns in the number of columns in the board]
Space complexity: O(rows * columns)

*/

class Solution
{
    public:
        vector<vector<char>> updateBoard(vector<vector<char>> & board, vector<int> & click)
        {
            int rows=board.size();

            int columns=board[0].size();

            array<pair<int, int>, 8> directions={{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}}};

            deque<pair<int, int>> queue;

            //If we click on a 'M', game over
            if(board[click[0]][click[1]]=='M')
            {
                board[click[0]][click[1]]='X';

                return board;
            }

            //Add click to queue
            queue.emplace_back(click[0], click[1]);

            //Perform breadth-first search
            while(!queue.empty())
            {
                auto current=queue.front();

                queue.pop_front();

                int currentRow=current.first;

                int currentColumn=current.second;

                //Keep track of the number of mines
                int mineCount=0;

                //From the current 'E' cell, check in all eight directions for surrounding mines
                for(auto & [rowOffset, columnOffset] : directions)
                {
                    int nextRow=currentRow + rowOffset;

                    int nextColumn=currentColumn + columnOffset;

                    bool onBoard=((nextRow >= 0 && nextRow < rows) && (nextColumn >= 0 && nextColumn < columns));

                    if(onBoard)
                    {
                        if(board[nextRow][nextColumn]=='M')
                        {
                            mineCount+=1;
                        }
                    }
                }

                //If we found some mines
                if(mineCount > 0)
                {
                    //Update the current spot in the board with the number of found mines
                    board[currentRow][currentColumn]=static_cast<char>(mineCount + '0');
                }
                //Else, we didn't find any mines
                else
                {
                    //Mark the current cell as blank
                    board[currentRow][currentColumn]='B';

                    //Check all eight adjacent cells
                    for(auto & [rowOffset, columnOffset] : directions)
                    {
                        int nextRow=currentRow + rowOffset;

                        int nextColumn=currentColumn + columnOffset;

                        bool onBoard=((nextRow >= 0 && nextRow < rows) && (nextColumn >= 0 && nextColumn < columns));

                        //If the cell is an 'E', mark it as blank and add it to the queue
                        if(onBoard && board[nextRow][nextColumn]=='E')
                        {
                            queue.emplace_back(nextRow, nextColumn);

                            board[nextRow][nextColumn]='B';
                        }
                    }
                }
            }

            return board;
        }
};