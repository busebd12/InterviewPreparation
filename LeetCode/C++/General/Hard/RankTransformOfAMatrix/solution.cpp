#include <algorithm>
#include <limits>
#include <map>
#include <utility>
#include <vector>
using namespace std;

/*
Solution: see comments.
*/

class Solution
{
    public:
        vector<vector<int>> matrixRankTransform(vector<vector<int>> & matrix)
        {
            vector<vector<int>> result;

            int rows=matrix.size();

            int columns=matrix[0].size();

            result.resize(rows, vector<int>(columns, 0));

            //Track the maximum rank for each row
            vector<int> maxRowRank(rows, 0);

            //Track the maximum rank for each column
            vector<int> maxColumnRank(columns, 0);

            //Map each value in the matrix to a vector of pairs where each pair is of the form {row, column}
            //These row column pairs represent the location in the matrix where each value occurrs
            //In other words, we are associating each value in the matrix with a list of places in the matrix where this values occurrs
            map<int, vector<pair<int, int>>> hashmap;

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    int value=matrix[row][column];

                    //Create the mapping
                    hashmap[value].emplace_back(row, column);
                }
            }

            //For each number in the matrix, going from lowest to highest
            for(auto & [number, indexPairs] : hashmap)
            {
                //This while loop is the crux of the algorithm
                //The approach is to view all {row, column} pairs corresponding to the same value as connected components in a graph
                //In other words, for a particular value, say 43, all occurrances of the value 43 that are in the same row or column will be part of a connected component
                //Then, we simply iterate through all connected components and assign a rank to each occurrance of number (i.e. each node in the connected component)
                while(indexPairs.size() > 0)
                {
                    vector<bool> usedRows(rows, false);

                    vector<bool> usedColumns(columns, false);

                    vector<pair<int, int>> indices=indexPairs;

                    vector<bool> usedIndices(indices.size(), false);

                    //Root of the connected component
                    pair<int, int> root=indices[0];

                    int rootRow=root.first;

                    int rootColumn=root.second;

                    //Mark the root as visited/used
                    usedRows[rootRow]=true;

                    usedColumns[rootColumn]=true;

                    usedIndices[0]=true;

                    //While true, visit all nodes in the connected component
                    while(true)
                    {
                        int visited=0;

                        for(int i=1;i<indices.size();i++)
                        {
                            //matrix[row][column]=number
                            int row=indices[i].first;

                            int column=indices[i].second;

                            //If we've already visited this node
                            if(usedIndices[i]==true)
                            {
                                continue;
                            }

                            //If this node hasn't been visited but the row or column has been,
                            //then we know that this node is part of the connected component we are current exploring
                            if(usedRows[row]==true or usedColumns[column]==true)
                            {
                                //Mark the row as used
                                usedRows[row]=true;

                                //Mark the column as used
                                usedColumns[column]=true;

                                //Mark the {row, column} pair as used
                                usedIndices[i]=true;

                                visited+=1;
                            }
                        }

                        //If we weren't able to visit any nodes in the connected component, then we are done exploring the connected component
                        if(visited==0)
                        {
                            break;
                        }
                    }

                    //List of {row, column} pairs that form the connected component
                    vector<pair<int, int>> connected;

                    //List of {row, column} pairs that didn't get explored as part of the current connected component
                    vector<pair<int, int>> leftover;

                    for(int i=0;i<indices.size();i++)
                    {
                        //If we visited the {row, column} pair
                        if(usedIndices[i]==true)
                        {
                            connected.push_back(indices[i]);
                        }
                        //Else, we didn't visit the {row, column} pair
                        else
                        {
                            leftover.push_back(indices[i]);
                        }
                    }

                    //Replace the previous list of {row, column} pairs with leftover
                    hashmap[number]=leftover;

                    //Calculate the rank for all the values identified by the {row, column} pairs we visited as part of the connected component
                    int rank=numeric_limits<int>::min();

                    for(auto & [row, column] : connected)
                    {
                        //Rank=max of (max rank in the row, max rank in the column) + 1
                        rank=max(rank, max(maxRowRank[row], maxColumnRank[column]) + 1);
                    }

                    for(auto & [row, column] : connected)
                    {
                        //Update the max rank for the current row
                        maxRowRank[row]=rank;

                        //Update the max rank for the current column
                        maxColumnRank[column]=rank;

                        //Assign the rank to the result matrix
                        result[row][column]=rank;
                    }
                }
            }

            return result;
        }
};