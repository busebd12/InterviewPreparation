#include <unordered_set>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(rows * colums) [where rows is the number of roww in the image and columns is the number of columns in the image]
Space complexity: O(rows + columns)
*/

class Solution
{
    public:
        int minArea(vector<vector<char>> & image, int x, int y)
        {
            int result=0;
            
            int rows=image.size();
            
            int columns=image[0].size();
            
            //Hashset used to store the unique row numbers
            unordered_set<int> usedRows;
            
            //Hashset used to store the unique column numbers
            unordered_set<int> usedColumns;
            
            //Iterate through the image
            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    //If we find a '1'
                    if(image[row][column]=='1')
                    {
                        //Add the row to the hashset
                        usedRows.insert(row);
                        
                        //Add the column to the hashset
                        usedColumns.insert(column);
                    }
                }
            }
            
            //Answer is just the number of unique rows multiplied by the number of unique columns
            result=usedRows.size() * usedColumns.size();
            
            return result;
        }
};