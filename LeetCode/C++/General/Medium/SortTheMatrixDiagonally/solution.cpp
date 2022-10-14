#include <funtional>
#include <queue>
#include <vector>
using namespace std;

/*
Solution: see comments.

Time complexity: O(d * (a * log(a))) [where d is the total number of diagonals and a is the average number of integers per diagonal]
Space complexity: O(rows * columns) [where rows is the number of rows in the matrix and columns is the number of columns in the matrix]
*/

class Solution
{
    public:
        vector<vector<int>> diagonalSort(vector<vector<int>> & mat)
        {
            int rows=mat.size();
            
            int columns=mat[0].size();
            
            //Iterate through all the diagonals starting with the first number in each row
            for(int row=rows-1;row>=0;row--)
            {
                int r=row;
                
                int column=0;
                
                //Use a minimum heap to store the values from each diagonal in sorted order
                priority_queue<int, vector<int>, greater<int>> minHeap;
                
                //Iterate over the diagonal and add all values to the minHeap
                while(r < rows and column < columns)
                {
                    minHeap.emplace(mat[r][column]);
                    
                    r+=1;
                    
                    column+=1;
                }
                
                r=row;

                column=0;

                //Iterate back through the diagonal and replace each number with the correct sorted value from the minHeap
                while(r < rows and column < columns and !minHeap.empty())
                {
                    mat[r][column]=minHeap.top();

                    minHeap.pop();

                    r+=1;

                    column+=1;
                }
            
            }
            
            //Iterate through all the digonals that start with the first number in each column beginning with the second column
            for(int column=1;column<columns;column++)
            {
                int row=0;
                
                int c=column;
                
                //Use a minimum heap to sort the elements from the diagonal
                priority_queue<int, vector<int>, greater<int>> minHeap;
                
                //Loop through the diagonal and add all elements to the minimum heap
                while(row < rows and c < columns)
                {
                    minHeap.emplace(mat[row][c]);
                    
                    row+=1;
                    
                    c+=1;
                }
                
                row=0;
                
                c=column;
                
                //Loop back through the diagonal and replace each number with the correct sorted value
                while(row < rows and c < columns and !minHeap.empty())
                {
                    mat[row][c]=minHeap.top();
                    
                    minHeap.pop();
                    
                    row+=1;
                    
                    c+=1;
                }
            }
            
            return mat;
        }
};