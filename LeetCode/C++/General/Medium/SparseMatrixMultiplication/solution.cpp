#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2)
        {
            int mat1Rows=mat1.size();

            int mat1Columns=mat1[0].size();

            int mat2Rows=mat2.size();

            int mat2Columns=mat2[0].size();

            vector<vector<int>> result(mat1Rows, vector<int>(mat2Columns, 0));

            for(int mat1Row=0;mat1Row<mat1Rows;mat1Row++)
            {
                vector<int> row;

                for(int mat2Column=0;mat2Column<mat2Columns;mat2Column++)
                {
                    int sum=0;

                    for(int index=0;index<mat1Columns;index++)
                    {
                        int product=mat1[mat1Row][index] * mat2[index][mat2Column];

                        sum+=product;
                    }

                    result[mat1Row][mat2Column]=sum;
                }
            }

            return result;
        }
};

class Solution
{
    public:
        vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2)
        {
            int mat1Rows=mat1.size();

            int mat1Columns=mat1[0].size();

            int mat2Rows=mat2.size();

            int mat2Columns=mat2[0].size();
            
            auto sparseMat1=createSparseMatrix(mat1, mat1Rows, mat1Columns);
            
            auto sparseMat2=createSparseMatrix(mat2, mat2Rows, mat2Columns);

            vector<vector<int>> result(mat1Rows, vector<int>(mat2Columns, 0));

            for(auto & [mat1Row, elements] : sparseMat1)
            {
                for(auto & [mat1Column, value1] : elements)
                {
                    for(auto & [mat2Column, value2] : sparseMat2[mat1Column])
                    {
                        result[mat1Row][mat2Column]+=(value1 * value2);
                    }
                }
            }

            return result;
        }
    
        unordered_map<int, vector<pair<int, int>>> createSparseMatrix(vector<vector<int>> & matrix, int rows, int columns)
        {
            unordered_map<int, vector<pair<int, int>>> sparseMatrix;
            
            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    if(matrix[row][column]!=0)
                    {
                        sparseMatrix[row].emplace_back(column, matrix[row][column]);
                    }
                }
            }
            
            return sparseMatrix;
        }
};