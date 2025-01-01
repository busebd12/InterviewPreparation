#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

/*
Time complexity: O(rows * columns)
Space complexity: O(rows * columns)
*/

class Solution
{
    public:
        vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k)
        {
            vector<vector<int>> result;

            int rows=grid.size();
    
            int columns=grid[0].size();

            result.resize(rows, vector<int>(columns, 0));
            
            int stop=min(rows, columns) / 2;
            
            int row=0;
            
            int column=0;
            
            int offset=0;
            
            while(row < stop and column < stop)
            {
                int minRow=0 + offset;
                
                int minColumn=0 + offset;
                
                int maxRow=rows - 1 - offset;
                
                int maxColumn=columns - 1 - offset;

                int leftColumnTotalNumbers=(maxRow - 1) - minRow + 1;

                int bottomRowTotalNumbers=(maxColumn - 1) - minColumn + 1;

                int rightColumnTotalNumbers=(maxRow - 1) - minRow + 1;

                int topRowTotalNumbers=(maxColumn - 1) - minColumn + 1;

                int totalLayerNumbers=leftColumnTotalNumbers + bottomRowTotalNumbers + rightColumnTotalNumbers + topRowTotalNumbers;

                for(int r=minRow;r<maxRow;r++)
                {
                    auto [rotatedRow, rotatedColumn]=rotateStartingDown(minRow, minColumn, maxRow, maxColumn, r, minColumn, k % totalLayerNumbers);

                    result[rotatedRow][rotatedColumn]=grid[r][minColumn];
                }
                
                for(int c=minColumn;c<maxColumn;c++)
                {   
                    auto [rotatedRow, rotatedColumn]=rotateStartingRight(minRow, minColumn, maxRow, maxColumn, maxRow, c, k % totalLayerNumbers);

                    result[rotatedRow][rotatedColumn]=grid[maxRow][c];
                }
                
                for(int r=maxRow;r>minRow;r--)
                {   
                    auto [rotatedRow, rotatedColumn]=rotateStartingUp(minRow, minColumn, maxRow, maxColumn, r, maxColumn, k % totalLayerNumbers);

                    result[rotatedRow][rotatedColumn]=grid[r][maxColumn];
                }

                for(int c=maxColumn;c>minColumn;c--)
                {
                    auto [rotatedRow, rotatedColumn]=rotateStartingLeft(minRow, minColumn, maxRow, maxColumn, minRow, c, k % totalLayerNumbers);

                    result[rotatedRow][rotatedColumn]=grid[minRow][c];
                }
                
                row+=1;
                
                column+=1;
                
                offset+=1;
            }

            return result;
        }

        pair<int, int> rotateStartingDown(int minRow, int minColumn, int maxRow, int maxColumn, int row, int column, int rotations)
        {
            int rotatedRow=row;
            
            int rotatedColumn=column;
            
            while(rotations > 0)
            {
                int downDifference=maxRow - rotatedRow;
                
                downDifference=min(downDifference, rotations);
                
                if(rotations - downDifference >= 0)
                {
                    rotations-=downDifference;
                
                    rotatedRow+=downDifference;
                }
                
                if(rotations==0)
                {
                    break;
                }
                
                int rightDifference=maxColumn - rotatedColumn;
                
                rightDifference=min(rightDifference, rotations);
                
                if(rotations - rightDifference >= 0)
                {
                    rotations-=rightDifference;
                    
                    rotatedColumn+=rightDifference;
                }
                
                if(rotations==0)
                {
                    break;
                }
                
                int upDifference=rotatedRow - minRow;
                
                upDifference=min(upDifference, rotations);
                
                if(rotations - upDifference >= 0)
                {
                    rotations-=upDifference;
                    
                    rotatedRow-=upDifference;
                }
                
                if(rotations==0)
                {
                    break;
                }
                
                int leftDifference=rotatedColumn - minColumn;
                
                leftDifference=min(leftDifference, rotations);
                
                if(rotations - leftDifference >= 0)
                {
                    rotations-=leftDifference;
                    
                    rotatedColumn-=leftDifference;
                }
            }

            return make_pair(rotatedRow, rotatedColumn);
        }

        pair<int, int> rotateStartingRight(int minRow, int minColumn, int maxRow, int maxColumn, int row, int column, int rotations)
        {
            int rotatedRow=row;
            
            int rotatedColumn=column;
            
            while(rotations > 0)
            {   
                int rightDifference=maxColumn - rotatedColumn;
                
                rightDifference=min(rightDifference, rotations);

                if(rotations - rightDifference >= 0)
                {
                    rotations-=rightDifference;
                    
                    rotatedColumn+=rightDifference;
                }
                
                if(rotations==0)
                {
                    break;
                }
                
                int upDifference=rotatedRow - minRow;
                
                upDifference=min(upDifference, rotations);
                
                if(rotations - upDifference >= 0)
                {
                    rotations-=upDifference;
                    
                    rotatedRow-=upDifference;
                }
                
                if(rotations==0)
                {
                    break;
                }
                
                int leftDifference=rotatedColumn - minColumn;
                
                leftDifference=min(leftDifference, rotations);
                
                if(rotations - leftDifference >= 0)
                {
                    rotations-=leftDifference;
                    
                    rotatedColumn-=leftDifference;
                }

                if(rotations==0)
                {
                    break;
                }

                int downDifference=maxRow - rotatedRow;
                
                downDifference=min(downDifference, rotations);
                
                if(rotations - downDifference >= 0)
                {
                    rotations-=downDifference;
                
                    rotatedRow+=downDifference;
                }
            }

            return make_pair(rotatedRow, rotatedColumn);
        }

        pair<int, int> rotateStartingUp(int minRow, int minColumn, int maxRow, int maxColumn, int row, int column, int rotations)
        {
            int rotatedRow=row;
            
            int rotatedColumn=column;
            
            while(rotations > 0)
            {   
                int upDifference=rotatedRow - minRow;
                
                upDifference=min(upDifference, rotations);
                
                if(rotations - upDifference >= 0)
                {
                    rotations-=upDifference;
                    
                    rotatedRow-=upDifference;
                }
                
                if(rotations==0)
                {
                    break;
                }
                
                int leftDifference=rotatedColumn - minColumn;
                
                leftDifference=min(leftDifference, rotations);
                
                if(rotations - leftDifference >= 0)
                {
                    rotations-=leftDifference;
                    
                    rotatedColumn-=leftDifference;
                }

                if(rotations==0)
                {
                    break;
                }

                int downDifference=maxRow - rotatedRow;
                
                downDifference=min(downDifference, rotations);
                
                if(rotations - downDifference >= 0)
                {
                    rotations-=downDifference;
                
                    rotatedRow+=downDifference;
                }

                if(rotations==0)
                {
                    break;
                }

                int rightDifference=maxColumn - rotatedColumn;
                
                rightDifference=min(rightDifference, rotations);
                
                if(rotations - rightDifference >= 0)
                {
                    rotations-=rightDifference;
                    
                    rotatedColumn+=rightDifference;
                }
            }

            return make_pair(rotatedRow, rotatedColumn);
        }

        pair<int, int> rotateStartingLeft(int minRow, int minColumn, int maxRow, int maxColumn, int row, int column, int rotations)
        {
            int rotatedRow=row;
            
            int rotatedColumn=column;
            
            while(rotations > 0)
            {   
                int leftDifference=rotatedColumn - minColumn;
                
                leftDifference=min(leftDifference, rotations);
                
                if(rotations - leftDifference >= 0)
                {
                    rotations-=leftDifference;
                    
                    rotatedColumn-=leftDifference;
                }

                if(rotations==0)
                {
                    break;
                }

                int downDifference=maxRow - rotatedRow;
                
                downDifference=min(downDifference, rotations);
                
                if(rotations - downDifference >= 0)
                {
                    rotations-=downDifference;
                
                    rotatedRow+=downDifference;
                }

                if(rotations==0)
                {
                    break;
                }

                int rightDifference=maxColumn - rotatedColumn;
                
                rightDifference=min(rightDifference, rotations);
                
                if(rotations - rightDifference >= 0)
                {
                    rotations-=rightDifference;
                    
                    rotatedColumn+=rightDifference;
                }

                if(rotations==0)
                {
                    break;
                }

                int upDifference=rotatedRow - minRow;
                
                upDifference=min(upDifference, rotations);
                
                if(rotations - upDifference >= 0)
                {
                    rotations-=upDifference;
                    
                    rotatedRow-=upDifference;
                }
            }

            return make_pair(rotatedRow, rotatedColumn);
        }
};