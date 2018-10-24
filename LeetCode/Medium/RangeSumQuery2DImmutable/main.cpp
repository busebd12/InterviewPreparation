#include <iostream>
#include <vector>
using namespace std;

class NumMatrix
{
    public:
        vector<vector<int>> m;

        NumMatrix(vector<vector<int>> matrix)
        {
            m=matrix;
        }

        int sumRegion(int row1, int col1, int row2, int col2)
        {
            int sum=0;

            if(m.empty())
            {
                return sum;
            }

            int rows=(row2 - row1) + 1;

            int columns=(col2 - col1) + 1;

            for(int row=row1,i=0;i<rows;++row,++i)
            {
                for(int column=col1,j=0;j<columns;++column,++j)
                {
                    sum+=m[row][column];
                }
            }

            return sum;
        }
};