#include <unordered_map>
#include <vector>
using namespace std;

/*
Solution: iterate through the matrix and for each black pixel, increment the count of the row and column in the corresponding hashmap.
Then, iterate through the matrix a second time and for each black pixel, if the count of the row and column is less than two, then
there is only one black pixel in this row and column, so we increment the result variable.

Time complexity: O(rows * columns)
Space complexity: O(rows * columns)
*/

class Solution
{
    public:
        int findLonelyPixel(vector<vector<char>> & picture)
        {
            int result=0;

            int rows=picture.size();

            int columns=picture[0].size();

            unordered_map<int, int> blackPixelRows;

            unordered_map<int, int> blackPixelColumns;

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    char pixel=picture[row][column];

                    if(pixel=='B')
                    {
                        if(blackPixelRows.find(row)==blackPixelRows.end())
                        {
                            blackPixelRows.emplace(row, 0);
                        }

                        blackPixelRows[row]+=1;

                        if(blackPixelColumns.find(column)==blackPixelColumns.end())
                        {
                            blackPixelColumns.emplace(column, 0);
                        }

                        blackPixelColumns[column]+=1;
                    }
                }
            }

            for(int row=0;row<rows;row++)
            {
                for(int column=0;column<columns;column++)
                {
                    char pixel=picture[row][column];

                    if(pixel=='B')
                    {
                        if(blackPixelRows[row] < 2 and blackPixelColumns[column] < 2)
                        {
                            result+=1;
                        }
                    }
                }
            }

            return result;
        }
};