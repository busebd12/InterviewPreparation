#include <vector>
using namespace std;

class Solution
{
    public:
        int diagonalSum(vector<vector<int>> & mat)
        {
            int result=0;

            int rows=mat.size();

            int columns=mat[0].size();

            int middleRow=rows / 2;

            int middleColumn=columns / 2;

            int primaryDiagonalSum=getPrimaryDiagonalSum(mat, rows, columns);

            result+=primaryDiagonalSum;

            int secondaryDiagonalSum=getSecondaryDiagonalSum(mat, rows, columns);

            result+=secondaryDiagonalSum;

            if((rows % 2)==1)
            {
                result-=mat[middleRow][middleColumn];
            }

            return result;   
        }

        int getPrimaryDiagonalSum(vector<vector<int>> & mat, int rows, int columns)
        {
            int sum=0;
            
            int row=0;

            int column=0;

            while(row < rows and column < columns)
            {
                sum+=mat[row][column];

                row+=1;

                column+=1;
            }

            return sum;
        }

        int getSecondaryDiagonalSum(vector<vector<int>> & mat, int rows, int columns)
        {
            int sum=0;

            int row=0;

            int column=columns - 1;

            while(row < rows and column >= 0)
            {
                sum+=mat[row][column];

                row+=1;

                column-=1;
            }

            return sum;
        }
};