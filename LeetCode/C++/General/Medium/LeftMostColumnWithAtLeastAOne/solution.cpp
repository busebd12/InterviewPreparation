#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(rows * log(column))
[where rows is the number of rows and column is the length of a column in the matrix]

Space complexity: O(1)
*/

class Solution
{
    public:
        void binarySearch(BinaryMatrix & binaryMatrix, int row, int columns, int & result)
        {
            int low=0;
            
            int high=columns - 1;
            
            while(low <= high)
            {
                int middle=(low + (high - low)/2);
                
                //If the value at binaryMatrix[row][middle] is 0, look to the right in the row
                if(binaryMatrix.get(row, middle)==0)
                {
                    low=middle + 1;
                }
                //Else, the value at binaryMatrix[row][middle] is 1
                else
                {
                    //We update result if the index is less than result or it's the first index we found
                    if(result==-1 || middle < result)
                    {
                        result=middle;
                    }
                    
                    //Since we need to find the leftmost index that is a one, and the value at this index is a one, let's keep looking left for a smaller index
                    high=middle - 1;
                }
            }
        }
    
        int leftMostColumnWithOne(BinaryMatrix & binaryMatrix)
        {
            int result=-1;
            
            vector<int> matrixDimensions=binaryMatrix.dimensions();
            
            int rows=matrixDimensions[0];
            
            int columns=matrixDimensions[1];
            
            //For each row in the matrix
            for(int row=0;row<rows;row++)
            {
                //Use binary search to find the leftmost column with a 1
                binarySearch(binaryMatrix, row, columns, result);
            }
            
            return result;
        }
};