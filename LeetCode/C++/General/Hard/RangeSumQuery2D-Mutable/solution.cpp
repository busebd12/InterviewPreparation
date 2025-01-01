#include <vector>
using namespace std;


class NumMatrix
{
    private:
        vector<vector<int>> rowPrefixSums;

        vector<vector<int>> grid;

        int rows;

        int columns;
    
    public:
        NumMatrix(vector<vector<int>> & matrix) //Time complexity: O(rows * columns)
        {
            rows=matrix.size();

            columns=matrix[0].size();

            grid=matrix;

            rowPrefixSums.resize(rows, vector<int>(columns, 0));

            for(int row=0;row<rows;row++)
            {
                createRowPrefixSum(matrix[row], row, columns);
            }
        }
        
        void update(int row, int col, int val) //Time complexity: O(columns)
        {
            grid[row][col]=val;

            createRowPrefixSum(grid[row], row, columns);
        }
        
        int sumRegion(int row1, int col1, int row2, int col2) //Time complexity: O(columns)
        {
            int sum=0;

            for(int row=row1;row<=row2;row++)
            {
                int rowSum=rowPrefixSums[row][col2];

                int leftBoundary=col1 - 1;

                if(leftBoundary >= 0)
                {
                    rowSum-=rowPrefixSums[row][leftBoundary];
                }

                sum+=rowSum;
            }

            return sum;
        }

        void createRowPrefixSum(vector<int> & row, int r, int columns) //Time complexity: O(columns)
        {
            rowPrefixSums[r][0]=row[0];

            for(int i=1;i<columns;i++)
            {
                rowPrefixSums[r][i]=rowPrefixSums[r][i - 1] + row[i];
            }
        }
};