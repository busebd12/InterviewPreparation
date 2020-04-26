#include <array>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>

/*
 * Solution: We can think of this problem as a shortest path problem on a graph. Each node is a different board state,
 * and we connect two boards by an edge if they can be transformed into one another in one move. We can find the shortest
 * path with breadth first search. The algorithm is as follows
 *
 * 1. Insert the starting state of the board and 0 as a pair into a queue.
 *
 * 2. Insert the starting state of the board into a set of vector of vectors. We will use the set to tell whether
 * we have seen a certain state of the board before.
 *
 * 3. Then, while the queue is not empty, do the following
 *
 * a. pop the top element off the queue. This will be a pair holding the current state of the board and
 * the number of moves it took to get to this state.
 *
 * b. If the current state of the board matches our goal state, we are done! The answer will be the number of
 * moves it took to get to this state.
 *
 * c. Then, we find the location of zero within the current board.
 *
 * d. For each valid swap of zero and another number that we can make, we create a copy of the current board, and do
 * the swap. If the resulting state is not a state we've seen before, we add it to the queue.
 *
 * 4. After the while loop completes (i.e. the queue is empty), if we haven't reach the goal state, then the puzzle
 * can't be solved, and our answer will be -1.
 *
 * Time complexity: O(R * C * (R * C)!), where R and C are the number of rows and columns of the board.
 * There are O((R * C)!) possible board states.
 *
 * Space complexity: O(R * C * (R * C)!)
 */

bool isOnBoard(int rows, int columns, int row, int column)
{
    return ((row >= 0 && row < rows) && (column >=0 && column < columns));
}

int slidingPuzzle(std::vector<std::vector<int>> & board)
{
    int result=-1;

    if(board.empty())
    {
        return result;
    }

    int rows=2;

    int columns=3;

    std::set<std::vector<std::vector<int>>> seen;

    std::vector<std::vector<int>> goalState={{1, 2, 3}, {4, 5, 0}};

    std::queue<std::pair<std::vector<std::vector<int>>,int>> Q;

    seen.insert(board);

    Q.emplace(std::make_pair(board, 0));

    while(!Q.empty())
    {
        auto currentState=Q.front();

        Q.pop();

        if(currentState.first==goalState)
        {
            result=currentState.second;

            break;
        }

        std::pair<int, int> zeroLocation(-1, -1);

        for(auto row=0;row<rows;++row)
        {
            bool found=false;

            for(auto column=0;column<columns;++column)
            {
                if(currentState.first[row][column]==0)
                {
                    zeroLocation.first=row;

                    zeroLocation.second=column;

                    found=true;

                    break;
                }
            }

            if(found)
            {
                break;
            }
        }

        std::array<std::pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

        for(auto & direction : directions)
        {
            auto boardCopy=currentState.first;

            int nextRow=zeroLocation.first + direction.first;

            int nextColumn=zeroLocation.second + direction.second;

            if(isOnBoard(rows, columns, nextRow, nextColumn))
            {
                std::swap(boardCopy[zeroLocation.first][zeroLocation.second], boardCopy[nextRow][nextColumn]);

                if(!seen.count(boardCopy))
                {
                    seen.insert(boardCopy);

                    Q.emplace(std::make_pair(boardCopy, currentState.second + 1));
                }
            }
        }
    }

    return result;
}