#include <algorithm>
#include <array>
#include <deque>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

/*
Solution: see comments for details

Time complexity: O(2^(rows * columns) * (rows * columns)) [where rows is the number of rows in the matrix and columns is the number of columns in the matrix]
Space complexity: O(2^(rows * columns))
*/

class Solution
{
    public:
        string convertMatrixToString(vector<vector<int>> & matrix)
        {
            string matrixAsString{};

            int rows=matrix.size();

            for(int row=0;row<rows;row++)
            {
                for(const auto & number : matrix[row])
                {
                    matrixAsString+=(number - '0');
                }

                if(row < rows-1)
                {
                    matrixAsString+='|';
                }
            }

            return matrixAsString;
        }

        bool allZeros(vector<vector<int>> & matrix)
        {
            for(const auto & row : matrix)
            {
                if(!all_of(begin(row), end(row), [] (const auto & number) {return number==0;}))
                {
                    return false;
                }
            }

            return true;
        }

        int minFlips(vector<vector<int>> & mat)
        {
            int rows=mat.size();

            int columns=mat[0].size();

            //Use this unordered_set<string> to help keep track of matrix states (represented as strings) that we've seen before
            unordered_set<string> seen;

            //Mark the starting matrix state as seen
            seen.insert(convertMatrixToString(mat));

            //Queue that will be used for Breadth-first search (BFS)
            deque<vector<vector<int>>> queue;

            queue.emplace_back(mat);

            //Represents which level of BFS we are on
            int level=0;

            while(!queue.empty())
            {
                int qSize=queue.size();

                //Iterate through all possible matrices at the current level
                for(int count=0;count<qSize;count++)
                {
                    //Current matrix
                    auto current=queue.front();

                    queue.pop_front();

                    //If the matrix is all zeros, then we are done
                    if(allZeros(current))
                    {
                        return level;
                    }

                    //Iterate through the matrix
                    for(int row=0;row<rows;row++)
                    {
                        for(int column=0;column<columns;column++)
                        {
                            //Copy of the current matrix for editing
                            auto copy=current;

                            //Don't forget to change the value at the current row and column!
                            copy[row][column]=!copy[row][column];

                            //Row and column offsets used to calculate neighbouring rows and columns
                            array<pair<int, int>, 4> directions={{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

                            for(auto & [rowOffset, columnOffset]: directions)
                            {
                                int nextRow=row + rowOffset;

                                int nextColumn=column + columnOffset;

                                //Check to make sure nextRow and nextColumn are valid
                                bool onMatrix=((nextRow < rows && nextRow >= 0) && (nextColumn < columns && nextColumn >= 0));

                                //If neighbouring cell is valid, flip the value
                                if(onMatrix)
                                {
                                    copy[nextRow][nextColumn]=!copy[nextRow][nextColumn];
                                }
                            }

                            //State of the matrix represented as a string
                            string matrixAsString=convertMatrixToString(copy);

                            //If we haven't seen this matrix state before
                            //This check is required because it filters out previously seen matrix states and prevents an infinite while loop,
                            //the queue never empties because we keep adding already seen matrix states to the queue.
                            if(!seen.count(matrixAsString))
                            {
                                //Mark it as seen
                                seen.insert(matrixAsString);

                                //Add the changed matrix to the queue
                                queue.emplace_back(copy);
                            }
                        }
                    }
                }

                //We have finished process all matrix states in the current level, so increment level
                level++;
            }
            
            return -1;
        }
};